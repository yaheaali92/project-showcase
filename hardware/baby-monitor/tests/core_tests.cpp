#include "../src/monitor_core.hpp"
#include "../src/labels.hpp"
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace baby_monitor;
void require(bool value) {if(!value)throw std::runtime_error("assertion failed");}
int main() {
  std::vector<std::pair<std::string,std::function<void()>>> cases;
  auto add=[&](const char* id,std::function<void()> check){cases.emplace_back(id,check);};
  add("BM-01",[]{Monitor m;require(m.read(Signal::AmbientTemperature,0).state==State::Missing);require(!m.read(Signal::AmbientTemperature,0).has_last_good);});
  add("BM-02",[]{Monitor m;m.ingest(Signal::AmbientTemperature,22,true,10);auto r=m.read(Signal::AmbientTemperature,10);require(r.state==State::Fresh&&r.last_good==22&&r.measured_at==10);});
  add("BM-03",[]{Monitor m;require(!m.ingest(Signal::AmbientTemperature,NAN,true,0));require(m.read(Signal::AmbientTemperature,0).state==State::Invalid);});
  add("BM-04",[]{Monitor m;require(!m.ingest(Signal::AmbientTemperature,INFINITY,true,0));require(!m.ingest(Signal::AmbientTemperature,-INFINITY,true,1));});
  add("BM-05",[]{Monitor m;m.ingest(Signal::AmbientTemperature,22,true,0);m.ingest(Signal::AmbientTemperature,NAN,true,1);auto r=m.read(Signal::AmbientTemperature,1);require(r.state==State::Invalid&&r.last_good==22&&r.measured_at==0);});
  add("BM-06",[]{Monitor m;m.ingest(Signal::Humidity,50,true,100);require(m.read(Signal::Humidity,6099).state==State::Fresh);require(m.read(Signal::Humidity,6100).state==State::Stale);});
  add("BM-07",[]{Monitor m;m.ingest(Signal::Humidity,50,true,100);m.ingest(Signal::Humidity,51,true,200);require(m.read(Signal::Humidity,6199).state==State::Fresh);});
  add("BM-08",[]{Monitor m;require(!m.ingest(Signal::Humidity,-1,true,1));require(!m.ingest(Signal::Humidity,101,true,2));require(m.ingest(Signal::Humidity,0,true,3));require(m.ingest(Signal::Humidity,100,true,4));});
  add("BM-09",[]{Monitor m;require(!m.ingest(Signal::PulseEstimate,0,true,1));require(!m.ingest(Signal::PulseEstimate,70,false,2));require(m.ingest(Signal::PulseEstimate,70,true,3));});
  add("BM-10",[]{Monitor m;require(!m.ingest(Signal::OxygenEstimate,110,true,0));require(!m.ingest(Signal::OxygenEstimate,-1,true,1));require(!m.ingest(Signal::OxygenEstimate,97,false,2));});
  add("BM-11",[]{Monitor m;require(m.ingest(Signal::Motion,0,true,1));require(m.read(Signal::Motion,1).state==State::Fresh);require(!m.ingest(Signal::Motion,0.5,true,2));});
  add("BM-12",[]{Monitor m;require(!m.ingest(Signal::SoundAdc,1024,true,1));require(!m.ingest(Signal::SoundAdc,-1,true,2));require(m.ingest(Signal::SoundAdc,1023,true,3));});
  add("BM-13",[]{Monitor m;m.ingest(Signal::Humidity,50,true,100);require(!m.ingest(Signal::Humidity,60,true,99));require(m.read(Signal::Humidity,101).last_good==50);});
  add("BM-14",[]{Monitor m;m.ingest(Signal::Motion,1,true,0xffffff00u);require(m.read(Signal::Motion,100).state==State::Fresh);require(m.read(Signal::Motion,744).state==State::Stale);});
  add("BM-15",[]{Monitor m;m.ingest(Signal::Humidity,50,true,0xfffffff0u);require(m.ingest(Signal::Humidity,51,true,20));require(m.read(Signal::Humidity,21).last_good==51);});
  add("BM-16",[]{Monitor m;m.ingest(Signal::AmbientTemperature,22,true,0);require(m.read(Signal::PulseEstimate,0).state==State::Missing);});
  add("BM-17",[]{Schedule s(2000);require(s.due(0));require(!s.due(1));require(!s.due(1999));require(s.due(2000));});
  add("BM-18",[]{Schedule s(100);require(s.due(0xffffffd0u));require(!s.due(40));require(s.due(60));});
  add("BM-19",[]{Schedule s(100);require(s.due(0));require(s.due(10000));require(!s.due(10000));});
  add("BM-20",[]{FaultGate g;require(g.changed(State::Invalid,0));require(!g.changed(State::Invalid,1000));require(!g.changed(State::Invalid,10000));});
  add("BM-21",[]{FaultGate g;require(!g.changed(State::Fresh,0));require(!g.changed(State::Invalid,1));require(g.changed(State::Fresh,2));});
  add("BM-22",[]{FaultGate g;g.changed(State::Missing,0);require(g.changed(State::Stale,1000));require(!g.changed(State::Stale,2000));});
  add("BM-23",[]{ReconnectPolicy p;require(!p.attempt_due(false,false,0));require(!p.attempt_due(false,false,60000));});
  add("BM-24",[]{ReconnectPolicy p;require(p.attempt_due(true,false,0));require(!p.attempt_due(true,false,999));require(p.attempt_due(true,false,1000));require(!p.attempt_due(true,false,2000));require(p.attempt_due(true,false,3000));});
  add("BM-25",[]{ReconnectPolicy p;p.attempt_due(true,false,0);p.attempt_due(true,false,1000);require(!p.attempt_due(true,true,1100));require(p.attempt_due(true,false,1101));});
  add("BM-26",[]{ReconnectPolicy p;require(p.attempt_due(true,false,0xffffff00u));require(!p.attempt_due(true,false,700));require(p.attempt_due(true,false,744));});
  add("BM-27",[]{Monitor m;m.ingest(Signal::AmbientTemperature,22,true,0);auto tx=current_transmission(m,true,6000);require(tx.available&&!tx.readings[0].has_last_good&&std::isnan(tx.readings[0].last_good));});
  add("BM-28",[]{Monitor m;m.ingest(Signal::AmbientTemperature,22,true,0);auto tx=current_transmission(m,true,1);require(tx.readings[0].has_last_good&&tx.readings[0].last_good==22);require(!tx.readings[2].has_last_good);});
  add("BM-29",[]{Monitor m;require(!current_transmission(m,false,0).available);m.ingest(Signal::Motion,1,true,1);require(current_transmission(m,true,1).readings[4].last_good==1);});
  add("BM-30",[]{for(unsigned language=0;language<3;language++)for(unsigned state=0;state<4;state++)require(std::string(state_label(static_cast<State>(state),static_cast<Language>(language))).size()>0);});
  add("BM-31",[]{Monitor m;require(!m.ingest(static_cast<Signal>(999),1,true,0));require(m.read(static_cast<Signal>(999),0).state==State::Invalid);});
  add("BM-32",[]{Monitor m;for(unsigned i=0;i<signal_count;i++)m.ingest(static_cast<Signal>(i),i==4?1:i==5?420:50,true,0);auto tx=current_transmission(m,true,7000);for(auto r:tx.readings)require(r.state==State::Stale&&!r.has_last_good);});
  add("BM-33",[]{FaultGate g;g.changed(State::Fresh,0);require(!g.changed(State::Invalid,1));require(g.changed(State::Invalid,1000));require(!g.changed(State::Invalid,2000));});
  add("BM-34",[]{ReconnectPolicy p;require(p.attempt_due(true,false,0));uint32_t now=1000;for(unsigned i=0;i<8;i++){require(p.attempt_due(true,false,now));now+=30000;}require(!p.attempt_due(true,false,now-1));require(p.attempt_due(true,false,now));});
  unsigned passed=0;
  for(const auto& item:cases) {try{item.second();std::cout<<item.first<<" PASS\n";passed++;}catch(const std::exception& error){std::cerr<<item.first<<" FAIL "<<error.what()<<'\n';return 1;}}
  std::cout<<"{\"cases\":"<<cases.size()<<",\"passed\":"<<passed<<",\"synthetic\":true,\"hardwareRun\":false,\"cloudCalls\":0}\n";
}
