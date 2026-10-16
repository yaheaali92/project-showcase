#pragma once
#include <cstdint>
#include "Wire.h"
extern bool fake_optical_present;
extern unsigned fake_fifo;
extern unsigned optical_check_calls,algorithm_calls;
class MAX30105 {
 public:
 bool begin(WireMock&,int){return fake_optical_present;}
 void setup(){}void setPulseAmplitudeRed(int){}void setPulseAmplitudeIR(int){}
 void check(){optical_check_calls++;}bool available(){return fake_fifo>0;}
 uint32_t getRed(){return 1000;}uint32_t getIR(){return 2000;}
 void nextSample(){if(fake_fifo)fake_fifo--;}
};
