/*
 * RTOS_Interface.h
 *
 *  Created on: Apr 19, 2023
 *      Author: akhaled
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_


void RTO_voidInit(void);

u8 RTO_u8CreatTask(u8 Copy_u8Priority,u16 Copy_u16Priodicity,u16 Copy_u16FirtsDelay,void (*pf)(void));
#endif /* RTOS_INTERFACE_H_ */
