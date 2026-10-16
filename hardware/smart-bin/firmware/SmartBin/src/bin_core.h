#ifndef YAHYA_SMART_BIN_CORE_H
#define YAHYA_SMART_BIN_CORE_H

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>

namespace smartbin {
enum class State { Unknown, Empty, Low, Medium, High, Full, SensorFault, ConfigFault };
enum class ReadingStatus { Valid, Timeout, OutOfRange };
enum class WriteResult { Empty, TooLong, Unsupported };

struct Config {
  std::array<double, 4> boundariesCm{{10.0, 20.0, 35.0, 50.0}};
  double minimumDistanceCm = 0.5;
  double maximumDistanceCm = 400.0;
  double hysteresisCm = 0.5;
  double soundSpeedCmPerUs = 0.034;
  std::uint32_t echoTimeoutUs = 30000;
  std::uint32_t sampleIntervalMs = 500;
  std::uint32_t readingExpiryMs = 1500;
  std::uint32_t notificationIntervalMs = 1000;
  std::uint32_t advertisingGraceMs = 500;
  std::size_t maximumWriteBytes = 32;
};

inline bool validConfig(const Config& c) {
  if (!std::isfinite(c.minimumDistanceCm) || !std::isfinite(c.maximumDistanceCm) ||
      !std::isfinite(c.hysteresisCm) || !std::isfinite(c.soundSpeedCmPerUs) ||
      c.minimumDistanceCm <= 0 || c.maximumDistanceCm <= c.minimumDistanceCm ||
      c.hysteresisCm < 0 || c.soundSpeedCmPerUs <= 0) return false;
  double previous = c.minimumDistanceCm;
  for (double boundary : c.boundariesCm) {
    if (!std::isfinite(boundary) || boundary <= previous ||
        boundary >= c.maximumDistanceCm || c.hysteresisCm * 2 >= boundary - previous) return false;
    previous = boundary;
  }
  return c.echoTimeoutUs > 0 && c.sampleIntervalMs > 0 &&
      c.readingExpiryMs > c.sampleIntervalMs && c.notificationIntervalMs > 0 &&
      c.maximumWriteBytes > 0 && c.maximumWriteBytes <= 512 &&
      c.sampleIntervalMs < 0x80000000u && c.readingExpiryMs < 0x80000000u &&
      c.notificationIntervalMs < 0x80000000u && c.advertisingGraceMs < 0x80000000u;
}

struct Reading {
  ReadingStatus status;
  double distanceCm;
  bool valid() const { return status == ReadingStatus::Valid; }
};
inline Reading distanceReading(double cm, const Config& c) {
  if (!std::isfinite(cm) || cm < c.minimumDistanceCm || cm > c.maximumDistanceCm)
    return {ReadingStatus::OutOfRange, 0};
  return {ReadingStatus::Valid, cm};
}
inline Reading pulseReading(std::uint32_t durationUs, const Config& c) {
  if (durationUs == 0) return {ReadingStatus::Timeout, 0};
  if (durationUs >= c.echoTimeoutUs) return {ReadingStatus::OutOfRange, 0};
  return distanceReading(durationUs * c.soundSpeedCmPerUs / 2.0, c);
}
inline bool measuredState(State s) { return s >= State::Empty && s <= State::Full; }
inline unsigned score(State s) { return measuredState(s) ? static_cast<unsigned>(s) - 1u : 0u; }
inline State stateForScore(unsigned s) { return static_cast<State>(s + 1u); }
inline State classifyRaw(double cm, const Config& c) {
  if (!distanceReading(cm, c).valid()) return State::SensorFault;
  unsigned result = 0;
  for (double boundary : c.boundariesCm) if (cm < boundary) ++result;
  return stateForScore(result);
}
inline State classifyStable(double cm, State previous, const Config& c) {
  if (!distanceReading(cm, c).valid()) return State::SensorFault;
  if (!measuredState(previous)) return classifyRaw(cm, c);
  unsigned result = score(previous);
  while (result < 4 && cm < c.boundariesCm[3 - result] - c.hysteresisCm) ++result;
  while (result > 0 && cm >= c.boundariesCm[4 - result] + c.hysteresisCm) --result;
  return stateForScore(result);
}
class MedianWindow {
 public:
  void clear() { count_ = cursor_ = 0; }
  double add(double value) {
    values_[cursor_] = value;
    cursor_ = (cursor_ + 1) % values_.size();
    if (count_ < values_.size()) ++count_;
    auto sorted = values_;
    std::sort(sorted.begin(), sorted.begin() + count_);
    return count_ == 2 ? (sorted[0] + sorted[1]) / 2 : sorted[count_ / 2];
  }
 private:
  std::array<double, 3> values_{{0, 0, 0}};
  std::size_t count_ = 0, cursor_ = 0;
};
struct Snapshot {
  State state = State::Unknown;
  ReadingStatus readingStatus = ReadingStatus::Timeout;
  double distanceCm = 0;
  std::uint32_t sampledAt = 0;
  bool valid = false;
};
inline Snapshot currentSnapshot(Snapshot s, std::uint32_t now, const Config& c) {
  if (s.valid && static_cast<std::uint32_t>(now - s.sampledAt) >= c.readingExpiryMs) {
    s.state = State::SensorFault;
    s.valid = false;
    s.distanceCm = 0;
  }
  return s;
}
inline WriteResult inspectWrite(const char* bytes, std::size_t length, const Config& c) {
  if (length == 0) return WriteResult::Empty;
  if (length > c.maximumWriteBytes) return WriteResult::TooLong;
  (void)bytes;
  // EN: Original S performed no action; no remote commands are added.
  // AR: الأمر S الأصلي بلا فعل؛ لا نضيف أوامر تحكم عن بعد.
  // TR: Özgün S komutu işlem yapmıyordu; uzaktan komut eklenmez.
  return WriteResult::Unsupported;
}
inline const char* wireValue(State s) {
  switch (s) {
    case State::Full: return "Çöp kutusu dolu";
    case State::Empty: return "BIN:EMPTY";
    case State::Low: return "BIN:LEVEL:1";
    case State::Medium: return "BIN:LEVEL:2";
    case State::High: return "BIN:LEVEL:3";
    case State::SensorFault: return "BIN:SENSOR_ERROR";
    case State::ConfigFault: return "BIN:CONFIG_ERROR";
    default: return "BIN:UNKNOWN";
  }
}
class DeviceIo {
 public:
  virtual ~DeviceIo() = default;
  virtual bool initializeDisplay() = 0;
  virtual std::uint32_t measureEcho(std::uint32_t timeoutUs) = 0;
  virtual bool connected() const = 0;
  virtual bool consumeAdvertisingRequest() = 0;
  virtual void advertise() = 0;
  virtual void outputs(unsigned leds, bool buzzer) = 0;
  virtual void render(const Snapshot& snapshot) = 0;
  virtual void publish(const Snapshot& snapshot) = 0;
  virtual void notifyFull() = 0;
};
class Controller {
 public:
  Controller(DeviceIo& io, Config config = Config()) : io_(io), config_(config) {}
  void begin(std::uint32_t now) {
    configured_ = validConfig(config_);
    displayReady_ = io_.initializeDisplay();
    snapshot_.state = configured_ ? State::Unknown : State::ConfigFault;
    snapshot_.sampledAt = now;
    applyOutputs();
    io_.publish(snapshot_);
  }
  void tick(std::uint32_t now) {
    const bool connected = io_.connected();
    if (io_.consumeAdvertisingRequest() && !connected) {
      advertisingPending_ = true;
      disconnectedAt_ = now;
    }
    if (connected) advertisingPending_ = false;
    if (advertisingPending_ && elapsed(now, disconnectedAt_) >= config_.advertisingGraceMs) {
      io_.advertise();
      advertisingPending_ = false;
    }
    if (connected && !previousConnected_ && snapshot_.state == State::Full) fullPending_ = true;
    previousConnected_ = connected;
    if (configured_ && (!sampled_ || elapsed(now, lastSample_) >= config_.sampleIntervalMs)) {
      sampled_ = true;
      lastSample_ = now;
      const State oldState = snapshot_.state;
      const Reading reading = pulseReading(io_.measureEcho(config_.echoTimeoutUs), config_);
      snapshot_.sampledAt = now;
      snapshot_.readingStatus = reading.status;
      snapshot_.valid = reading.valid();
      if (reading.valid()) {
        snapshot_.distanceCm = median_.add(reading.distanceCm);
        snapshot_.state = classifyStable(snapshot_.distanceCm, oldState, config_);
      } else {
        median_.clear();
        snapshot_.distanceCm = 0;
        snapshot_.state = State::SensorFault;
      }
      fullPending_ = snapshot_.state == State::Full && (fullPending_ || oldState != State::Full);
      applyOutputs();
      io_.publish(snapshot_);
    }
    // EN: Legacy clients receive full-only events, not new alerts for empty/error.
    // AR: نحافظ على إشعارات الامتلاء فقط؛ لا يتحول خطأ أو فراغ إلى تنبيه موروث.
    // TR: Eski istemcilere yalnız dolu bildirimi gider; boş/hata yeni alarm olmaz.
    if (fullPending_ && connected && snapshot_.valid && snapshot_.state == State::Full &&
        (!notified_ || elapsed(now, lastNotification_) >= config_.notificationIntervalMs)) {
      io_.notifyFull();
      notified_ = true;
      lastNotification_ = now;
      fullPending_ = false;
    }
  }
  Snapshot readable(std::uint32_t now) const { return currentSnapshot(snapshot_, now, config_); }
  bool displayReady() const { return displayReady_; }
 private:
  static std::uint32_t elapsed(std::uint32_t now, std::uint32_t before) { return now - before; }
  void applyOutputs() {
    io_.outputs(snapshot_.valid ? score(snapshot_.state) : 0, snapshot_.valid && snapshot_.state == State::Full);
    if (displayReady_) io_.render(snapshot_);
  }
  DeviceIo& io_;
  Config config_;
  MedianWindow median_;
  Snapshot snapshot_;
  bool configured_ = false, displayReady_ = false, sampled_ = false;
  bool previousConnected_ = false, advertisingPending_ = false, fullPending_ = false, notified_ = false;
  std::uint32_t lastSample_ = 0, disconnectedAt_ = 0, lastNotification_ = 0;
};
}  // smartbin / الصندوق / kutu
#endif
