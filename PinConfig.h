/*
 * PinConfig.h
 *
 * Created: 12.03.2016 00:07:11
 *  Author: KZM
 */ 


#ifndef PINCONFIG_H_
#define PINCONFIG_H_
#include <arduino.h>
//ADC


#define ModuleAddress 0x204



#define periode 10.0
#define EBattMax 1000

/********************** Bluetooth *********************
	IN:
		- Connection State */
			#define Bluetooth_STATE 18 /*
	PARAMETER:
		- Baud rate */
			#define Bluetooth_BAUD 38400 /*
		- Serial Port */
			#define BTSerial Serial2
	
/********************** Throttle **********************
	IN:
		- Voltage from Throttle */
			#define Throttle_Uraw 0 /*
	PARAMETER:
		- Minimum Voltage in mV (Lower -> ERROR) */
			#define Throttle_Voltage_Minimum 1000 /*
		- Maximum Voltage (Higher -> ERROR) */
			#define Throttle_Voltage_Maximum 4500 /*
		- Voltage Offset (mostly Voltage_Minimum) */
			#define Thottle_Voltage_Offset 1600 /*
		- Factor to match full 5V range */
			#define Throttle_Factor 1.9 /* 

/********************** Battery **********************
	IN:
		- Current from ACS709 VIOUT = (0.028 V/A * i + 2.5 V) * VCC / 5 V */
			#define Battery_CS 3 /*
	PARAMETER:
		- Maximum Cell Voltage in mV */
			#define Battery_CellVoltageMax 3550.0 /*
		- Minimum Cell Voltage in mV*/
			#define Battery_CellVoltageMin 2500.0 /*
		- Maximum Discharge Current in mA */
			#define Battery_CurrentMaxDischarge -60000 /*
		- Maximum Charge Current in mA */
			#define Battery_CurrentMaxCharge 60000 /*
		- Nominal Capacity in mAh */
			#define Battery_Capacity 50000 /*

/********************** Charger **********************				
	IN:
		- Analog Voltage over Voltage divider*/ 
			#define Charger_Vout 4 /*
	OUT:
		- PWM Signal for Controlling Voltage on Timer1OutputCompare*/ 
			#define Charger_PWM 13 /*
		- Digital with Relay LOW Active*/ 
			#define Charger_RELAY A13 /*
	PARAMETER:
		- Maximum Charge Current in mA */
			#define CHARGER_MaxCurrent 10000.0 /*

/********************** Bridge1 **********************
	IN:
		- Analog ACS714 current sensor output (66 mV/A centered at 2.5 V). */ 
			#define Bridge1_CS	2 /*
		- Digital FaultFlag 1 
			NC
		- Digital FaultFlag 2
			NC
			
			FF1	FF2
			L 	L 	No fault
			L 	H 	Short Circuit
			H 	L 	Over Temperature 
			H 	H 	Under Voltage 
	OUT:
		- PWM Signal PWMH Pulse width modulation input: a PWM signal on this pin corresponds to a PWM output on the motor outputs. */ 
			#define Bridge1_PWMH 11 /*
		- PWM Signal PWML Control input that enables coasting when both PWML and PWMH are low. */ 
			#define Bridge1_PWML 6 /*
		- Digital DIR Direction input: when DIR is high current will flow from OUTA to OUTB, when it is low current will flow from OUTB to OUTA.*/ 
			#define Bridge1_DIR 5 /*
		- Digital RESET When held low, it puts the driver into a low-power sleep mode and clears any latched fault flags.*/ 
			#define Bridge1_RESET 7 /*
	PARAMETER:
		- Maximum Output Current */
			#define Bridge1_CurrentMax 25000 /*
		-Minimum Output Current */
			#define Bridge1_CurrentMin -25000

/********************** Bridge2 **********************

	IN:
		- Analog ACS714 current sensor output (66 mV/A centered at 2.5 V). */ 
			#define Bridge2_CS 1 /*
		- Digital FaultFlag 1 
			NC
		- Digital FaultFlag 2
			NC
			
			FF1	FF2
			L 	L 	No fault
			L 	H 	Short Circuit
			H 	L 	Over Temperature 
			H 	H 	Under Voltage 
	OUT:
		- PWM Signal PWMH Pulse width modulation input: a PWM signal on this pin corresponds to a PWM output on the motor outputs. */ 
			#define Bridge2_PWMH 12 /*
		- PWM Signal PWML Control input that enables coasting when both PWML and PWMH are low. */ 
			#define Bridge2_PWML 3 /*
		- Digital DIR Direction input: when DIR is high current will flow from OUTA to OUTB, when it is low current will flow from OUTB to OUTA.*/ 
			#define Bridge2_DIR	2 /*
		- Digital RESET When held low, it puts the driver into a low-power sleep mode and clears any latched fault flags.*/ 
			#define Bridge2_RESET 4 /*
	PARAMETER:
		- Maximum Output Current */
			#define Bridge2_CurrentMax 25000 /*
		-Minimum Output Current */
			#define Bridge2_CurrentMin -25000

/********************** CAN-SHIELD **********************
	
	IN:
		- SPI MISO */
			#define CAN_MISO 50 /*
		- Receive Interrupt */
			#define CAN_INT INT3 /*
	OUT:
		- SPI MOSI */
			#define CAN_MOSI 51 /*
		- SPI SCK */
			#define CAN_SCK 52 /*
		- SPI SS (SLAVE SELCT) */
			#define CAN_CS 53 /*
*/


#define PinATXPower			29
#define PinPowerButton		15
#define PinATXEnable		14
#define Power_RELAY	A14
#define ChannelIBat A3
#define ChannelUThrottle A0
#define ChannelIMot1 A1
#define ChannelIMot2 A2

//IN

#define PinCanInt			3

#define PinTacho			38


#endif /* PINCONFIG_H_ */
