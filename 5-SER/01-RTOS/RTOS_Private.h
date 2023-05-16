/*
 * RTOS_Private.h
 *
 *  Created on: Apr 19, 2023
 *      Author: akhaled
 */

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

typedef struct
{
	u16 Preiodicity;
	void (*Copy_pvTaskFunc)(void);

}Task_T;

static void voidScheduler(void);

#endif /* RTOS_PRIVATE_H_ */
