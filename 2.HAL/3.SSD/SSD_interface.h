/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Lyer:HAL				*****************/
/*****************		SWC:SSD					*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

typedef struct
{
	u8 SSD_Port;
	u8 Conn_Type;
	u8 SSD_Number;
	u8 SSD_Enable_Port;
	u8 SSD_Enable_Pin;
}SSD_T;

void SSD_voidTurnOn(SSD_T *SSD);
void SSD_voidTurnOff(SSD_T *SSD);


#endif
