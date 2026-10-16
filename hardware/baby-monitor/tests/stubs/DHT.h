#pragma once
constexpr int DHT11=11;
extern float fake_temperature,fake_humidity;
extern int temperature_reads,humidity_reads;
class DHT {public:DHT(int,int){}void begin(){}float readTemperature(){temperature_reads++;return fake_temperature;}float readHumidity(){humidity_reads++;return fake_humidity;}};
