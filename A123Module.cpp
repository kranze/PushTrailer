/* 
* A123Module.cpp
*
* Created: 14.03.2016 16:02:50
* Author: KZM
*/


#include "A123Module.h"


#define BCM_CMD_ID 0x50
#define MOD_V_OFFSET 1000
#define MOD_THERM_OFFSET -40

boolean Flag_Recv;

void CAN_ISR()
{
	Flag_Recv = true;
}

int32_t A123Module::getCurrent(){
	int32_t res=0;
	for (int i=0;i<means;i++)
	res+=this->CURRENT[i];
	
	return((res/means));
}

uint16_t A123Module::getVoltage()
{
	return(avevoltage*7);
}

void A123Module::setBits(unsigned int startBit, unsigned int length, unsigned char *buf, unsigned int data)
{
	unsigned int endBit = startBit + length - 1;
	for  (unsigned int i = 0; i < length; i++) {
		unsigned maskedData = data & 1;
		if (maskedData) {
			unsigned char mask = maskedData << (7 - ((endBit - i) % 8));
			buf[(endBit - i) / 8] = buf[(endBit - i) / 8] | mask;
			} else {
			unsigned char mask = ~(~maskedData << (7 - ((endBit - i) % 8)));
			buf[(endBit - i) / 8] = buf[(endBit - i) / 8] & mask;
		}
		data = data >> 1;
	}
}

unsigned int A123Module::getBits(int startBit, int length, unsigned char *buf) {
	unsigned int val = 0;
	unsigned char startBitByte = startBit / 8;
	unsigned char bitShift = 0;
	unsigned char currentBit = startBit % 8;
	unsigned char currentByte = buf[startBitByte];
	
	if (length <= 8) {
		unsigned char mask = 0;
		for (char i = 0; i < length; i++) {
			mask += 1 << (currentBit + i);
		}
		val = (currentByte & mask) >> currentBit ;
		} else {
		while (length > 0) {
			val += (currentByte >> currentBit) << (bitShift);
			bitShift += 8 - currentBit;
			length -= 8 - currentBit;
			currentBit = 0;
			startBitByte -= 1;
			currentByte = buf[startBitByte];
		}
	}
	return val;
}


boolean A123Module::start()
{
	if ( CAN_OK != CAN.begin(CAN_500KBPS,MCP_8MHz) ){
		Serial.println("CAN NOT OK");
		return(false);
	}
	else {
		Serial.println("CAN OK");
		running=true;
		/*cli();
		PCICR=(1<<PCIE2);
		ISC20
		PCMSK2=0x80;
		sei();*/
		//attachInterrupt(INT0, CAN_ISR, FALLING); // start interrupt
		return(true);
	}
}

void A123Module::stop(){
	running=false;
	SPI.end();
	pinMode(CAN_CS,OUTPUT); digitalWrite(CAN_CS,LOW);
}

void A123Module::send_balance(uint16_t voltage){
	
	unsigned char buf[8]={0x01, 0xFF, 0XF0, 0x01, 0x10, 0, 0, 0};
	
	unsigned int data;
	if (running){
		msg_id_send++;
		if (msg_id_send>16){
			msg_id_send=1;
		}
		setBits(0,4,buf,msg_id_send);
		voltage=min(voltage,3550);
		
		if (voltage<=2400){
			voltage=3550;
		}

		data=(voltage-1000)/0.5;
		setBits(8,13,buf,data);

		
		this->CAN.sendMsgBuf(BCM_CMD_ID,0,8,buf);
		Flag_Recv=true;
		this->UpdateValues();
	}
}

void A123Module::UpdateCurrent(){
	static uint8_t mean;
	this->CURRENT[mean] = ( (analogRead(Battery_CS)-515) * 174.3861607143 );
	mean++;
	if (mean>means)
		mean=0;	
}

int16_t A123Module::getPower()
{
	return (getCurrent()/1000.0)*(getVoltage()/1000.0);
}

void A123Module::UpdateValues() {
	
	// If we get data write to buffer
	if (Flag_Recv && !unwritten_data) {                   // check if get data
		Flag_Recv = 0;
		this->unwritten_data = true;
		this->buffersUsed = 0;
		
		while (CAN_MSGAVAIL == CAN.checkReceive()) {
			CAN.readMsgBuf(&len[buffersUsed], buf + 8 * buffersUsed);    // read data,  id: message id, len: data length, buf: data buf
			id[buffersUsed]=CAN.getCanId();
			buffersUsed += 1;
			if (buffersUsed > 7) {
				break;
			}
		}
	}
	if (unwritten_data) {
		for (int i = 0 ; i < buffersUsed; i++) {
			unsigned char id_mod = id[i] >> 8;
			
			if (id_mod == 0x2) {
				undervoltage = getBits(3, 1, buf);
				overvoltage = getBits(2, 1, buf);
				minvoltage = getBits(27, 13, buf) * 0.5 + MOD_V_OFFSET;
				maxvoltage = getBits(43, 13, buf) * 0.5 + MOD_V_OFFSET;
				avevoltage = getBits(59, 13, buf) * 0.5 + MOD_V_OFFSET;
				
				msg_id_recv = getBits(4, 4, buf);
				unsigned char mod_tmp_chn = getBits(24, 3, buf);
				if (mod_tmp_chn==2)
					temperature = getBits(8, 8, buf) * 0.5 + MOD_THERM_OFFSET;
				mod_bal_cnt = getBits(40, 3, buf);
				unsigned char mod_v_compare_oor = getBits(58, 1, buf);
			}
		}
		buffersUsed = 0;
		unwritten_data = false;
	}
}

// default constructor
A123Module::A123Module():CAN(CAN_CS)
{
	
} //A123Module

 A123Module::A123Module(uint16_t Address, uint8_t PinCS)
 :Address(Address), CAN(PinCS)
{
	
}

// default destructor
A123Module::~A123Module()
{
} //~A123Module
