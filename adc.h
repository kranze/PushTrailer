// adc.h

#ifndef _ADC_h
#define _ADC_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

long GetMotor1CurrentmA(void);
long GetMotor2CurrentmA(void);
long GetBatteryCurrentmA(void);
int GetThrottle(void);

#endif

