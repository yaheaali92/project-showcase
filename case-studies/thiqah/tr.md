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

Mevcut çekirdek kimlik, oturum, kuruluş, üyelik, şube ve kapsam bazlı yetkilendirmeyi içerir. Davet akışının uygulanması doğrulanmamıştır. Fatura, alacak, mutabakat, itiraz ve ticari senkronizasyon tasarım aşamasındadır veya eksiktir; uçtan uca işleyişleri doğrulanmamıştır. İdari denetim kayıtları seçili yönetim işlemlerini izler; ticari muhasebe ayrı bir alandır.

## Mühendislik öncelikleri

Tutarlı kullanım deneyimiyle finansal işlem mantığını ayrı sorumluluklar olarak ele alıyorum. Kalıcı veriler PostgreSQL ve Prisma’ya, arayüz Flutter ve Dart’a dayanır. Güncel çalışmalar, iş alanlarını genişletmeden önce kimliğin, ilişkilerin ve yetkilerin doğru kurulmasına odaklanır.

## Kısa bakış

- **Problem:** İşletmeler arasındaki ilişkilerin bilgisini ve geçmişini düzenlemek.
- **Hedef kitle:** İlişkilerini, faturalarını ve alacaklarını belgelemek isteyen işletmeler.
- **Katkım:** Arayüz, kimlik, organizasyon, yetkilendirme ve veri temellerini geliştirmek.
- **Teknolojiler ve yöntem:** Flutter, Dart, PostgreSQL, Prisma
- **İncelenebilenler:** Çok dilli arayüz temeli ile kimlik, organizasyon ve işlem kaydı hizmetleri; ticari alanlar sonraki geliştirme planındadır.

## Uygulanan temel ve ticari tasarım

Ortak ticari kayıt modelini tasarladım ve mevcut temeli geliştirdim: çok dilli Flutter arayüzü ile PostgreSQL ve Prisma kullanan modüler NestJS arka ucu. Belgelenen çekirdek kimliği, oturumları, kuruluşları, üyelikleri, şubeleri ve kapsamlı yetki kontrollerini kapsar. Bazı idari işlemler denetim kaydı ve sınırlı tekrar koruması içerir. Fatura, alacak, mutabakat, itiraz ve çevrimdışı ticari eşitleme tasarım aşamasında veya eksiktir; uçtan uca işleyişleri doğrulanmamıştır. Cihazda bekleyen işlem, sunucu onayı veya karşı taraf kabulü anlamına gelmez.

[Sitede okumayı sürdür](https://yahyaalali.com/tr/works/thiqah/) · [Çalışma listesine dön](../../README.tr.md)
