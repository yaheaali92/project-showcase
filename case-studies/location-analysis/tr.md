# Sosyal Medya Lokasyon Analizi — tez ve sonraki yazılım yenilemesi

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

Ana çalışma, 2024'te tamamlanan yüksek lisans tezidir. 2026'da başlayan yerel yazılım yenilemesi ayrı bir mühendislik çalışmasıdır.

**Tez: 2024'te tamamlandı. Yazılım yenilemesi: geliştiriliyor.**

![Gerçek harita veya araştırma sonucu olmayan, üretilmiş kavramsal tez kapağı](https://yahyaalali.com/images/editorial/location-analysis-r6.webp)

Üretilmiş kavramsal görsel; gerçek arayüz veya araştırma sonucu değildir.

## Kanıt zinciri ve yayın bilgileri

2021–2022 öğretim dönemindeki Bilgisayar Mühendisliği bitirme çalışması Yahya ALALI ve Muhammed Ayham Galavinci tarafından ortak hazırlandı; kaynak bireysel görevleri ayırmıyor. Bireysel “Sosyal Medya Lokasyon Analizi” yüksek lisans tezi [Sakarya Üniversitesinde 5 Temmuz 2024'te kabul edildi](https://acikerisim.sakarya.edu.tr/xmlui/handle/20.500.12619/102984). Yerel PDF'deki 24 Haziran tarihli eksik jüri şablonu, resmî son kayıt yerine kullanılmıyor.

Yahya ALALI ve Nilüfer YURTAY imzalı türev tam metin, [IMASCON 2024 Spring bildiri kitabında](https://www.imascon.com/kayit/kayittr/dosyalar/imascon_2024_spring/imascon_2024_spring_fen_tammetin_bildiriler.pdf) 43–50. sayfalarda yer alır; ISBN 978-605-72746-5-6. Dergi makalesi değildir ve DOI doğrulanmadı. 2026 yenilemesi tez baskısı veya bildirinin deney sonucu değildir.

## 2024'teki tarihsel iş akışı

Uygulama, hedef hesap gönderilerini Instaloader ile alıp uygulama verilerini Firebase'de tutuyordu. Önce gönderi konum etiketi kullanıldı; etiket yoksa Google Cloud Vision ile görüntüdeki yer işaretleri arandı; ipuçları yetersizse OpenCV/TensorFlow görüntü işleme denendi. Coğrafi kodlama yer adlarını çözdü; ülke/şehir tekrar sayıları ve oranları rapor ile haritada gösterildi. Tez uygulamayı ve örnek çalışmaları belgeliyor, ancak yeniden sınanabilir etiketli karşılaştırma kümesi veya doğruluk ölçümü sağlamıyor. Başkalarının hesaplarını hedeflemek gizlilik ve platform koşulları bakımından sorunludur; güncel öneri değildir.

## Ayrı 2026 yazılım sorusu

Kullanıcının analizine izin verdiği veri dışa aktarımları, dağınık konum ve zaman bilgileri içerebilir. Bu projeyi; noktaların nerede toplandığını, zaman içinde nasıl dağıldığını ve veri kümelerinin nasıl farklılaştığını düzenli biçimde incelemek için geliştiriyorum. Yerel işlem, girdilerin mahremiyetini dikkate alan tasarımın bir parçasıdır.

## Noktalardan ölçümlere

Çalışma kapsamında DBSCAN ile mekânsal kümeleme, yayılımı incelemek için dönme yarıçapı, çeşitlilik için Shannon entropisi ve zaman analizi yer alıyor. Jaccard benzerliği, Bray–Curtis farklılığı ve merkezler arası uzaklık, veri kümelerini farklı açılardan karşılaştırıyor; bunlar kendiliğinden tek bir sonuca dönüşmüyor.

Yapay bir örnek, iki konum çevresinde toplanan noktaları ve iki dönem arasındaki dağılım değişimini gösterebilir. Böyle bir çizim analiz yöntemini açıklar; gerçek bir kişinin hareket kaydı veya ölçülmemiş bir doğruluk sonucu değildir.

## Katkım ve test sınırı

Analiz araçlarını ve çıktıların yorumlanmasını sağlayan arayüzleri geliştiriyorum. 2026 yazılım yenilemesi [2024 yüksek lisans tezinden](https://yahyaalali.com/tr/content-library/publication/masters-thesis/) ayrıdır. Yalıtılmış kopyada 402 Python testi geçti ve dört isteğe bağlı bağımlılık testi atlandı; masaüstü pencere testleri takıldığından tam kapı kapanmadı. Paket olduğu gibi yayımlanmadı: tarihsel `legacy` ve oturum açma yolları, desteklenmeyen iddialar, teknik belgeler ve isteğe bağlı rapor bağımlılığı tanımı düzenleme gerektiriyor. Kişisel dışa aktarımlar, oturumlar ve benzerlik raporu özeldir; yerel işleme tek başına bütün hukuki yükümlülükleri kaldırmaz.

## Kısa bakış

- **Problem:** Kullanıcının izin verdiği dışa aktarımların mekânsal ve zamansal analizi.
- **Hedef kitle:** Kullanma yetkisine sahip oldukları mekânsal verileri inceleyen kullanıcılar.
- **Katkım:** Mekânsal ve zamansal analiz araçlarının geliştirilmesi.
- **Teknolojiler ve yöntem:** DBSCAN; dönme yarıçapı; Shannon entropisi; Jaccard; Bray–Curtis; merkez mesafesi.
- **Mühendislik kararı:** Yetkili veri dışa aktarımlarıyla mahremiyeti gözeten, yerel işlemeyi önceleyen bir yön.
- **İncelenebilenler:** Resmî tez kaydı, bildiri kitabı ve 2026 yenilemesinin sınırlı teknik açıklaması; henüz genel çalıştırılabilir paket veya kişi konumu verisi yok.

[Sitede okumayı sürdür](https://yahyaalali.com/tr/content-library/project/location-analysis/) · [Çalışma listesine dön](../../README.tr.md)
