/*
 * PWM.h
 *
 * Created: 27/08/2019 11:32:44 ص
 *  Author: AhmedGaber
 */ 


#ifndef PWM_H_
#define PWM_H_
#include "DIO.h"

#define Inverted 0 
#define Non_inverted 1

 
extern void pwm_init(void);
extern void pwm_write(uint8 speed);
#endif /* PWM_H_ */