/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:HAL				*****************/
/*****************		SWC:LCD				    *****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


/*Options
 * 		1-BIT_4
 * 		2-BIT_8*/

#define LCD_MODE		BIT_4



#define LCD_DATA_PORT    PORTB

/*Use this when u in 4 Bit mode*/
#define LCD_DATA_PIN_4       PIN4
#define LCD_DATA_PIN_5       PIN5
#define LCD_DATA_PIN_6       PIN6
#define LCD_DATA_PIN_7       PIN7



#define LCD_CTRL_PORT    PORTC
#define LCD_RS_PIN		  PIN0
#define LCD_RW_PIN		  PIN1
#define LCD_E_PIN		  PIN2








#endif
