#include "stubs/Arduino.h"
#include "../src/pin_config.hpp"

static_assert(baby_monitor::pins::ambientData == D6, "DHT data must avoid historical boot pin D3");
static_assert(baby_monitor::pins::motionData == D7, "PIR data must avoid historical boot pin D4");
static_assert(baby_monitor::pins::opticalSda == D2 && baby_monitor::pins::opticalScl == D1, "I2C assignment must match the reference diagram");
static_assert(baby_monitor::pins::soundAnalog == A0, "MAX9814 candidate remains on conditioned A0");

int main() { return 0; }
