/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Lyer:HAL				*****************/
/*****************		SWC:LED					*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

typedef struct
{
	u8 Led_Port;
	u8 Conn_Type;
	u8 Led_Pin;
}LED_T;


/****************************************************************/
/*		Func_Name: LED_voidLEDTurnOn							*/
/*		i/p Argument : LED_T *LED: Struct to LED Configuration	*/
/*		Return : void											*/
/****************************************************************/
void LED_voidLEDTurnOn(LED_T *LED);

/****************************************************************/
/*		Func_Name: LED_voidLEDTurnOff							*/
/*		i/p Argument : LED_T *LED: Struct to LED Configuration	*/
/*		Return : void											*/
/****************************************************************/
void LED_voidLEDTurnOff(LED_T *LED);

#endif
