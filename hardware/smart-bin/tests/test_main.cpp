#include "../firmware/SmartBin/src/bin_core.h"
#include "../firmware/SmartBin/src/i18n.h"
#include "../firmware/SmartBin/src/oled_labels.h"
#include "../firmware/SmartBin/src/pin_config.h"
#include <cstring>
#include <functional>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

static_assert(smartbin::pins::trigger == 5 && smartbin::pins::echo == 18, "Course sensor pins must match the historical diagram");
static_assert(smartbin::pins::powerIndicator == 14, "Retain the course power-indicator pin");
static_assert(smartbin::pins::fillIndicators[0] == 32 && smartbin::pins::fillIndicators[1] == 33 && smartbin::pins::fillIndicators[2] == 26 && smartbin::pins::fillIndicators[3] == 25, "Fill LED pins must match the wiring guide");
static_assert(smartbin::pins::oledSda == 21 && smartbin::pins::oledScl == 22, "OLED pins must match the wiring guide");
using namespace smartbin;
struct FakeIo final : DeviceIo {
  bool display = true, link = false, advertisingRequest = false;
  std::uint32_t echo = 3000, observedTimeout = 0;
  unsigned reads = 0, renders = 0, advertisements = 0, notifications = 0, leds = 0;
  bool buzzer = false;
  Snapshot published, rendered;
  bool initializeDisplay() override { return display; }
  std::uint32_t measureEcho(std::uint32_t timeout) override { ++reads; observedTimeout = timeout; return echo; }
  bool connected() const override { return link; }
  bool consumeAdvertisingRequest() override { const bool result = advertisingRequest; advertisingRequest = false; return result; }
  void advertise() override { ++advertisements; }
  void outputs(unsigned level, bool alarm) override { leds = level; buzzer = alarm; }
  void render(const Snapshot& snapshot) override { ++renders; rendered = snapshot; }
  void publish(const Snapshot& snapshot) override { published = snapshot; }
  void notifyFull() override {
    if (!link || !published.valid || published.state != State::Full) throw std::runtime_error("unsafe notification / إشعار غير آمن / güvensiz bildirim");
    ++notifications;
  }
};
void require(bool condition) { if (!condition) throw std::runtime_error("assertion failed / فشل التحقق / doğrulama başarısız"); }
unsigned passed = 0, failed = 0;
void test(const char* id, const char* ar, const char* en, const char* tr, const std::function<void()>& body) {
  try {
    body(); ++passed;
    std::cout << "{\"id\":\"" << id << "\",\"labels\":{\"ar\":\"" << ar << "\",\"en\":\"" << en << "\",\"tr\":\"" << tr << "\"},\"passed\":true}\n";
  } catch (const std::exception&) {
    ++failed;
    std::cout << "{\"id\":\"" << id << "\",\"labels\":{\"ar\":\"" << ar << "\",\"en\":\"" << en << "\",\"tr\":\"" << tr << "\"},\"passed\":false}\n";
  }
}
int main() {
  Config c;
  const double boundaries[] = {9.99, 10, 19.99, 20, 34.99, 35, 49.99, 50};
  const unsigned expected[] = {4, 3, 3, 2, 2, 1, 1, 0};
  for (unsigned i = 0; i < 8; ++i) {
    const std::string id = "SB-TEST-01/B" + std::to_string(i + 1);
    test(id.c_str(), "حد المسافة وعدد المؤشرات", "Distance boundary and LED score", "Mesafe sınırı ve LED sayısı", [&, i] { require(score(classifyRaw(boundaries[i], c)) == expected[i]); });
  }
  test("SB-TEST-01/config-valid", "إعداد افتراضي صالح", "Valid default configuration", "Geçerli varsayılan ayar", [&] { require(validConfig(c)); });
  test("SB-TEST-01/config-order", "رفض حدود غير مرتبة", "Reject unordered boundaries", "Sırasız sınırları reddet", [&] { auto bad = c; bad.boundariesCm[1] = 5; require(!validConfig(bad)); });
  test("SB-TEST-01/config-hysteresis", "رفض هامش كبير", "Reject excessive hysteresis", "Aşırı histerezisi reddet", [&] { auto bad = c; bad.hysteresisCm = 8; require(!validConfig(bad)); });
  test("SB-TEST-01/config-fail-closed", "إعداد خاطئ بلا قياس أو إنذار", "Invalid config fails closed", "Geçersiz ayar güvenli kalır", [&] { FakeIo f; auto bad = c; bad.echoTimeoutUs = 0; Controller r(f, bad); r.begin(0); r.tick(0); require(f.reads == 0 && !f.buzzer && f.leds == 0 && f.published.state == State::ConfigFault); });
  test("SB-TEST-02/timeout", "مهلة بلا امتلاء كاذب", "Timeout is not full", "Zaman aşımı dolu değildir", [&] { auto s = pulseReading(0, c); require(!s.valid() && s.status == ReadingStatus::Timeout); });
  test("SB-TEST-02/negative", "قراءة سالبة مرفوضة", "Negative distance rejected", "Negatif mesafe reddedilir", [&] { require(!distanceReading(-1, c).valid()); });
  test("SB-TEST-02/nan", "قراءة غير عددية مرفوضة", "NaN rejected", "NaN reddedilir", [&] { require(!distanceReading(std::numeric_limits<double>::quiet_NaN(), c).valid()); });
  test("SB-TEST-02/infinity", "قراءة غير محدودة مرفوضة", "Infinity rejected", "Sonsuz değer reddedilir", [&] { require(!distanceReading(std::numeric_limits<double>::infinity(), c).valid()); });
  test("SB-TEST-02/range", "حدود مجال القياس", "Measurement domain boundaries", "Ölçüm aralığı sınırları", [&] { require(!distanceReading(0.49, c).valid() && distanceReading(0.5, c).valid() && distanceReading(400, c).valid() && !distanceReading(400.01, c).valid()); });
  test("SB-TEST-02/echo-deadline", "نبضة خارج المهلة", "Echo beyond explicit deadline", "Açık süreyi aşan yankı", [&] { require(!pulseReading(c.echoTimeoutUs, c).valid()); });
  test("SB-TEST-02/outputs-error", "فشل الحساس يطفئ المؤشرات", "Sensor fault clears outputs", "Sensör hatası çıkışları kapatır", [&] { FakeIo f; f.echo = 0; f.link = true; Controller r(f); r.begin(0); r.tick(0); require(f.leds == 0 && !f.buzzer && f.notifications == 0 && f.published.state == State::SensorFault && !f.rendered.valid && f.rendered.distanceCm == 0); });
  test("SB-TEST-03/hysteresis-stay", "ثبات حول حد الامتلاء", "Stable around full boundary", "Dolu sınırında kararlılık", [&] { require(classifyStable(10.2, State::Full, c) == State::Full && classifyStable(9.8, State::High, c) == State::High); });
  test("SB-TEST-03/hysteresis-cross", "تجاوز الحد والهامش", "Cross boundary and margin", "Sınır ve payı aş", [&] { require(classifyStable(10.5, State::Full, c) == State::High && classifyStable(9.4, State::High, c) == State::Full); });
  test("SB-TEST-03/hysteresis-jump", "انتقال عبر مستويات متعددة", "Jump across multiple levels", "Birden çok düzey geçişi", [&] { require(classifyStable(9.8, State::Empty, c) == State::High && classifyStable(51, State::Full, c) == State::Empty); });
  test("SB-TEST-03/median", "ترشيح الوسيط الثلاثي", "Three-sample median filter", "Üç örnekli medyan süzgeci", [&] { MedianWindow m; m.add(30); m.add(31); require(m.add(5) == 30); });
  test("SB-TEST-03/invalid-resets", "خطأ يلغي القراءة القديمة", "Fault resets old filter state", "Hata eski süzgeç durumunu siler", [&] { FakeIo f; f.echo = 3000; Controller r(f); r.begin(0); r.tick(0); f.echo = 0; r.tick(500); f.echo = 294; r.tick(1000); require(f.published.state == State::Full && f.published.distanceCm < 10); });
  test("SB-TEST-03/expiry", "لا تعرض قراءة منتهية كحديثة", "Expired reading is not current", "Süresi dolan okuma güncel değildir", [&] { FakeIo f; Controller r(f); r.begin(0); r.tick(0); const auto s = r.readable(1500); require(!s.valid && s.state == State::SensorFault && s.distanceCm == 0); });
  test("SB-TEST-03/no-duplicate", "إشعار واحد دون تكرار دوري", "No repeated full notification", "Tekrarlayan dolu bildirimi yok", [&] { FakeIo f; f.echo = 294; f.link = true; Controller r(f); r.begin(0); for (unsigned t = 0; t <= 5000; t += 100) r.tick(t); require(f.notifications == 1 && f.published.state == State::Full); });
  test("SB-TEST-03/rate-limit", "تقييد إشعار انتقال سريع", "Rate-limit a quick transition", "Hızlı geçiş bildirimi sınırlı", [&] { FakeIo f; f.echo = 294; f.link = true; auto fast = c; fast.sampleIntervalMs = 100; Controller r(f, fast); r.begin(0); r.tick(0); f.echo = 0; r.tick(100); f.echo = 294; r.tick(200); require(f.notifications == 1); r.tick(1000); require(f.notifications == 2); });
  test("SB-TEST-03/read-state", "القراءة توافق المخرجات", "Read state matches outputs", "Okuma çıkışlarla eşleşir", [&] { FakeIo f; f.echo = 294; Controller r(f); r.begin(0); r.tick(0); require(f.published.state == State::Full && f.buzzer && f.leds == 4 && std::strcmp(wireValue(f.published.state), "Çöp kutusu dolu") == 0); });
  test("SB-TEST-04/disconnected", "لا إشعار لعميل مفصول", "No notification while disconnected", "Bağlantı yokken bildirim yok", [&] { FakeIo f; f.echo = 294; Controller r(f); r.begin(0); r.tick(0); require(f.notifications == 0); });
  test("SB-TEST-04/reconnect", "إعادة الاتصال تقرأ الحالة الحالية", "Reconnect receives current full state", "Yeniden bağlanma güncel dolu durumunu alır", [&] { FakeIo f; f.echo = 294; Controller r(f); r.begin(0); r.tick(0); f.link = true; r.tick(50); require(f.notifications == 1 && f.published.state == State::Full); });
  test("SB-TEST-04/advertise-empty", "إعادة الإعلان دون امتلاء", "Re-advertise independently of full", "Doluluktan bağımsız yeniden ilan", [&] { FakeIo f; f.link = true; Controller r(f); r.begin(0); r.tick(0); f.link = false; f.advertisingRequest = true; r.tick(100); r.tick(599); require(f.advertisements == 0); r.tick(600); require(f.advertisements == 1 && f.published.state == State::Empty); });
  test("SB-TEST-04/advertise-full", "إعادة الإعلان عند الامتلاء", "Re-advertise while full", "Doluyken yeniden ilan", [&] { FakeIo f; f.echo = 294; f.link = true; Controller r(f); r.begin(0); r.tick(0); f.link = false; f.advertisingRequest = true; r.tick(100); r.tick(600); require(f.advertisements == 1 && f.notifications == 1); });
  test("SB-TEST-04/short-disconnect", "حفظ حدث فصل قصير", "Short disconnect event retained", "Kısa kopma olayı korunur", [&] { FakeIo f; Controller r(f); r.begin(0); f.advertisingRequest = true; r.tick(100); r.tick(600); require(f.advertisements == 1); });
  test("SB-TEST-04/cancel-advertise", "إلغاء إعلان عند اتصال قائم", "Cancel pending advertising on connection", "Bağlantı kurulunca bekleyen ilan iptal", [&] { FakeIo f; Controller r(f); r.begin(0); f.advertisingRequest = true; r.tick(100); f.link = true; r.tick(200); r.tick(700); require(f.advertisements == 0); });
  test("SB-TEST-04/clock-wrap", "الجدولة عبر التفاف الساعة", "Scheduling across clock wrap", "Sayaç taşmasında zamanlama", [&] { FakeIo f; Controller r(f); const std::uint32_t near = 0xfffffff0u; r.begin(near); r.tick(near); r.tick(near + 499u); require(f.reads == 1); r.tick(near + 500u); require(f.reads == 2); });
  test("SB-TEST-05/display-failure", "فشل الشاشة لا يوقف القياس", "Display failure preserves sensing", "Ekran hatası ölçümü durdurmaz", [&] { FakeIo f; f.display = false; f.echo = 294; f.link = true; Controller r(f); r.begin(0); r.tick(0); require(!r.displayReady() && f.renders == 0 && f.reads == 1 && f.buzzer && f.notifications == 1); });
  test("SB-TEST-05/write-empty", "مدخل فارغ بلا فعل", "Empty input has no action", "Boş girdinin işlemi yok", [&] { require(inspectWrite("", 0, c) == WriteResult::Empty); });
  test("SB-TEST-05/write-long", "مدخل طويل مرفوض", "Oversized input rejected", "Uzun girdi reddedilir", [&] { require(inspectWrite(nullptr, 33, c) == WriteResult::TooLong); });
  test("SB-TEST-05/write-S", "لا اختراع وظيفة للأمر القديم", "No invented S command", "S komutuna işlev uydurulmaz", [&] { require(inspectWrite("S", 1, c) == WriteResult::Unsupported); });
  test("SB-TEST-05/write-unknown", "أمر مجهول لا يغير القراءة", "Unknown write does not change reading", "Bilinmeyen yazma okumayı değiştirmez", [&] { FakeIo f; Controller r(f); r.begin(0); r.tick(0); const auto old = f.published.state; require(inspectWrite("OPEN", 4, c) == WriteResult::Unsupported && f.published.state == old); });
  test("SB-TEST-05/write-binary", "مدخل ثنائي لا ينفذ فعلًا", "Binary input performs no action", "İkili girdi işlem yapmaz", [&] { const char bytes[] = {'S', '\0', 'X'}; require(inspectWrite(bytes, 3, c) == WriteResult::Unsupported); });
  test("SB-TEST-05/three-languages", "تغطية نصوص اللغات الثلاث", "All three languages have labels", "Üç dilin metinleri mevcut", [&] { for (unsigned l = 0; l < 3; ++l) for (unsigned s = 0; s < 8; ++s) require(std::strlen(stateLabel(static_cast<Language>(l), static_cast<State>(s))) > 0); require(std::strcmp(stateLabel(Language::Arabic, State::Full), stateLabel(Language::English, State::Full)) != 0); });
  test("SB-TEST-05/explicit-timeout", "تمرير مهلة القياس الفعلية", "Runtime passes explicit echo deadline", "Çalışma açık yankı süresini iletir", [&] { FakeIo f; Controller r(f); r.begin(0); r.tick(0); require(f.observedTimeout == c.echoTimeoutUs); });
  test("SB-TEST-05/oled-bitmaps", "صور نصوص الشاشة غير فارغة", "Localized OLED bitmaps are nonblank", "Yerelleştirilmiş OLED resimleri boş değil", [&] { for (unsigned l = 0; l < 3; ++l) for (unsigned s = 0; s < 8; ++s) { const auto* bytes = oledStateLabel(static_cast<Language>(l), static_cast<State>(s)); unsigned nonzero = 0; for (unsigned n = 0; n < 300; ++n) nonzero += bytes[n] != 0; require(nonzero > 0); } });
  std::cout << "{\"summary\":true,\"passed\":" << passed << ",\"failed\":" << failed << ",\"hardwareTested\":false,\"esp32FirmwareCompiled\":false}\n";
  return failed == 0 ? 0 : 1;
}
