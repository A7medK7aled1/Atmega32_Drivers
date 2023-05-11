#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_Config.h"
#include "TWI_Interface.h"
#include "TWI_Private.h"
#include "TWI_Register.h"
#include "LCD_Interface.h"




void TWI_voidMasterInit(u8 Copy_u8MasterAddress)
{


	/*Set Prescaler*/
	TWSR &=PRESCALER_MASK;
	TWSR |=CLK_PRESCALER;

	/*BIT Rate Value*/
	TWBR=((F_CPU / SEND_SPEED) - 16) / (2 * power(4, CLK_PRESCALER));

	if(Copy_u8MasterAddress !=0)
	{
		TWAR= Copy_u8MasterAddress <<1 ;
	}


#if GENERAL_CALL == ENABLE
	SET_BIT(TWAR,TWAR_TWGCE);

#elif GENERAL_CALL == DISABLE
	CLR_BIT(TWAR,TWAR_TWGCE);

#endif

	/*Enable ACK*/
	SET_BIT(TWCR,TWCR_TWEA);

	/*Enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);

}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{

	TWAR=(Copy_u8SlaveAddress<<1);


#if GENERAL_CALL == ENABLE
	SET_BIT(TWAR,TWAR_TWGCE);

#elif GENERAL_CALL == DISABLE
	CLR_BIT(TWAR,TWAR_TWGCE);

#endif

	/*Enable ACK*/
	SET_BIT(TWCR,TWCR_TWEA);
	/*Enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
}

TWI_ErrStatus TWI_StartCondition(void)
{
	TWI_ErrStatus Local_ErrStatus =NoError;

	/*Send Start Condition*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*Clear TWI Interrupt Flag*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait the Flag is Set again*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check The Operation */
	if((TWSR & STATUS_MASK) != START_ACK)
	{
		Local_ErrStatus=StartConditionError;
	}

	return Local_ErrStatus;
}

TWI_ErrStatus TWI_RepeatStartCondition(void)
{
	TWI_ErrStatus Local_ErrStatus =NoError;

	/*Send Start Condition*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*Clear TWI Interrupt Flag*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait the Flag is Set again*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check The Operation */
	if((TWSR & STATUS_MASK) != REP_START_ACK)
	{
		Local_ErrStatus=RepeatedStartError;
	}

	return Local_ErrStatus;
}


void TWI_voidStopCondition(void)
{
	/*Send Stop Condition*/
	SET_BIT(TWCR,TWCR_TWSTO);

	/*Clear TWI Interrupt Flag*/
	SET_BIT(TWCR,TWCR_TWINT);

}

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Local_ErrStatus =NoError;



	/*Send Slave Address*/
	TWDR=Copy_u8SlaveAddress<<1;
	/*Send Read*/
	SET_BIT(TWDR,0);

	/*Clear Start Condition Bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Clear TWI Interrupt Flag*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait the Flag is Set again*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check The Operation */
	if((TWSR & STATUS_MASK) != SLAVE_ADD_AND_RD_ACK)
	{
		Local_ErrStatus=SlaveAddressReadError;
	}

	return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Local_ErrStatus =NoError;



	/*Send Slave Address*/
	TWDR=Copy_u8SlaveAddress<<1;
	/*Send Write*/
	CLR_BIT(TWDR,0);

	/*Clear Start Condition Bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Clear TWI Interrupt Flag*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait the Flag is Set again*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check The Operation */
	if((TWSR & STATUS_MASK) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrStatus=SlaveAddressWriteError;
	}

	return Local_ErrStatus;
}

TWI_ErrStatus TWI_MasterSendData(u8 Copy_u8Data)
{
	TWI_ErrStatus Local_ErrStatus =NoError;

	/*Write Data Byte */

	TWDR = Copy_u8Data;

	/*Clear TWI Interrupt Flag*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait the Flag is Set again*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check The Operation */
	if((TWSR & STATUS_MASK) != MSTR_WR_BYTE_ACK)
	{
		Local_ErrStatus=MasterWriteError;
	}


	return Local_ErrStatus;
}

TWI_ErrStatus TWI_MasterRecevingData(u8* Copy_pu8RecevingData)
{
	TWI_ErrStatus Local_ErrStatus =NoError;

	/*Clear TWI Interrupt Flag*/
	SET_BIT(TWCR,TWCR_TWINT);

	SET_BIT(TWCR,TWCR_TWEA);

	/*Wait the Flag is Set again*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check The Operation */
	if((TWSR & STATUS_MASK) != MSTR_RD_BYTE_WITH_ACK)
	{
		Local_ErrStatus=MasterReceiveError;
	}
	else
	{
		/*Read The Data*/
		*Copy_pu8RecevingData=TWDR;

	}



	return Local_ErrStatus;
}


TWI_ErrStatus TWI_MasterRecevingDataNACK(u8* Copy_pu8RecevingData)
{
	TWI_ErrStatus Local_ErrStatus =NoError;

	/*Clear TWI Interrupt Flag*/
	SET_BIT(TWCR,TWCR_TWINT);

	CLR_BIT(TWCR,TWCR_TWEA);

	/*Wait the Flag is Set again*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check The Operation */
	if((TWSR & STATUS_MASK) != MSTR_RD_BYTE_WITH_NACK)
	{
		Local_ErrStatus=MasterReceiveNACKError;
	}
	else
	{
		/*Read The Data*/
		*Copy_pu8RecevingData=TWDR;

	}



	return Local_ErrStatus;
}

static u32 power(u8 base, u8 exponent)
{
	f64 result = 1.0;
    u8 i;
    for(i = 1; i <= exponent; ++i) {
        result *= base;
    }
    return result;
}
