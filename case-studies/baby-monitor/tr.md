# Bebek izleme prototipi — yorumdan önce veri kalitesi

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md) · [Siteye dön](https://yahyaalali.com/tr/content-library/project/baby-monitor/)

![Dört sensör girdisi ve denetleyicinin kavramsal görseli; cihaz fotoğrafı veya çocuk deneyi değildir](../../assets/editorial/baby-monitor-r4.webp)

Gözlem ve veri kalitesi için kavramsal kapak; çalışan ürün değildir.

## Fikir ve bağlam

Çalışma 2024 ders projesi olarak sensör girdilerini tek kartta topluyor, Serial ve Arduino IoT Cloud üzerinden gösteriyordu. Güncel incelemesi güncel ölçümün, sensör hatasından doğan sıfırdan veya bağlantı kesildikten sonra bellekte kalan eski değerden nasıl ayrılacağını ele alır.

## Bileşenler ve yorum sınırları

| Bileşen  | Gerçek girdi                                             | Yorum sınırı                                      |
| -------- | -------------------------------------------------------- | ------------------------------------------------- |
| DHT11    | Ortam sıcaklığı ve nemi                                  | Vücut sıcaklığı değildir                          |
| MAX30102 | Nabız/doygunluk tahmini için kırmızı ve kızılötesi girdi | Algoritma geçerliliği klinik doğruluğu kanıtlamaz |
| HC-SR501 | PIR hareket sinyali                                      | Düşmeyi veya belirli davranışı kanıtlamaz         |
| MAX9814  | Mikrofon yükseltecinden analog örnek                     | Kalibre desibel veya ağlama teşhisi değildir      |

## Güncel katkım

Ekim 2026'da örnek kabulünü, gösterimden ve durum-değişikliği bildiriminden ayıran bağımsız sürümü geliştirdim. Özgün ders dosyaları korundu. Bu değişiklikler eski teslim tarihine mal edilmez; kitaplıklar ve sinyal işleme algoritması yazarlarına aittir. İncelenen sınırlı kaynak ve raporlar Arduino IoT Cloud yolundadır; Blynk varsayımsal olarak birleştirilmedi.

## Örnekten duruma

Okumalarda eksik, güncel, geçersiz veya eski durumu açıkça belirtilir. Sensör hatası normal durum olmaz; son geçerli değer yeni ölçüm diye gönderilmez. Döngü sayısı yerine süreyle zamanlama yapılır; optik sensör başlamadığında diğer kanallar sürer. FIFO okuma sınırlıdır, örnek için sonsuz bekleme yoktur.

Durum geçişinde sınırlı bekleme ve kaybolmayan bekleyen geçiş kullanılır. Bağlantı gecikmesi ve eski veriyi gizleme yapay girdilerle test edildi; aday gerçek bulut gönderimi yapmaz, eski kimlik bilgilerini kullanmaz. Kalibre edilmemiş tarihsel sağlık eşikleri onaylı tıbbi ayar değildir.

## Doğrulama ve sınırlar

34 yerel C++ mantık senaryosu ve sahte sensör, Serial ve algoritma çıktısıyla üç dilde tekrarlanan 8 bağdaştırıcı etkileşim senaryosu başarılı oldu. Hata, sonlu olmayan/eski veri, örnek sırası, sayaç taşması, zamanlama, bildirim ve benzetilen bağlantı incelendi. Bunlar çocuk/cihaz ölçümü veya nabız algoritmasının doğrulaması değildir.

Gerçek ESP8266 SDK/kitaplık derlemesi, bağlantı, kalibrasyon, sürücü süresi ve güç testleri yapılmadı. Doğruluk/klinik onay iddiası yoktur. Üretilmiş kapak ve veri akışı çizimi kavramsaldır; cihaz fotoğrafı veya bağlantı planı değildir. Kaynak, geçmiş ve ayrıntılı testler özeldir; genel belgeler çalışmayı ve güvenli sonuçları sunar.

## Teknik kaynaklar

- [Adafruit DHT](https://github.com/adafruit/DHT-sensor-library/blob/master/DHT.cpp)
- [SparkFun MAX3010x](https://github.com/sparkfun/SparkFun_MAX3010x_Sensor_Library/blob/master/src/MAX30105.cpp)
- [MAX30102](https://www.analog.com/en/products/max30102.html)
- [MAX9814](https://www.analog.com/en/products/max9814.html)
- [ESP8266](https://arduino-esp8266.readthedocs.io/en/latest/reference.html)

## Açıklayıcı veri akışı

```mermaid
flowchart TD
  DHT["DHT11"] --> MCU["ESP8266: Sınırlı toplama"]
  OPT["MAX30102"] --> MCU
  PIR["HC-SR501"] --> MCU
  MIC["MAX9814"] --> MCU
  MCU --> VALID["Geçerlilik ve ölçüm zamanı"]
  VALID --> STATE["Güncel, eksik, geçersiz veya eski"]
  STATE --> OUT["Durum gösterimi; canlı bulut gönderimi kapalı"]
```
