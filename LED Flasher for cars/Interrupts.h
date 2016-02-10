/*
 * Interrupts.h
 *
 * Created: 05/09/2015 03:47:44 م
 *  Author: Mostafa
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_


typedef void (*PfType)(void);
void EINT_Init(PfType Int0Fn,PfType Int1Fn,PfType Int2Fn);



#endif /* INTERRUPTS_H_ */