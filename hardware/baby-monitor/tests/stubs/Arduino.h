#pragma once
#include <cstdint>
#include <sstream>
constexpr int D1=1,D2=2,D3=3,D4=4,D6=6,D7=7,A0=10,INPUT=0;
extern uint32_t fake_now;
extern int fake_motion,fake_adc,cooperative_yields;
inline uint32_t millis(){return fake_now;}
inline int digitalRead(int){return fake_motion;}
inline int analogRead(int){return fake_adc;}
inline void pinMode(int,int){}
inline void yield(){cooperative_yields++;}
struct SerialMock {
  std::ostringstream output;
  void begin(int){}
  template<class T>void print(T value){output<<value;}
  void println(){output<<'\n';}
  template<class T>void println(T value){output<<value<<'\n';}
};
extern SerialMock Serial;
