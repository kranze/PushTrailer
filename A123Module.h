/* 
* A123Module.h
*
* Created: 14.03.2016 16:02:51
* Author: KZM
*/


#ifndef __A123MODULE_H__
#define __A123MODULE_H__
#include "PinConfig.h"
#include <Arduino.h>
#include <mcp_can.h>
#include <SPI.h>

#define means 10

class A123Module {
//variables
public:
	uint8_t msg_id_send;
	uint8_t msg_id_recv; 
	boolean undervoltage;
	boolean overvoltage;
	boolean balanceactive;
	uint8_t mod_bal_cnt;
	uint16_t cellvoltage[7];
	uint16_t maxvoltage;
	uint16_t minvoltage;
	uint16_t avevoltage;
	uint16_t temperature;
	int32_t current;
	boolean running;
	long unsigned int id[8];
protected:
private:
	
	boolean unwritten_data;
	uint8_t buffersUsed;
	uint16_t Address;
	MCP_CAN CAN;
	uint8_t len[8];
	uint8_t buf[64];
	int32_t CURRENT[means];


//functions
public:
	A123Module();
	A123Module(uint16_t Address, uint8_t PinCS);
	~A123Module();
	void send_balance(uint16_t voltage);
	int32_t getCurrent();
	uint16_t getVoltage();
	boolean start();
	void stop();
	void UpdateCurrent();
	int16_t getPower();
protected:
private:
	A123Module( const A123Module &c );
	A123Module& operator=( const A123Module &c );
	void setBits(unsigned int startBit, unsigned int length, unsigned char *buf, unsigned int data);
	unsigned int getBits(int startBit, int length, unsigned char *buf);
	void UpdateValues();
}; //A123Module

#endif //__A123MODULE_H__
