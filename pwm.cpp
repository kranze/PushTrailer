// 
// 
// 

#include "pwm.h"
#include "PinConfig.h"
#include <TimerOne.h>




void pwm_init(void){
	
	
	//40us -> 25kHz
	Timer1.initialize(40);
	//Timer1.pwm(9,0);
	//Timer1.pwm(10,0);

}

void set_pwm_Motor_1(unsigned int PWM10_t){
	
	//Timer1.setPwmDuty(9, PWM10_t);
}

void set_pwm_Motor_2(unsigned int PWM10_t){
	
	//Timer1.setPwmDuty(10, PWM10_t);
}

void enable_bridges(uint8_t enable)
{
	
}

