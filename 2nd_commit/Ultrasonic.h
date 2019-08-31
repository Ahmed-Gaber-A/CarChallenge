/*
 * ultrasonic.h
 *
 *  Created on: Aug 30, 2019
 *      Author: Hossam-PC
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "LIB/Standard_Types.h"
#include "Gpio.h"
#include "Ultrasonic.h"
#include "util/delay.h"

#define TRIG		8   //WIFI_RESET
#define ECHO		10	 //Push_btn1

void Ultrasonic_Init(void);

void Ultrasonic_Trig(void);

#endif /* ULTRASONIC_H_ */
