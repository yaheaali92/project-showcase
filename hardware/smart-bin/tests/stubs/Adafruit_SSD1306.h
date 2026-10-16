#ifndef SMART_BIN_DECLARATION_STUB_SSD
#define SMART_BIN_DECLARATION_STUB_SSD
#include "Adafruit_GFX.h"
#include "Wire.h"
constexpr int SSD1306_SWITCHCAPVCC = 2, SSD1306_WHITE = 1;
class Adafruit_SSD1306 : public Adafruit_GFX {
 public:
  Adafruit_SSD1306(std::uint8_t, std::uint8_t, TwoWire*, std::int8_t);
  bool begin(std::uint8_t, std::uint8_t);
  void clearDisplay(); void display(); void setTextColor(int); void setTextSize(int); void setCursor(int, int);
  void drawBitmap(int, int, const std::uint8_t*, int, int, int);
  void print(double, int); void print(const char*);
};
#endif
