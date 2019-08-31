/*
 * car.c
 *
 * Created: 27/08/2019 03:56:28 م
 *  Author: AhmedGaber
 */ 

#include "motor.h"
#include "Timer.h"
#include "DIO.h"
#include <util/delay.h>

#define frwrd 2
#define slow 1
#define stop 0
 
uint8 state = frwrd ;
int main(void)
{
	
	DIO_SetPinDirection(PIN16,INPUT);
	DIO_SetPinDirection(PIN17,INPUT);
	DIO_SetPinDirection(PIN18,INPUT);
	DIO_SetPinDirection(PIN11,OUTPUT);
	
	motor_init();
	pwm_init();
	
	
    while(1)
    {
		pwm_write(255);
        if (DIO_ReadPin(PIN16) == 1 && DIO_ReadPin(PIN17) ==0 && DIO_ReadPin(PIN18) ==0) {state = frwrd;}
   else if (DIO_ReadPin(PIN16) ==0 &&DIO_ReadPin(PIN17) ==1 && DIO_ReadPin(PIN18) ==0) {state = slow;}	
   else if (DIO_ReadPin(PIN16) ==0 &&DIO_ReadPin(PIN17) ==0 && DIO_ReadPin(PIN18) ==1) {state = stop;}	
	   
	   if (state==frwrd)
	   {
		pwm_write(100); //100% of speed 
		motor_forward();
	   }
	   else if (state == slow)
	   {
	   pwm_write(60); //60% of speed
		   motor_forward();
	   }
	   else if ( state == stop) 
	   {
	
		   pwm_write(50); //turn right with 50% of speed
		   motor_right();
		   
	   }
}
   }