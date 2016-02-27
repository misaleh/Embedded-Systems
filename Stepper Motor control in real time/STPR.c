/*
 * STPR.c
 *
 * Created: 06/02/2016 09:54:49 م
 *  Author: Mostafa
 
 Half Mode:
  1 3 2 6 4 12 8
 0001
 0011
 0010
 0110
 0100
 1100
 1000
 */ 
#include "DIO.h"
#include "STPR.h"
extern unsigned char Stepper_Flag;
void STPR_Init(void)
{	
	DIO_vidWritePortDirection(PA,STPR1_MASK,0x0F); /* port output*/
}
void STPR_MOV_HALFR(signed char speed) 
{
	static unsigned char direction = 1;
				if(Stepper_Flag == speed)
	{
	switch (direction){
		case 8:
				direction = 9;
				break;
		case 9:
				direction = 1;
				break;
		case 1:
				direction = 5;
				break;
		case 5:
				direction = 4;
				break;
		case 4:
				direction = 6;
				break;
		case 6:
				direction = 2;
				break;
		case 2:
				direction = 0x0A;
				break;
		case 0x0A:
				direction = 8;
				break;
	}				
		DIO_vidWritePortData(PA,0x0F,direction);
		Stepper_Flag = -1;
	}		
	}	
		
void STPR_MOV_HALFL(signed char speed)
{
	static unsigned char direction = 1;
			if(Stepper_Flag == speed)
	{
		switch (direction){
		case 8:
				direction = 0x0A;
				break;
		case 0x0A:
				direction = 2;
				break;
		case 2:
				direction = 6;
				break;
		case 6:
				direction = 4;
				break;
		case 4:
				direction = 5;
				break;
		case 5:
				direction = 1;
				break;
		case 1:
				direction = 9;
				break;
		case 9:
				direction = 8;
				break;
	}				
		DIO_vidWritePortData(PA,0x0F,direction);
		Stepper_Flag = -1;
		}		
}
void STPR_MOV_FULLR(signed char speed) 
{
	static unsigned char direction = 1;
		if(Stepper_Flag == speed)
	{
	switch (direction){
		case 8:
				direction = 1;
				break;
		case 1:
				direction = 4;
				break;
		case 4:
				direction = 2;
				break;
		case 2:
				direction = 8;
				break;
}				
	DIO_vidWritePortData(PA,0x0F,direction);
	Stepper_Flag = -1;
	}	

}
void STPR_MOV_FULLL(signed char speed)
{
	static unsigned char direction = 1;
	if(Stepper_Flag == speed)
	{

switch (direction){
		case 8:
				direction = 2;
				break;
		case 2:
				direction = 4;
				break;
		case 4:
				direction = 1;
				break;
		case 1:
				direction = 8;
				break;
}				
	DIO_vidWritePortData(PA,0x0F,direction);
	Stepper_Flag = -1;
}
}
void STPR_Stop(void)
{
	DIO_vidWritePortData(PA,STPR1_MASK,0);
}
