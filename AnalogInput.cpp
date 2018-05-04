/* 
* AnalogInput.cpp
*
* Created: 14.03.2016 19:28:14
* Author: KZM
*/

#include "AnalogInput.h"

float AnalogInput::read(){
	int16_t temp=analogRead(this->channel);
	//Lower dead Zone:
	//Serial.println(temp);
	
	OutOfRange = ( temp<ldz || temp>udz );
	
	temp-=this->offset;
	
	temp=max(temp,0);
	
	temp=min(temp, this->udz);
	
	temp*=factor;
	
	//Serial.println(temp);
	return(temp);
}
void AnalogInput::setLowerDeadZone(uint16_t ldz){
	
	this->ldz=min(ldz/4.8875, 1023);
}
void AnalogInput::setUpperDeadZone(uint16_t udz){
	this->udz=min(udz/4.8875, 1023);
}

void AnalogInput::setOffSet(uint16_t offset){
	this->offset=min(offset/4.8875, 1023);
}
void AnalogInput::setFactor(float factor){
	this->factor=factor;
}
// default constructor
AnalogInput::AnalogInput()
{
} //AnalogInput

AnalogInput::AnalogInput(uint8_t pin):channel(pin)
{
	
} //AnalogInput

// default destructor
AnalogInput::~AnalogInput()
{
} //~AnalogInput
