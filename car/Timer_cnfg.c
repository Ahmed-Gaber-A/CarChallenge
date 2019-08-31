/*
 * Timer_cnfg.c
 *
 * Created: 18/08/2019 01:26:25 م
 *  Author: AhmedGaber
 */ 
#include "Timer.h"

/*
Modes ={ Normal_mode ,PWM_PhaseCorrect ,CTC ,Fast_PWM }
Prescaler = {no_prescaler ,8 ,64 ,256, 1024, XFE (external falling edge) ,XRE (external rising edge) } 
compare match interrupt {Enabled ,Disabled}
overflow interrupt {Enabled ,Disabled}
*/
 struct cnfg_type timer_cnfg = {
				 PWM_PhaseCorrect,
				 256,
				 Disabled, //Compare Match Interrupt
				 Disabled , //overflow  Interrupt 
         	};