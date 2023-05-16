/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:MCAL				*****************/
/*****************		SWC:TIMER0				*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*TIMER0_STATE Options
 * 			1-TIMER0_ENABLE
 * 			2-TIMER0_DISABLE*/

#define TIMER0_STATE		TIMER0_ENABLE

/*COUNTER0_MODE Options
 * 			1-COUNT_FALLING
			2-COUNT_RISING*/

#define COUNTER0_MODE		COUNT_FALLING


/*TIMER0_MODE Options
 * 			1-TIMER0_OVF
			2-TIMER0_PWM_PHASE
			3-TIMER0_CTC
			4-TIMER0_FAST_PWM
								*/


#define TIMER0_MODE			TIMER0_PWM_PHASE

/*OC0_PIN_CTC Options
 *
 * 		1-OC0_DISCONNECT
		2-OC0_TOGGLE
		3-OC0_CLR
		4-OC0_SET			*/



#define OC0_PIN_CTC				OC0_DISCONNECT




/*FAST_PWM_OUTPUT Options
 * 		1-OC0_DISCONNECT
 * 		2-SET_TOP_CLR_COMP
		3-CLR_TOP_SET_COMP
							*/


#define FAST_PWM_OUTPUT			SET_TOP_CLR_COMP


/*PHASE_PWM_OUTPUT Options
 * 		1-OC0_DISCONNECT
 * 		2-CLR_UP_SET_DOWN
		3-SET_UP_CLR_DOWN
							*/



#define PHASE_PWM_OUTPUT		SET_UP_CLR_DOWN



/*COUNTER_MODE Options
 * 		1-COUNT_FALLING
		2-COUNT_RISING
						*/

#define COUNTER_MODE			COUNT_FALLING


/*TIMER0_PRESCALER Options
 * 		1-PRESCALER_1
		2-PRESCALER_8
		3-PRESCALER_64
		4-PRESCALER_256
		5-PRESCALER_1024*/



#define TIMER_PRESCALER			PRESCALER_8



#endif
