/*
 * DIO.h
 * MCAL
 * Created: 1/22/2016 5:21:10 PM
 *  Author: Amit
 */ 


#ifndef DIO_H_
#define DIO_H_

#define PA 0x00
#define PB 0x01
#define PC 0x02
#define PD 0x03

extern void DIO_vidWritePortDirection(unsigned char u8PortName,unsigned char u8PortMask,unsigned char u8Direction);
extern void DIO_vidWritePortData(unsigned char u8PortName,unsigned char u8PortMask,unsigned char u8Data);
extern void DIO_vidTogglePortData(unsigned char u8PortName,unsigned char u8PortMask);
extern void DIO_vidReadPortData(unsigned char u8PortName,unsigned char u8PortMask,unsigned char *pu8DataPtr);



#endif /* DIO_H_ */