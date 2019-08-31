/*
 * Timer_cnfg.c
 *
 * Created: 18/08/2019 01:26:25 م
 *  Author: AhmedGaber
 */ 
#include "Timer.h"
 struct cnfg_type timer_cnfg = {
				 CTC,
				 64,
				 Disabled, //Compare Match Interrupt
				 Disabled , //overflow  Interrupt 
         	};