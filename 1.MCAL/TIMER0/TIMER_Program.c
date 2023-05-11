
/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:MCAL				*****************/
/*****************		SWC:TIMER0				*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_Interface.h"
#include "TIMER_Registers.h"
#include "TIMER_Config.h"
#include "TIMER_Private.h"


static void (*TIMER0_pvCallBackFunc)(void)=NULL;

void TIMER0_voidInit(void)
{
#if TIMER0_MODE == TIMER0_OVF

	/*Overflow Mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	/*Overflow Interrupt Enable */
	SET_BIT(TIMSK,TIMSK_TOIE0);

#elif TIMER0_MODE == TIMER0_PWM_PHASE

	/*PWM Phase Correct Mode*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	#if PHASE_PWM_OUTPUT == OC0_DISCONNECT

	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);

	#elif PHASE_PWM_OUTPUT == CLR_UP_SET_DOWN

	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

	#elif PHASE_PWM_OUTPUT == SET_UP_CLR_DOWN

	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

	#endif


	/*Compare Match Mode*/
#elif TIMER0_MODE == TIMER0_CTC

	/*Compare Match Mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*Overflow Interrupt Enable */
	SET_BIT(TIMSK,TIMSK_OCIE0);

	#if OC0_PIN_CTC == OC0_DISCONNECT

	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);



	#elif OC0_PIN_CTC == OC0_TOGGLE

	SET_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);


	#elif OC0_PIN_CTC == OC0_CLR

	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

	#elif OC0_PIN_CTC == OC0_SET

	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

	#endif

#elif TIMER0_MODE == TIMER0_FAST_PWM

	/*Fast PWM Mode*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	#if FAST_PWM_OUTPUT == OC0_DISCONNECT

	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);

	#elif FAST_PWM_OUTPUT == SET_TOP_CLR_COMP

	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);



	#elif FAST_PWM_OUTPUT == CLR_TOP_SET_COMP

	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);



	#endif

#else
#error "Wrong TIMER0_MODE Options "

#endif

#if TIMER0_STATE == TIMER0_ENABLE

/*Chose Timer Prescaler*/
TCCR0 &= TCCR0_MASK;
TCCR0 |= TIMER_PRESCALER;

#elif TIMER0_STATE == TIMER0_DISABLE

TCCR0 &= TCCR0_MASK;
TCCR0 |= DISABLE_MASK;

#endif
}


void TIMER0_voidCompMatchValue(u8 Copy_u8CompMatchValue)
{
	OCR0=Copy_u8CompMatchValue;
}




void TIMER0_voidPreload(u8 Copy_u8PreloadValue)
{
	TCNT0=Copy_u8PreloadValue;
}


void TINER0_voidPWM(u8 Copy_u8DutyCycleValue)
{

	OCR0=Copy_u8DutyCycleValue;
}


u8 Counter0_u8GetCount(void)
{
	u8 Local_u8Counter;
#if COUNTER0_MODE == COUNT_FALLING
	TCCR0 &= TCCR0_MASK;
	TCCR0 |= COUNT_FALLING;



#elif COUNTER0_MODE ==COUNT_RISING

	TCCR0 &= TCCR0_MASK;
	TCCR0 |= COUNT_RISING;


#endif

	Local_u8Counter=TCNT0;

	return Local_u8Counter;


}


void TIMER0_voidDelay_ms(u16 Copy_u16DelayValue)
{
	u16 Local_u16Iterator;
	u8 flag;

	/*Set Timer Option to be in compare match mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	/*Chose 8 prescaler*/
	TCCR0 &= TCCR0_MASK;
	TCCR0 |= PRESCALER_8;
	/*Set Compare Match Value*/
	OCR0=250;
	/*Disable Compare Match Interrupt*/
	CLR_BIT(TIMSK,TIMSK_OCIE0);

	/*Every Iteration take 1ms then ii can get the time that user want*/

	for(Local_u16Iterator=0;Local_u16Iterator<=Copy_u16DelayValue;Local_u16Iterator++)
	{
		for(flag=0;flag<4;flag++)
		{
			while(!GET_BIT(TIFR,TIFR_OCF0))
			{

			}
			SET_BIT(TIFR,TIFR_OCF0);
		}


	}

}


void TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{

	TIMER0_pvCallBackFunc= Copy_pvCallBackFunc;

}




/*Interrupt Service Routine for Compare Match Mode*/
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{



	if(TIMER0_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc();
	}


}




/*Interrupt Service Routine for Overflow Mode*/

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{


	if(TIMER0_pvCallBackFunc!=NULL)
	{
			TIMER0_pvCallBackFunc();
	}


}
