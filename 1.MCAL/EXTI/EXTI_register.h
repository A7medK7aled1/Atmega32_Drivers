/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Lyer:MCAL				*****************/
/*****************		SWC:EXTI				*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define GICR				*((volatile u8*)0x5B)		/*General Interrupt Control in Enable or Disable*/
#define GICR_INT1			7							/*Enable or Disable for INT1*/
#define GICR_INT0			6                           /*Enable or Disable for INT0*/
#define GICR_INT2			5							/*Enable or Disable for INT2*/

#define GIFR				*((volatile u8*)0x5A)		/*General Interrupt Flag*/

#define MCUCR				*((volatile u8*)0x55)		/*Control External Interrupt (0,1) Sense Register*/
#define MCUCR_ISC11			3							/*Interrupt 1 Sense Control*/
#define MCUCR_ISC10			2							/*Interrupt 1 Sense Control*/
#define MCUCR_ISC01			1							/*Interrupt 0 Sense Control*/
#define MCUCR_ISC00			0							/*Interrupt 0 Sense Control*/

#define MCUCSR				*((volatile u8*)0x54)		/*Control External Interrupt2 Sense Register*/
#define MCUCSR_INT2			6							/*Interrupt Sense Control 2*/

#endif
