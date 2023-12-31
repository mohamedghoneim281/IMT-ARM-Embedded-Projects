/***************************************************/
/* SWC : STK Driver                                */
/* Author : Seif Hashad                            */
/* Version : V 1.0                                 */
/* Date : 05 AUG 2023                              */
/* Description : SWC for System Timer              */
/***************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_Interface.h"
#include "STK_Private.h"
#include "STK_Config.h"

u8 INTERVAL_FLAG_MODE = SINGLE_INTERVAL;         

static void (*GpF)(void) = NULL;

void STK_voidInit(void)
{
    /*Stop Timer*/
    CLR_BIT(STK_CTRL, 0);
    /*Stop Int*/
    CLR_BIT(STK_CTRL, 1);
    /*Clk Source of System Timer*/
    #if STK_CLK_SRC == AHB
        SET_BIT(STK_CTRL, 2);
    #elif STK_CLK_SRC == AHB_DIV_BY_8
        CLR_BIT(STK_CTRL, 2);
    #endif
	//STK_CTRL = 0;
}

void STK_voidSetBusyWait(u32 Copy_u32TicksCounts)
{
    /*1- Load the RELOAD value*/
    STK_LOAD = Copy_u32TicksCounts;

    /*2- Start Timer*/
    SET_BIT(STK_CTRL, 0);

    /*3- Poll on the COUNT Flag*/
    while(GET_BIT(STK_CTRL,16) == 0);   //while(!GET_BIT(STK_CTRL,16));

    /*4- Stop Timer*/
    CLR_BIT(STK_CTRL, 0);
    STK_LOAD = 0;
    STK_VAL = 0;
}

void STK_voidSetIntervalSingle(u32 Copy_u32TicksCounts, void (*Lpf)(void))
{
    //0-Stop Timer
	STK_LOAD = 0;
    STK_VAL = 0;
    /*1- Load the RELOAD value*/
    STK_LOAD = Copy_u32TicksCounts;

    /*2- Start Timer*/
    SET_BIT(STK_CTRL, 0);

    /*3- Save Callback*/
    GpF = Lpf;

    /*4- Single Mode*/
    INTERVAL_FLAG_MODE = SINGLE_INTERVAL;

    /*4- Enable Int*/
    SET_BIT(STK_CTRL, 1);
}

void STK_voidSetIntervalPeriodic(u32 Copy_u32TicksCounts, void (*Lpf)(void))
{
    /*1- Load the RELOAD value*/
    STK_LOAD = Copy_u32TicksCounts;

    /*2- Start Timer*/
    SET_BIT(STK_CTRL, 0);

    /*3- Save Callback*/
    GpF = Lpf;

    /*4- Periodic Mode*/
    INTERVAL_FLAG_MODE = PERIODIC_INTERVAL;

    /*4- Enable Int*/
    SET_BIT(STK_CTRL, 1);
}

u32  STK_u32GetElapsedTime(void)
{
    return(STK_LOAD - STK_VAL);
}

void  STK_u32GetRemaningTime(u32* RemaingTime)
{
    *RemaingTime = STK_VAL;
}

void SysTick_Handler()
{
    u8 Local_u8Temp = 0;
    if(INTERVAL_FLAG_MODE == SINGLE_INTERVAL)
    {
        /*Stop Timer*/
        CLR_BIT(STK_CTRL, 0);
        /*Stop Int*/
        CLR_BIT(STK_CTRL, 1);
        /*Zero in LOAD, VAL Registers*/
        STK_LOAD = 0;
        STK_VAL = 0;
    }
    /*Execute Action to be done after the time passed*/
    if(GpF != NULL)
    {
        GpF();
    }
    /*Clear the Flag of The Timer*/
    Local_u8Temp = GET_BIT(STK_CTRL, 16);
}
