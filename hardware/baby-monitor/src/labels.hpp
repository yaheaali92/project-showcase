#pragma once
#include "monitor_core.hpp"
namespace baby_monitor {
enum class Language { Arabic, English, Turkish };
inline const char* state_label(State state, Language language) {
  static const char* const labels[3][4] = {
    {"لا توجد قراءة", "قراءة حديثة", "قراءة غير صالحة", "قراءة قديمة"},
    {"No reading", "Fresh reading", "Invalid reading", "Stale reading"},
    {"Okuma yok", "Güncel okuma", "Geçersiz okuma", "Eski okuma"}
  };
  return labels[static_cast<unsigned>(language)][static_cast<unsigned>(state)];
}
inline const char* signal_label(Signal signal, Language language) {
  static const char* const labels[3][signal_count] = {
    {"حرارة البيئة", "رطوبة البيئة", "تقدير النبض البصري", "تقدير التشبع البصري", "الحركة", "عينة الصوت الخام"},
    {"Ambient temperature", "Ambient humidity", "Optical pulse estimate", "Optical saturation estimate", "Motion", "Raw audio sample"},
    {"Ortam sıcaklığı", "Ortam nemi", "Optik nabız tahmini", "Optik doygunluk tahmini", "Hareket", "Ham ses örneği"}
  };
  return labels[static_cast<unsigned>(language)][static_cast<unsigned>(signal)];
}
}
