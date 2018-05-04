#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2018-05-03 08:35:44

#include "Arduino.h"
#include <TimerOne.h>
#include <arduino.h>
#include <EEPROM.h>
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

ISR(TIMER4_COMPA_vect) ;
ISR(TIMER5_OVF_vect) ;
ISR(TIMER5_CAPT_vect) ;
void timer4_init() ;
void timer4_start() ;
void timer4_stop() ;
void setup() ;
void PowerMode(uint8_t mode) ;
void startup() ;
void standby() ;
void shutdown() ;
void loop() ;
void step() ;

#include "RadlTrailer.ino"


#endif
