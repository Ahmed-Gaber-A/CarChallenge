/*
 * ICU.c
 *
 * Created: 26/08/2019 10:58:17 ص
 *  Author: AhmedGaber
 */ 


#include "ICU.h"
#include "DIO.h"
#include "Timer.h"
//configuration
uint8 trigger = falling  ; //
uint8 ICU_INT = Disabled ;

void ICU_init(void) {
	//edge trigger select
   	 if (trigger == rising ) { setbit(TCCR1B,ICES1);}
else if (trigger == falling) { clrbit(TCCR1B,ICES1);}
	
	 if (ICU_INT == Enabled)  { setbit(SREG,7);  setbit(TIMSK,TICIE);}
else if (ICU_INT == Disabled) {clrbit(TIMSK,TICIE);}		

//set timer 1 for normal mode 
 TCCR1A = 0x00; 
 //clear registers
 TCNT1H = 0x00;
 TCNT1L = 0x00;
 ICR1H  = 0x00;
 ICR1L  = 0x00;
//prescaler select	  8 MHz 1024
setbit(TCCR1B,CS12); clrbit(TCCR1B,CS11); setbit(TCCR1B,CS10);


}