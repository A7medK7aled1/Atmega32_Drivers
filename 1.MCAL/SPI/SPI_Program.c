#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"


static u16* SPI_pu16Receving=NULL;
static void (*SPI_pvCallBackNotificationFunc)(void);
static u8 SPI_STATE=IDLE;

void SPI_voidMasterInit(void)
{
	DIO_voidSetPinDirection(PORTB,PIN4,INPUT);
	DIO_voidSetPinDirection(PORTB,PIN5,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN6,INPUT);
	DIO_voidSetPinDirection(PORTB,PIN7,OUTPUT);

#if SEND_RECEIVE_TYPE == LSB_FIRST
	SET_BIT(SPCR,SPCR_DORD);
#elif SEND_RECEIVE_TYPE == MSB_FIRST
	CLR_BIT(SPCR,SPCR_DORD);

#endif



#if SCK_IDLE == IDLE_HIGH
	SET_BIT(SPCR,SPCR_CPOL);
#elif SCK_IDLE == IDLE_LOW
	CLR_BIT(SPCR,SPCR_CPOL);
#endif



#if CLK_PHASE == SAMPLE_FIRST
	CLR_BIT(SPCR,SPCR_CPHA);
#elif CLK_PHASE == SETUP_FIRST
	SET_BIT(SPCR,SPCR_CPHA);
#endif

#if DOUBLE_SPEED == SPEED_ON
	SET_BIT(SPSR,SPSR_SPI2X);
#elif  DOUBLE_SPEED == SPEED_OFF
	CLR_BIT(SPSR,SPSR_SPI2X);
#endif

SPCR &= SPCR_MASK;
SPCR |= CLOCK_RATE;


	/*Master Select Mode*/
	SET_BIT(SPCR,SPCR_MSTR);


	/*SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);
}



void SPI_voidSlaveInit(void)
{
	DIO_voidSetPinDirection(PORTB,PIN4,INPUT);
	DIO_voidSetPinDirection(PORTB,PIN5,INPUT);
	DIO_voidSetPinDirection(PORTB,PIN6,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN7,INPUT);

#if SEND_RECEIVE_TYPE == LSB_FIRST
	SET_BIT(SPCR,SPCR_DORD);
#elif SEND_RECEIVE_TYPE == MSB_FIRST
	CLR_BIT(SPCR,SPCR_DORD);

#endif



#if SCK_IDLE == IDLE_HIGH
	SET_BIT(SPCR,SPCR_CPOL);
#elif SCK_IDLE == IDLE_LOW
	CLR_BIT(SPCR,SPCR_CPOL);
#endif



#if CLK_PHASE == SAMPLE_FIRST
	CLR_BIT(SPCR,SPCR_CPHA);
#elif CLK_PHASE == SETUP_FIRST
	SET_BIT(SPCR,SPCR_CPHA);
#endif


	/*Slave Select Mode*/
	CLR_BIT(SPCR,SPCR_MSTR);

	/*SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidSendData(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;

	while(GET_BIT(SPSR,SPSR_SPIF) == 0);





}

void SPI_voidAsynchSendData(u8 Copy_u8Data,void(*Copy_pvNotificationFunc)(void),u8* Copy_pu8Receive)
{
	if(SPI_STATE==IDLE)
	{

		if(Copy_pvNotificationFunc!=NULL)
		{
			SPI_STATE=BUSY;

			SPDR = Copy_u8Data;

			SPI_pu16Receving=Copy_pu8Receive;

			SPI_pvCallBackNotificationFunc=Copy_pvNotificationFunc;

			SET_BIT(SPCR,SPCR_SPIE);
		}

	}


}
u8 SPI_u8ReceiveData(void)
{

	while(GET_BIT(SPSR,SPSR_SPIF) == 0);	/* Wait till reception complete */
	return(SPDR);
}


void SPI_voidEnable(void)
{
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidDisable(void)
{
	CLR_BIT(SPCR,SPCR_SPE);
}



void __vector_12 (void)  __attribute__((signal));
void __vector_12 (void)
{

	
	*SPI_pu16Receving=SPDR;
	SPI_pvCallBackNotificationFunc();

	SPI_STATE=IDLE;

	/*Disable SPI Interrupt*/
	CLR_BIT(SPCR,SPCR_SPIE);

}

