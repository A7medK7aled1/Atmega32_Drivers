/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:MCAL				*****************/
/*****************		SWC:TIMER1				*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/



#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#define ICU_FALLING_EDGE			0

#define ICU_RISING_EDGE				1



void ICU_voidICUEnable(void);

void ICU_voidICUDisable(void);

void TIMER1_voidInit(void);

void TIMER1_voidPreload(u16 Copy_u16PreloadValue);

void TIMER1OVF_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));

void TIMER1_voidCompMatchValueChannelA(u16 Copy_u16CompMatchValue);

void TIMER1_voidCompMatchValueChannelB(u16 Copy_u16CompMatchValue);


void TIMER1_voidDelay_ms(u16 Copy_u16DelayValue);

u8 Counter1_u8GetCount(void);

void TIMER1CAPTURE_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));

void TIMER1COMPB_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));

void TIMER1COMPA_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));


void TIMER1_voidPWMChannelA(u16 Copy_u16DutyCycleValue,u16 Copy_u16PeriodTime);

void TIMER1_voidPWMChannelB(u16 Copy_u16DutyCycleValue,u16 Copy_u16PeriodTime);

u16 ICU_u16ICUReading();

void ICU_voidInit(void);

void ICU_voidSetEdge(u8 Copy_u8ICUEdge);

#endif
