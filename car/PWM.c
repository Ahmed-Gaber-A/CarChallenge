/*
 * PWM.c
 *
 * Created: 27/08/2019 11:25:45 ص
 *  Author: AhmedGaber
 */ 

#include "PWM.h"
#include "Timer.h"

uint8 pwm_inv =  Non_inverted ; 
void pwm_init(void) {
	
	timer0_init();
	 if (pwm_inv == Non_inverted) {setbit(TCCR0,COM00); setbit(TCCR0,COM01);}
else if (pwm_inv == Inverted) {clrbit(TCCR0,COM00); setbit(TCCR0,COM01);}
	
}


void pwm_write(uint8 speed) {
	
	OCR0 = ((100 - speed )*255)/100 ; 
}

