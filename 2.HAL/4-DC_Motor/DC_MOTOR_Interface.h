#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_

typedef struct
{
	u8 Motor_Port;
	u8 Motor_Pin1;
	u8 Motor_Pin2;


}DC_MOTORS;

void DCMOTOR_voidInit(DC_MOTORS *MOTOR);

void DCMOTOR_voidClockWise(DC_MOTORS *MOTOR);

void DCMOTOR_voidAntiClockWise(DC_MOTORS *MOTOR);

void DCMOTOR_voidStop(DC_MOTORS *MOTOR);

#endif
