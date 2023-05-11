#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DC_MOTOR_Interface.h"






void DCMOTOR_voidInit(DC_MOTORS *MOTOR)
{
	DIO_voidSetPinDirection(MOTOR->Motor_Port,MOTOR->Motor_Pin1,OUTPUT);
	DIO_voidSetPinDirection(MOTOR->Motor_Port,MOTOR->Motor_Pin2,OUTPUT);

}

void DCMOTOR_voidClockWise(DC_MOTORS *MOTOR)
{
	DIO_voidSetPin(MOTOR->Motor_Port,MOTOR->Motor_Pin1,HIGH);
	DIO_voidSetPin(MOTOR->Motor_Port,MOTOR->Motor_Pin2,LOW);
}

void DCMOTOR_voidAntiClockWise(DC_MOTORS *MOTOR)
{
	DIO_voidSetPin(MOTOR->Motor_Port,MOTOR->Motor_Pin1,LOW);
	DIO_voidSetPin(MOTOR->Motor_Port,MOTOR->Motor_Pin2,HIGH);
}

void DCMOTOR_voidStop(DC_MOTORS *MOTOR)
{
	DIO_voidSetPin(MOTOR->Motor_Port,MOTOR->Motor_Pin1,LOW);
	DIO_voidSetPin(MOTOR->Motor_Port,MOTOR->Motor_Pin2,LOW);
}
