/*
 * Timer1.h
 *
 *  Created on: Aug 30, 2019
 *      Author: Hossam-PC
 */

#ifndef TIMER1_H_
#define TIMER1_H_

#include "LIB/Bit_Math.h"
#include "LIB/Standard_Types.h"

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


void Timer1_init(uint8 prescaler);

void Timer1_stop(void);

void Timer1_Normal(void);


#endif /* TIMER1_H_ */
