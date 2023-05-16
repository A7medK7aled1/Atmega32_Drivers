#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_Interface.h"
#include "GIE_interface.h"

#include "RTOS_Config.h"
#include "RTOS_Interface.h"
#include "RTOS_Private.h"


Task_T SystemTask[TASK_NUM]={{NULL}};

static void voidScheduler(void)
{
	static u16 Local_u16TickCounter=0;
	u8 Local_u8TaskCounter;

	Local_u16TickCounter++;

	for(Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_NUM;Local_u8TaskCounter++)
	{
		if((Local_u16TickCounter % SystemTask[Local_u8TaskCounter].Preiodicity)==0)
		{
			if(SystemTask[Local_u8TaskCounter].Copy_pvTaskFunc != NULL)
			{
				SystemTask[Local_u8TaskCounter].Copy_pvTaskFunc();
			}
			else
			{
				/*Do Nothing*/
			}
		}
	}

}



void RTOS_voidStart(void)
{
	TIMER0_u8SetCallBack(&voidScheduler);
	GIE_voidEnable();
	TIMER0_voidInit();
	TIMER0_voidCompMatchValue(125);
}

u8 RTO_u8CreatTask(u8 Copy_u8Priority,u16 Copy_u16Priodicity,void (*Copy_pvTaskFunc)(void))
{
	SystemTask[Copy_u8Priority].Preiodicity=Copy_u16Priodicity;
	SystemTask[Copy_u8Priority].Copy_pvTaskFunc=Copy_pvTaskFunc;


}

