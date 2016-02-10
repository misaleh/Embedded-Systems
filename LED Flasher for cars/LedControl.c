/*
 * LedControl.c
 *
 * Created: 05/09/2015 10:43:19 ص
 *  Author: Mostafa
 */ 
#include <avr/io.h>
#include "ModuleEssential.h"
#include "essential.h"
#include "DataTypes.h"
extern mail ;
void FlashRight(u8 s)
{
	CBIT(PORTD,LEDL);
	mail = 0;
while((mail <= 62) && (SwitchAll == s) )
	{
	SBIT(PORTD,LEDR);	
	}

	mail=0;
while((mail <= 62) && (SwitchAll == s))
		{
		CBIT(PORTD,LEDR);
		}	
	



}
void FlashLeft(u8 s)
{
	CBIT(PORTD,LEDR);
	mail = 0;
while((mail <= 62) && (SwitchAll == s))
	{
	SBIT(PORTD,LEDL);
	}

	mail = 0;
while((mail <= 62) && (SwitchAll == s))
	{
	CBIT(PORTD,LEDL);
	}
	
	

}
void FlashBoth(u8 s)
{
	mail = 0;
while((mail <= 62) && (SwitchAll == s))
	{
	SBIT(PORTD,LEDR);
	SBIT(PORTD,LEDL);
	}
		mail = 0;
while((mail <= 62) && (SwitchAll == s))
	{
	CBIT(PORTD,LEDR);
	CBIT(PORTD,LEDL);
	}
}


void FlashRightE(u8 s)
{
	CBIT(PORTD,LEDL);
	mail = 0;
while((mail <= 18) && (SwitchAll == s) ) /* 1 sec */
	{
	SBIT(PORTD,LEDR);	
	}

	mail=0;
while((mail <= 18) && (SwitchAll == s))
		{
		CBIT(PORTD,LEDR);
		}	
	



}
void FlashLeftE(u8 s)
{
	CBIT(PORTD,LEDR);
	mail = 0;
while((mail <= 18) && (SwitchAll == s))
	{
	SBIT(PORTD,LEDL);
	}

	mail = 0;
while((mail <= 18) && (SwitchAll == s))
	{
	CBIT(PORTD,LEDL);
	}
	
	

}
void FlashBothE(u8 s)
{
	mail = 0;
while((mail <= 18) && (SwitchAll == s))
	{
	SBIT(PORTD,LEDR);
	SBIT(PORTD,LEDL);
	}
		mail = 0;
while((mail <= 18) && (SwitchAll == s))
	{
	CBIT(PORTD,LEDR);
	CBIT(PORTD,LEDL);
	}
}

void FlashNone(u8 s)
{
	mail = 0;
	CBIT(PORTD,LEDR);
	CBIT(PORTD,LEDL);
	
}
