/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Layer:MCAL				*****************/
/*****************		SWC:DIO					*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"




/****************************************************************/
/*		Func_Name: DIO_voidSetPinValue							*/
/*		i/p Argument : Copy_u8Port: PORTA,POARTB,PORTC,PORTD	*/
/*		Copy_u8Pin :PIN0-->PIN7									*/
/*		Copy_u8Value : HIGH , LOW  								*/
/*		Return : void											*/
/****************************************************************/




void DIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	if(Copy_u8Port>PORTD||Copy_u8Pin>PIN7 )
	{

	}
	else
	{
		switch(Copy_u8Value)
		{
		case LOW:
			switch(Copy_u8Port)
			{
			case PORTA:CLR_BIT(PORTA_REG,Copy_u8Pin);break;
			case PORTB:CLR_BIT(PORTB_REG,Copy_u8Pin);break;
			case PORTC:CLR_BIT(PORTC_REG,Copy_u8Pin);break;
			case PORTD:CLR_BIT(PORTD_REG,Copy_u8Pin);break;
			default:break;
			}
			break;

			case HIGH:
				switch(Copy_u8Port)
				{
				case PORTA:SET_BIT(PORTA_REG,Copy_u8Pin);break;
				case PORTB:SET_BIT(PORTB_REG,Copy_u8Pin);break;
				case PORTC:SET_BIT(PORTC_REG,Copy_u8Pin);break;
				case PORTD:SET_BIT(PORTD_REG,Copy_u8Pin);break;
				default:break;
				}
				break;

				default:break;
		}


	}

}


/****************************************************************/
/*		Func_Name: DIO_voidSetPinDirection						*/
/*		i/p Argument : Copy_u8Port: PORTA,POARTB,PORTC,PORTD	*/
/*		Copy_u8Pin :PIN0-->PIN7									*/
/*		Copy_u8Value : INPUT , OUTPUT  							*/
/*		Return : void											*/
/****************************************************************/
void DIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PinDirection)
{
	if(Copy_u8Port>PORTD||Copy_u8Pin>PIN7 )
	{

	}
	else
	{
		switch(Copy_u8PinDirection)
		{
		case INPUT:
			switch(Copy_u8Port)
			{
			case PORTA:CLR_BIT(DDRA_REG,Copy_u8Pin);break;
			case PORTB:CLR_BIT(DDRB_REG,Copy_u8Pin);break;
			case PORTC:CLR_BIT(DDRC_REG,Copy_u8Pin);break;
			case PORTD:CLR_BIT(DDRD_REG,Copy_u8Pin);break;
			default:break;
			}
			break;

			case OUTPUT:
				switch(Copy_u8Port)
				{
				case PORTA:SET_BIT(DDRA_REG,Copy_u8Pin);break;
				case PORTB:SET_BIT(DDRB_REG,Copy_u8Pin);break;
				case PORTC:SET_BIT(DDRC_REG,Copy_u8Pin);break;
				case PORTD:SET_BIT(DDRD_REG,Copy_u8Pin);break;
				default:break;
				}
				break;

				default:break;
		}


	}

}

/****************************************************************/
/*		Func_Name: DIO_u8GetPinValue							*/
/*		i/p Argument : Copy_u8Port: PORTA,POARTB,PORTC,PORTD	*/
/*		Copy_u8Pin :PIN0-->PIN7									*/
/*		Return : u8												*/
/****************************************************************/

u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8Value;

	switch(Copy_u8Port)
	{
	case PORTA : Local_u8Value = GET_BIT(PINA_REG,Copy_u8Pin);break;
	case PORTB : Local_u8Value = GET_BIT(PINB_REG,Copy_u8Pin);break;
	case PORTC : Local_u8Value = GET_BIT(PINC_REG,Copy_u8Pin);break;
	case PORTD : Local_u8Value = GET_BIT(PIND_REG,Copy_u8Pin);break;
	default:break;
	}

	return Local_u8Value;

}



/****************************************************************/
/*		Func_Name: DIO_voidSetPortValue							*/
/*		i/p Argument : Copy_u8Port: PORTA,POARTB,PORTC,PORTD	*/
/*		Copy_u8Value :PORT_HIGH,PORT_LOW						*/
/*		Return : void											*/
/****************************************************************/

void DIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
	case PORTA : PORTA_REG=Copy_u8Value;break;
	case PORTB : PORTB_REG=Copy_u8Value;break;
	case PORTC : PORTC_REG=Copy_u8Value;break;
	case PORTD : PORTD_REG=Copy_u8Value;break;
	default:break;
	}

}


/****************************************************************/
/*		Func_Name: DIO_voidSetPortDirection						*/
/*		i/p Argument : Copy_u8Port: PORTA,POARTB,PORTC,PORTD	*/
/*		Copy_u8Value :PORT_OUTPUT,PORT_INPUT					*/
/*		Return : void											*/
/****************************************************************/

void DIO_voidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8PinDirection)
{
	switch(Copy_u8Port)
	{
	case PORTA : DDRA_REG=Copy_u8PinDirection;break;
	case PORTB : DDRB_REG=Copy_u8PinDirection;break;
	case PORTC : DDRC_REG=Copy_u8PinDirection;break;
	case PORTD : DDRD_REG=Copy_u8PinDirection;break;
	default:break;
	}

}

/****************************************************************/
/*		Func_Name: DIO_u8GetPortValue							*/
/*		i/p Argument : Copy_u8Port: PORTA,POARTB,PORTC,PORTD	*/					
/*		Return : u8												*/
/****************************************************************/

u8 DIO_u8GetPortValue(u8 Copy_u8Port)
{
	u8 Local_u8Value;

	switch(Copy_u8Port)
	{
	case PORTA : Local_u8Value = PINA_REG;break;
	case PORTB : Local_u8Value = PINB_REG;break;
	case PORTC : Local_u8Value = PINC_REG;break;
	case PORTD : Local_u8Value = PIND_REG;break;
	default:break;
	}

	return Local_u8Value;

}
