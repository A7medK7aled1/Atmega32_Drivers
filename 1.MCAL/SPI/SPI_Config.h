/*
 * SPI_Config.h
 *
 *  Created on: Apr 19, 2023
 *      Author: akhaled
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*SEND_RECEIVE_TYPE Options
 * 				1-MSB_FIRST
				2-LSB_FIRST*/

#define SEND_RECEIVE_TYPE			LSB_FIRST


/*SCK_IDLE Option
 * 				1-IDLE_HIGH
				2-IDLE_LOW	*/

#define SCK_IDLE 					IDLE_HIGH


/*CLK_PHASE Options
 *				1-SAMPLE_FIRST
				2-SETUP_FIRST */
#define CLK_PHASE					SAMPLE_FIRST


/*DOUBLE_SPEED Options
 * 				1-SPEED_ON
				2-SPEED_OFF*/
#define DOUBLE_SPEED		SPEED_OFF


/*CLOCK_RATE Options
 * 				1-PRESCALER_4
               	2-PRESCALER_16
                3-PRESCALER_64
                4-PRESCALER_128

      Use This When Enable Double Speed
               1-DOU_PRESCALER_2
               2-DOU_PRESCALER_8
               3-DOU_PRESCALER_32
               4-DOU_PRESCALER_64 */



#define CLOCK_RATE			PRESCALER_128

#endif /* SPI_CONFIG_H_ */
