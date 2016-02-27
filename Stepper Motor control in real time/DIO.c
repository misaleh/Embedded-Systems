/*
 * DIO.c
 * MCAL
 * Created: 1/22/2016 5:21:21 PM
 *  Author: Amit
 */ 
#include "DIO.h"
#include <avr/io.h>

#define SET_REG_VAL(REG,VAL,MASK) REG &= ~(MASK);\
                                  REG |= (VAL & MASK) 
#define Toggle_REG_VAL(REG,MASK) REG ^= MASK;
								  
#define GET_REG_VAL(REG,MASK) REG & MASK
void DIO_vidWritePortDirection(unsigned char u8PortName,unsigned char u8PortMask,unsigned char u8Direction)
{
	switch(u8PortName)
	{
		case PA:
		{
			SET_REG_VAL(DDRA,u8Direction,u8PortMask);
		}	
		break;
		
		case PB:
		{
			SET_REG_VAL(DDRB,u8Direction,u8PortMask);
		}	
		break;
		case PC:
		{
			SET_REG_VAL(DDRC,u8Direction,u8PortMask);
		}
		break;
		
		case PD:
		{
			SET_REG_VAL(DDRD,u8Direction,u8PortMask);
		}
		break;
		
	}
	
}
 void DIO_vidWritePortData(unsigned char u8PortName,unsigned char u8PortMask,unsigned char u8Data)
{
		switch(u8PortName)
		{
			case PA:
			{
				SET_REG_VAL(PORTA,u8Data,u8PortMask);
			}
			break;
			
			case PB:
			{
				SET_REG_VAL(PORTB,u8Data,u8PortMask);
			}
			break;
			case PC:
			{
				SET_REG_VAL(PORTC,u8Data,u8PortMask);
			}
			break;
			
			case PD:
			{
				SET_REG_VAL(PORTD,u8Data,u8PortMask);
			}
			break;
			
		}
	
}
 void DIO_vidTogglePortData(unsigned char u8PortName,unsigned char u8PortMask)
{
		switch(u8PortName)
		{
			case PA:
			{
				Toggle_REG_VAL(PORTA,u8PortMask);
			}
			break;
			
			case PB:
			{
				Toggle_REG_VAL(PORTB,u8PortMask);
			}
			break;
			case PC:
			{
				Toggle_REG_VAL(PORTC,u8PortMask);
			}
			break;
			
			case PD:
			{
				Toggle_REG_VAL(PORTD,u8PortMask);
			}
			break;
			
		}
	
}
 void DIO_vidReadPortData(unsigned char u8PortName,unsigned char u8PortMask,unsigned char *pu8DataPtr)
 {
	 switch(u8PortName)
	 {
		 case PA:
		 *pu8DataPtr = GET_REG_VAL(PINA,u8PortMask);
		 break;
		 case PB:
		 *pu8DataPtr = GET_REG_VAL(PINB,u8PortMask);
		 break;
		 case PC:
		 *pu8DataPtr = GET_REG_VAL(PINC,u8PortMask);
		 break;
		 case PD:
		 *pu8DataPtr = GET_REG_VAL(PIND,u8PortMask);
		 break;
	 }		 
 }