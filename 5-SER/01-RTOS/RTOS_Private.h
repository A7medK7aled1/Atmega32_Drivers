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
	void (*TaskFunc)(void);
	u8 State;
	u16 FIrstDelay;

}Task_T;

static void voidScheduler(void);

#define TASK_RESUMED		0
#define TASK_SUSPENDED		1

#endif /* RTOS_PRIVATE_H_ */
