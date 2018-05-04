/* 
* Lights.cpp
*
* Created: 19.04.2016 19:49:57
* Author: KZM
*/

#include <Adafruit_NeoPixel.h>
#include "Lights.h"

void Lights::enable(uint8_t status)
{
	enabled=status;
	for(int i=0;i<strip.numPixels();i++){
		strip.setPixelColor(i,50*status,0,0);
	}
	strip.show();
}

void Lights::breaklight(uint8_t status)
{
	breaking=status;
	for(int i=0;i<strip.numPixels();i++){
		strip.setPixelColor(i,min( 255 * breaking + 50 * enabled, 255),0,0);
	}
	strip.show();
}

void Lights::flash(int8_t dir)
{
	if (dir == 1){ //right
		for(int i=0;i<5;i++){
			strip.setPixelColor(i,255*right,80*right,0);
			//strip.setPixelColor(i,min( 255 * breaking + 50 * enabled, 255),255*right,0);
		}
		right=!right;
	}
	
	if (dir == -1){ //left
		for(int i=strip.numPixels()-5;i<strip.numPixels();i++){
			strip.setPixelColor(i,255*left,80*left,0);
			//strip.setPixelColor(i,min( 255 * breaking + 50 * enabled, 255),255*right,0);
		}
		left=!left;
	}
	if (dir == 0){
				
	}
	strip.show();
	
	
}

void Lights::charging(uint8_t mode)
{
	static uint8_t color;
	static boolean dir;

	if (color==0){
		dir = 1;
	}
	if (color==150){
		dir=0;
	}
	if (dir){
		color++;
	}
	else{
		color--;
	}
	for(int i=0;i<strip.numPixels();i++){
		switch(mode){
			
		case 2: strip.setPixelColor(i,0,0,color); break;
		case 3: strip.setPixelColor(i,0,color,0); break;
		case 4: strip.setPixelColor(i,0,150,0); break;
		}
	}
	strip.show();
}

void Lights::beginn()
{
	strip.begin();
	strip.show();
}

// default constructor
Lights::Lights(uint16_t n, uint8_t pin)
{
	strip = Adafruit_NeoPixel(n, pin, NEO_GRB + NEO_KHZ800);
	//strip.begin();
	//strip.show();
} //Lights

// default destructor
Lights::~Lights()
{
} //~Lights
