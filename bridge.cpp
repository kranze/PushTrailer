/* 
 * bridge.cpp
 *
 * Created: 14.03.2016 14:22:22
 * Author: KZM
 */

#include "bridge.h"

// default constructor
bridge::bridge() {
	this->PinPWMH=0;
} //bridge

void bridge::start() {

	Timer1.initialize(Period);
	Timer1.pwm(PinPWMH, 0);
	PWMH = 0;
	digitalWrite(PinReset, HIGH);
	digitalWrite(PinPWML, HIGH);
}
void bridge::setDir(int8_t Dir) {
	this->DIR = Dir;
	switch (DIR) {
	case -1:
		digitalWrite(PWML, HIGH);
		digitalWrite(PinDir, HIGH);
		break;
	case 0:
		digitalWrite(PWML, LOW);
		setPWM(0);
		break;
	case 1:
		digitalWrite(PWML, HIGH);
		digitalWrite(PinDir, LOW);
		break;
	}
}

void bridge::setImaxRWD(int16_t Imax) {
	ImaxRWD = min(Imax, 0);
}
void bridge::setImaxFWD(int16_t Imax) {
	ImaxFWD = max(Imax, 0);
}
void bridge::setPWMmax(uint16_t PWMmax) {
	maxPWMH = PWMmax;
}
void bridge::calibrateCS() {
	csOffset = 0;
	for (int i = 0; i < means; i++)
		readCurrent();
	csOffset = getCurrent();
}
int32_t bridge::readCurrent() {
	static uint8_t i = 0;
	uint8_t j;
	int32_t res = 0;
	CURRENT[i % means] = DIR * ((analogRead(PinCS) - 512) * -71.6796875 - csOffset);
	i++;
	for (j = 0; j < means; j++) {
		res += CURRENT[j];
	}
	res /= means;
	return (res);
}
int32_t bridge::getCurrent() {
	int32_t res = 0;
	for (int i = 0; i < means; i++)
		res += CURRENT[i];

	return ((res / means));
}
void bridge::stop() {
	digitalWrite(PinReset, LOW);
}

void bridge::setup(uint8_t PinPWMH, uint8_t PinPWML, uint8_t PinDir, uint8_t PinReset, uint8_t PinCS, uint16_t Period) {

	this->PinPWMH = PinPWMH;
	this->PinPWML = PinPWML;
	this->PinDir = PinDir;
	this->PinReset = PinReset;
	this->PinCS = PinCS;
	this->Period = Period;
	pinMode(PinPWMH, OUTPUT);
	pinMode(PinReset, OUTPUT);
	digitalWrite(PinReset, LOW); //Bis Richtung festgelegt wird...
	pinMode(PinPWML, OUTPUT);
	digitalWrite(PinPWML, LOW);
	pinMode(PinDir, OUTPUT);
	digitalWrite(PinDir, LOW);
}
//bridge::bridge(uint8_t PinPWMH, uint8_t PinPWML, uint8_t PinDir, uint8_t PinReset, uint8_t PinCS, uint16_t Period) :
//		PinPWMH(PinPWMH), PinPWML(PinPWML), PinDir(PinDir), PinReset(PinReset), PinCS(PinCS), Period(Period) {
//
//	pinMode(PinPWMH, OUTPUT);
//	pinMode(PinReset, OUTPUT);
//	digitalWrite(PinReset, LOW); //Bis Richtung festgelegt wird...
//	pinMode(PinPWML, OUTPUT);
//	digitalWrite(PinPWML, LOW);
//	pinMode(PinDir, OUTPUT);
//	digitalWrite(PinDir, LOW);
//
//}

void bridge::setPWM(int16_t value) {
	float stell;
	float thproz;
	int16_t Itemp = readCurrent();
	value = min(maxPWMH, value);
	thproz = (float) value / (float) maxPWMH;
	stell = ((value - PWMH) / 10.0);

	if (stell >= 0)
		stell = min(stell, min(20, (ImaxFWD*thproz-Itemp)/1000.0));
	else
		stell = max(stell, max(-20, (ImaxRWD*(1-thproz)-Itemp)/1000.0));

	this->PWMH += stell;

	//PWM begrenzen
	PWMH = min(PWMH, maxPWMH);
	PWMH = max(PWMH, 0);
	Serial.print(PinPWMH);
	Serial.print(";");
	Serial.print(value);
	Serial.print(";");
	Serial.print(PWMH);
	Serial.print(";");
	Serial.print(stell);
	Serial.print(";");
	Serial.println(Itemp);
	Timer1.pwm(PinPWMH, (int) PWMH + 1);
}

// default destructor
bridge::~bridge() {
} //~bridge
