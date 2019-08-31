/*
 * Registers.h
 *
 *  Created on: Aug 30, 2019
 *      Author: Hossam-PC
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "LIB/Standard_Types.h"

#define TCCR1A  (*((volatile uint8*)0x4F))
#define TCCR1B  (*((volatile uint8*)0x4E))

#define TCNT1  (*((volatile uint16*)0x4C))
#define TCNT1H  (*((volatile uint8*)0x4D))
#define TCNT1L  (*((volatile uint8*)0x4C))

#define TIMSK   (*((volatile uint8*)0X59))
#define TIFR    (*((volatile uint8*)0X58))
#define SREG    (*((volatile uint8*)0X5F))

#define ICR1    (*((volatile uint16*)0X46))
#define ICR1H    (*((volatile uint8*)0X47))
#define ICR1L    (*((volatile uint8*)0X46))

#define GICR    (*((volatile uint8*)0X5B))

#define MCUCSR  (*((volatile uint8*)0X54))


/* PORT A*/

#define PORTA  (*((volatile uint8*)0x3B))
#define DDRA   (*((volatile uint8*)0x3A))
#define PINA   (*((volatile uint8*)0x39))

////////////////////////////////////////

/* PORT B*/

#define PORTB  (*((volatile uint8*)0x38))
#define DDRB   (*((volatile uint8*)0x37))
#define PINB   (*((volatile uint8*)0x36))

////////////////////////////////////////

/* PORT C*/

#define PORTC  (*((volatile uint8*)0x35))
#define DDRC   (*((volatile uint8*)0x34))
#define PINC   (*((volatile uint8*)0x33))

////////////////////////////////////////

/* PORT D*/

#define PORTD  (*((volatile uint8*)0x32))
#define DDRD   (*((volatile uint8*)0x31))
#define PIND   (*((volatile uint8*)0x30))
#endif /* REGISTERS_H_ */
