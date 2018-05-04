// 
// 
// 

#include "adc.h"
#include "PinConfig.h"

long GetBatteryCurrentmA(void){

	return ( (analogRead(ChannelIBat)-512) * 174.3861607143 );
}

long GetMotor1CurrentmA(void){

	return ( (analogRead(ChannelIMot1)-512)*-71.6796875 );
}

long GetMotor2CurrentmA(void){

	return ( (analogRead(ChannelIMot2)-512)*-71.6796875 );
}
	
int GetThrottle(void){
	int result;
	result=analogRead(ChannelUThrottle);
	result -= 250;
	if (result < 0)
		result=0;
	result *= 1.8;
	if (result > 1023)
		result=1023;
	return (result);
}
