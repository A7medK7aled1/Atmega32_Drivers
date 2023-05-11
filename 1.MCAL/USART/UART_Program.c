#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_Interface.h"
#include "UART_Config.h"
#include "UART_Private.h"
#include "UART_Register.h"


static u8* USART_u8DataReceving=NULL;
static u8 SEND=IDLE;
static u8 Recieve=IDLE;
static u8 USART_u8DataSending=0;
static void (*USART_pvCallBackNotificationFunc[3])(void);


void USART_voidInit(void)
{
	u8 Local_u8UCSRC=0;

	SET_BIT(Local_u8UCSRC,UCSRC_URSEL);
#if USART_MODE == USART_ASYNCH

	CLR_BIT(Local_u8UCSRC,UCSRC_UMSEL);
	CLR_BIT(UCSRA,UCSRA_U2X);

#elif USART_MODE == USART_SYNCH
	SET_BIT(Local_u8UCSRC,UCSRC_UMSEL);
	CLR_BIT(UCSRA,UCSRA_U2X);
	SET_BIT(UCSRA,UCSRA_MPCM);

	#if CLOCK_POLARITY == TX_RISING_RX_FALLING

	CLR_BIT(Local_u8UCSRC,UCSRC_UCPOL);

	#elif CLOCK_POLARITY == TX_FALLING_RX_RISING

	SET_BIT(Local_u8UCSRC,UCSRC_UCPOL);

	#endif

#endif

#if	PARITY_MODE == PARITY_DISABLED

	CLR_BIT(Local_u8UCSRC,UCSRC_UPM0);
	CLR_BIT(Local_u8UCSRC,UCSRC_UPM1);

#elif PARITY_MODE == PARITY_EVEN

	CLR_BIT(Local_u8UCSRC,UCSRC_UPM0);
	SET_BIT(Local_u8UCSRC,UCSRC_UPM1);


#elif PARITY_MODE == PARITY_ODD

	SET_BIT(Local_u8UCSRC,UCSRC_UPM0);
	SET_BIT(Local_u8UCSRC,UCSRC_UPM1);

#endif

#if STOP_BIT == ONE_STOP_BIT

	CLR_BIT(Local_u8UCSRC,UCSRC_USBS);

#elif STOP_BIT == TWO_STOP_BIT

	SET_BIT(Local_u8UCSRC,UCSRC_USBS);

#endif


#if DATA_SIZE == DATA_5_BITS

	CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif DATA_SIZE == DATA_6_BITS

	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);


#elif DATA_SIZE == DATA_7_BITS

	CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif DATA_SIZE == DATA_8_BITS

	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif DATA_SIZE == DATA_9_BITS

	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	SET_BIT(UCSRB,UCSRB_UCSZ2);

#endif

	UCSRC=Local_u8UCSRC;

	CLR_BIT(Local_u8UCSRC,UCSRC_URSEL);
	UCSRC=Local_u8UCSRC;

	UBRRH = (u8) (51>>8);
	UBRRL = (u8)(51);

	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);


}

void USART_voidDisale(void)
{
	CLR_BIT(UCSRB,UCSRB_RXEN);
	CLR_BIT(UCSRB,UCSRB_TXEN);
}
void USART_voidEnable(void)
{
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);
}

void USART_voidDataSynchTransmit(u8 Copy_u8Data)
{
	while((GET_BIT(UCSRA,UCSRA_UDRE))==0);
	UDR=Copy_u8Data;






}
u8 USART_u8DataSynchReceive(void)
{
	while((GET_BIT(UCSRA,UCSRA_RXC))==0);
	return UDR;
}

void USART_voidBaudRate(u16 Copy_u16BaudRate)
{
	u8 Local_u8UCSRC=0;
	u16 Local_u16UBBR;
	CLR_BIT(UCSRA,UCSRA_U2X);

	Local_u16UBBR=(u16) (((SYSTEM_FREQUANCY)/ (16*Copy_u16BaudRate))-1);

	CLR_BIT(Local_u8UCSRC,UCSRC_URSEL);
	UCSRC=Local_u8UCSRC;

	UBRRH = (u8) (Local_u16UBBR>>8);
	UBRRL = (u8)(Local_u16UBBR);



}

void USART_voidDataASynchTransmit(u8 Copy_u8Data, void(*Copy_pvNotificationFunc)(void))
{
	if(SEND==IDLE)
	{
		SEND=BUSY;

		if(Copy_pvNotificationFunc==NULL)
		{
			/*Do Nothing*/
		}
		else
		{
			/*Take Data From User*/
			USART_u8DataSending=Copy_u8Data;

			USART_pvCallBackNotificationFunc[0]=Copy_pvNotificationFunc;

			/*Enable Empty Register Interrupt*/
			SET_BIT(UCSRB,UCSRB_UDRIE);

		}


	}
	else
	{
		/*Do Nothing*/
	}




}

void USART_voidDataASynchReceive(u8* Copy_pu8Data,void(*Copy_pvNotificationFunc)(void))
{
	if(Recieve==IDLE)
	{

		if(Copy_pvNotificationFunc==NULL || Copy_pu8Data==NULL)
		{
			/*Do Nothing*/
		}
		else
		{
			Recieve=BUSY;

			USART_u8DataReceving=Copy_pu8Data;

			USART_pvCallBackNotificationFunc[1]=Copy_pvNotificationFunc;

			/*Enable */
			SET_BIT(UCSRB,UCSRB_RXCIE);
		}

	}






}


void __vector_15 (void) __attribute__((signal));
void __vector_15 (void)
{
	USART_pvCallBackNotificationFunc[0]();
	SET_BIT(UCSRA,UCSRA_TXC);


}


void __vector_13 (void) __attribute__((signal));
void __vector_13 (void)
{


	*USART_u8DataReceving = UDR;
	Recieve=IDLE;
	USART_pvCallBackNotificationFunc[1]();

	CLR_BIT(UCSRB,UCSRB_RXCIE);


}








void __vector_14 (void) __attribute__((signal));
void __vector_14 (void)
{


	UDR=USART_u8DataSending;

	SEND=IDLE;

	USART_pvCallBackNotificationFunc[0]();


	CLR_BIT(UCSRB,UCSRB_UDRIE);


}
