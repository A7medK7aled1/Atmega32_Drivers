/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:MCAL				*****************/
/*****************		SWC:ADC					*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define IDEL  						0
#define BUSY 						1

#define ADC_AREF					1
#define ADC_AVCC					2
#define ADC_INAREF					3

#define ADC_RES8					1
#define ADC_RES10					2



#define ADC_DIV2							1
#define ADC_DIV4							2
#define ADC_DIV8							3
#define ADC_DIV16							4
#define ADC_DIV32							5
#define ADC_DIV64							6
#define ADC_DIV128							7


#define FREE_RUNNIG							0b00000000
#define ANALOG_COMPARATOR					0b00100000
#define EXTERNAL_INTE0						0b01000000
#define TIMER_0_COMPARE_MATCH				0b01100000
#define TIMER_0_OVERFLOW					0b10000000
#define TIMER_COMPARE_MATCH_B				0b10100000
#define TIMER_1_OVERFLOW					0b11000000
#define TIMER_1_CAPTURE_EVENT				0b11100000



#define SINGLE_CHANNEL_ASYNCH				0
#define CHAIN_ASYNCH						1



#define ADCSRA_MASK							0b11111000
#define ADMUX_MASK							0b11100000
#define SFIOR_MASK							0b00011111







#define ADMUX    		   *((volatile u8*)0x27)		//ADC multiplecer selection register
#define ADMUX_REFS1			7							//reference selection bit1
#define	ADMUX_REFS0			6							//reference selection bit0
#define	ADMUX_ADLAR			5							//ADC left adjust result

#define ADCSRA    		   *((volatile u8*)0x26)		//ADC control and status register a

#define ADCSRA_ADEN			7							//ADC enable
#define ADCSRA_ADSC			6                           //start conversion
#define ADCSRA_ADATE		5                           //Auto trigger enable
#define ADCSRA_ADIF			4                           //Interruption flag
#define ADCSRA_ADIE			3                           //Interruption enable
#define ADCSRA_ADPS2		2                           //Prescaler bit2
#define ADCSRA_ADPS1		1                           //Prescaler bit1
#define ADCSRA_ADPS0		0                           //Prescaler bit0

#define SFIOR				*((volatile u8*)0x30)

#define ADCH    		   *((volatile u8*)0x25)		//ADC high register
#define ADCL    		   *((volatile u8*)0x24)       //ADC low register






#endif
