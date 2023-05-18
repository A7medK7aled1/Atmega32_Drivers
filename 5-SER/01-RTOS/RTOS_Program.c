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
	u8 Local_u8TaskCounter;

	Local_u16TickCounter++;

	for(Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_NUM;Local_u8TaskCounter++)
	{
		/*Check about Task Status is Resumed or Suspended*/
		if(SystemTask[Local_u8TaskCounter].State == TASK_RESUMED)
		{

			if(SystemTask[Local_u8TaskCounter].FirstDelay==0)
			{
				if(SystemTask[Local_u8TaskCounter].Copy_pvTaskFunc != NULL)
				{
					SystemTask[Local_u8TaskCounter].Copy_pvTaskFunc();

					SystemTask[Local_u8TaskCounter].FirstDelay=SystemTask[Local_u8TaskCounter].Preiodicity-1;
				}
				else
				{
					SystemTask[Local_u8TaskCounter].FirstDelay--;
				}
		
			}
		}
		else
		{
			/*Do Nothing*/
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

u8 RTOS_u8CreatTask(u8 Copy_u8Priority,u16 Copy_u16Priodicity,void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay)
{
	u8 Local_u8ErrorState=OK;

	/*Check if the required priority is empty or used*/
	if(SystemTask[Copy_u8Priority].TaskFunc==NULL)
	{
		SystemTask[Copy_u8Priority].Preiodicity=Copy_u16Priodicity;
		SystemTask[Copy_u8Priority].TaskFunc=Copy_pvTaskFunc;
		SystemTask[Copy_u8Priority].State= TASK_RESUMED;
		SystemTask[Copy_u8Priority].FirstDelay= Copy_u16FirstDelay;

	}
	else
	{
		Local_u8ErrorState=NOK;
	}




	return 	Local_u8ErrorState;

}



void RTOS_voidSuspendTask(u8 Copy_u8Priority)
{
	SystemTask[Copy_u8Priority].State=TASK_SUSPENDED;
}

void RTOS_voidResumTask(u8 Copy_u8Priority)
{
	SystemTask[Copy_u8Priority].State=TASK_RESUMED;

}



void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
	SystemTask[Copy_u8Priority].TaskFunc=NULL;
}

