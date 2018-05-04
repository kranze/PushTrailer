// pwm.h

#ifndef _PWM_h
#define _PWM_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

void pwm_init(void);
void set_pwm_Motor_1(unsigned int PWM10_t);
void set_pwm_Motor_2(unsigned int PWM10_t);
void enable_bridges(uint8_t enable);

#endif

