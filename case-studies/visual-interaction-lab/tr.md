# Görsel Etkileşim Laboratuvarı

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

**Yerelde doğrulanmış özel sürüm adayı**

## Tasarım ve uygulama

Windows üzerinde yüz ve el analizini tek tarayıcı arayüzünde incelemek için bu laboratuvarı geliştirdim. Görüntü, video dosyası veya kullanıcının açtığı kameradan gelen kareler yerel Python hizmetine gider. YuNet yüzleri bulur; seçilen tek yüz, ONNX Runtime üzerinden yedi sınıflı EmotiEffLib modeliyle değerlendirilir. El hareketlerini MediaPipe Gesture Recognizer işler. OK işareti ayrı bir deneysel el noktası kuralına dayanır. Arayüz bilinmeyen hareketi el algılanmamasından ayırır.

## Doğrulama, sınırlar ve erişim

Kamera kullanıcı seçimiyle açılır ve analiz aynı cihazda yürütülür. Belgelenen özel aday gerçek Windows imleç denetimini kapatır ve uygulama içi önizleme sunar. Çoklu yüz kutuları performans kontrolünü geçemedi; maske değerlendirmesi için bağımsız veri yoktur. Aday 48 Python, 18 Node ve 17 Chrome otomatik kontrolünü geçti. Önceki KDEF değerlendirmesinde 12 kişiye ait 71 görselin 67’si eşleşti. Kalibre edilmemiş görünür ifade puanları duygu, genel doğruluk, gerçek zamanlı performans veya fiziksel kamera kesintisinden sonra toparlanma kanıtı değildir. Genel sayfa laboratuvarı tanıtır; kaynak kodu, modeller, ağırlıklar ve eğitim verileri özel veya ayrı dağıtım haklarına tabidir.

[Yayımlanan vaka çalışması](https://yahyaalali.com/tr/works/visual-interaction-lab/) · [Dizine dön](../../README.tr.md)
