#include "stubs/Arduino.h"
#include "stubs/Wire.h"
#include <iostream>
#include <stdexcept>
uint32_t fake_now=0;
int fake_motion=0,fake_adc=420,cooperative_yields=0,temperature_reads=0,humidity_reads=0;
float fake_temperature=22,fake_humidity=50;
bool fake_optical_present=false;
unsigned fake_fifo=0,optical_check_calls=0,algorithm_calls=0;
int32_t fake_pulse=77,fake_oxygen=97;
int8_t fake_pulse_valid=1,fake_oxygen_valid=1;
SerialMock Serial;WireMock Wire;
#include "../firmware/monitor/monitor.ino"
void require(bool value){if(!value)throw std::runtime_error("interaction assertion failed");}
int main(){
  try {
    setup();loop();require(temperature_reads==1&&cooperative_yields==1&&!optical_ready);std::cout<<"BM-I01 PASS\n";
    fake_now=1000;loop();require(temperature_reads==1);fake_now=2000;loop();require(temperature_reads==2);std::cout<<"BM-I02 PASS\n";
    require(monitor.read(Signal::PulseEstimate,fake_now).state==State::Invalid);require(monitor.read(Signal::AmbientTemperature,fake_now).state==State::Fresh);std::cout<<"BM-I03 PASS\n";
    fake_optical_present=true;fake_now=30000;loop();require(optical_ready);fake_fifo=100;fake_now+=10;loop();require(fake_fifo==96&&sample_count==4);std::cout<<"BM-I04 PASS\n";
    for(unsigned i=0;i<24;i++){fake_now+=10;loop();}require(algorithm_calls==1&&sample_count==0&&monitor.read(Signal::PulseEstimate,fake_now).last_good==77);std::cout<<"BM-I05 PASS\n";
    fake_pulse_valid=0;fake_fifo=100;for(unsigned i=0;i<25;i++){fake_now+=10;loop();}require(monitor.read(Signal::PulseEstimate,fake_now).state==State::Invalid);std::cout<<"BM-I06 PASS\n";
    fake_fifo=0;fake_now+=6000;loop();require(!optical_ready);require(monitor.read(Signal::OxygenEstimate,fake_now).state==State::Stale);std::cout<<"BM-I07 PASS\n";
    fake_temperature=NAN;fake_now+=2000;Serial.output.str("");loop();require(monitor.read(Signal::AmbientTemperature,fake_now).state==State::Invalid);require(Serial.output.str().find(state_label(State::Invalid,language))!=std::string::npos);std::cout<<"BM-I08 PASS\n";
    std::cout<<"{\"cases\":8,\"passed\":8,\"language\":"<<MONITOR_LANGUAGE<<",\"adapterSimulated\":true,\"realFirmwareBuild\":false,\"cloudCalls\":0}\n";
  }catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
}
