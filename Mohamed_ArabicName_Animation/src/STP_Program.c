/***************************************************/
/* SWC : STP Driver                                */
/* Author : Mohamed Ghoneim                        */
/* Version : V 1.0                                 */
/* Date : 05 AUG 2023                              */
/* Description : SWC for Serial to Parallel        */
/***************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Interface.h"
#include "STK_Interface.h"

#include "STP_Interface.h"
#include "STP_Private.h"
#include "STP_Config.h"

void STP_voidInit(){
    GPIO_voidSetPinMode(STP_SERIAL_PIN, OUTPUT);
    GPIO_voidSetPinMode(STP_SH_CLK_PIN, OUTPUT);
    GPIO_voidSetPinMode(STP_ST_CLK_PIN1, OUTPUT);
    GPIO_voidSetPinMode(STP_ST_CLK_PIN2, OUTPUT);

    GPIO_voidSetPinType(STP_SERIAL_PIN, OUTPUT_PP);
    GPIO_voidSetPinType(STP_SH_CLK_PIN, OUTPUT_PP);
    GPIO_voidSetPinType(STP_ST_CLK_PIN1, OUTPUT_PP);
    GPIO_voidSetPinType(STP_ST_CLK_PIN2, OUTPUT_PP);

    GPIO_voidSetPinSpeed(STP_SERIAL_PIN, OUTPUT_LS);
    GPIO_voidSetPinSpeed(STP_SH_CLK_PIN, OUTPUT_LS);
    GPIO_voidSetPinSpeed(STP_ST_CLK_PIN1, OUTPUT_LS);
    GPIO_voidSetPinSpeed(STP_ST_CLK_PIN2, OUTPUT_LS);

}
void STP_voidSendSynch1(u8 Copy_u8Data){
u8 Local_u8Bit;
s8 Local_u8Counter;

for (Local_u8Counter = 7; Local_u8Counter>=0; Local_u8Counter--){
	//DS=Current Bit
    Local_u8Bit = GET_BIT(Copy_u8Data, Local_u8Counter);
    GPIO_voidSetPinValue(STP_SERIAL_PIN, Local_u8Bit);
//clck on shift clk pin]
GPIO_voidSetPinValue(STP_SH_CLK_PIN, HIGH);
STK_voidSetBusyWait(1);
GPIO_voidSetPinValue(STP_SH_CLK_PIN, LOW);
STK_voidSetBusyWait(1);

}
//clck on store bit
GPIO_voidSetPinValue(STP_ST_CLK_PIN1, HIGH);
STK_voidSetBusyWait(1);
GPIO_voidSetPinValue(STP_ST_CLK_PIN1, LOW);
STK_voidSetBusyWait(1);
}
void STP_voidSendSynch2(u8 Copy_u8Data){
u8 Local_u8Bit;
s8 Local_u8Counter;

//send data to stp1
for (Local_u8Counter = 7; Local_u8Counter>=0; Local_u8Counter--){
	//DS=Current Bit
    Local_u8Bit = GET_BIT(Copy_u8Data, Local_u8Counter);
    GPIO_voidSetPinValue(STP_SERIAL_PIN, Local_u8Bit);
//clck on shift clk pin]
GPIO_voidSetPinValue(STP_SH_CLK_PIN, HIGH);
STK_voidSetBusyWait(1);
GPIO_voidSetPinValue(STP_SH_CLK_PIN, LOW);
STK_voidSetBusyWait(1);

}
//shift data to stp 2
for (Local_u8Counter = 7; Local_u8Counter>=0; Local_u8Counter--){

    GPIO_voidSetPinValue(STP_SERIAL_PIN, LOW);
//clck on shift clk pin]
GPIO_voidSetPinValue(STP_SH_CLK_PIN, HIGH);
STK_voidSetBusyWait(1);
GPIO_voidSetPinValue(STP_SH_CLK_PIN, LOW);
STK_voidSetBusyWait(1);

}
//clck on store bit 2
GPIO_voidSetPinValue(STP_ST_CLK_PIN2, HIGH);
STK_voidSetBusyWait(1);
GPIO_voidSetPinValue(STP_ST_CLK_PIN2, LOW);
STK_voidSetBusyWait(1);
}
