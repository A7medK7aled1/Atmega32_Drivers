/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:MCAL				*****************/
/*****************		SWC:TIMER1				*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TIMER1_OVF						0
#define TIMER1_PWM_PHASE				1
#define TIMER1_CTC						2
#define TIMER1_FAST_PWM					3




















#define TCCR1B_MASK						0b11111000

/*Clock Prescaler*/
#define PRESCALER_1						1
#define PRESCALER_8						2
#define PRESCALER_64					3
#define PRESCALER_256					4
#define PRESCALER_1024					5

/*Counter Mode*/
#define COUNT_FALLING					6
#define COUNT_RISING					7






















#endif
