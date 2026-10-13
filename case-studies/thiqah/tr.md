# THIQAH — işletmeler arası ticari ilişkileri belgelemek

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

Kimlik, organizasyon ve yetkilendirme temelleri üzerine kurulan; fatura, alacak, ödeme ve uyuşmazlık kayıtlarını hedefleyen işletmeler arası ticaret ağı projesi.

**Aşama: Geliştirme aşamasında**

![THIQAH — işletmeler arası ticari ilişkileri belgelemek](https://yahyaalali.com/images/editorial/thiqah-network-r3.webp)

Üretilmiş kavramsal görsel; gerçek arayüz veya araştırma sonucu değildir.

## Ticari ilişki için ortak bir kayıt

THIQAH, işletmeler arasındaki ilişkileri belgelemek için geliştirdiğim bir projedir. Fatura, alacak, ödeme ve uyuşmazlıkların anlaşılır bir bağlamda izlenmesini hedefler. Genel bir pazar yeri veya finansal cüzdan değildir; ticari ilişkiyi oluşturan bilgileri düzenlemeye odaklanır.

## Mevcut temel

Çok dilli Flutter arayüz temelini ve uyarlanabilir ekran yapısını, arka uçtaki kimlik, organizasyon, yetkilendirme ve işlem kaydı temelleriyle birlikte geliştirdim. Bu yapı, sonraki ticari işlevler için hesap ve organizasyon sınırlarını belirler.

Fatura, alacak, ödeme ve uyuşmazlık alanları henüz tamamlanmış ticari işlevler değil, geliştirme planının parçalarıdır. Proje müşteri fonlarını tutmaz; gelecekteki ödeme entegrasyonu uygun ve ayrı bir düzenleme gerektirir.

Mevcut uygulama; çok dilli arayüzü, kimlik ve oturum temellerini, sunucu yetkileriyle korunan asgari organizasyon oluşturma, okuma ve profil güncelleme API’sini içeriyor. Davet, üyelik, şube, fatura, alacak, ödeme ve uyuşmazlık işlevleri sonraki çalışmalardır. Böylece kimlik ve organizasyon temeli, ona bağlı ticari işlemlerden açıkça ayrılıyor.

## Mühendislik öncelikleri

Tutarlı kullanım deneyimiyle finansal işlem mantığını ayrı sorumluluklar olarak ele alıyorum. Kalıcı veriler PostgreSQL ve Prisma’ya, arayüz Flutter ve Dart’a dayanır. Güncel çalışmalar, iş alanlarını genişletmeden önce kimliğin, ilişkilerin ve yetkilerin doğru kurulmasına odaklanır.

## Kısa bakış

- **Problem:** İşletmeler arasındaki ilişkilerin bilgisini ve geçmişini düzenlemek.
- **Hedef kitle:** İlişkilerini, faturalarını ve alacaklarını belgelemek isteyen işletmeler.
- **Katkım:** Arayüz, kimlik, organizasyon, yetkilendirme ve veri temellerini geliştirmek.
- **Teknolojiler ve yöntem:** Flutter, Dart, PostgreSQL, Prisma
- **İncelenebilenler:** Çok dilli arayüz temeli ile kimlik, organizasyon ve işlem kaydı hizmetleri; ticari alanlar sonraki geliştirme planındadır.

[Sitede okumayı sürdür](https://yahyaalali.com/tr/content-library/project/thiqah/) · [Çalışma listesine dön](../../README.tr.md)
