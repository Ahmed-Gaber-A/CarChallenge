/*
 * ultrasonic.c
 *
 *  Created on: Aug 30, 2019
 *      Author: Hossam-PC
 */

#include "Ultrasonic.h"

void Ultrasonic_Init(void)
{
	DIO_SetPinDirection(TRIG,OUTPUT);  //LED 1 PIN
	DIO_WritePin(TRIG,LOW);
	_delay_us(10);
}

void Ultrasonic_Trig(void)
{
	DIO_WritePin(TRIG,HIGH);
	_delay_us(15);
	DIO_WritePin(TRIG,LOW);
}

