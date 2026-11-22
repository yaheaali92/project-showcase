# Belediye yönetimi — birbirine bağlı çalışma düzeyleri

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

Faaliyetleri, projeleri, görevleri, destek taleplerini ve raporları düzenleyen; Deyrizor’dan Suriye–il–belediye yapısına genişletilen platform.

**Aşama: Geliştirme aşamasında**

![Belediye yönetimi — birbirine bağlı çalışma düzeyleri](https://yahyaalali.com/images/editorial/municipalities-hierarchy-r3.webp)

Üretilmiş kavramsal görsel; gerçek arayüz veya araştırma sonucu değildir.

## Belediye çalışmalarının düzenlenmesi

Platforma Deyrizor belediyelerinin faaliyetlerini, projelerini, görevlerini, destek taleplerini ve raporlarını düzenlemek amacıyla başladım. Her işlem ilgili belediyeyle ilişkilendirilir. Böylece çalışanlar, ayrı dosya ve işlemler arasında arama yapmak yerine sorumluluğu ve ilerlemeyi aynı bağlamda takip edebilir.

İlk aşamada Flutter arayüzünü ve veri modelini geliştirdim; arka uç entegrasyonunda PocketBase ve JavaScript kullandım. O aşama yukarıda açıklanan belediye iş akışlarını kapsıyordu. Platform geliştikçe yetki ve veri kapsamları gözden geçiriliyor.

## Geliştirilen daha geniş yapı

Platform, Suriye’den illere ve bu illere bağlı belediyelere uzanan bir hiyerarşi için geliştiriliyor. Her düzey, kendisine uygun çalışmaları ve yetkileri gösteriyor; kayıtlar ilgili il ve belediyeyle bağlantılı tutuluyor. Bu çalışma yalnızca bir listeye il adları eklemek değil, ilişkileri ve sorumlulukları yeniden düzenlemek anlamına geliyor.

Bu, güncel geliştirme yönüdür; ülke genelinde tamamlanmış bir işletim veya kapsamlı resmî onay iddiası değildir. Platform [Ashara portalından](https://yahyaalali.com/tr/content-library/project/ashara/) bağımsızdır: Ashara şehir bilgilerini ve hizmetleri sunarken bu platform belediyelerin idari çalışmalarını düzenler.

## Gösterim durumu

Önceki önizleme, geliştirme ve genişleme sırasında geçici olarak durdurulmuştur. Eşlik eden şema hedeflenen çalışma yapısını açıklar; canlı bir kamu paneli veya gerçek işletim verisi değildir.

## Kısa bakış

- **Problem:** Belediye süreçlerini ilgili belediye ve yetki kapsamıyla ilişkilendirmek.
- **Hedef kitle:** Belediye işlemlerini, projelerini ve görevlerini yöneten çalışanlar.
- **Katkım:** Yönetim arayüzü, veri modeli ve arka uç entegrasyonu.
- **Teknolojiler ve yöntem:** Flutter / Dart, C# / .NET 10 ve PostgreSQL. PocketBase / JavaScript geçmiş uygulama ve aşamalı geçiş kapsamındadır.
- **İncelenebilenler:** Çok illi bir hiyerarşiye doğru genişletilen mevcut belediye çalışma uygulaması.

## İdari kapsam ve teknik geçiş

Platformu; iller, belediyeler ve birimleri proje, faaliyet, görev, kanıt incelemesi ve raporlama sorumluluklarıyla bağlamak için geliştirdim. Doğrulanan uygulama arayüzü Arapçadır. Yalıtılmış Flutter bileşenleri ve kaynağa dayalı çizimler sentetik veri kullanır. Hizmetlerde C#/.NET 10 modüler monoliti ve PostgreSQL kullanılır; geçiş sırasında eski PocketBase yolu korunur. Gösterimler seçili akışları kapsar; geçişin tamamlandığı, kamu onayı ve belediyeler genelinde üretim kullanımı doğrulanmamıştır.

[Sitede okumayı sürdür](https://yahyaalali.com/tr/works/deir-ezzor-municipalities/) · [Çalışma listesine dön](../../README.tr.md)
