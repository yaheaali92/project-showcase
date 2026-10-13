# Akıllı çöp kutusu — ölçümden güvenilir uyarıya

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

Ölçümü karardan ayırmak, sensör hatalarını ele almak ve uyarı ile üç dilli gösterimi düzenlemek için iyileştirilen ESP32 ve BLE tabanlı akademik prototip.

Yazılım iyileştirmesi test edildi; donanım test edilmedi

![Akıllı çöp kutusu prototipinde mesafe algılama, OLED ve göstergelerle ESP32 ve BLE bağlantısının işlevsel çizimi](../../assets/editorial/smart-bin-r3.webp)

Kodla hazırlanmış işlevsel tasvir; monte edilmiş cihaz fotoğrafı veya deney sonucu değildir.

## Fikir ve bağlam

Bir kutu, gerçek doluluğu geçersiz sensör okumasından nasıl ayırır? Bu prototip mesafe ölçümü, küçük ekran, dört LED ve sesli uyarıyı; Bluetooth Low Energy üzerinden okunabilen durumla birleştirir. Sahada kullanılan atık toplama hizmeti veya bulut platformu değildir.

## Özgün çalışma ve güncel iyileştirme

Özgün akademik sketch mesafeyi ölçüyor, OLED üzerinde gösteriyor, dört gösterge ile alarmı çalıştırıyor ve dolulukta BLE bildirimi gönderiyordu. Kaynak açıklamasında adım yer alır; ESP32 ve Adafruit kütüphaneleri kendi yazarlarına aittir. Bu açıklama tek başına rapor ve donanımdaki tüm katkıları kanıtlamaz.

Ekim 2026 tarihli sınırlı iyileştirmeyi; ölçüm, doğrulama ve sınıflandırmayı ekran ve bağlantı yönetiminden ayırmak için yönlendirdim. Amaç ve BLE kimlikleri korundu. Değişiklikler sonraki bir aşamadır; eski akademik teslim tarihine ait değildir.

## Okumadan karara

Sensör darbesi için açık 30 ms süre sınırı vardır. Geçersiz okuma hata olur; boş veya dolu sayılmaz. Hata süzgeci sıfırlar ve eski mesafeyi gizler. Geçerli okuma üç örnekli medyan ve ayarlanabilir histerezisle değerlendirilerek sınır yakınındaki geçişler azaltılır.

Özgün 10/20/35/50 cm sınırları, 0,5 cm payla geçici varsayılan olarak korunur. Bunlar mevcut kutu veya sensör için ölçülmüş kalibrasyon değildir; uygun ayarlar fiziksel ölçümle belirlenmelidir.

| Açıklayıcı girdi        | Karar                     | Gösterim ve uyarı                                        |
| ----------------------- | ------------------------- | -------------------------------------------------------- |
| İlk geçerli okuma: 5 cm | Geçici ayarlara göre dolu | Dört LED ve sesli uyarı; bağlı istemciye tek olay        |
| Sensör zaman aşımı      | Sensör hatası, dolu değil | Eski mesafe veya dolu alarmı yok; BLE READ hata bildirir |

Bunlar yapay yazılım testi girdileridir, cihaz ölçümleri değildir.

## Bağlantı ve gösterim

Bağlanma, kopma ve yeniden ilan doluluktan bağımsızdır. Dolu olayı duruma girişte veya bağlantıda, asgari zaman aralığıyla gönderilir; her döngüde tekrarlanmaz. Eski dolu iletisi sabit uyumluluk değeri olarak kalır. Diğer durumlar yeni dolu alarmı üretmeden okunabilir.

WRITE yeni kontrol komutu eklemez. Boş veya fazla uzun girdi reddedilir; özgün işlemsiz komut dâhil bilinmeyen girdi işlem yapmaz veya READ değerini değiştirmez. Ekran metinleri ve belgeler Arapça, İngilizce ve Türkçedir. Dil bir derleme ayarıdır, yeni telefon uygulaması değildir. Arapça etiketler harflerin birleşimini koruyacak şekilde tam olarak rasterleştirilir.

## Doğrulama ve kalan sınırlar

Sınırlar, geçersiz okumalar, süzgeç, zamanlama, bildirimler, BLE bağlantı değişiklikleri, ekran hatası ve girdiler için 44 yerel C++ senaryosu geçti. Yerel bildirim tanımlarıyla üç dilde bağdaştırıcı sözdizimi kontrolü geçti; bunlar gerçek ESP32 derlemeleri değildir.

Mevcut ESP32 araç zinciri bulunmadı ve genel sistem araçları kurulmadı. Firmware derlemesi, kart ve sensörün belirlenmesi, bağlantı kontrolü ve fiziksel testler bekliyor. Ölçülmüş doğruluk, enerji, gecikme veya saha kabulü iddiası yoktur. Görseller monte edilmiş cihaz fotoğrafı veya bağlantı planı değildir.

Kaynak, geçmiş ve ayrıntılı testler özeldir. Genel bağlantı yalnız vaka çalışmasını ve seçilmiş güvenli sonuçları sunar.

## Veri ve durum akışı — işlevsel şema

![Veri ve durum akışı — işlevsel şema](../../assets/editorial/smart-bin-flow-tr.svg)

[Sitede okumayı sürdür](https://yahyaalali.com/tr/content-library/project/smart-bin/) · [Çalışmalara dön](../../README.tr.md)
