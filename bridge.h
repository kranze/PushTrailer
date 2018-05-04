/* 
* bridge.h
*
* Created: 14.03.2016 14:22:23
* Author: KZM
*/


#ifndef __BRIDGE_H__
#define __BRIDGE_H__

#include <Arduino.h>
#include <TimerOne.h>
#define means 20

class bridge
{
//variables
public:
protected:
private:
	uint8_t PinPWMH;
	uint8_t PinPWML;
	uint8_t PinDir;
	uint8_t PinReset;
	uint8_t PinCS;
	uint16_t Period;
	
	int16_t ImaxFWD;
	int16_t ImaxRWD;
	int16_t maxPWMH;
	float PWMH;
	int16_t PWML;
	int8_t DIR;
	int16_t CURRENT[means];
	int16_t csOffset;
	
//functions
public:
	bridge();
	//bridge(uint8_t PinPWMH, uint8_t PinPWML, uint8_t PinDir, uint8_t PinReset, uint8_t PinCS, uint16_t Period);
	~bridge();
	void setup(uint8_t PinPWMH, uint8_t PinPWML, uint8_t PinDir, uint8_t PinReset, uint8_t PinCS, uint16_t Period);
	int32_t readCurrent();
	int32_t getCurrent();
	void setDir(int8_t Dir);
	void start();
	void stop();
	void setImaxFWD(int16_t Imax);
	void setImaxRWD(int16_t Imax);
	void setPWMmax(uint16_t PWMmax);
	void calibrateCS();
	void setPWM(int16_t value);
	
	
protected:
private:
	//bridge( const bridge &c );
	//bridge& operator=( const bridge &c );

}; //bridge

#endif //__BRIDGE_H__

