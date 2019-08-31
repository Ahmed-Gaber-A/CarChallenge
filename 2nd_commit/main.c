

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>

#include "LIB/Bit_Math.h"
#include "Ultrasonic.h"
#include "Timer1.h"
#include "Interrupt.h"

#define enable            5
#define registerselection 6

void send_a_command(unsigned char command);
void send_a_character(unsigned char character);
void send_a_string(char *string_of_characters);

void Lcd_init(void);

static volatile int pulse = 0;
static volatile int i = 0;

int main(void)
{
    DDRA = 0xFF;
    DDRC = 0xFF;			//b>>>c
    DDRB = 0b11111011;
    DIO_SetPinDirection(TRIG,OUTPUT);
    DIO_SetPinDirection(ECHO,INPUT);
    _delay_ms(50);

    Ext2_Interrupt2_Enable();

    Ext2_Interrupt2_Mode(rising);

    Timer1_Normal();

    int16_t COUNTA = 0;

    char SHOWA [16];


    Lcd_init();

    Ultrasonic_Init();

    Global_Interrupt_Enable();

    while(1)
    {
        Ultrasonic_Trig();

        COUNTA = (pulse/58);
        send_a_string ("CIRCUIT DIGEST");
        send_a_command(0x80 + 0x40 + 0);
        send_a_string ("DISTANCE=");
        itoa(COUNTA,SHOWA,10);
        send_a_string(SHOWA);
        send_a_string ("cm    ");
        send_a_command(0x80 + 0);

    }
}

ISR(INT2_vect)
{
	 if (i==0)
	 {
		Timer1_init(8);
		i=1;
		Ext2_Interrupt2_Mode(falling);
	    }
	 else if (i==1)
    {
        Timer1_stop();
        pulse=TCNT1;
        TCNT1=0;
        i=0;
        Ext2_Interrupt2_Mode(rising);
    }
}

void Lcd_init(void)
{
	send_a_command(0x01); //Clear Screen 0x01 = 00000001
	    _delay_ms(50);
	    send_a_command(0x38);
	    _delay_ms(50);
	    send_a_command(0b00001111);
	    _delay_ms(50);
}

void send_a_command(unsigned char command)
{
    PORTC = command;		//b>>>c
    PORTB &= ~ (1<<registerselection);
    PORTB |= 1<<enable;
    _delay_ms(8);
    PORTB &= ~1<<enable;
    PORTC = 0;			//b>>>c
}

void send_a_character(unsigned char character)
{
    PORTC = character;			//b>>>c
    PORTB |= 1<<registerselection;
    PORTB |= 1<<enable;
    _delay_ms(8);
    PORTB &= ~1<<enable;
    PORTC = 0;				//b>>>c
}
void send_a_string(char *string_of_characters)
{
    while(*string_of_characters > 0)
    {
        send_a_character(*string_of_characters++);
    }
}
