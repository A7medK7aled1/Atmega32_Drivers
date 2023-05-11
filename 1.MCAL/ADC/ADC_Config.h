/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:MCAL				*****************/
/*****************		SWC:ADC					*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*Options
 	 	 1-ADC_AREF
		 2-ADC_AVCC
		 3-ADC_INAREF	*/


#define ADC_REF_INIT		ADC_AVCC

/*Options
 	 	1-ADC_RES8
		2-ADC_RES10	*/

#define  ADC_RES			ADC_RES10




/*Options

  	 	1-ADC_DIV2
		2-ADC_DIV4
		3-ADC_DIV8
		4-ADC_DIV16
		5-ADC_DIV32
		6-ADC_DIV64
		7-ADC_DIV128
					*/

#define ADC_PRESCALER		ADC_DIV128

/*Options
 	 	 1-AUTO_TRIGGER
 	 	 2-SINGLE_CONVERSION
 	 	 	 	 	 	 	 */

#define ADC_CONVERSION			SINGLE_CONVERSION

/*Auto Trigger Mode Options
 * 						1-FREE_RUNNIG
						2-ANALOG_COMPARATOR
						3-EXTERNAL_INTE0
						4-TIMER_0_COMPARE_MATCH
						5-TIMER_0_OVERFLOW
						6-TIMER_COMPARE_MATCH_BB
						7-TIMER_1_OVERFLOW
						8-TIMER_1_CAPTURE_EVENT
									*/
#define ADC_AUTO_TRIG			FREE_RUNNIG

#define ADC_u32TimeOut  		50000

#endif
