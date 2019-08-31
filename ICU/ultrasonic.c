/*
 * ultrasonic.c
 *
 * Created: 26/08/2019 05:02:03 م
 *  Author: AhmedGaber
 */ 
#include "DIO.h"
#include "Timer.h"
#include <util/delay.h>

#define echo PIN30
#define trig PIN8

void ultrasonic_init (void) {
	ICU_init();
	DIO_SetPinDirection(trig,OUTPUT);
	DIO_SetPinDirection(echo,INPUT);
}

uint16 US_measure(void){
	uint16 start=0 , end=0,distance=0,flag = 0;
	f16 time ;
	DIO_WritePin(trig,HIGH);
	TCNT1H = 0x00;
	TCNT1L = 0x00;
	ICR1H =0x00;
	ICR1L =0x00;
	_delay_us(10);
	DIO_WritePin(trig,LOW);
	
	setbit(TCCR1B,ICES1);
	
	while (flag ==0 ){
		
		 
		setbit(TCCR1B,ICES1);
		if (getbit(TIFR,ICF1)) {
			flag ++ ;
			start = (ICR1L|(ICR1H<<8) );
			setbit(TIFR,ICF1);
			}	
		while (flag==1){
			clrbit(TCCR1B,ICES1);
			if (getbit(TIFR,ICF1)) {
				flag ++ ;
				end = (ICR1L|(ICR1H<<8) );
				setbit(TIFR,ICF1);
				DIO_WritePin(PIN14,LOW);
				DIO_WritePin(PIN13,HIGH);
			}
		}
	}
	
     if (flag ==2 ){
	     time = (end-start) *0.000128 ; //in seconds 
		 distance = 34300*time/2 ;
	     flag = 0;
	     TCNT1H = 0x00;
	     TCNT1L = 0x00;
	     ICR1H  = 0x00;
	     ICR1L  = 0x00;	 
     }
	return distance ; //in cm
} 

void us_detect (void)
{
uint16 start=0 , end=0,time=0,distance=0,flag = 0;

DIO_WritePin(trig,HIGH);
_delay_us(10);
DIO_WritePin(trig,LOW);

//while (flag ==0 ){ 
	if (getbit(TIFR,ICF1)) { 
		//DIO_WritePin(PIN14,HIGH);
		//flag =2 ;
		//start = (ICR1L|(ICR1H<<8) );
		setbit(TIFR,ICF1);
		DIO_WritePin(PIN12,HIGH);
		//timer_delay(100);
		//DIO_WritePin(PIN14,LOW);
		
	//}	
}
else {DIO_WritePin(PIN12,LOW);}

}