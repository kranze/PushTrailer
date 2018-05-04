/* 
* Lights.h
*
* Created: 19.04.2016 19:49:58
* Author: KZM
*/


#ifndef __LIGHTS_H__
#define __LIGHTS_H__


//#include <Adafruit_NeoPixel.h>

class Lights
{
//variables
public:
uint8_t enabled;
uint8_t breaking;
boolean left, right=0;
protected:
private:

Adafruit_NeoPixel strip; 
//functions
public:
	void enable(uint8_t status);
	void breaklight(uint8_t status);
	void flash(int8_t dir);
	void charging(uint8_t mode);
	void beginn();
	Lights(uint16_t n, uint8_t pin);
	~Lights();
protected:
private:
	Lights( const Lights &c );
	Lights& operator=( const Lights &c );

}; //Lights

#endif //__LIGHTS_H__
