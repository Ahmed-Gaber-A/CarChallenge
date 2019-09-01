/*
 * main.c
 *
 * Created: 26/08/2019 01:41:36 م
 *  Author: AhmedGaber
 */ 
#include "ICU.h"
#include "DIO.h"
#include "Timer.h"

/*
int main (){
	timer0_init();
	ICU_init();
	uint16 start=0 , end=0 ,delay_time=0,flag = 0;
	 DIO_SetPinDirection(PIN12,OUTPUT);
	 DIO_SetPinDirection(PIN13,OUTPUT);
	 DIO_SetPinDirection(PIN14,OUTPUT);
	 DIO_SetPinDirection(PIN30,INPUT);
	while (1){
		while (flag ==0 ){
			//while (getbit(TIFR,ICF1) == 0);
		if (getbit(TIFR,ICF1)) {
			flag ++ ; 
			start = (ICR1L|(ICR1H<<8) );
			setbit(TIFR,ICF1); 
			DIO_WritePin(PIN14,HIGH);
			DIO_WritePin(PIN13,LOW);
			DIO_WritePin(PIN12,LOW);
			
		}
		
		while (flag==1){
			if (getbit(TIFR,ICF1)) {
				flag ++ ;
				end = (ICR1L|(ICR1H<<8) );
				setbit(TIFR,ICF1); 
				DIO_WritePin(PIN14,LOW);
				DIO_WritePin(PIN13,HIGH);
				DIO_WritePin(PIN12,LOW);
				
		}
		
		}		
	}
	delay_time = (end - start)/8; 
	
	if (flag ==2 ){
		DIO_WritePin(PIN13,LOW);
		DIO_WritePin(PIN14,LOW);
		DIO_WritePin(PIN12,HIGH);
		timer_delay(delay_time);
		DIO_WritePin(PIN12,LOW);
		//timer_delay(delay_time);
		flag = 0;
		TCNT1H = 0x00;
		TCNT1L = 0x00;
		ICR1H  = 0x00;
		ICR1L  = 0x00;
		
		DIO_WritePin(PIN13,LOW);
		DIO_WritePin(PIN12,LOW);
	}
	
}
}

*/

extern void ultrasonic_init (void) ;
extern uint32 US_measure(void) ;
extern void us_detect (void);

int main () {
	
	
	DIO_SetPinDirection(PIN12,OUTPUT);
	DIO_SetPinDirection(PIN13,OUTPUT);
	DIO_SetPinDirection(PIN14,OUTPUT);
	
	DIO_SetPinDirection(PIN16,OUTPUT);
	DIO_SetPinDirection(PIN17,OUTPUT);
	DIO_SetPinDirection(PIN18,OUTPUT);
	uint16 distance ; //in cm
	ultrasonic_init();
	while (1){
		distance = US_measure();
		
		if ( distance >40 && distance  < 80) { //slow state 
			
			DIO_WritePin(PIN16,LOW);DIO_WritePin(PIN17,HIGH);DIO_WritePin(PIN18,LOW);
			DIO_WritePin(PIN12,LOW);DIO_WritePin(PIN13,HIGH);DIO_WritePin(PIN14,LOW);
			
		}
		else if ( distance  < 40) //stop state 
		{
			
			DIO_WritePin(PIN16,LOW);DIO_WritePin(PIN17,LOW);DIO_WritePin(PIN18,HIGH);
			DIO_WritePin(PIN12,LOW);DIO_WritePin(PIN13,LOW);DIO_WritePin(PIN14,HIGH);
		} 
		else  //normal state
		{
			
			DIO_WritePin(PIN16,HIGH);DIO_WritePin(PIN17,LOW);DIO_WritePin(PIN18,LOW);
			DIO_WritePin(PIN12,HIGH);DIO_WritePin(PIN13,LOW);DIO_WritePin(PIN14,LOW);
		} 
		
//us_detect ();
	}
	
	return 0 ;
}