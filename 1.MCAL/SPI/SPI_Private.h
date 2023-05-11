/*
 * SPI_Private.h
 *
 *  Created on: Apr 19, 2023
 *      Author: akhaled
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR   					*((volatile u8*)0x2D)			/*SPI Control Register*/
#define SPCR_SPIE               7                               /*SPI Interrupt Enable*/
#define SPCR_SPE                6                               /*SPI Enable*/
#define SPCR_DORD               5                               /*Data Order*/
#define SPCR_MSTR               4                               /*Master/Slave Select*/
#define SPCR_CPOL               3                               /*Clock Polarity*/
#define SPCR_CPHA               2                               /*Clock Phase*/
#define SPCR_SPR1               1                               /*SPI Clock Rate bit 1*/
#define SPCR_SPR0               0                               /*SPI Clock Rate bit 0*/

#define SPSR   					*((volatile u8*)0x2E)			/*SPI Status Register*/
#define SPSR_SPIF  				7								/*SPI Interrupt Flag*/
#define SPSR_WCOL  				6								/*Write COLlision Flag*/
#define SPSR_SPI2X 				0								/*SPI Clock Rate bit 2*/

#define SPDR   					*((volatile u8*)0x2F)			/*SPI Data Register*/

#define SPCR_MASK				0b11111100

#define MSB_FIRST				0
#define LSB_FIRST			    1

#define IDLE_HIGH				1
#define IDLE_LOW				0

#define SAMPLE_FIRST			0
#define SETUP_FIRST				1

#define SPEED_ON				1
#define SPEED_OFF				0

#define PRESCALER_4              0
#define PRESCALER_16             1
#define PRESCALER_64             2
#define PRESCALER_128            3

#define DOU_PRESCALER_2              0
#define DOU_PRESCALER_8              1
#define DOU_PRESCALER_32             2
#define DOU_PRESCALER_64             3

#endif /* SPI_PRIVATE_H_ */
