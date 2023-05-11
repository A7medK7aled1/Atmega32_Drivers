/*
 * TWI_Register.h
 *
 *  Created on: Apr 27, 2023
 *      Author: akhaled
 */

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_

#define TWBR					      *((volatile u8*)0x20)			/*TWI Bit Rate Register*/

#define TWCR					      *((volatile u8*)0x56)			/*TWI Control Register*/

#define TWCR_TWINT                     7                            /*TWI Interrupt Flag*/
#define TWCR_TWEA                      6                            /*TWI Enable Acknowledge Bit*/
#define TWCR_TWSTA                     5                            /*TWI START Condition Bit*/
#define TWCR_TWSTO                     4                            /*TWI STOP Condition Bit*/
#define TWCR_TWWC                      3                            /*TWI Write Collision Flag*/
#define TWCR_TWEN                      2                            /*TWI Enable Bit*/
#define TWCR_TWIE                      0                            /*TWI Interrupt Enable*/

#define TWSR					       *((volatile u8*)0x21)        /*TWI Status Register*/

#define TWDR					       *((volatile u8*)0x23)        /*TWI Data Register*/

#define TWAR					       *((volatile u8*)0x22)        /*TWI (Slave) Address Register*/
#define TWAR_TWGCE					   0							/*TWI General Call Recognition Enable Bit*/










#endif /* TWI_REGISTER_H_ */
