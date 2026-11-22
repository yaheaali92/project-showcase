# Rawaj — dijital pazar yeri mühendisliği

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

Satıcıyı, alıcıyı ve platform yönetimini buluşturan; arayüz, iş hizmetleri ve veri sorumluluklarını ayıran çok rollü pazar yeri projesi.

**Aşama: Geliştirme aşamasında**

![Rawaj — dijital pazar yeri mühendisliği](https://yahyaalali.com/images/editorial/rawaj-journey-r3.webp)

Üretilmiş kavramsal görsel; gerçek arayüz veya araştırma sonucu değildir.

## Pazarın taraflarını buluşturmak

Rawaj’ı 2026’da satıcılar, alıcılar ve platform yönetimi için dijital bir pazar yeri olarak geliştirmeye başladım. Proje, ürün listelemekle sınırlı değildir; siparişin taraflar arasındaki akışını, satış sonrasındaki iadeleri, uyuşmazlıkları ve hesaplaşmayı da ele alır.

Uygulama tasarımını, arayüzünü, arka uç hizmetlerini ve veri modelini geliştiriyorum. Çalışmayı yönlendiren soru şudur: her işlem kullanıcı için nasıl anlaşılır kalır ve siparişin durumuyla hesap yetkilerine nasıl uyum sağlar?

Ürünlerin sunulması satıcıyla alıcıyı buluşturur; sipariş ise iki tarafın ve platform yönetiminin farklı sorumluluklar taşıdığı bir süreç başlatır. Kapsam, ilgili yetkiler çerçevesinde sipariş durumunu, iade taleplerini, uyuşmazlıkları ve hesaplaşmayı ele alır. Bu akışlar aşamalı biçimde geliştirilip uygulamaya bağlanıyor; açıklanmaları ticari yayının tamamlandığı anlamına gelmiyor.

## Ayrı mühendislik sorumlulukları

| Katman | Teknoloji ve amaç |
| --- | --- |
| Uygulama arayüzü | Flutter ve Dart |
| Uygulama hizmetleri | TypeScript, Node.js ve Express |
| Kalıcı veriler | PostgreSQL |
| Önbellek | Redis |
| Gerçek zamanlı iletişim | Socket.IO |

Bu mimari, kullanım deneyimini, iş mantığını, verileri ve gerçek zamanlı iletişimi birbirinden ayırır. Kod tabanında hesap ve yetki yönetimi, yönetici işlem kaydı, ürün ilanlarının yayımlanması ve incelenmesi, sepet ve sipariş akışları ile iade, uyuşmazlık ve satıcıya ödenecek tutarların muhasebeleştirilmesine yönelik bileşenler bulunur. Bu akışların entegrasyon ve doğrulama düzeyleri farklıdır; kaynak kodda yer almaları, ticari sürecin uçtan uca kabul edildiği anlamına gelmez.

Flutter arayüzü, hesap yetkileri ile sipariş, ödeme ve iade durumlarına göre işlemleri gösterirken arka uç hizmetleri yetkilendirme kontrollerini yapar ve durum geçişlerini doğrular. Bu projede hesaplaşma, satıcıya ödenecek tutarların muhasebe kayıtlarına alınması, siparişlerle ve muhasebe hareketleriyle ilişkilendirilmesi anlamına gelir; bu tutarların fiilen ödenmesi ise ayrı bir aşamadır.

## Güncel aşama

Rawaj geliştirme aşamasındadır ve ticari işletime açılmamıştır. Daha önceki ayrı yerel test turlarında, arka uca ve veritabanına bağlı arayüzler üzerinden sentetik veriler kullanılarak ürün ilanlarının yayımlanması ve incelenmesi ile sepet akışları belgelendi.

26 Ekim 2026’da belgelenen kontroller, arka uca ve veritabanına bağlı Flutter arayüzleri üzerinden web ve Android emülatöründe, sentetik verilerle oturum açmayı, alıcı siparişlerini ve finansal verileri görüntülemeyi kapsadı. Bu turda kabul edilen finansal işlemler yalnızca okumayla sınırlıydı.

Sipariş ve satış sonrası sürecin taraflar arasındaki iade ve uyuşmazlık akışlarını da kapsayan uçtan uca kabulü, onaylı bir sağlayıcı üzerinden tahsilat, para iadesi ve satıcıya ödeme işlemlerinin doğrulanması ve ticari işletime geçiş henüz tamamlanmadı.

## Kısa bakış

- **Problem:** Pazarın taraflarını sipariş durumu ve satış sonrası süreçlerle ilişkilendirmek.
- **Hedef kitle:** Satıcılar, alıcılar ve pazar yeri yöneticileri.
- **Katkım:** Uygulama tasarımı, arayüz, arka uç hizmetleri ve veri modeli.
- **Teknolojiler ve yöntem:** Flutter, Dart, TypeScript, Node.js, Express, PostgreSQL, Redis, Socket.IO
- **İncelenebilenler:** Mimarinin, gerçekleştirilen işlevlerin ve belgelenmiş yerel doğrulama turlarının sınırlarıyla birlikte özeti. Kamuya açık olmayan kaynak kodu ve iç kabul kayıtları bu vaka çalışmasına eklenmemiştir.

## Sipariş sınırları ve doğrulama

Alıcı, satıcı ve moderasyon akışlarını tasarlayıp geliştirdim. Flutter/Dart arayüzü, Express/TypeScript erişim denetimli hizmetleri, PostgreSQL ise işlemsel kayıtları yürütür. Sipariş durumu işlem, lojistik, ödeme ve iade boyutlarına ayrılır. İade, bağlı bir uyuşmazlık açabilir; satıcıya ait muhasebe alacağı kayda alınır ve beklemeye alınabilir. Seçilmiş akışlar yerel web, Android emülatörü ve Windows üzerinde ayrı ayrı sentetik verilerle doğrulandı. Canlı tahsilat, geri ödeme, sağlayıcı mutabakatı ve para aktarımı doğrulanmış kapsamın dışındadır.

[Sitede okumayı sürdür](https://yahyaalali.com/tr/works/rawaj/) · [Çalışma listesine dön](../../README.tr.md)
