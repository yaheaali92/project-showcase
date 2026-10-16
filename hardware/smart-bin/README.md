# Smart bin — public educational source

[العربية](README.ar.md) · English · [Türkçe](README.tr.md)

The original course prototype estimates fill level from an ultrasonic distance reading. An ESP32 shows state on an OLED and LEDs, sounds a buzzer when full, and sends a Bluetooth Low Energy alert to a nearby connected phone. [The course demonstration](https://youtu.be/GwyfZ4DQr9k) is historical visual evidence, not calibration or field deployment. The firmware here is a later software refinement, not the submitted original.

The public candidate separates sensor validity, filtering, hysteresis, display and BLE state. It preserves four fill LEDs and the historical GPIO14 power indicator. The included historical wiring diagram records a direct 5 V Echo connection as a hazard; the reference diagram is conditional on board and module verification. Read [the three-language wiring guide](WIRING.md) before building. Do not attach a 5 V Echo directly to ESP32 GPIO18.

Host checks with a C++11 compiler: `g++ -std=c++11 -Wall -Wextra -Werror tests/test_main.cpp -o smart-bin-tests` then run the executable. These logic checks alone do not compile the ESP32 firmware. Separately, on 2026-10-16 the sanitized sketch compiled for generic `esp32:esp32:esp32` with portable Arduino CLI 1.5.1, ESP32 core 3.3.12 and the pinned libraries in `build-target.json` (1,143,731 bytes of program storage; 43,180 bytes of global data). This does not prove exact-board compatibility, electrical safety, sensor behavior or physical operation.

The [portfolio case](https://yahyaalali.com/en/content-library/project/smart-bin/) explains the prototype for visitors. Assets in `assets/` separate a generated conceptual cover, a portfolio mark, historical evidence and labelled diagrams. No general reuse licence is granted; see [NOTICE](NOTICE). No Wi‑Fi or cloud credentials are needed or included.
