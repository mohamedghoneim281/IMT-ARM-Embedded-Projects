/*****************************************/
/* Author  :  Seif Hashad                */
/* Version :  V01                        */
/* Date    : 18 May 2023                 */
/*****************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void EXTI_voidInit();
void EXTI_voidSetExtiLineEnable(u8 Copy_u8LineId);
void EXTI_voidSetExtiLineDisable(u8 Copy_u8LineId);
void EXTI_voidSetSenseControl(u8 Copy_u8SenseControl, u8 Copy_u8LineId);
void EXTI_voidSetEXTIpinConfig(u8 Copy_u8PortId, u8 Copy_u8LineId);
void EXTI_voidSetEXTIConfiguration(u8 Copy_u8ExtiLine , u8 Copy_u8GpioPortNum );
void EXTI_voidSetCallBack(void (*LpF)(void));


#define FALLING_EDGE            0
#define RISING_EDGE             1
#define ON_CHANGE               2

#define EXTI_LINE_0             0
#define EXTI_LINE_1             1
#define EXTI_LINE_2             2
#define EXTI_LINE_3             3
#define EXTI_LINE_4             4
#define EXTI_LINE_5             5
#define EXTI_LINE_6             6
#define EXTI_LINE_7             7
#define EXTI_LINE_8             8
#define EXTI_LINE_9             9
#define EXTI_LINE_10            10
#define EXTI_LINE_11            11
#define EXTI_LINE_12            12
#define EXTI_LINE_13            13
#define EXTI_LINE_14            14
#define EXTI_LINE_15            15

/*Source Input for EXTIx*/
#define EXTI_PA                 0
#define EXTI_PB                 1
#define EXTI_PC                 2


#endif
