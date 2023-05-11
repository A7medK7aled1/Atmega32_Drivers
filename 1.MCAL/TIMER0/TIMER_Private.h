/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:MCAL				*****************/
/*****************		SWC:TIMER0				*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define TIMER0_OVF						0
#define TIMER0_PWM_PHASE				1
#define TIMER0_CTC						2
#define TIMER0_FAST_PWM					3


/*CTC OC0 PIN*/
#define OC0_DISCONNECT					0
#define OC0_TOGGLE						1
#define OC0_CLR							2
#define OC0_SET							3


/*FAst PWM */
#define SET_TOP_CLR_COMP				2
#define CLR_TOP_SET_COMP				3

/*PWM Phase Correct */
#define CLR_UP_SET_DOWN					2
#define SET_UP_CLR_DOWN					3

/*Clock Prescaler*/
#define PRESCALER_1						1
#define PRESCALER_8						2
#define PRESCALER_64					3
#define PRESCALER_256					4
#define PRESCALER_1024					5

/*Counter Mode*/
#define COUNT_FALLING					6
#define COUNT_RISING					7


#define TCCR0_MASK						0b11111000

#define DISABLE_MASK					0b00000000

#define TIMER0_ENABLE					1

#define TIMER0_DISABLE					0

#endif /* TIMER_PRIVATE_H_ */
