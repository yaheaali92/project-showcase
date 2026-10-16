#pragma once
#include <array>
#include <cmath>
#include <cstdint>
#include <limits>

namespace baby_monitor {
enum class State { Missing, Fresh, Invalid, Stale };
enum class Signal : unsigned { AmbientTemperature, Humidity, PulseEstimate, OxygenEstimate, Motion, SoundAdc, Count };
constexpr unsigned signal_count = static_cast<unsigned>(Signal::Count);
struct Reading {
  State state;
  bool has_last_good;
  float last_good;
  uint32_t measured_at;
};
struct Spec { float minimum; float maximum; uint32_t max_age_ms; bool integral; };
class Channel {
 public:
  explicit Channel(Spec spec) : spec_(spec) {}
  bool ingest(float value, bool provider_valid, uint32_t now) {
    // EN: Ignore out-of-order input, including across clock wrap. | AR: تجاهل العينة الأقدم مع مراعاة التفاف الساعة. | TR: Sayaç taşmasında da eski örneği yok say.
    if (observed_ && uint32_t(now - observed_at_) >= 0x80000000u) return false;
    observed_ = true;
    observed_at_ = now;
    valid_ = provider_valid && std::isfinite(value) && value >= spec_.minimum &&
             value <= spec_.maximum && (!spec_.integral || std::floor(value) == value);
    if (valid_) { has_good_ = true; value_ = value; measured_at_ = now; }
    return valid_;
  }
  Reading read(uint32_t now) const {
    State state = !observed_ ? State::Missing : !valid_ ? State::Invalid : State::Fresh;
    if (has_good_ && uint32_t(now - measured_at_) >= spec_.max_age_ms) state = State::Stale;
    return {state, has_good_, value_, measured_at_};
  }
 private:
  Spec spec_;
  bool observed_ = false, valid_ = false, has_good_ = false;
  float value_ = std::numeric_limits<float>::quiet_NaN();
  uint32_t measured_at_ = 0, observed_at_ = 0;
};
class Monitor {
 public:
  Monitor() : channels_{{
    Channel({-std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), 6000, false}),
    Channel({0, 100, 6000, false}),
    Channel({std::numeric_limits<float>::min(), std::numeric_limits<float>::max(), 6000, false}),
    Channel({0, 100, 6000, false}),
    Channel({0, 1, 1000, true}),
    Channel({0, 1023, 1000, true})
  }} {}
  bool ingest(Signal signal, float value, bool provider_valid, uint32_t now) {
    const unsigned index = static_cast<unsigned>(signal);
    return index < signal_count && channels_[index].ingest(value, provider_valid, now);
  }
  Reading read(Signal signal, uint32_t now) const {
    const unsigned index = static_cast<unsigned>(signal);
    return index < signal_count ? channels_[index].read(now) : Reading{State::Invalid,false,std::numeric_limits<float>::quiet_NaN(),0};
  }
 private:
  // EN: These are data-quality rules, not medical limits. | AR: هذه قواعد جودة بيانات وليست حدودًا طبية. | TR: Bunlar veri kalitesi kurallarıdır, tıbbi eşikler değildir.
  std::array<Channel, signal_count> channels_;
};
class Schedule {
 public:
  explicit Schedule(uint32_t interval) : interval_(interval) {}
  bool due(uint32_t now) {
    if (started_ && uint32_t(now - last_) < interval_) return false;
    started_ = true; last_ = now; return true;
  }
 private:
  uint32_t interval_, last_ = 0;
  bool started_ = false;
};
class FaultGate {
 public:
  bool changed(State state, uint32_t now) {
    if (!seen_) { seen_ = true; state_ = state; last_notice_ = now; return state != State::Fresh; }
    if (state == state_) {
      if (pending_ && uint32_t(now - last_notice_) >= 1000) { pending_ = false; last_notice_ = now; return true; }
      return false;
    }
    const bool recovery = state == State::Fresh;
    state_ = state;
    if (!recovery && uint32_t(now - last_notice_) < 1000) { pending_ = true; return false; }
    pending_ = false; last_notice_ = now; return true;
  }
 private:
  bool seen_ = false;
  bool pending_ = false;
  State state_ = State::Missing;
  uint32_t last_notice_ = 0;
};
class ReconnectPolicy {
 public:
  bool attempt_due(bool enabled, bool connected, uint32_t now) {
    if (!enabled) { attempted_ = false; delay_ = 1000; return false; }
    if (connected) { attempted_ = false; delay_ = 1000; return false; }
    if (attempted_ && uint32_t(now - last_) < delay_) return false;
    last_ = now;
    if (attempted_) delay_ = delay_ < 16000 ? delay_ * 2 : 30000;
    attempted_ = true; return true;
  }
 private:
  bool attempted_ = false;
  uint32_t delay_ = 1000, last_ = 0;
};
struct Transmission { bool available; std::array<Reading, signal_count> readings; };
inline Transmission current_transmission(const Monitor& monitor, bool connected, uint32_t now) {
  Transmission output{}; output.available = connected;
  for (unsigned i=0;i<signal_count;i++) {
    output.readings[i]=monitor.read(static_cast<Signal>(i),now);
    // EN: Stale values must never travel as current samples. | AR: لا تُرسل القيم القديمة كعينات حديثة. | TR: Eski değerleri güncel örnek diye gönderme.
    if(output.readings[i].state!=State::Fresh) {output.readings[i].has_last_good=false;output.readings[i].last_good=std::numeric_limits<float>::quiet_NaN();}
  }
  return output;
}
}
