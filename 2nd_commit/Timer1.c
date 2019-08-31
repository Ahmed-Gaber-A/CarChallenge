/*
 * Timer1.c
 *
 *  Created on: Aug 30, 2019
 *      Author: Hossam-PC
 */

#include "Timer1.h"

void Timer1_init(uint8 prescaler)
{
	switch(prescaler)
	{
		case 1:
			Set_Bit(TCCR1B,CS10);
			Clr_Bit(TCCR1B,CS11);
			Clr_Bit(TCCR1B,CS12);
			break;
		case 8:
			Set_Bit(TCCR1B,CS11);
			Clr_Bit(TCCR1B,CS10);
			Clr_Bit(TCCR1B,CS12);
			break;
	}
}

void Timer1_stop(void)
{
	Clr_Bit(TCCR1B,CS10);
	Clr_Bit(TCCR1B,CS11);
	Clr_Bit(TCCR1B,CS12);
}

void Timer1_Normal(void)
{
    TCCR1A = 0;
}

