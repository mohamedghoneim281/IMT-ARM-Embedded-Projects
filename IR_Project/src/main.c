#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"
#include "NVIC_Interface.h"
#include "EXTI_Interface.h"

void APP_voidGetFrame(void);
void APP_voidTakeAction(void);
void APP_voidPlay(void);

void main(void)
{
	/*Initialize System Clock*/
	RCC_voidInitSysClk();
	/*Enable Clock For GPIOA*/
	RCC_voidEnablePeripheralClk(AHB1, 0);
	/*Initialize The Pins*/
	GPIO_voidSetPinMode(IOA, PIN0, INPUT);
	GPIO_voidSetPinPUPD(IOA, PIN0,  FLOATING);        /* A0 -> EXTI0 */
	GPIO_voidSetPinMode(IOA, PIN5, OUTPUT);
	GPIO_voidSetPinType(IOA, PIN5, OUTPUT_PP);	 /* A1 -> RED   */
	GPIO_voidSetPinSpeed(IOA, PIN5, OUTPUT_LS);
	GPIO_voidSetPinMode(IOA, PIN6, OUTPUT);
	GPIO_voidSetPinType(IOA, PIN6, OUTPUT_PP);	 /* A2 -> BLUE  */
	GPIO_voidSetPinSpeed(IOA, PIN6, OUTPUT_LS);
	GPIO_voidSetPinMode(IOA, PIN7, OUTPUT);
	GPIO_voidSetPinType(IOA, PIN7, OUTPUT_PP);	 /* A3 -> GREEN */
	GPIO_voidSetPinSpeed(IOA, PIN7, OUTPUT_LS);

	/*Set EXTI0 Callback Function*/
	EXTI_voidSetEXTIpinConfig(EXTI_PA, EXTI_LINE_0);
	EXTI_voidSetCallBack(&APP_voidGetFrame);
	/*Initialize External Line*/
	EXTI_voidInit();
	/*Enable Interrupt for EXTI0*/
	EXTI_voidSetExtiLineEnable(EXTI_LINE_0);
	NVIC_voidEnablePeriInt(6);			// EXTI0
	/*Systick Initialize*/
	STK_voidInit();
	while(1)
	{

	}
}

u8   APP_u8StartFlag = 0;
u32  APP_u32ReceivedFrame[50] = {0};
u8   APP_u8EdgeCounter = 0;
u8   APP_u8Data = 0;
void APP_voidGetFrame(void)
{
	/*Check if the Received Edge The very first falling edge or not*/
	if(APP_u8StartFlag == 0)
	{
		/*Start Timer To Count The Ticks*/
		STK_voidSetIntervalSingle(1000000, &APP_voidTakeAction);
		APP_u8StartFlag = 1;
	}
	else
	{
		APP_u32ReceivedFrame[APP_u8EdgeCounter] = STK_u32GetElapsedTime();	//13500
		STK_voidSetIntervalSingle(1000000, &APP_voidTakeAction);
		APP_u8EdgeCounter++;
	}
}

void APP_voidTakeAction(void)
{
	APP_u8Data = 0;
	u8 Local_u8LoopCounter;
	if(APP_u32ReceivedFrame[0] >= 10000 && APP_u32ReceivedFrame[0] <= 15000 )
	{
		for(Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
		{
			if( (APP_u32ReceivedFrame[17+Local_u8LoopCounter] >= 1000) &&
					(APP_u32ReceivedFrame[17+Local_u8LoopCounter] <= 1500))
			{
				CLR_BIT(APP_u8Data, Local_u8LoopCounter);
			}
			else
			{
				SET_BIT(APP_u8Data, Local_u8LoopCounter);
			}
		}
		APP_voidPlay();
	}
	else
	{
		/*Invalid Frame*/
	}

	APP_u32ReceivedFrame[0] = 0;
	APP_u8EdgeCounter = 0;
	APP_u8StartFlag = 0;
}

void APP_voidPlay(void)
{
	switch(APP_u8Data)	//00001010
	{
	case 11:	//Data 12 ==> 1
		GPIO_voidSetPinValue(IOA, PIN5, HIGH);
		break;
	case 16:	//Data 24 ==> 2
		GPIO_voidSetPinValue(IOA, PIN6, HIGH);
		break;
	case 14:  //Data 74 ==> 9
		GPIO_voidSetPinValue(IOA, PIN7, HIGH);
		break;
	}
}





