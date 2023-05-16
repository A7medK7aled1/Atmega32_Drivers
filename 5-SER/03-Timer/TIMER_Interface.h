/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:MCAL				*****************/
/*****************		SWC:TIMER0				*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER0_voidInit(void);

void TIMER0_voidPreload(u8 Copy_u8PreloadValue);

void TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));

void TIMER0_voidCompMatchValue(u8 Copy_u8CompMatchValue);

void TIMER0_voidDelay_ms(u16 Copy_u16DelayValue);

u8 Counter0_u8GetCount(void);


void TINER0_voidPWM(u8 Copy_u8DutyCycleValue);

#endif /* TIMER_INTERFACE_H_ */
