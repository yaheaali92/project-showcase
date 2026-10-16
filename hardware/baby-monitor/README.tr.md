# Sensörlerle bebek ortamı izleme — akademik prototip

[العربية](README.ar.md) · [English](README.md) · Türkçe

Tarihsel ESP8266 ders projesi DHT11 ortam sıcaklığı/nemi, MAX30102 optik sinyalleri, HC-SR501 hareketi ve MAX9814 ses girdisini Serial ve Arduino IoT Cloud sunumuyla birleştirdi. Onaylı tıbbi cihaz değildi. Sonraki genel yazılım adayı güncel, eksik, geçersiz ve eski okumaları ayırır; canlı buluta bağlanmaz ve eski kimlik bilgilerini yeniden kullanmaz. Klinik doğruluk veya yeniden üretilmiş çocuk ölçümü iddia edilmez.

`assets/` tarihsel D3/D4/D2/D1/A0 sinyal haritasını ve ders raporundan kırpılmış figürleri içerir. Ayrı koşullu başvuru çizimi DHT11 ile PIR'ı ESP8266 açılış uçlarından taşır; ancak bilinmeyen MAX30102 modülünde regülatör/seviye dönüştürücü bulunduğunu veya NodeMCU A0 aralığının MAX9814 çıkışını kabul ettiğini varsaymaz. [Üç dilli bağlantı kılavuzunu](WIRING.md) okuyun. Tarihsel Fritzing görselini montaj talimatı olarak kullanmayın.

Yerel mantık testi: `g++ -std=c++11 -Wall -Wextra -Werror tests/core_tests.cpp -o baby-core-tests` ve sonucu çalıştırın. Bağdaştırıcı etkileşim testi `tests/firmware_interaction.cpp` dosyasını `-Itests/stubs -Isrc -DMONITOR_LANGUAGE=0` (veya 1, 2) ile sahte tanımlara karşı derler. Bunlar yapay bilgisayar testleridir, klinik doğrulama değildir. Aday, sürümleri sabitlenmiş araç, kart paketi ve sensör kitaplıklarıyla NodeMCU/ESP8266 için de derlendi; [derleme sözleşmesine](build-target.json) bakın. Dış MAX3010x kitaplığı `I2C_BUFFER_LENGTH` makrosunun yeniden tanımlandığı uyarısını verdi. Fiziksel kart, bağlantı, kalibrasyon ve klinik ölçümler test edilmedi.

[Portföy çalışması](https://yahyaalali.com/tr/content-library/project/baby-monitor/) ve [NOTICE](NOTICE) kapsamı açıklar. `secrets.example.h` yalnız sahte şablondur; tarihsel `thingProperties.h`, `sketch.json`, bulut anahtarı, Wi-Fi parolası veya özel kaynak geçmişi eklenmedi. Genel yeniden kullanım lisansı verilmez.
