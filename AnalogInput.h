/* 
* AnalogInput.h
*
* Created: 14.03.2016 19:28:14
* Author: KZM
*/


#ifndef __ANALOGINPUT_H__
#define __ANALOGINPUT_H__

#include <Arduino.h>
class AnalogInput
{
//variables
public:
	boolean OutOfRange;
protected:
private:
	uint8_t channel;
	float factor=1;
	uint16_t udz=1023;
	uint16_t ldz;
	uint16_t offset;
//functions
public:
	AnalogInput();
	AnalogInput(uint8_t Channel);
	~AnalogInput();
	float read();
	void setLowerDeadZone(uint16_t ldz);
	void setUpperDeadZone(uint16_t udz);
	void setFactor(float factor);
	void setOffSet(uint16_t offset);
protected:
private:
	AnalogInput( const AnalogInput &c );
	AnalogInput& operator=( const AnalogInput &c );

}; //AnalogInput

#endif //__ANALOGINPUT_H__
