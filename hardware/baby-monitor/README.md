# Sensor-based baby environment monitor — academic prototype

[العربية](README.ar.md) · English · [Türkçe](README.tr.md)

The historical ESP8266 course project combined DHT11 ambient temperature/humidity, MAX30102 optical signals, HC-SR501 motion and MAX9814 microphone-amplifier input with a Serial and Arduino IoT Cloud presentation. It was not a validated medical device. The later public software candidate separates fresh, missing, invalid and stale readings; it does not transmit to a live cloud or reuse legacy credentials. Clinical accuracy and reproduced child measurements are not claimed.

The historical D3/D4/D2/D1/A0 signal map and cropped course-report figures are in `assets/`. The distinct conditional reference diagram moves DHT11 and PIR off ESP8266 boot pins, but does **not** assume that an unspecified MAX30102 breakout includes a regulator or level shifting, nor that a NodeMCU A0 range accepts MAX9814 output. Read [the trilingual wiring guide](WIRING.md). Do not assemble from the historical Fritzing image.

Host logic tests: `g++ -std=c++11 -Wall -Wextra -Werror tests/core_tests.cpp -o baby-core-tests`, then run the executable. The adapter interaction test compiles `tests/firmware_interaction.cpp` against local stubs with `-Itests/stubs -Isrc -DMONITOR_LANGUAGE=0` (or 1, 2). These are synthetic host checks, not clinical validation. The candidate also compiled for NodeMCU/ESP8266 with pinned Arduino CLI, core and sensor-library versions; see [the build contract](build-target.json). The SparkFun MAX3010x library emitted an `I2C_BUFFER_LENGTH` macro-redefinition warning. No physical board, wiring, calibration or clinical measurements were verified.

See the [portfolio case](https://yahyaalali.com/en/content-library/project/baby-monitor/) and [NOTICE](NOTICE). `secrets.example.h` is a dummy template only; no historical `thingProperties.h`, `sketch.json`, cloud key, Wi-Fi secret or private source history is included. No general reuse licence is granted.
