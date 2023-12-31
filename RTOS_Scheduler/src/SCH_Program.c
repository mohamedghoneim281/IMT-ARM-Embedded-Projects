/***************************************************/
/* SWC : OS Driver                                 */
/* Author : Mohamed Ghoneim                        */
/* Version : V 1.0                                 */
/* Date : 02 Sep 2023                              */
/* Description : SWC for OS                        */
/***************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_Interface.h"
#include "SCH_Interface.h"
#include "SCH_Config.h"
#include "SCH_Private.h"
void SCH_voidCreateTask(u8 Copy_u8Priority, u32 Copy_u32Periodicity, u32 Copy_u32FirstDelay, void(*Lpf)(void)){
// Validation
if (Copy_u8Priority>NO_OF_TASKS){
    // DO Nothing
}
 Task[Copy_u8Priority].priodicty=Copy_u32Periodicity;
 Task[Copy_u8Priority].FirstDelay=Copy_u32FirstDelay;
Task[Copy_u8Priority].pf=Lpf;

}
void SCH_voidStartOS(){
//1-Init system clock
STK_voidInit();
//2-Scheudler functionality
STK_voidSetIntervalPeriodic(SCH_TICK_TIME, &Private_voidScheudlerStart);

}
void Private_voidScheudlerStart(){
    for(u8 Local_u8CopyCounter=0; Local_u8CopyCounter< NO_OF_TASKS; Local_u8CopyCounter++){
        if(Task[Local_u8CopyCounter].FirstDelay==0){
            Task[Local_u8CopyCounter].pf();
            Task[Local_u8CopyCounter].FirstDelay=Task[Local_u8CopyCounter].priodicty-1;
        }
        else{
            Task[Local_u8CopyCounter].FirstDelay--;
        }
    }
}
