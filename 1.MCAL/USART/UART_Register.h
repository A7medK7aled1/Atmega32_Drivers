/*
 * UART_Register.h
 *
 *  Created on: Apr 16, 2023
 *      Author: akhaled
 */

#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

#define UDR					*((volatile u8 *)0x2c)		/*UART Data Transmit and Receive Register */


#define UCSRA				*((volatile u8 *)0x2b)		/*UART Control Register*/
#define UCSRA_RXC			7							/*Receive Complete Flag*/
#define UCSRA_TXC			6							/*Transmit Complete Flag*/
#define UCSRA_UDRE			5							/*Data Register Empty Flag*/
#define UCSRA_FE			4							/*Frame Error Flag*/
#define UCSRA_DOR			3							/*Data OverRun Flag*/
#define UCSRA_PE			2							/*Parity Error Flag*/
#define UCSRA_U2X			1							/*Double Speed Mode Active Bit*/
#define UCSRA_MPCM			0							/*Multi Processor Mode*/

#define UCSRB				*((volatile u8 *)0x2a)		/*UART Control Register*/
#define UCSRB_RXCIE         7                           /*Receive  Complete Interrupt Enable*/
#define UCSRB_TXCIE         6                           /*Transmit  Complete Interrupt Enable*/
#define UCSRB_UDRIE         5                           /*Data Register Empty Interrupt Enable*/
#define UCSRB_RXEN          4                           /*Receiver Enable*/
#define UCSRB_TXEN          3                           /*Transmit Enable*/
#define UCSRB_UCSZ2         2                           /*Data Size Bit 2*/
#define UCSRB_RXB8          1                           /*9 Bit Receive Data*/
#define UCSRB_TXB8          0                           /*9 Bit Transmit Data*/

#define UCSRC				*((volatile u8 *)0x20)		/*UART Control and Status Register*/
#define UCSRC_URSEL			 7                          /*Register Select Between UBRRH/UCSRC*/
#define UCSRC_UMSEL          6                          /*UART Mode Select*/
#define UCSRC_UPM1           5                          /*Parity Mode Bit 0*/
#define UCSRC_UPM0           4                          /*Parity Mode Bit 1*/
#define UCSRC_USBS           3                          /*Stop Bit Select*/
#define UCSRC_UCSZ1          2                          /*Data Size Bit 1*/
#define UCSRC_UCSZ0          1                          /*Data Size Bit 0*/
#define UCSRC_UCPOL          0                          /*Clock Polarity*/


#define UBRRL				*((volatile u8 *)0x29)		/*Baud Rate Low Register*/
#define UBRRH				*((volatile u8 *)0x20)		/*Baud Rate High Register*/
#define UBRRH_URSEL			7							/*Register Select Between UBRRH/UCSRC*/







#endif /* UART_REGISTER_H_ */
