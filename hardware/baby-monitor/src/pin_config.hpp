#pragma once

#include <Arduino.h>

namespace baby_monitor {
namespace pins {
// Reference rebuild only: D3/GPIO0 and D4/GPIO2 were the historical boot-sensitive pins.
constexpr int ambientData = D6;
constexpr int motionData = D7;
constexpr int opticalSda = D2;
constexpr int opticalScl = D1;
constexpr int soundAnalog = A0;
}  // namespace pins
}  // namespace baby_monitor
