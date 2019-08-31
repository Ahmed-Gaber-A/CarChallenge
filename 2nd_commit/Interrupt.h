/*
 * Interrupt.h
 *
 *  Created on: Aug 30, 2019
 *      Author: Hossam-PC
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "LIB/Standard_Types.h"
#include "LIB/Bit_Math.h"
#include "Registers.h"

#define	ISC2	6

#define I   	7

#define TOIE1	2   //TIMSK register
#define TICIE1	5

#define WGM12	3
#define WGM13	4

#define ICES1	6

#define CS10	0
#define CS11	1
#define CS12	2


#define ICF1	5 //icu flag in TIFR register

#define INT2	5

#define ICU		30

#define falling		0
#define rising		1


void Global_Interrupt_Enable(void);

void Ext2_Interrupt2_Enable(void);

void Ext2_Interrupt2_Mode(uint8 mode);

void Timer_overflow_Interrupt_Enable(void);

void Timer1_Input_capture_Interrupt_Enable(void);


#endif /* INTERRUPT_H_ */
