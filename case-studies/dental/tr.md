# Sinad — hekim çalışma alanı ve hasta randevuları

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

Hekimin çalışma alanını hasta randevu süreciyle bağlayan, Flutter ve Firebase ile geliştirilen ve ayrı bir test ortamında sunulan uygulama.

**Aşama: Deneme önizlemesi**

![Sinad — hekim çalışma alanı ve hasta randevuları](https://yahyaalali.com/images/editorial/sinad-workflow-r3.webp)

Üretilmiş kavramsal görsel; gerçek arayüz veya araştırma sonucu değildir.

## Randevuyu çalışma düzenine bağlamak

Sinad’ı hekimin çalışma takvimiyle hastanın randevu sürecini bir araya getirmek için geliştiriyorum. Arayüz, rolleri ayırır: hekim kendi çalışma alanında takvimini düzenlerken hasta ilgili randevu akışına ulaşır.

Arayüzde Flutter ve Dart, kimlik, veri ve arka uç hizmetlerinde Firebase kullanılıyor. Bir randevunun bağımsız bir form olarak kalmaması için arayüz işlemlerini veri durumu ve yetkilerle ilişkilendiriyorum.

Çalışma alanı hekime aittir; merkez veya klinik, hekimin programına eklediği bir iş yeridir. Aynı merkezde çalışan iki hekimin bağımsız alanları vardır; aynı yeri kullanmaları hasta kayıtlarını kendiliğinden paylaşmaz. Hastanın randevu süreci hekimi, hizmeti, iş yerini ve uygun zamanı birbirine bağlar. Bu süreçlerin geliştirilmesi ve önizleme ortamındaki testleri, operasyonel yayından önce sürüyor.

## Önizlemede neler görülebilir?

[Sinad test ortamında](https://test.sinaddental.com/) giriş arayüzü ve test hesaplarına sunulan işlevler incelenebilir. Bu ortam gerçek hasta verileriyle klinik kullanım değildir; operasyonel yayın, proje önizlemesinden ayrı bir aşamadır.

## Kısa bakış

- **Problem:** Hekim takvimiyle anlaşılır bir hasta randevu akışını ilişkilendirmek.
- **Hedef kitle:** Farklı rollere ve çalışma alanlarına sahip hekimler ve hastalar.
- **Katkım:** Uygulama arayüzü; kimlik, veri ve randevu hizmetlerinin entegrasyonu.
- **Teknolojiler ve yöntem:** Flutter, Dart, Firebase
- **İncelenebilenler:** Açıkça test olarak belirtilen alan adında erişilebilen ayrı web arayüzü.

[Sitede okumayı sürdür](https://yahyaalali.com/tr/content-library/project/dental/) · [Test ortamı girişini aç](https://test.sinaddental.com/) · [Çalışma listesine dön](../../README.tr.md)
