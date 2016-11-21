// ********************************************************************************
// class Car
// ********************************************************************************

#pragma once

#include <Door.h>
#include <SPI.h>
#include <mcp_can.h>

#define SPI_CS_PIN					10				// pin for CS CAN
#define CAN_SPEED					CAN_250KBPS		// can speed settings
#define CAN_FREQ					MCP_16MHZ		// can frequency

#define CAN_DOOR_ID					0xA1			// can packet id for doors
#define CAN_DOOR_BYTE				2
#define CAN_DOOR_FRONT_LEFT_BIT		4
#define CAN_DOOR_FRONT_RIGHT_BIT	5
#define CAN_DOOR_REAR_LEFT_BIT		6
#define CAN_DOOR_REAR_RIGHT_BIT		7

#define CAN_SPEED_ID				0xA2			// can packet id for Speed
#define CAN_SPEED_BYTE				2
#define CAN_SPEED_BIT_FROM			4
#define CAN_SPEED_BIT_TO			8

class Car{
	private:		
		
	public:
		int speed;
		int rpm;
		Door doorFrontLeft 	;
		Door doorFrontRight ;
		Door doorRearLeft 	;
		Door doorRearRight 	;
		
		Car ();		
		canProcess();

}

Car :: Car ()
{
	Serial.begin(115200);
	
	MCP_CAN CAN0(SPI_CS_PIN);                               // Set CS pin
	
	if(CAN0.begin(MCP_ANY, CAN_SPEED, CAN_FREQ) == CAN_OK) 
		Serial.print("CAN: [OK]");  
	else
		Serial.print("CAN: [ERROR]");  
	CAN0.setMode(MCP_NORMAL);                     // Set operation mode to normal so the MCP2515 sends acks to received data.
	
	CAN0.init_Filt(0, 0, CAN_DOOR_ID);
	CAN0.init_Filt(1, 0, CAN_SPEED_ID);
	
}

void Car :: canProcess();
		{
			CAN0.readMsgBuf(&len, rxBuf);
			if (CAN.getCanId()==CAN_DOOR_ID){	
				doorFrontLeft.setState	( bitRead ( rxBuf[CAN_DOOR_BYTE] ),		CAN_DOOR_FRONT_LEFT_BIT );
				doorFrontRight.setState	( bitRead ( rxBuf[CAN_DOOR_BYTE] ),		CAN_DOOR_FRONT_RIGHT_BIT );
				doorRearLeft.setState	( bitRead ( rxBuf[CAN_DOOR_BYTE] ),		CAN_DOOR_REAR_LEFT_BIT );
				doorRearRight.setState	( bitRead ( rxBuf[CAN_DOOR_BYTE] ),		CAN_DOOR_REAR_RIGHT_BIT );
			}
			if (CAN.getCanId()==CAN_SPEED_ID){
				speed = rxBuf[CAN_SPEED_BYTE]	>>	CAN_SPEED_BIT_TO	;
			}	
		}


