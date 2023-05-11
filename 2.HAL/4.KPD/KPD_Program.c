/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:HAL				*****************/
/*****************		SWC:KPD					*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/

#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "KPD_Config.h"
#include "KPD_Interface.h"
#include "KPD_Private.h"

void KPD_voidInit(void)
{
	DIO_voidSetPinDirection(KPD_PORT,KPD_COLUMN0_PIN,OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_COLUMN1_PIN,OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_COLUMN2_PIN,OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_COLUMN3_PIN,OUTPUT);

	DIO_voidSetPinDirection(KPD_PORT,KPD_ROW0_PIN,INPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_ROW1_PIN,INPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_ROW2_PIN,INPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_ROW3_PIN,INPUT);

	DIO_voidSetPortValue(KPD_PORT,PORT_HIGH);




}

u8 KPD_u8GetPressedKey(void)
{

	u8 Local_u8PressedKey=KPD_NO_PRESSED_KEY;


	static u8 Local_u8KPDArr[ROW_NUM][COULMN_NUM]=KPD_ARR_VAL;

	u8 Local_u8ColumIndx,Local_u8RowIndx,Local_u8PinState;

	static u8 Local_u8KPDCoulmnArr[COULMN_NUM]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};

	static u8 Local_u8KPDArrRow[ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};


	for(Local_u8ColumIndx=0;Local_u8ColumIndx<COULMN_NUM;Local_u8ColumIndx++)
	{
		/*Active the coulm*/
		DIO_voidSetPinValue(KPD_PORT,Local_u8KPDCoulmnArr[Local_u8ColumIndx],LOW);


		for(Local_u8RowIndx=0;Local_u8RowIndx<ROW_NUM;Local_u8RowIndx++)
		{
			/*read current row*/
			Local_u8PinState=DIO_u8GetPinValue(KPD_PORT,Local_u8KPDArrRow[Local_u8RowIndx]);

			/*Check button is pressed*/
			if(LOW==Local_u8PinState)
			{
				Local_u8PressedKey=Local_u8KPDArr[Local_u8RowIndx][Local_u8ColumIndx];

				/*polling until the key is pressed*/
				while(LOW==Local_u8PinState)
				{
					Local_u8PinState=DIO_u8GetPinValue(KPD_PORT,Local_u8KPDArrRow[Local_u8RowIndx]);
				}

				return Local_u8PressedKey;

			}
		}


		DIO_voidSetPinValue(KPD_PORT,Local_u8KPDCoulmnArr[Local_u8ColumIndx],HIGH);
	}

	return Local_u8PressedKey;
}
