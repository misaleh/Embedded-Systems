/*
 * BTN.c
 *
  Author: Amit
 */ 
#include "BTN.h"
#include "DIO.h"

#define  STATE_OPEN 0x00
#define  STATE_CLOSED 0x01

typedef struct
{
	unsigned char BtnPort;
	unsigned char BtnMask;
}BtnConfigType;

static const BtnConfigType BtnConfigData[NUM_OF_BTNS] =
{
	{
		PD,0x01
	}
	,
	{
		PD,0x02
	}
	,
	{
		PD,0x04
	}
	,
	{
		PD,0x08
	}
};

static unsigned char State[NUM_OF_BTNS];
static unsigned char GetState(unsigned char BtnID);
void BTN_Init(void)
{
	
	unsigned char LoopIndex;
	unsigned char BtnPort;
	unsigned char BtnMask;
	for(LoopIndex = 0 ; LoopIndex < NUM_OF_BTNS ; LoopIndex ++)
	{
		BtnPort = BtnConfigData[LoopIndex].BtnPort;
		BtnMask = BtnConfigData[LoopIndex].BtnMask;
		DIO_vidWritePortDirection(BtnPort,BtnMask,0x00);
		State[LoopIndex] = STATE_OPEN;
	}
}

void BTN_GetBtnState(unsigned char u8BtnId,unsigned char* pu8BtnStatePtr) /*which btn, and  pointer to data */
{
   *pu8BtnStatePtr = GetState(u8BtnId);
}

static unsigned char GetState(unsigned char BtnID)
{
	unsigned char BtnPort;
	unsigned char BtnMask;
	unsigned char BtnData;
	unsigned char BtnOut;
	BtnPort = BtnConfigData[BtnID].BtnPort;
	BtnMask = BtnConfigData[BtnID].BtnMask;
	DIO_vidReadPortData(BtnPort,BtnMask,&BtnData);
	
	if(State[BtnID] == STATE_OPEN)
	{
		if(BtnData == 0x00)
		{
			State[BtnID] = STATE_OPEN;
			BtnOut = BTN_STATE_INACTIVE;
		}
		else
		{
			State[BtnID] = STATE_CLOSED;
			BtnOut = BTN_STATE_ACTIVE;
		}
	}
	else
	{
		if(BtnData == 0x00)
		{
			State[BtnID] = STATE_OPEN;
			BtnOut = BTN_STATE_INACTIVE;
		}
		else
		{
			State[BtnID] = STATE_CLOSED;
			BtnOut = BTN_STATE_INACTIVE;
		}
		
	}
	return BtnOut;
	
}