/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:MCAL				*****************/
/*****************		SWC:TIMER0				*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/

#ifndef TIMER_REGISTERS_H_
#define TIMER_REGISTERS_H_

			/*TIMER 0 Registers*/


#define TCCR0				*((volatile u8*)0x53)		/*TIMER 0 Register to chose Options*/

#define TCCR0_CS00			0                           /*Clock Select prescaler*/
#define TCCR0_CS01			1                           /*Clock Select Prescaler*/
#define TCCR0_CS02			2                           /*Clock Select Prescaler*/
#define TCCR0_WGM01			3                           /*Waveform Generation Mode */
#define TCCR0_COM00			4                           /*Compare Match Output Mode*/
#define TCCR0_COM01			5                           /*Compare Match Output Mode*/
#define TCCR0_WGM00			6                           /*Waveform Generation Mode*/
#define TCCR0_FOC0			7                           /*Force Compare Match Event*/



#define TCNT0               *((volatile u8*)0x52)		/*Overflow and Preload Register*/

#define OCR0                *((volatile u8*)0x5c)		/*Compare Match value*/
#define TIMSK               *((volatile u8*)0x59)		/*Timer Interrupt*/

#define TIMSK_TOIE0			0							/*Overflow Interrupt*/
#define TIMSK_OCIE0			1							/*compare match interrupt*/

#define TIFR                *((volatile u8*)0x58)		/*Timer Flags*/

#define TIFR_TOV0			0							/*Overflow Mode Flag*/
#define TIFR_OCF0			1							/*Compare Match Mode Flag*/


#define SFIOR               *((volatile u8*)0x50)
#define SFIOR_PSR10			0

#endif /* TIMER_REGISTERS_H_ */
