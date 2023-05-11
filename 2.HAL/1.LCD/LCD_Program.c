/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:HAL				*****************/
/*****************		SWC:LCD				    *****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"

void LCD_voidInit(void)
{

#if LCD_MODE == BIT_8
	DIO_voidSetPortDirection(LCD_DATA_PORT, PORT_OUTPUT);

	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, OUTPUT);

	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, OUTPUT);

	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_E_PIN, OUTPUT);

	_delay_ms(40);
	//font size and line
	LCD_voidSendCommand(0b00111000);
	//display enable and cursor
	LCD_voidSendCommand(0b00001100);
	//clear lcd
	LCD_voidSendCommand(1);
	_delay_ms(2);
	LCD_voidSendCommand(0b00000110);
	_delay_ms(2);

#elif LCD_MODE == BIT_4

	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_E_PIN, OUTPUT);

	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN_4, OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN_5, OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN_6, OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN_7, OUTPUT);

	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, LOW);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, LOW);

	_delay_ms(50);

	// Set interface to 4-bit mode
	LCD_voidSendCommand(0x33);
	LCD_voidSendCommand(0x32);
	LCD_voidSendCommand(0x28);
	LCD_voidSendCommand(0x0c);


//	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_4,HIGH);
//	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_5,LOW);
//	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_6,LOW);
//	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_7,LOW);



	LCD_voidSendCommand(1);
	_delay_ms(2);





#else
#error "Invalid LCD Mode"



#endif
}

void LCD_voidSendCommand(u8 Copy_u8Command)
{
#if LCD_MODE == BIT_8

	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,LOW);
	//RW
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,LOW);
	//command
	DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Command);
	//E
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,LOW);

#elif LCD_MODE == BIT_4

	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,LOW);

	//RW = 0
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,LOW);

	//High nibble
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_7,GET_BIT(Copy_u8Command,7));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_6,GET_BIT(Copy_u8Command,6));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_5,GET_BIT(Copy_u8Command,5));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_4,GET_BIT(Copy_u8Command,4));

	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, LOW);


	//Low nibble
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_7,GET_BIT(Copy_u8Command,3));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_6,GET_BIT(Copy_u8Command,2));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_5,GET_BIT(Copy_u8Command,1));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_4,GET_BIT(Copy_u8Command,0));

	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, LOW);


#endif
}

void LCD_voidSendData(u8 Copy_u8Data)
{
#if LCD_MODE == BIT_8
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,HIGH);
	//RW
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,LOW);
	//command
	DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Data);
	//E
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,LOW);

#elif LCD_MODE == BIT_4

	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,HIGH);
	//RW
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,LOW);

	//High nibble
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_7,GET_BIT(Copy_u8Data,7));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_6,GET_BIT(Copy_u8Data,6));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_5,GET_BIT(Copy_u8Data,5));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_4,GET_BIT(Copy_u8Data,4));

	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, LOW);


	//Low nibble
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_7,GET_BIT(Copy_u8Data,3));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_6,GET_BIT(Copy_u8Data,2));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_5,GET_BIT(Copy_u8Data,1));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_4,GET_BIT(Copy_u8Data,0));

	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, LOW);


#endif
}


void LCD_voidSendString(char* Copy_pString)
{
	u8 Local_u8Counter=0;
	while(Copy_pString[Local_u8Counter] != '\0')
	{
		LCD_voidSendData(Copy_pString[Local_u8Counter]);
		Local_u8Counter++;

		if(Local_u8Counter==15)
		{
			LCD_voidGoToXY(1,0);
		}



	}
}

void LCD_voidNumber(s32 Copy_u32Number)
{
	u32 Local_u32Reversed=1;
	if(Copy_u32Number<0)
	{
		LCD_voidSendData('-');
		Copy_u32Number=Copy_u32Number*-1;
	}
	else if(Copy_u32Number==0)
	{
		Local_u32Reversed=0;
	}
	while(Copy_u32Number!=0)
	{
		Local_u32Reversed=Local_u32Reversed*10+Copy_u32Number%10;
		Copy_u32Number/=10;
	}

	do
	{

		LCD_voidSendData((Local_u32Reversed%10)+'0');
		Local_u32Reversed/=10;
	}while(Local_u32Reversed!=1&&Local_u32Reversed!=0);

}





void LCD_voidSendNumber(f32 Copy_f32Number)
{
	s32 Local_u32Variable;
	Local_u32Variable=Copy_f32Number;
	if(Copy_f32Number==0,0)
	{
		LCD_voidNumber(0);
	}
	if(Local_u32Variable==Copy_f32Number)
	{
		LCD_voidNumber(Local_u32Variable=Copy_f32Number);
	}
	else
	{
		if(Copy_f32Number>0)
		{

			LCD_voidNumber(Local_u32Variable);
			Copy_f32Number=Copy_f32Number-Local_u32Variable;
			Copy_f32Number=Copy_f32Number*100;
			Local_u32Variable=Copy_f32Number;
			LCD_voidSendData('.');
			LCD_voidNumber(Local_u32Variable);
		}
		else
		{
			LCD_voidSendData('-');
			Local_u32Variable=Local_u32Variable*-1;

			LCD_voidNumber(Local_u32Variable);
			Copy_f32Number=Copy_f32Number+Local_u32Variable;
			Copy_f32Number=Copy_f32Number*100;
			Copy_f32Number=Copy_f32Number*-1;
			Local_u32Variable=Copy_f32Number;
			LCD_voidSendData('.');
			LCD_voidNumber(Local_u32Variable);

		}

	}


}

void LCD_voidWriteSprcialCharacter(u8* Copy_pu8Pattern ,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAddress=0;
	u8 Local_u8Iterator;
	// calculate cgram address where location write
	Local_u8CGRAMAddress=Copy_u8PatternNumber*8;

	//send cgram address command lcd with setting bit 6 from data sheet
	LCD_voidSendCommand(Local_u8CGRAMAddress+64);

	//write pattern in cgram
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		LCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
	}

	LCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);

	LCD_voidSendData(Copy_u8PatternNumber);


}

void LCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8Address;
	if(Copy_u8XPos==0)
	{
		// location is at first line
		Local_u8Address=Copy_u8YPos;
	}
	else if(Copy_u8XPos==1)
	{
		// location is at second line
		Local_u8Address=Copy_u8YPos+0x40;
	}
	//set bit number 7 at DDRAM of LCD then send command
	LCD_voidSendCommand(Local_u8Address+128);
}

