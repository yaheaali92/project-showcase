#pragma once
#include <cstdint>
extern int32_t fake_pulse,fake_oxygen;
extern int8_t fake_pulse_valid,fake_oxygen_valid;
extern unsigned algorithm_calls;
inline void maxim_heart_rate_and_oxygen_saturation(uint32_t*,int,uint32_t*,int32_t* oxygen,int8_t* oxygen_valid,int32_t* pulse,int8_t* pulse_valid){algorithm_calls++;*oxygen=fake_oxygen;*oxygen_valid=fake_oxygen_valid;*pulse=fake_pulse;*pulse_valid=fake_pulse_valid;}
