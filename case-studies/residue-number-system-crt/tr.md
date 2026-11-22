# Kalıntı Sayı Sistemi ve Çin Kalan Teoremi

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

**Yerelde test edilmiş eğitim uygulaması**

## Tasarım ve uygulama

Uygulama negatif olmayan bir tamsayıyı, birden büyük ve ikişer ikişer aralarında asal farklı modüllerin boş olmayan listesindeki kalıntılarla kodlar. Toplama, çıkarma ve çarpma kanal bazında yürütülür. Çin Kalan Teoremi modüler terslerle kalıntıları birleştirir ve sıfır ile modüllerin çarpımı arasındaki tek kanonik temsilciyi döndürür; üst sınır dahil değildir. 3, 5 ve 7 modülleri 105 değer verir. Modüler bölme için pozitif bölenin her kanalda tersi olmalıdır. Geçersiz kalıntılar ve desteklenmeyen modüller reddedilir.

## Doğrulama, sınırlar ve erişim

Girdi alanını tanımladım, aritmetik çekirdeği arayüzden ayırdım, referans uygulamayı ve doğruluk kontrollerini oluşturdum. İlk ders projesi ortaktı; belgelenmeyen görev dağılımını atfetmedim. Yerel testler 105 temsilcinin kodlanması ve geri kurulmasını, toplama, çıkarma ve çarpmanın her biri için 11.025 sıralı çifti ve geçersiz girdileri kapsadı. Ayrı bir işaretsiz ikili bölücü, bir ila sekiz bit genişlikte 86.870 durumda divmod ile karşılaştırıldı. Bu kontroller genel performans veya donanım sonucu göstermez. Vaka çalışması açıktır; kaynak kodu özeldir.

[Yayımlanan vaka çalışması](https://yahyaalali.com/tr/works/residue-number-system-crt/) · [Dizine dön](../../README.tr.md)
