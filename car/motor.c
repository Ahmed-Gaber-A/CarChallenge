#include "motor.h"
#include "DIO.h"

void motor_init(){

    DIO_SetPinDirection( PIN30 , OUTPUT ); //motor2 A dir
    DIO_SetPinDirection( PIN31 , OUTPUT ); //motor2 B dir

    DIO_SetPinDirection( PIN26 , OUTPUT ); //motor1 A dir
    DIO_SetPinDirection( PIN27 , OUTPUT ); //motor1 B dir

   // DIO_SetPinDirection( PIN29 , OUTPUT ); //motor1 en
   // DIO_SetPinDirection( PIN28 , OUTPUT ); //motor2 en

}

void motor_forward(){
    DIO_WritePin(PIN30 , HIGH);//motor2 A
    DIO_WritePin(PIN31 , LOW);//motor2 B 
	
    DIO_WritePin(PIN26 , HIGH);//motor1 A
    DIO_WritePin(PIN27 , LOW);//motor1 B
}

void motor_backward(){

    DIO_WritePin(PIN30 , LOW);//motor2 A
    DIO_WritePin(PIN31 , HIGH);//motor2 B 
    DIO_WritePin(PIN26 , LOW);//motor1 A
    DIO_WritePin(PIN27 , HIGH);//motor1 B
}

void motor_right(){
    DIO_WritePin(PIN30 , HIGH);//motor2 A
    DIO_WritePin(PIN31 , LOW);//motor2 B 
    DIO_WritePin(PIN26 , LOW);//motor1 A
    DIO_WritePin(PIN27 , HIGH);//motor1 B
}

void motor_left(){

    DIO_WritePin(PIN30 , LOW);//motor2 A
    DIO_WritePin(PIN31 , HIGH);//motor2 B 
    DIO_WritePin(PIN26 , HIGH);//motor1 A
    DIO_WritePin(PIN27 , LOW);//motor1 B
} 

void motor_stop(){

    DIO_WritePin(PIN30 , LOW);//motor2 A
    DIO_WritePin(PIN31 , LOW);//motor2 B 
    DIO_WritePin(PIN26 , LOW);//motor1 A
    DIO_WritePin(PIN27 , LOW);//motor1 B

}

