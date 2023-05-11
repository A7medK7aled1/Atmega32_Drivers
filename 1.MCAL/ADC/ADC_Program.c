/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:MCAL				*****************/
/*****************		SWC:ADC					*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"





static u16* ADC_pu16Reading=NULL;
static void (*ADC_pvCallBackNotificationFunc)(void);
u8 ADC_u8State=IDEL;



void ADC_voidInit(void)
{
	//Check Voltage Reference
#if ADC_REF_INIT==ADC_AVCC

	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif ADC_REF_INIT == ADC_AREF

	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif ADC_REF_INIT == ADC_INAREF

	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);

#else
#error "Wrong ADC Voltage Reference Configuration Option"
#endif


	//Check Left Or Right Adjust
#if ADC_RES == ADC_RES8

	SET_BIT(ADMUX,ADMUX_ADLAR);

#elif ADC_RES == ADC_RES10

	CLR_BIT(ADMUX,ADMUX_ADLAR);

#else
#error "Wrong ADC Resolution Configuration Option"
#endif

	//Prescaler Chose
	ADCSRA &= ADCSRA_MASK;
	ADCSRA |=ADC_PRESCALER;

	//Enable ADC
	SET_BIT(ADCSRA,ADCSRA_ADEN);

	ADMUX &= ADMUX_MASK;

#if ADC_CONVERSION == SINGLE_CONVERSION
	//Clear Interrupt Bit
	CLR_BIT(ADCSRA,ADCSRA_ADIE);

	//Clear Auto Trigger Bit
	CLR_BIT(ADCSRA,ADCSRA_ADATE);

#elif ADC_CONVERSION == AUTO_TRIGGER

	// Set Auto Trigger bit
	SET_BIT(ADCSRA,ADCSRA_ADATE);

	//Set Interrupt Enabled
	SET_BIT(ADCSRA,ADCSRA_ADIE);

	SFIOR &= SFIOR_MASK;
	SFIOR |= ADC_AUTO_TRIG;

	//Start Conversion
	SET_BIT(ADCSRA,ADCSRA_ADSC);

#else
#error "Wrong ADC Conversion Configuration Option"

#endif
}

void ADC_Enabled(void)
{
	SET_BIT(ADCSRA,ADCSRA_ADEN);			/*Enable ADC Peripheral*/
}


void ADC_Disabled(void)
{
	CLR_BIT(ADCSRA,ADCSRA_ADEN);			/*Disable ADC Peripheral*/
}

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel,u16* Copy_pu16Reading)
{
	u32 Local_u32Counter=0;				/*A counter to check the amount of time it takes for the flag to rise*/
	u8 Local_u8ErrorState=OK;			/*Check about the polling is finished because the flag is coming or the timeOut*/


	if(ADC_u8State==IDEL)
	{
		SET_BIT(ADCSRA,ADCSRA_ADEN);

		ADMUX &=ADMUX_MASK;				/*Clear Channel Bits*/
		ADMUX |=Copy_u8Channel;			/*Select the Channel*/


		SET_BIT(ADCSRA,ADCSRA_ADSC);	/*Make ADC Start Conversion*/

		/*polling until conversion complete flag is raising or TimeOut*/
		while((GET_BIT(ADCSRA,ADCSRA_ADIF)==0) && (Local_u32Counter<ADC_u32TimeOut))
		{
			Local_u32Counter++;
		}

		if(Local_u32Counter==ADC_u32TimeOut)		/*Check about Error State*/
		{
			Local_u8ErrorState=NOK;
		}
		else
		{
			/*clear ADC flag*/
			SET_BIT(ADCSRA,ADCSRA_ADIF);

			//Check The Resolution
			if(ADC_RES==ADC_RES8)					/*Left Adjust*/
			{
				/*return value*/
				*Copy_pu16Reading=ADCH;

			}
			else if(ADC_RES==ADC_RES10)				/*Right Adjust*/
			{

				/*return value*/
				*Copy_pu16Reading= ADCL | (ADCH << 8);

			}
		}
	}
	else
	{
		Local_u8ErrorState=BUSY_FUNC;
	}

	return Local_u8ErrorState;

}



u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16* Copy_pu8Reading, void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_uErrorState=OK;
	if(ADC_u8State== IDEL)
	{
		if((Copy_pu8Reading ==NULL) || (Copy_pvNotificationFunc == NULL))
		{
			Local_uErrorState= NULL_POINTER;
		}
		else
		{
			/*make ADC busy in order not to work until being idle*/
			ADC_u8State= BUSY;

			/*Initialize the reading variable globally*/
			ADC_pu16Reading = Copy_pu8Reading;

			/*Initialize the callback notification function globally*/
			ADC_pvCallBackNotificationFunc= Copy_pvNotificationFunc;

			/*Clear the MUX bits in ADMUX register*/
			ADMUX &= ADMUX_MASK;

			/*Set the required channel into the MUX bits*/
			ADMUX|= Copy_u8Channel;

			/*Start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*ADC interrupt enable*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
	}
	else
	{
		Local_uErrorState= BUSY_FUNC;
	}

	return Local_uErrorState;
}


void __vector_16 (void)  __attribute__((signal));
void __vector_16 (void)
{
	/*Read ADC result*/

	//Check The Resolution
	if(ADC_RES==ADC_RES8)					/*Left Adjust*/
	{
		/*return value*/
		*ADC_pu16Reading=ADCH;

	}
	else if(ADC_RES==ADC_RES10)				/*Right Adjust*/
	{

		/*return value*/
		*ADC_pu16Reading= ADCL | (ADCH << 8);

	}

	/*Make ADC state be IDLE because it finished*/
	ADC_u8State=IDEL;

	/*Invoke the callback notification function*/
	ADC_pvCallBackNotificationFunc();

	/*Disable ADC conversion complete interrupt*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}
