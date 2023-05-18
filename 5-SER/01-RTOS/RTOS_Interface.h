/*
 * RTOS_Interface.h
 *
 *  Created on: Apr 19, 2023
 *      Author: akhaled
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_


void RTOS_voidStart(void);

u8 RTOS_u8CreatTask(u8 Copy_u8Priority,u16 Copy_u16Priodicity,void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay);

void RTOS_voidSuspendTask(u8 Copy_u8Priority);

void RTOS_voidResumTask(u8 Copy_u8Priority);

void RTOS_voidDeleteTask(u8 Copy_u8Priority);
#endif /* RTOS_INTERFACE_H_ */
