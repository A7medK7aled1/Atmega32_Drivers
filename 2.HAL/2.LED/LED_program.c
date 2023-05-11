/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Lyer:HAL				*****************/
/*****************		SWC:LED					*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/

#include "STD_TYPES.h"
#include "LED_config.h"
#include "LED_interface.h"
#include "DIO_interface.h"



/****************************************************************/
/*		Func_Name: LED_voidLEDTurnOn							*/
/*		i/p Argument : LED_T *LED: Struct to LED Configuration	*/
/*		Return : void											*/
/****************************************************************/



void LED_voidLEDTurnOn(LED_T *LED)
{
	if(LED->Conn_Type==SRC)
	{
		DIO_voidSetPinValue(LED->Led_Port,LED->Led_Pin,HIGH);
	}
	else if(LED->Conn_Type==SINK)
	{
		DIO_voidSetPinValue(LED->Led_Port,LED->Led_Pin,LOW);
	}

}



/****************************************************************/
/*		Func_Name: LED_voidLEDTurnOff							*/
/*		i/p Argument : LED_T *LED: Struct to LED Configuration	*/
/*		Return : void											*/
/****************************************************************/
void LED_voidLEDTurnOff(LED_T *LED)
{
	if(LED->Conn_Type==SRC)
	{
		DIO_voidSetPinValue(LED->Led_Port,LED->Led_Pin,LOW);
	}
	else if(LED->Conn_Type==SINK)
	{
		DIO_voidSetPinValue(LED->Led_Port,LED->Led_Pin,HIGH);
	}
}

