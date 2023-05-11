/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:MCAL				*****************/
/*****************		SWC:ADC					*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_





		/*Single Ended Input*/
#define ADC0						0
#define ADC1						1
#define ADC2						2
#define ADC3						3
#define ADC4						4
#define ADC5						5
#define ADC6						6
#define ADC7						7

	/*Postive_Negative_Gain*/
#define ADC0_ADC0_10				8
#define ADC1_ADC0_10				9
#define ADC0_ADC0_200				10
#define ADC1_ADC0_200				11
#define ADC2_ADC2_10				12
#define ADC3_ADC2_10				13
#define ADC2_ADC2_200				14
#define ADC3_ADC2_200				15

	/*Postive_Negative*/
#define ADC0_ADC1					16
#define ADC1_ADC1                   17
#define ADC2_ADC1                   18
#define ADC3_ADC1                   19
#define ADC4_ADC1                   20
#define ADC5_ADC1                   21
#define ADC6_ADC1                   22
#define ADC7_ADC1                   23
#define ADC0_ADC2                   24
#define ADC1_ADC2                   25
#define ADC2_ADC2                   26
#define ADC3_ADC2                   27
#define ADC4_ADC2                   28





void ADC_voidInit(void);
void ADC_Enabled(void);
void ADC_Disabled(void);

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel,u16* Copy_pu16Reading);
u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16* Copy_pu8Reading, void(*Copy_pvNotificationFunc)(void));




#endif

