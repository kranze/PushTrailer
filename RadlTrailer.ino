#include <TimerOne.h>

#include <arduino.h>

#include <EEPROM.h>
//#include <TimerOne.h>
#include <ArduinoJson.h>
#include <SPI.h>
#include <mcp_can_dfs.h>
#include <mcp_can.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <Adafruit_NeoPixel.h>

#include "PinConfig.h"
#include "bridge.h"
#include "A123Module.h"
#include "AnalogInput.h"
#include "Lights.h"

//Kalibrierung
//	Fahrwerk
#define RADUMFANG 1.257

//	Antrieb

//	Batterie

float eeODO EEMEM;
float eeTRIP EEMEM;
float eeEBATT EEMEM;
float eeKWH100 EEMEM;
uint32_t eeTIME EEMEM;


//Bridge1_PWMH, Bridge1_PWML, Bridge1_DIR, Bridge1_RESET, Bridge1_CS, 40);
//bridge Bridge2(Bridge2_PWMH, Bridge2_PWML, Bridge2_DIR, Bridge2_RESET, Bridge2_CS, 40);
A123Module Battery(0x20E, CAN_CS);
AnalogInput Throttle(Throttle_Uraw);
AnalogInput UCharge(Charger_Vout);
uint16_t tacho = 0;
uint16_t debouncer = 0;
StaticJsonBuffer<200> jsonOutBuffer;
Lights myLights(26, 23);

JsonObject& root = jsonOutBuffer.createObject();
char recBuffer[255];
uint8_t notaus = 0;
uint32_t time;
uint8_t power = 0;
unsigned long step_count;

int16_t IMotMax;
int16_t IMotRecuMax;
uint8_t BytesRead;
boolean step_active;
volatile float wh_100km;
volatile float ETrip;
float kmh = 0;
uint16_t ic5_alt;
volatile float trip = 0;
volatile float odo = 0;
volatile float EBatt = 0;
volatile float CBattCharge = 0;
volatile float CBattDischg = 0;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
char ErrorString[200];
boolean ParseError;
uint16_t ovf_counter;
uint8_t chargerstatus;
void step(void);

ISR(TIMER4_COMPA_vect) {
	step();
}

ISR(TIMER5_OVF_vect) {
	if (ovf_counter == 0) {
//		Serial.println("Bla");
		wdt_reset();
		eeprom_write_float(&eeTRIP, trip);
		wdt_reset();
		eeprom_update_float(&eeODO, odo);
		wdt_reset();
		eeprom_update_float(&eeEBATT, EBatt);
	}
	ovf_counter++;
	kmh = 0;
	if (ovf_counter > 75) {
		ovf_counter = 0;
//		if (chargerstatus == 0 || chargerstatus == 4)
//			shutdown();
	}
}
ISR(TIMER5_CAPT_vect) {
	TCNT5 = 0;
	if (ICR5 > 1500) {
		kmh = (RADUMFANG / ((ICR5) * 0.000064)) * 3.6;

		odo += RADUMFANG;
		trip += RADUMFANG;
		wh_100km = -ETrip / ((trip / 1000.0) / 100.0);
	}
	ovf_counter = 0;
}

void timer4_init() {

	TCCR4B = 0;
	TCCR4A = 0;
	TCCR4B = (1 << WGM42); // CTC Modus
	TIMSK4 |= (1 << OCIE4A);
	OCR4A = 2499;
}
void timer4_start() {
	TIMSK4 |= (1 << OCIE4A);
	TCCR4B = (1 << WGM42); // CTC Modus
	TCCR4B |= (0 << CS42) | (1 << CS41) | (1 << CS40);
}
void timer4_stop() {
	TIMSK4 = 0;
	TCCR4B = (1 << WGM42); // CTC Modus
}

bridge Bridge1;
bridge Bridge2;
void setup() {

	Bridge1.setup(Bridge1_PWMH, Bridge1_PWML, Bridge1_DIR, Bridge1_RESET, Bridge1_CS, 40);
	Bridge2.setup(Bridge2_PWMH, Bridge2_PWML, Bridge2_DIR, Bridge2_RESET, Bridge2_CS, 40);
	pinMode(Power_RELAY, OUTPUT);
	digitalWrite(A14, LOW);
	pinMode(48, INPUT);
	pinMode(46, OUTPUT);
	digitalWrite(46, LOW);
	pinMode(42, OUTPUT);
	digitalWrite(42, HIGH);
	pinMode(13, OUTPUT);
	pinMode(12, OUTPUT);
	myLights.beginn();
	/* add setup code here */
	inputString.reserve(200);
	wdt_disable();
	IMotMax = Bridge1_CurrentMax;
	IMotRecuMax = Bridge1_CurrentMin;
	odo = eeprom_read_float(&eeODO);
	EBatt = eeprom_read_float(&eeEBATT);
	trip = eeprom_read_float(&eeTRIP);
	//eeprom_update_float(&eeODO, 0);
	/* Setup Serial */
	Serial.begin(115200);
	BTSerial.begin(38400);
	//BTSerial.setTimeout(50);

	pinMode(PinPowerButton, INPUT);
	Serial.println("Hello");

	//pinMode(41,OUTPUT); digitalWrite(41,HIGH);
	pinMode(Bluetooth_STATE, INPUT);
	pinMode(Charger_RELAY, OUTPUT);
	digitalWrite(Charger_RELAY, HIGH);

	/* SETUP Throttle */
	Throttle.setLowerDeadZone(Throttle_Voltage_Minimum);
	Throttle.setUpperDeadZone(Throttle_Voltage_Maximum);
	Throttle.setOffSet(Thottle_Voltage_Offset);
	Throttle.setFactor(Throttle_Factor);

	TCCR5A = 0;
	TCCR5C = 0;

	TCCR5B = 0x0; //256
	TCCR5B |= (1 << ICNC5);
	TCCR5B |= (1 << ICES5);

	TIMSK5 = (1 << TOV5);
	TIMSK5 |= (1 << ICIE5);

	UCharge.setFactor(32);
	UCharge.setUpperDeadZone(27000);
	Bridge1.stop();
	Bridge2.stop();
	Battery.stop();
	pinMode(PinATXPower, OUTPUT);
	digitalWrite(PinATXPower, LOW);
	pinMode(PinATXEnable, OUTPUT);
	digitalWrite(PinATXEnable, HIGH);
	while (digitalRead(PinPowerButton) == HIGH)
		delay(100);

}

void PowerMode(uint8_t mode) {
	switch (mode) {
	case 2:
		startup();
		break;
	case 1:
		standby();
		break;
	case 0:
		shutdown();
		break;
	}

}
void startup() {
	power = true;
	Bridge1.start();
	Bridge1.calibrateCS();
	Bridge2.start();
	Bridge2.calibrateCS();
	Battery.start();
	while (digitalRead(PinPowerButton) == HIGH)
		delay(100);
	Bridge1.setPWMmax(1024);
	Bridge1.setDir(1);
	Bridge1.setImaxFWD(IMotMax);
	Bridge1.setImaxRWD(IMotRecuMax);

	Bridge2.setPWMmax(1024);
	Bridge2.setDir(-1);
	Bridge2.setImaxFWD(IMotMax);
	Bridge2.setImaxRWD(IMotRecuMax);

	Serial.println("ON");
	Battery.send_balance(0);
	Timer1.pwm(13, 0);
	trip = 0;


	 /*pinMode(38,INPUT_PULLUP);
	 pinMode(40,OUTPUT); digitalWrite(40,LOW);*/
	for (int i = 0; i < 5; i++) {
		Battery.send_balance(0);

		Throttle.read();
		delay(20);
	}
	//Serial.println(Battery.id[0],HEX);
	//Serial.println(Battery.minvoltage);
	timer4_init();
	timer4_start();
	TCCR5B |= 0x5;
	wdt_enable(WDTO_250MS);

}
void standby() {
	timer4_stop();
	wdt_disable();
	power = false;
	notaus = false;
	Serial.println("OFF");
	Bridge1.stop();
	Bridge2.stop();
}
void shutdown() {
	standby();
	Battery.stop();
	digitalWrite(PinATXPower, HIGH);
	digitalWrite(Charger_RELAY, HIGH);
	delay(1000);
	digitalWrite(Power_RELAY, HIGH);
}

void loop() {
	StaticJsonBuffer<200> jsonInBuffer;
	/* add main program code here */
	delay(100);
	static int counter = 0;
	char buf[255];
	//Serial.println(Battery.id[0], HEX);
	//Serial.println(kmh);

	//Serial.println(UCharge.read());
	//Errorchecks
	memset(ErrorString, 0, sizeof(ErrorString));
	if (notaus > 0)
		strcat(ErrorString, "CAN ERROR");
	if (Throttle.OutOfRange)
		strcat(ErrorString, "Throttle Out of Range");
	if (!power && Throttle.read() > 0)
		strcat(ErrorString, "Throttle not 0");
	if (power && Battery.minvoltage < Battery_CellVoltageMin)
		strcat(ErrorString, "Under Voltage!");
	if (Battery.maxvoltage > Battery_CellVoltageMax)
		strcat(ErrorString, "Over Voltage!");
	if (ParseError)
		strcat(ErrorString, "ParseError");

	if ((digitalRead(PinPowerButton) == HIGH || UCharge.read() > 15000) && power == false && Throttle.read() == 0) {
		Serial.println("startup");

		startup();

	}
	if ((digitalRead(PinPowerButton) == HIGH && power == true) || notaus > 10) {
		if (chargerstatus != 0)
			shutdown();
		//Serial.println("Notaus");
		//Serial.println("OFF");

	}
	if (digitalRead(Bluetooth_STATE)) {

		if (BTSerial.available()) {

			inputString = BTSerial.readStringUntil('\n');
			JsonObject& rootin = jsonInBuffer.parseObject(inputString);
			if (!rootin.success()) {
				ParseError = true;
			} else {
				ParseError = false;
				if (rootin.containsKey("ACC"))
					IMotMax = rootin["ACC"];
				Bridge1.setImaxFWD(IMotMax);
//				Bridge2.setImaxFWD(IMotMax);
				if (rootin.containsKey("REC"))
					IMotRecuMax = rootin["REC"];
				Bridge1.setImaxRWD(IMotRecuMax);
//				Bridge2.setImaxRWD(IMotRecuMax);
				if (rootin.containsKey("RESETTRIP")) {
					trip = 0;
					ETrip = 0;
				}
				if (rootin.containsKey("SHUTDOWN"))
					notaus = true;
				if (rootin.containsKey("SETEBATT"))
					EBatt = rootin["SETEBATT"];
				if (rootin.containsKey("Light"))
					myLights.enable(rootin["Light"]);
				if (rootin.containsKey("Power"))
					PowerMode(rootin["Power"]);
			}
		}
		{
			root["SPEED"] = kmh;
			root["PBATT"] = Battery.getPower();
			root["WH100"] = wh_100km;
			root["TRIP"] = trip / 1000.0;
			root["ODO"] = odo / 1000.0;
			root["TEMP"] = Battery.temperature;
			root["IBATT"] = Battery.getCurrent();
			root["UBATT"] = Battery.getVoltage();
			root["UDRIFT"] = Battery.maxvoltage - Battery.minvoltage;
			root["EBATT"] = EBatt;
			root["ACC"] = IMotMax;
			root["REC"] = IMotRecuMax;
			root["IMOT"] = (Bridge1.getCurrent() + Bridge2.getCurrent()) / 2.0;
			if (ErrorString[0]) {
				root["ERROR"] = ErrorString;
			}
			root.printTo(BTSerial);
			//root.printTo(Serial);
		}
	}

	if (power) {
		Battery.send_balance(Battery.minvoltage + 1);
		// liegen mehr als 3 NAchrichten differenz-> Notaus
		if (abs(Battery.msg_id_send-Battery.msg_id_recv) >= 3) {
			Serial.println(Battery.avevoltage);
			notaus++;
		} else {
			notaus = 0;
		}
	}
	if ((Bridge1.getCurrent()  + Bridge2.getCurrent()) / 2.0 < -3000) {
		myLights.breaklight(1);
	} else if (myLights.breaking == 1) {
		myLights.breaklight(0);
	}
	if (counter % 10 == 0) {
		sprintf(buf, "%ld; %d; %d; %d; %ld; %ld", Battery.getCurrent(), Battery.getVoltage(), Battery.maxvoltage, (int) Throttle.read(), (long) CBattCharge, (long) CBattDischg);
		Serial.println(buf);
	}
	counter++;
}

void step() {
	static float chpwm = 0;

	step_count++;

	wdt_reset();
	Battery.UpdateCurrent();

	EBatt += (Battery.getPower() / 3600.0) * (periode / 1000.0);
	EBatt = min(EBattMax, EBatt);
	ETrip += (Battery.getPower() / 3600.0) * (periode / 1000.0);

	// Ladeteil
	// Statemachine mit chargerstatus
	switch (chargerstatus) {
	// 0: kein Laden
	case 0:
		if (UCharge.read() > 15000) {
			Serial.println("Charger=1");
			chargerstatus = 1;
		}
		break;
		// 1: Ladegr�t ist an 230V angeschlossen und der Zwischenkreis wird vorgeladen
	case 1:
		chpwm += (Battery.getVoltage() - UCharge.read()) / 1500.0;
		if (abs(Battery.getVoltage() - UCharge.read() < 500)) {
			chargerstatus = 2;
			digitalWrite(Charger_RELAY, LOW);
		}
		break;
		// 2: ZK vorgeladen und Relais geschlossen
		//		solange einzelne Zellspannung unter [UCellMax] mV liegt, sind wir im Konstatstromladen mit [IChgMax] mA geladen
	case 2:
		myLights.charging(chargerstatus);
		if (Battery.maxvoltage < Battery_CellVoltageMax) {
			chpwm += (CHARGER_MaxCurrent - Battery.getCurrent()) / 20000.0;
		} else {
			Serial.print("Charger=3");
			Serial.println(chpwm);
			chargerstatus = 3;
		}
		break;
		// 3: Konstantspannungsladen mit [UcellMax] mV
	case 3:
		myLights.charging(chargerstatus);
		chpwm += (Battery_CellVoltageMax - Battery.maxvoltage) / 100.0;
		if (Battery.getCurrent() < 0)
			chpwm += 0.1;
		if (Battery.getCurrent() < 1000 && (Battery.maxvoltage - Battery.minvoltage) <= 5) {
			Serial.println("Charger=4");
			EBatt = EBattMax;
			eeprom_update_float(&eeEBATT, EBatt);
			chargerstatus = 4;
			digitalWrite(Charger_RELAY, HIGH);
		}
		break;
		//4: Warten bis Ladeger�t ausgesteckt wurde
	case 4:
		myLights.charging(chargerstatus);
		if (UCharge.read() < 10000) {
			myLights.enable(0);
			chpwm = 0;
			chargerstatus = 0;
		}
		break;
	}
	// Ladeger�t sollte nicht die 1000 �berschreiten
	if (chpwm > 850) {
		Serial.println(">1000");
		chpwm = 0;
		chargerstatus = 4;
		digitalWrite(Charger_RELAY, HIGH);
	}
	// pwm wert f�r ladeger�t setzen
	Timer1.pwm(Charger_PWM, round(chpwm));
	//Timer1.pwm(Charger_PWM, 0);
	//analogWrite(13, round(chpwm / 4.5));
	// Tachosignal debouncen:

	// Motorbr�cken ansteuern
	// Ladeger�t darf nicht angeschlossen sein und Throttle muss innerhalb der Range sein.
	if (Battery.minvoltage < Battery_CellVoltageMin) {
		IMotMax = 0;
		EBatt = 0;
		Bridge1.setImaxFWD(IMotMax);
		Bridge2.setImaxFWD(IMotMax);

	}
	if (Battery.maxvoltage > Battery_CellVoltageMax) {
		IMotRecuMax = 0;
		Bridge1.setImaxRWD(IMotRecuMax);
		Bridge2.setImaxRWD(IMotRecuMax);
	}
	uint16_t thro = Throttle.read();
	if (chargerstatus == 0 && !Throttle.OutOfRange) {
		//Serial.println(thro);
		Bridge1.setPWM(thro);
		Bridge2.setPWM(thro);
	} else {
		Bridge1.setPWM(0);
		Bridge2.setPWM(0);
	}
}
