/*
 * TWI_Interface.h
 *
 *  Created on: Apr 27, 2023
 *      Author: akhaled
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum
{
	NoError,
	StartConditionError,
	RepeatedStartError,
	SlaveAddressWriteError,
	SlaveAddressReadError,
	MasterWriteError,
	MasterReceiveError,
	MasterReceiveNACKError

}TWI_ErrStatus;

/*If you don't want to give the master any address pass 0 in the argument*/
void TWI_voidMasterInit(u8 Copy_u8MasterAddress);

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);

void TWI_voidStopCondition(void);

TWI_ErrStatus TWI_RepeatStartCondition(void);


TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_MasterSendData(u8 Copy_u8Data);

TWI_ErrStatus TWI_MasterRecevingData(u8* Copy_pu8RecevingData);

TWI_ErrStatus TWI_MasterRecevingDataNACK(u8* Copy_pu8RecevingData);


#endif /* TWI_INTERFACE_H_ */
