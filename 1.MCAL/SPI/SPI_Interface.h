/*
 * SPI_Interface.h
 *
 *  Created on: Apr 19, 2023
 *      Author: akhaled
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidMasterInit(void);

void SPI_voidSlaveInit(void);

void SPI_voidSendData(u8 Copy_u8Data);

u8 SPI_u8ReceiveData(void);




void SPI_voidAsynchSendData(u8 Copy_u8Data,void(*Copy_pvNotificationFunc)(void),u8* Copy_pu8Receive);

void SPI_voidEnable(void);

void SPI_voidDisable(void);

#endif /* SPI_INTERFACE_H_ */
