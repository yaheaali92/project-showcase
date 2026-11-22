# Bellek içi işleme simülatörlerinin doğrulanması — uPIMulator ve Downmem

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

**Devam eden bağımsız araştırma**

Çalışma, uPIMulator ve Downmem üzerinde ortak bir UPMEM vektör toplama iş yükü için doğrulama protokolü geliştirir. Her simülatörün beklenen çıktıyı üretip üretmediğini ve günlüklerinde hangi işlemlerin kaydedildiğini inceler.

## Doğrulama protokolü

İş yükü, girdiler ve simülatör ayarları sabitlenir. Beklenen vektör bağımsız olarak hesaplanır, simülatör çıktısı çıkarılır ve eleman bazında karşılaştırılır. Her simülatörde üç durum incelenir: temel durum, A ve B vektörlerinin yer değiştirmesi ve her iki girdide eleman sırasının ters çevrilmesi. Böylece toplam altı çalıştırma planlanır. Ters sırada, karşılaştırmadan önce özgün eleman sırası geri yüklenir.

## Doğruluk ve performans

Çıktıların eşleşmesi yalnızca incelenen durumların doğruluğunu gösterir. Seçilen uPIMulator doğrulama okuması ve Downmem adaptörünün geri okuması farklı işlemleri kapsar. Sayaçlar veya süreler yorumlanmadan önce günlüklerin anlamı ve ölçüm sınırları incelenir.

## Kanıtlar ve sınırlar

Protokol ve seçilen yürütme yolları belgelenmiştir. Yayımlanan çalışmada altı karşılaştırma çalıştırması henüz tamamlanmamıştır ve kontrollü hata algılama deneyleri planlanmaktadır. Performans eşdeğerliği, ölçülmüş sistem enerjisi veya genel simülatör uyumu gösterilmemiştir.

[Yayımlanan çalışmayı oku](https://yahyaalali.com/tr/research/studies/gem5-pim/) · [Tarihsel gem5 ders denetimi](../gem5-pim/tr.md) · [Çalışma listesine dön](../../README.tr.md)
