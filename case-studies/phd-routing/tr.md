# SDN–MPLS ağlarında akıllı yönlendirme ve hizmet kalitesi

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

Değişen ağ yüküne ve bağlantı arızalarına yanıt veren yönlendirme kararlarını, SDN–MPLS ağlarında hizmet kalitesi açısından değerlendiren doktora araştırması.

**Aşama: Devam eden araştırma**

![SDN–MPLS ağlarında akıllı yönlendirme ve hizmet kalitesi](https://yahyaalali.com/images/editorial/routing-paths-r3.webp)

Üretilmiş kavramsal görsel; gerçek arayüz veya araştırma sonucu değildir.

## Araştırdığım problem

Ağ yükü değiştiğinde veya bir bağlantı arızalandığında, kısa süre önce uygun olan yol artık en iyi seçenek olmayabilir. Araştırmam, çok protokollü etiket anahtarlama (MPLS) kullanan yazılım tanımlı ağlarda yönlendirme kararlarının bu değişikliklere nasıl yanıt verebileceğini ve hizmet kalitesine etkisinin nasıl değerlendirilebileceğini ele alıyor.

İstanbul Üniversitesi-Cerrahpaşa’da bilgisayar mühendisliği doktora eğitimime Eylül 2024’te başladım. Çalışmam; ağdan yapılan gözlemleri, mevcut durumun temsilini ve veri trafiği için yol seçimini birbirine bağlıyor.

## Ağ ölçümünden yol kararına

Ağ ölçümlerini, yönlendirme kararını ve programlanabilir iletimi birleştiren bir deney ortamı kuruyorum. Yük ve bağlantı durumu bilgileri, karar mekanizmasının kullanabileceği bir temsile dönüştürülüyor. PPO, yönlendirme kararını veren bileşendir; kararlarının etkisinden öğrenen bir pekiştirmeli öğrenme yöntemidir. LSTM tabanlı trafik tahmini ise karara yardımcı bilgi sağlayan bir bileşen olarak inceleniyor, yönlendirme bileşeninin yerini almıyor.

Kontrol talimatları, iletim cihazlarında seçilen yolu uygular. Kullanıcı paketleri ağın veri yollarından geçmeye devam eder; akıllı bir denetleyici kullanılması her paketin öğrenme programından geçtiği anlamına gelmez.

## Kararın değerlendirilmesi

Kontrollü yoğunluk ve bağlantı arızası senaryolarında yönlendirme davranışını karşılaştırıyorum. Gecikme, gecikmedeki değişim, paket kaybı, aktarım hızı, bağlantı kullanımı ve toparlanma süresi ölçülüyor. Hizmet kalitesi gereksinimleri, bu ölçümleri veri trafiğinin ihtiyaçlarıyla ilişkilendirmeyi sağlıyor; yalnızca kısa bir yol seçmek yeterli kabul edilmiyor.

Ağ ortamını, ölçüm ile karar arasındaki entegrasyonu ve değerlendirme yöntemini geliştiriyorum. Araştırma sürüyor. Sonraki adım, belirli senaryolar için karşılaştırmaları ve istatistiksel doğrulamayı tamamlayıp sonuçları buna göre sunmak.

Kontrol ile veri iletimi arasındaki fark için [yazılım tanımlı ağlara giriş](https://yahyaalali.com/tr/content-library/article/software-defined-networking-sdn/) yazısını okuyabilirsiniz.

## Kısa bakış

- **Problem:** Ağ durumuna ve hizmet kalitesi gereksinimlerine uyum sağlayan yönlendirme kararlarını incelemek.
- **Hedef kitle:** Ağ ve sistem araştırmacıları ile mühendisleri.
- **Katkım:** Eylül 2024’ten beri bilgisayar mühendisliği doktora öğrencisi olarak araştırmayı yürütmek.
- **Teknolojiler ve yöntem:** SDN, MPLS
- **İncelenebilenler:** Devam eden doktora konusu ve hizmet kalitesi değerlendirme soruları; yayımlanmış nicel sonuç sunulmaz.

[Sitede okumayı sürdür](https://yahyaalali.com/tr/content-library/project/phd-routing/) · [Çalışma listesine dön](../../README.tr.md)
