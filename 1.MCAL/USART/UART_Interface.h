/*
 * UART_Interface.h
 *
 *  Created on: Apr 16, 2023
 *      Author: akhaled
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void USART_voidInit(void);

void USART_voidDisale(void);
void USART_voidEnable(void);

void USART_voidDataSynchTransmit(u8 Copy_u8Data);
u8 USART_u8DataSynchReceive(void);

void USART_voidDataASynchTransmit(u8 Copy_u8Data,void(*Copy_pvNotificationFunc)(void));
void USART_voidDataASynchReceive(u8* Copy_pu8Data,void(*Copy_pvNotificationFunc)(void));

void USART_voidBaudRate(u16 Copy_u16BaudRate);

#endif /* UART_INTERFACE_H_ */
