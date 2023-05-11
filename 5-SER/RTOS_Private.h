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
	u16 FirstDelay;
	u16 Preiodicity;
	void (*pf)(void);

}RTO_TCB;


#endif /* RTOS_PRIVATE_H_ */
