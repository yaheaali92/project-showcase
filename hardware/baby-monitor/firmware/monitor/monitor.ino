#include <Arduino.h>
#include <Wire.h>
#include <DHT.h>
#include <MAX30105.h>
#include <spo2_algorithm.h>
#include <monitor_core.hpp>
#include <labels.hpp>
#include <pin_config.hpp>

using namespace baby_monitor;
#ifndef MONITOR_LANGUAGE
#define MONITOR_LANGUAGE 0
#endif
static_assert(MONITOR_LANGUAGE >= 0 && MONITOR_LANGUAGE <= 2, "Select language 0, 1 or 2");
constexpr Language language = static_cast<Language>(MONITOR_LANGUAGE);
// Reference pin assignment differs from the historical D3/D4 course wiring; verify on the exact board.
DHT environment(pins::ambientData,DHT11);
MAX30105 optical;
Monitor monitor;
Schedule ambient_poll(2000), digital_poll(100), optical_poll(10), reports(2000), optical_retry(30000);
std::array<FaultGate, signal_count> notices;
bool optical_ready=false;
uint32_t infrared[100],red[100];
uint32_t last_optical_sample=0;
unsigned sample_count=0;

void setup() {
  Serial.begin(115200);
  Wire.begin(pins::opticalSda,pins::opticalScl);
  environment.begin();
  pinMode(pins::motionData,INPUT);
  // No legacy credentials or live cloud transmission.
}
void poll_optical(uint32_t now) {
  if(optical_ready && uint32_t(now-last_optical_sample)>=6000) {optical_ready=false;sample_count=0;monitor.ingest(Signal::PulseEstimate,0,false,now);monitor.ingest(Signal::OxygenEstimate,0,false,now);}
  if(!optical_ready) {
    if(!optical_retry.due(now)) return;
    optical_ready=optical.begin(Wire,I2C_SPEED_FAST);
    if(optical_ready) { optical.setup();optical.setPulseAmplitudeRed(0x3F);optical.setPulseAmplitudeIR(0x3F);last_optical_sample=now; }
    else {monitor.ingest(Signal::PulseEstimate,0,false,now);monitor.ingest(Signal::OxygenEstimate,0,false,now);}
    sample_count=0;
    return;
  }
  if(!optical_poll.due(now))return;
  optical.check();
  // Bounded FIFO draining; never wait indefinitely for a sample.
  for(unsigned drained=0;drained<4 && optical.available();drained++) {
    red[sample_count]=optical.getRed();infrared[sample_count]=optical.getIR();optical.nextSample();sample_count++;last_optical_sample=now;
    if(sample_count==100) {
      int32_t oxygen=0,pulse=0;int8_t valid_oxygen=0,valid_pulse=0;
      maxim_heart_rate_and_oxygen_saturation(infrared,100,red,&oxygen,&valid_oxygen,&pulse,&valid_pulse);
      monitor.ingest(Signal::PulseEstimate,float(pulse),valid_pulse!=0,now);
      monitor.ingest(Signal::OxygenEstimate,float(oxygen),valid_oxygen!=0,now);
      sample_count=0;
    }
  }
}
void loop() {
  const uint32_t now=millis();
  if(ambient_poll.due(now)) {
    monitor.ingest(Signal::AmbientTemperature,environment.readTemperature(),true,now);
    monitor.ingest(Signal::Humidity,environment.readHumidity(),true,now);
  }
  if(digital_poll.due(now)) {
    monitor.ingest(Signal::Motion,float(digitalRead(pins::motionData)),true,now);
    monitor.ingest(Signal::SoundAdc,float(analogRead(pins::soundAnalog)),true,now);
  }
  poll_optical(now);
  if(reports.due(now)) {
    for(unsigned index=0;index<signal_count;index++) {
      const Signal signal=static_cast<Signal>(index);const Reading reading=monitor.read(signal,now);
      Serial.print(signal_label(signal,language));Serial.print(": ");Serial.print(state_label(reading.state,language));
      if(reading.state==State::Fresh) {Serial.print("; ");Serial.print(reading.last_good);}
      Serial.println();
      if(notices[index].changed(reading.state,now)) Serial.println(state_label(reading.state,language));
    }
  }
  // Driver calls themselves are not proven nonblocking on hardware.
  yield();
}
