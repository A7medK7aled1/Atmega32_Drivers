/*
 * UART_Config.h
 *
 *  Created on: Apr 16, 2023
 *      Author: akhaled
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_


/*USART_MODE Options
 * 			1-USART_ASYNCH
			2-USART_SYNCHO*/

#define USART_MODE			USART_ASYNCH



/*PARITY_MODE Options
 * 			1-PARITY_DISABLED
			2-PARITY_EVEN
			3-PARITY_ODD	*/

#define PARITY_MODE  		PARITY_DISABLED


/*STOP_BIT Options
 * 			1-ONE_STOP_BIT
			2-TWO_STOP_BIT	*/


#define STOP_BIT			ONE_STOP_BIT

/*DATA_SIZE Options
 * 			1-DATA_5_BITS
			2-DATA_6_BITS
			3-DATA_7_BITS
			4-DATA_8_BITS
			5-DATA_9_BITS		*/
#define DATA_SIZE			DATA_8_BITS



/*CLOCK_POLARITY Options
 * 				1-TX_RISING_RX_FALLING
				2-TX_FALLING_RX_RISING*/
#define CLOCK_POLARITY  	TX_RISING_RX_FALLING





#define SYSTEM_FREQUANCY				8000000









#endif /* UART_CONFIG_H_ */
