/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:MCAL				*****************/
/*****************		SWC:TIMER1				*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/

#ifndef TIMER1_REGISTERS_H_
#define TIMER1_REGISTERS_H_

#define TCCR1A						*((volatile u8*)0x4f)		/*TIMER 1 Channel A Register to chose Options*/

#define TCCR1A_WGM10				0							/*Waveform Generation Mode*/
#define TCCR1A_WGM11				1							/*Waveform Generation Mode*/
#define TCCR1A_FOC1B				2							/*Force Compare Match Event in Channel B*/
#define TCCR1A_FOC1A				3							/*Force Compare Match Event in Channel A*/
#define TCCR1A_COM1B0				4							/*Compare Output Mode for Channel B*/
#define TCCR1A_COM1B1				5							/*Compare Output Mode for Channel B*/
#define TCCR1A_COM1A0				6							/*Compare Output Mode for Channel A*/
#define TCCR1A_COM1A1				7							/*Compare Output Mode for Channel A*/



#define TCCR1B						*((volatile u8*)0x4e)		/*TIMER 1 Channel B Register to chose Options*/

#define TCCR1B_CS10			  	   0							/*Clock Select prescaler*/
#define TCCR1B_CS11                1                            /*Clock Select prescaler*/
#define TCCR1B_CS12                2                            /*Clock Select prescaler*/
#define TCCR1B_WGM12               3                            /*Waveform Generation Mode*/
#define TCCR1B_WGM13               4                            /*Waveform Generation Mode*/
#define TCCR1B_ICES1               6                            /*Input Capture Edge Select*/
#define TCCR1B_ICNC1               7							/*Input Capture Noise Canceler*/

#define TCNT1L						*((volatile u16*)0x4c)		 /*Overflow and Preload Register*/
#define OCR1AL 						*((volatile u16*)0x4a)       /*Compare Match value Channel A*/
#define OCR1BL 						*((volatile u16*)0x48)       /*Compare Match value Channel B*/
#define ICR1L 						*((volatile u16*)0x46)       /*Input Capture Unite Register*/


#define TIMSK            			*((volatile u8*)0x59)		/*Timer Interrupt*/

#define	TIMSK_TOIE1					2							/*TIMER1 Overflow Interrupt Enable*/
#define	TIMSK_OCIE1B                3                           /*Output Compare B Match Interrupt Enable*/
#define	TIMSK_OCIE1A                4                           /*Output Compare A Match Interrupt Enable*/
#define	TIMSK_TICIE1                5                           /*Input Capture Interrupt Enable*/

#define TIFR                		*((volatile u8*)0x58)		/*Timer Flags*/

#define	TIFR_TOV1					2                           /*Overflow Flag*/
#define TIFR_OCF1B                  3                           /* Output Compare B Match Flag*/
#define	TIFR_OCF1A                  4                           /* Output Compare A Match Flag*/
#define	TIFR_ICF1                   5                           /*Input Capture Flag*/





#endif
