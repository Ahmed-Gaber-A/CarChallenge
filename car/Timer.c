/*
 * Timer.c
 *
 * Created: 18/08/2019 10:02:39 ص
 *  Author: AhmedGaber
 */ 

#include "Timer.h"
extern struct cnfg_type timer_cnfg;

void timer0_init(void){
	OCR0  = 0x00;
	TCCR0 = 0x00;
	TCNT0 = 0x00; 
	
	if (timer_cnfg.mode== Normal_mode){	
		clrbit(TCCR0,WGM00); clrbit(TCCR0,WGM01); clrbit(TCCR0,COM00); clrbit(TCCR0,COM01);		
	}
	else if (timer_cnfg.mode== PWM_PhaseCorrect) {
		setbit(TCCR0,WGM00); clrbit(TCCR0,WGM01); //setbit(TCCR0,COM00); setbit(TCCR0,COM01);
	}
	else if (timer_cnfg.mode== CTC) {
		clrbit(TCCR0,WGM00); setbit(TCCR0,WGM01); setbit(TCCR0,COM00); clrbit(TCCR0,COM01);
	}
	else if (timer_cnfg.mode== Fast_PWM) {
        setbit(TCCR0,WGM00); setbit(TCCR0,WGM01); setbit(TCCR0,COM00); setbit(TCCR0,COM01);			
	}
	
     if (timer_cnfg.prescaler== no_prescaler ) {setbit(TCCR0,CS00); clrbit(TCCR0,CS01); clrbit(TCCR0,CS02);}
else if (timer_cnfg.prescaler== 8 )    {clrbit(TCCR0,CS00); setbit(TCCR0,CS01); clrbit(TCCR0,CS02);}
else if (timer_cnfg.prescaler== 64 )   {setbit(TCCR0,CS00); setbit(TCCR0,CS01); clrbit(TCCR0,CS02);}
else if (timer_cnfg.prescaler== 256 )  {clrbit(TCCR0,CS00); clrbit(TCCR0,CS01); setbit(TCCR0,CS02);}
else if (timer_cnfg.prescaler== 1024 ) {setbit(TCCR0,CS00); clrbit(TCCR0,CS01); setbit(TCCR0,CS02);}
else if (timer_cnfg.prescaler== XFE )  {clrbit(TCCR0,CS00); setbit(TCCR0,CS01); setbit(TCCR0,CS02);}
else if (timer_cnfg.prescaler== XRE )  {setbit(TCCR0,CS00); setbit(TCCR0,CS01); setbit(TCCR0,CS02);}
	
	

	if      (timer_cnfg.CMI==Enabled)  { setbit(TIMSK,OCIE0); setbit(SREG,7); }
	else if (timer_cnfg.CMI==Disabled) { clrbit(TIMSK,OCIE0); }
		
    if      (timer_cnfg.OVI==Enabled)  { setbit(TIMSK,TOIE0);setbit(SREG,7); }
	else if (timer_cnfg.OVI==Disabled) { clrbit(TIMSK,TOIE0); }

}


void timer1_init(void){
	//clear all registers
	TCCR1A = 0x00;
	TCCR1B = 0x00;
	TCNT1H = 0x00;
	TCNT1L = 0x00;
	OCR1AH = 0x00;
	OCR1AL = 0x00;
	OCR1BH = 0x00;
	OCR1BL = 0x00;
	ICR1H  = 0x00;
	ICR1L  = 0x00;
	/*if (timer_cnfg.mode== Normal_mode){
		clrbit(TCCR1A,WGM00); clrbit(TCCR1A,WGM01); clrbit(TCCR0,COM00); clrbit(TCCR0,COM01);
	}
	else if (timer_cnfg.mode== PWM_PhaseCorrect) {
		setbit(TCCR0,WGM00); clrbit(TCCR0,WGM01); setbit(TCCR0,COM00); setbit(TCCR0,COM01);
	}
	else if (timer_cnfg.mode== CTC) {
		clrbit(TCCR0,WGM00); setbit(TCCR0,WGM01); setbit(TCCR0,COM00); clrbit(TCCR0,COM01);
	}
	else if (timer_cnfg.mode== Fast_PWM) {
		setbit(TCCR0,WGM00); setbit(TCCR0,WGM01); setbit(TCCR0,COM00); setbit(TCCR0,COM01);
	}
	*/


}

void timer_delay(uint32 n){
	TCNT0 = 0;
	OCR0 = 125;
	while (n != 0)
	{
      while ((getbit(TIFR,OCF0)) != 1 );
	  n--;
	  setbit(TIFR,OCF0);		
	}
		
}

