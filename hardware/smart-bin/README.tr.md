# Akıllı çöp kutusu — açık eğitim kaynağı

[العربية](README.ar.md) · [English](README.md) · Türkçe

Ders prototipi ultrasonik sensörle atık yüzeyine olan uzaklığı ölçer. ESP32 durumu OLED ekranda ve LED'lerde gösterir, doluyken sesli uyarı verir ve yakındaki bağlı telefona Bluetooth Low Energy bildirimi gönderir. [Ders videosu](https://youtu.be/GwyfZ4DQr9k) sınırlı tarihsel gösterim kanıtıdır; kalibrasyon veya saha kullanımı değildir. Buradaki yazılım, özgün teslimden sonraki ayrı bir iyileştirmedir.

Genel aday sensör geçerliliği, süzme, histerezis, ekran ve BLE durumlarını ayırır. Dört doluluk LED'i ile tarihsel GPIO14 güç göstergesi korunur. Tarihsel şema, 5 V Echo'nun ESP32 girişine doğrudan bağlanmasını bir tehlike olarak belgeler; başvuru şeması kart ve modül doğrulamasına bağlıdır. [Üç dilli bağlantı kılavuzunu](WIRING.md) okuyun. 5 V Echo'yu GPIO18'e doğrudan bağlamayın.

C++11 mantık denetimi: `g++ -std=c++11 -Wall -Wextra -Werror tests/test_main.cpp -o smart-bin-tests` ve çıkan programı çalıştırın. Bu testler tek başına ESP32 firmware derlemesi değildir. Ayrı olarak iyileştirilmiş sketch, 16 Ekim 2026'da taşınabilir Arduino CLI 1.5.1, çekirdek 3.3.12 ve `build-target.json` içindeki sabit kütüphanelerle genel `esp32:esp32:esp32` hedefi için derlendi. Bu, gerçek kart uyumluluğunu, elektrik güvenliğini veya sensör ve donanım testini kanıtlamaz.

[Portföydeki çalışma](https://yahyaalali.com/tr/content-library/project/smart-bin/) ziyaretçiye modeli açıklar. `assets/` içinde üretilmiş kavramsal kapak, portföy işareti, tarihsel kanıt ve etiketli şemalar ayrıdır. Genel yeniden kullanım lisansı verilmez; [NOTICE](NOTICE) dosyasına bakın. Wi‑Fi veya bulut kimlik bilgileri bulunmaz.
