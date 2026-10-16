#ifndef YAHYA_SMART_BIN_I18N_H
#define YAHYA_SMART_BIN_I18N_H
#include "bin_core.h"
namespace smartbin {
enum class Language { Arabic = 0, English = 1, Turkish = 2 };
inline const char* stateLabel(Language language, State state) {
  static const char* const labels[3][8] = {
    {"بانتظار القياس", "فارغ", "امتلاء منخفض", "امتلاء متوسط", "قارب الامتلاء", "ممتلئ", "خطأ الحساس", "خطأ الإعداد"},
    {"Awaiting reading", "Empty", "Low fill", "Medium fill", "Nearly full", "Full", "Sensor error", "Config error"},
    {"Ölçüm bekleniyor", "Boş", "Az dolu", "Orta dolu", "Dolmaya yakın", "Dolu", "Sensör hatası", "Ayar hatası"}
  };
  const unsigned l = static_cast<unsigned>(language), s = static_cast<unsigned>(state);
  return labels[l < 3 ? l : 1][s < 8 ? s : 0];
}
inline const char* displayFailureLabel(Language language) {
  static const char* const labels[] = {
    "تعذر بدء الشاشة؛ يبقى القياس والاتصال نشطين",
    "Display initialization failed; sensing and BLE remain active",
    "Ekran başlatılamadı; ölçüm ve BLE çalışmaya devam eder"
  };
  const unsigned l = static_cast<unsigned>(language);
  return labels[l < 3 ? l : 1];
}
inline const char* writeResultLabel(Language language, WriteResult result) {
  static const char* const labels[3][3] = {
    {"مدخل فارغ مرفوض", "مدخل يتجاوز الحد", "أمر غير مدعوم دون تنفيذ"},
    {"Empty write rejected", "Write exceeds limit", "Unsupported command; no action"},
    {"Boş yazma reddedildi", "Yazma sınırı aşıldı", "Desteklenmeyen komut; işlem yok"}
  };
  const unsigned l = static_cast<unsigned>(language);
  return labels[l < 3 ? l : 1][static_cast<unsigned>(result)];
}
}
#endif
