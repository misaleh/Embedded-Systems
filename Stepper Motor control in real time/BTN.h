/*
 * BTN.h
 *
  Author: Amit
 */ 


#ifndef BTN_H_
#define BTN_H_
#define NUM_OF_BTNS 0x04
#define BTN_SPEEDDOWN 0x00 
#define BTN_SPEEDUP 0x01 
#define BTN_Mode 0x02
#define BTN_Dir 0x03
#define BTN_STATE_ACTIVE   0x00
#define BTN_STATE_INACTIVE 0x01
extern void BTN_Init(void);
extern void BTN_GetBtnState(unsigned char u8BtnId,unsigned char* pu8BtnStatePtr);



#endif /* BTN_H_ */