/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:MCAL				*****************/
/*****************		SWC:DIO					*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/



#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_



#define  PORTA			0
#define  PORTB			1
#define  PORTC			2
#define  PORTD			3

#define PIN0            0
#define PIN1            1
#define PIN2            2
#define PIN3            3
#define PIN4            4
#define PIN5            5
#define PIN6            6
#define PIN7            7

#define INPUT			0
#define OUTPUT			1

#define HIGH			1
#define LOW				0

#define PORT_HIGH       0xff
#define PORT_LOW        0


#define PORT_OUTPUT       0xff
#define PORT_INPUT        0




/****************************************************************/
/*		Func_Name: DIO_voidSetPinValue							*/
/*		i/p Argument : Copy_u8Port: PORTA,POARTB,PORTC,PORTD	*/
/*		Copy_u8Pin :PIN0-->PIN7									*/
/*		Copy_u8Value : HIGH , LOW  								*/
/*		Return : void											*/
/****************************************************************/

void DIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);




/****************************************************************/
/*		Func_Name: DIO_voidSetPinDirection						*/
/*		i/p Argument : Copy_u8Port: PORTA,POARTB,PORTC,PORTD	*/
/*		Copy_u8Pin :PIN0-->PIN7									*/
/*		Copy_u8Value : INPUT , OUTPUT  							*/
/*		Return : void											*/
/****************************************************************/

void DIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PinDirection);



/****************************************************************/
/*		Func_Name: DIO_u8GetPinValue							*/
/*		i/p Argument : Copy_u8Port: PORTA,POARTB,PORTC,PORTD	*/
/*		Copy_u8Pin :PIN0-->PIN7									*/
/*		Return : u8												*/
/****************************************************************/
u8 DIO_u8GetPinvalue(u8 Copy_u8Port,u8 Copy_u8Pin);


/****************************************************************/
/*		Func_Name: DIO_voidSetPortValue							*/
/*		i/p Argument : Copy_u8Port: PORTA,POARTB,PORTC,PORTD	*/
/*		Copy_u8Value :PORT_HIGH,PORT_LOW						*/
/*		Return : void											*/
/****************************************************************/
void DIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value);


/****************************************************************/
/*		Func_Name: DIO_voidSetPortDirection						*/
/*		i/p Argument : Copy_u8Port: PORTA,POARTB,PORTC,PORTD	*/
/*		Copy_u8Value :PORT_OUTPUT,PORT_INPUT					*/
/*		Return : void											*/
/****************************************************************/
void DIO_voidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8PinDirection);


/****************************************************************/
/*		Func_Name: DIO_u8GetPortValue							*/
/*		i/p Argument : Copy_u8Port: PORTA,POARTB,PORTC,PORTD	*/					
/*		Return : u8												*/
/****************************************************************/
u8 DIO_u8GetPortValue(u8 Copy_u8Port);









#endif
