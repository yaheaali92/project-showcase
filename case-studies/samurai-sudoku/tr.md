# Eşzamanlı Samurai Sudoku

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

**Yerelde test edilmiş eğitim uygulaması**

## Tasarım ve uygulama

Java çözümü, örtüşen beş Sudoku ızgarasını 36’sı ortak olan 369 fiziksel hücreli tek tahta olarak modeller. Verilen değerler doğrulandıktan sonra eşzamanlı çalışanlar, farklı başlangıç hücrelerinden bağımsız durumlarla tüm tahtayı arar ve ardından en kısıtlı hücreyi seçer. Beş çalışanlı mod ızgara başına bir, on çalışanlı mod iki başlangıç noktası kullanır. İlk geçerli çözüm atomik olarak yayımlanır; kalan görevler iptal edilir ve bitmeleri beklenir. Kazanan tahta yeniden doğrulanır.

## Doğrulama, sınırlar ve erişim

Sıralı olay günlüğü, çelişen atamaları birleştirmeden seçilen tek çalışanın aramasını yeniden oynatır. İçe aktarma sıra, geçen süre, çalışan kimliği, hücre ve değer geçerliliğini denetler. Ortak ders projesinin belgelenen sürümünde örtüşme modelini, eşzamanlılık ve günlük sözleşmelerini tanımladım ve çalışma kanıtlarını inceledim. 36 yerel kabul testi bozuk, tek çözümlü, çok çözümlü ve çözümsüz girdileri, sonlandırmayı, değiştirilmiş günlüğü ve yeniden oynatmayı kapsadı. Bağımsız bir doğrulayıcı iki modu da kontrol etti. Genel sayfadaki görüntüler sentetik bir bulmacanın çalıştırılmasından alınmıştır. Kanıtlar tüm bulmacaların çözümünü veya on çalışanın daha hızlı olduğunu göstermez. Kaynak kodu özeldir.

[Yayımlanan vaka çalışması](https://yahyaalali.com/tr/works/samurai-sudoku/) · [Dizine dön](../../README.tr.md)
