# gem5 ders çalışması: iki bellek profilinin kaynak zinciri denetimi

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md) · [Portföy](https://yahyaalali.com/tr/)

Çalışma bilgisayar mimarisi dersi kapsamında başladı. Ekim 2026'da Dhrystone, Google'dan esinlenen yük, matris çarpımı, PageRank, STREAM benzeri yük, küçük bir CNN ve vektör toplama için mevcut dosyaları inceledim. Her yükün C kaynağı, yürütülebilir dosyası ve baseline/PIM etiketli tarihsel gem5 istatistik çifti vardır. Dosya özetleri özel kayıtta tutulur; kaynak kodu, yürütülebilir dosyalar ve ham istatistikler burada yayımlanmaz.

## Kanıt sınırları

Çalıştırma komutları, kesin gem5 sürümü, yapılandırmalar, çıkış kodları ve eşleşen işlevsel çıktılar bulunmadı. Dosyaların varlığı, yürütülebilir dosyanın mevcut kaynaktan üretildiğini veya iki tarafta da kullanıldığını kanıtlamaz. Eski rapordaki matris boyutu mevcut kaynaktan farklıdır; toplu CSV'nin IPC/CPI değerleri eşleşen istatistiklere uymaz. Tarihsel CSV çıkarıcısı belirtilen kapsamda bulunamadı; uyuşmazlığın nedeni bilinmiyor.

Eski rapor farklı bellek profilleri tarif eder, fakat incelenen materyal bellek içinde hesaplama birimini veya işlem aktarımını doğrulamaz. PIM etiketi belirli bir uygulamanın kanıtı değildir. STREAM benzeri uygulamanın zamanlayıcısı gerçek süre değil, yapay sayaçtır.

## Denetim sonucu

Yeni bağımsız denetleyici 14 istatistik dosyasını okudu ve dokuz odaklı testi geçti. Aynı iş, eşleşen çıktılar ve başarılı çıkışlar kanıtlanmadığı için hiçbir çift performans oranına uygun değildir. Simülasyon 2026'da yeniden çalıştırılmadı; sistem enerjisi belgelenmiş bir modelle ölçülmedi. Bu çalışma hakemli makale veya mimari üstünlük iddiası değil, ders çalışması ve kaynak zinciri denetimidir.

Yeni deney için gem5 sürümü, iki tarafın yapılandırma ve komutları, program/girdi özetleri ve karşılaştırma öncesinde eşleşen işlevsel çıktılar gerekir.
