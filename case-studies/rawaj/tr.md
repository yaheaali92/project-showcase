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

Bu yapı; kullanım deneyimini, iş mantığını, verileri ve gerçek zamanlı iletişimi ayırır. Mevcut temel, hesap profili yönetimini, erişim denetimini ve yönetici işlem kaydını kapsar. Sipariş, iade, uyuşmazlık ve hesaplaşma akışları aşamalı olarak geliştiriliyor.

## Güncel aşama

Rawaj geliştirme aşamasındadır ve ticari işletime açılmamıştır. Sonraki çalışmalar, pazar yeri akışlarını tamamlayıp tutarlı bir arayüze bağlamaya; satıcı, alıcı ve yönetici sorumluluklarını anlaşılır tutmaya odaklanıyor.

## Kısa bakış

- **Problem:** Pazarın taraflarını sipariş durumu ve satış sonrası süreçlerle ilişkilendirmek.
- **Hedef kitle:** Satıcılar, alıcılar ve pazar yeri yöneticileri.
- **Katkım:** Uygulama tasarımı, arayüz, arka uç hizmetleri ve veri modeli.
- **Teknolojiler ve yöntem:** Flutter, Dart, TypeScript, Node.js, Express, PostgreSQL, Redis, Socket.IO
- **İncelenebilenler:** Hesap profili, erişim denetimi ve yönetici işlem kaydı temelleri; sipariş, iade, uyuşmazlık ve hesaplaşma akışları geliştirme aşamasındadır.

[Sitede okumayı sürdür](https://yahyaalali.com/tr/content-library/project/rawaj/) · [Çalışma listesine dön](../../README.tr.md)
