/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:HAL				*****************/
/*****************		SWC:LCD				    *****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void LCD_voidInit(void);

void LCD_voidSendCommand(u8 Copy_u8Command);

void LCD_voidSendData(u8 Copy_u8Data);

void LCD_voidSendString(char* Copy_pString);

void LCD_voidNumber(s32 Copy_u32Number);

void LCD_voidSendNumber(f32 Copy_f32Number);

void LCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos);

void LCD_voidWriteSprcialCharacter(u8* Copy_pu8Pattern ,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);






#endif
