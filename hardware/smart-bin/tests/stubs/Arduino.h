#ifndef SMART_BIN_DECLARATION_STUB_ARDUINO
#define SMART_BIN_DECLARATION_STUB_ARDUINO
// EN: Host declaration stub only, not the ESP32 SDK or runtime behavior.
// AR: تعريفات لبناء المضيف فقط؛ ليست SDK أو محاكاة لسلوك ESP32.
// TR: Yalnız konak derleme bildirimleri; ESP32 SDK veya çalışma davranışı değildir.
#include <cstdint>
#include <string>
class String {
 public:
  String(const char* s) : value(s) {}
  std::size_t length() const { return value.size(); }
  const char* c_str() const { return value.c_str(); }
 private: std::string value;
};
constexpr int HIGH = 1, LOW = 0, OUTPUT = 1, INPUT = 0;
using portMUX_TYPE = int;
#define portMUX_INITIALIZER_UNLOCKED 0
void portENTER_CRITICAL(portMUX_TYPE*);
void portEXIT_CRITICAL(portMUX_TYPE*);
std::uint32_t millis();
void yield();
void delay(std::uint32_t);
void pinMode(int, int);
void digitalWrite(int, int);
void delayMicroseconds(std::uint32_t);
unsigned long pulseIn(int, int, unsigned long);
struct SerialType { void begin(unsigned long); void println(const char*); };
extern SerialType Serial;
#endif
