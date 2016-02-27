/*
 * STPR.h
 *
 * Created: 06/02/2016 09:54:36 م
 *  Author: Mostafa
 */ 


#ifndef STPR_H_
#define STPR_H_
#define STPR1_MASK 0x0F
void STPR_Init(void);
void STPR_MOV_HALFR(signed char);
void STPR_MOV_HALFL(signed char);
void STPR_MOV_FULLL(signed char);
void STPR_MOV_FULLR(signed char);
void STPR_Stop(void);


#endif /* STPR_H_ */