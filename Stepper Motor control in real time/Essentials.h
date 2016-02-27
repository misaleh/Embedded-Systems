/*
 * IncFile1.h
 *
 * Created: 06/02/2016 09:41:29 م
 *  Author: Mostafa
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#define F_CPU 1000000ul
/*LEDS*/
unsigned char Right;
unsigned char Left;
unsigned char Mode_Half ;
unsigned char Mode_Full;
/*Buttons*/
unsigned char Speed_Up ;
unsigned char Speed_Dn ;
unsigned char OState;
unsigned char Mode ; /* half or full */
unsigned char Direction;/*Right or left*/
volatile unsigned char SysTick = 0 ;
volatile unsigned char ledFlag = 0;
volatile unsigned char SysTick;
volatile unsigned char  ledFlag_RIGHT = 0;
volatile unsigned char  ledFlag_LEFT  = 0;
volatile unsigned char  ledFlag_HALF = 0;
volatile unsigned char  ledFlag_FULL = 0;
volatile unsigned char ButtonData = 0;
volatile unsigned char ButtonData1 = 0;
volatile unsigned char ButtonData2 = 0;
volatile unsigned char ButtonState = 0;
volatile signed char speed = 0;
volatile unsigned char Stepper_Flag = 0;

typedef enum state { Half_Right,Full_Right,Half_Left,Full_Left } Mealy_state;
typedef struct {
void (*FunctionPointerStepper)(unsigned char s); /*For stepper motor*/
void (*FunctionPointerLeds1)(void);
void (*FunctionPointerLeds2)(void);
Mealy_state nexState[4]; /*4 states */  
  }StateType;
#endif /* INCFILE1_H_ */