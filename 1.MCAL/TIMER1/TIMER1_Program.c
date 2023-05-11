/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:MCAL				*****************/
/*****************		SWC:TIMER1				*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER1_Interface.h"
#include "TIMER1_Config.h"
#include "TIMER1_Private.h"
#include "TIMER1_Registers.h"
#include "DIO_Interface.h"



static void (*TIMER1OVF_pvCallBackFunc)(void)=NULL;

static void (*TIMER1COMPA_pvCallBackFunc)(void)=NULL;

static void (*TIMER1COMPB_pvCallBackFunc)(void)=NULL;

static void (*TIMER1CAPTURE_pvCallBackFunc)(void)=NULL;


void TIMER1_voidInit(void)
{
#if	TIMER1_MODE == TIMER1_OVF

	/*Set Overflow Bits in TCCR1A and TCCR1B Registers*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);

	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);




#elif TIMER1_MODE == TIMER1_CTC

	/*Set Compare match Bits in TCCR1A and TCCR1B Registers*/


	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);

	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);




#elif TIMER1_MODE == TIMER1_PWM_PHASE

	/*Set PWM Phase Correct Bits in TCCR1A and TCCR1B Registers*/


	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);

	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);



#elif TIMER1_MODE == TIMER1_FAST_PWM

	/*Set Fast PWM TOP ICR1 Bits in TCCR1A and TCCR1B Registers*/


	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);

	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);





#endif

	/*Chose Timer Prescaler*/
	TCCR1B &= TCCR1B_MASK;
	TCCR1B |= TIMER_PRESCALER;

}


void TIMER1_voidPreload(u16 Copy_u16PreloadValue)
{
	TCNT1L=Copy_u16PreloadValue;
	/*Enable OverFlow Interrupt*/
	SET_BIT(TIMSK,TIMSK_TOIE1);
}

void TIMER1_voidCompMatchValueChannelA(u16 Copy_u16CompMatchValue)
{
	OCR1AL = Copy_u16CompMatchValue;
	/*Enable Compare Match Channel A Interrupt*/
	SET_BIT(TIMSK,TIMSK_OCIE1A);
}


void TIMER1_voidCompMatchValueChannelB(u16 Copy_u16CompMatchValue)
{
	OCR1BL = Copy_u16CompMatchValue;
	/*Enable Compare Match Channel B Interrupt*/
	SET_BIT(TIMSK,TIMSK_OCIE1B);
}



void TIMER1_voidDelay_ms(u16 Copy_u16DelayValue)
{
	u16 Local_u16Iterator;
	u8 flag;


	/*Set Timer Option to be in compare match mode*/

	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);

	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	/*Chose 1 prescaler*/

	TCCR1B &= TCCR1B_MASK;
	TCCR1B |= PRESCALER_8;

	/*Channel A CompareMatch*/
	OCR1AL=250;

	/*Disable Interrupt in Channel A*/

	CLR_BIT(TIMSK,TIMSK_OCIE1A);


	/*Every Iteration take 1ms then ii can get the time that user want*/

	for(Local_u16Iterator=0;Local_u16Iterator<=Copy_u16DelayValue;Local_u16Iterator++)
	{
		for(flag=0;flag<4;flag++)
		{
			while(!GET_BIT(TIFR,TIFR_OCF1A));

			SET_BIT(TIFR,TIFR_OCF1A);

		}

	}





}





void ICU_voidInit(void)
{
	SET_BIT(TCCR1B,TCCR1B_ICES1);

	SET_BIT(TIMSK,TIMSK_TICIE1);

}



void ICU_voidSetEdge(u8 Copy_u8ICUEdge)
{
	switch(Copy_u8ICUEdge)
	{
	case ICU_FALLING_EDGE : CLR_BIT(TCCR1B,TCCR1B_ICES1);break;
	case ICU_RISING_EDGE : SET_BIT(TCCR1B,TCCR1B_ICES1);break;
	}
}



void ICU_voidICUEnable(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1);

}

void ICU_voidICUDisable(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);

}



u16 ICU_u16ICUReading()
{
	return ICR1L;
}

void TIMER1OVF_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{

	TIMER1OVF_pvCallBackFunc= Copy_pvCallBackFunc;

}


void TIMER1COMPA_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{

	TIMER1COMPA_pvCallBackFunc= Copy_pvCallBackFunc;

}

void TIMER1COMPB_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{

	TIMER1COMPB_pvCallBackFunc= Copy_pvCallBackFunc;

}

void TIMER1CAPTURE_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{

	TIMER1CAPTURE_pvCallBackFunc= Copy_pvCallBackFunc;

}




void TIMER1_voidPWMChannelA(u16 Copy_u16DutyCycleValue,u16 Copy_u16PeriodTime)
{
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

	ICR1L=Copy_u16PeriodTime;
	OCR1AL=Copy_u16DutyCycleValue;

}



void TIMER1_voidPWMChannelB(u16 Copy_u16DutyCycleValue,u16 Copy_u16PeriodTime)
{
	/*SET on Top Clear On Compare*/
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

	ICR1L=Copy_u16PeriodTime;
	OCR1BL=Copy_u16DutyCycleValue;

}

/*ISR Overflow Event*/
void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{


	if(TIMER1OVF_pvCallBackFunc!=NULL)
	{
		TIMER1OVF_pvCallBackFunc();
	}


}


/*ISR Compare Match Channel B Event*/
void __vector_8 (void) __attribute__((signal));
void __vector_8 (void)
{
	if(TIMER1COMPB_pvCallBackFunc!=NULL)
	{
		TIMER1COMPB_pvCallBackFunc();
	}
}



/*ISR Compare Match Channel A Event*/
void __vector_7 (void) __attribute__((signal));
void __vector_7 (void)
{
	if(TIMER1COMPA_pvCallBackFunc!=NULL)
	{
		TIMER1COMPA_pvCallBackFunc();
	}
}




/*ISR Input Capture Unit Event*/
void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(TIMER1CAPTURE_pvCallBackFunc!=NULL)
	{
		TIMER1CAPTURE_pvCallBackFunc();
	}
}

