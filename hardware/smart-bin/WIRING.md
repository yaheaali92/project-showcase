# Wiring and component guide · دليل المكونات والتوصيل · Bileşen ve bağlantı kılavuzu

## English

Historical prototype: ESP32; 5 V ultrasonic distance module (TRIG GPIO5, ECHO GPIO18); SSD1306 OLED (SDA GPIO21, SCL GPIO22); four fill LEDs (GPIO32/33/26/25); power indicator (GPIO14); buzzer (GPIO27); BLE phone connection. The source report includes five LED branches with 330 Ω series resistors. The GPS/municipality/fleet concept was not built.

The historical direct 5 V Echo connection must **not** be copied. A conditional rebuild uses a 1 kΩ/2 kΩ divider on Echo to yield about 3.3 V at GPIO18 (subject to resistor tolerance and actual module output), individual LED series resistors, common ground, a verified 3.3 V OLED breakout, and a buzzer driver if the load requires more current than GPIO can supply. Fit flyback protection if the sounder is inductive. Verify whether a 3.3 V trigger is accepted by the chosen ultrasonic module. No physical validation or electrical certification is claimed. [Espressif GPIO voltage FAQ](https://docs.espressif.com/projects/esp-faq/en/latest/hardware-related/hardware-design.html).

## العربية

النموذج التاريخي: ESP32؛ حساس مسافة يعمل عند 5 فولت (TRIG على GPIO5 وECHO على GPIO18)؛ شاشة SSD1306 (SDA على GPIO21 وSCL على GPIO22)؛ أربعة مؤشرات امتلاء على GPIO32/33/26/25؛ مؤشر طاقة على GPIO14؛ صفارة على GPIO27؛ وهاتف متصل عبر BLE. يذكر التقرير مقاومات تسلسلية 330 أوم للمؤشرات الخمسة. لم تُنفذ أفكار GPS والمنصة البلدية والأسطول.

**لا يُنسخ** توصيل Echo ذي 5 فولت المباشر. تقترح إعادة البناء المشروطة مقسم 1 كيلوأوم و2 كيلوأوم ليصل نحو 3.3 فولت إلى GPIO18، ومقاومة مستقلة لكل LED، وأرضيًا مشتركًا، ووحدة OLED موثقة عند 3.3 فولت، ودارة قيادة للصفارة إذا تجاوز تيارها قدرة خرج GPIO، وحماية للملف إن كانت حثية. يجب التحقق من قبول الحساس لإشارة TRIG ذات 3.3 فولت ومن القيم الفعلية للوحدات. لا ادعاء اختبار عتاد أو اعتماد سلامة. [مرجع Espressif الرسمي](https://docs.espressif.com/projects/esp-faq/en/latest/hardware-related/hardware-design.html).

## Türkçe

Tarihsel model: ESP32; 5 V ultrasonik uzaklık modülü (TRIG GPIO5, ECHO GPIO18); SSD1306 OLED (SDA GPIO21, SCL GPIO22); dört doluluk LED'i (GPIO32/33/26/25); güç göstergesi (GPIO14); sesli uyarı (GPIO27); BLE ile bağlı telefon. Rapor beş LED kolu için 330 Ω seri dirençleri içerir. GPS/belediye/filo fikri uygulanmadı.

Doğrudan 5 V Echo bağlantısı **kopyalanmamalıdır**. Koşullu yeniden kurulumda Echo için 1 kΩ/2 kΩ gerilim bölücüyle GPIO18'de yaklaşık 3,3 V, her LED'de ayrı seri direnç, ortak toprak, belgelenmiş 3,3 V OLED modülü ve yük akımı gerektiriyorsa sesli uyarı sürücüsü kullanılır. Endüktif tipte ters gerilim koruması gerekir. Seçilen sensörün 3,3 V TRIG düzeyini kabul ettiği ayrıca doğrulanmalıdır. Fiziksel test veya elektrik güvenliği onayı iddia edilmez. [Espressif kaynağı](https://docs.espressif.com/projects/esp-faq/en/latest/hardware-related/hardware-design.html).
