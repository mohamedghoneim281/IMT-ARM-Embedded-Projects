#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"
#include "SCH_Interface.h"
void App_BlinkLed0();
void App_BlinkLed1();
void App_BlinkLed2();
void main(){
    RCC_voidInitSysClk();
    RCC_voidEnablePeripheralClk(AHB1,0);
    for(u8 i=0; i<3; i++){
        GPIO_voidSetPinMode(IOA, i, OUTPUT);
        GPIO_voidSetPinType(IOA, i, OUTPUT_PP);
        GPIO_voidSetPinSpeed(IOA, i, OUTPUT_LS);
    }
    SCH_voidCreateTask(0,1000,0,App_BlinkLed1);
    SCH_voidCreateTask(2,2000,0,App_BlinkLed2);
    SCH_voidCreateTask(1,4000,0,App_BlinkLed0);
    SCH_voidStartOS();
    while(1){

    }
}

void App_BlinkLed0(){
    static u8 Copy_u8LocalPinValue=0;
    if(Copy_u8LocalPinValue == 0){
        GPIO_voidSetPinValue(IOA, 0, Copy_u8LocalPinValue);
        Copy_u8LocalPinValue=1;
    }
    else{
        GPIO_voidSetPinValue(IOA, 0, Copy_u8LocalPinValue);
        Copy_u8LocalPinValue=0;
}
}
void App_BlinkLed1(){
    u8 Copy_u8LocalPinValue=0;
    if(Copy_u8LocalPinValue == 0){
        GPIO_voidSetPinValue(IOA, 1, Copy_u8LocalPinValue);
        Copy_u8LocalPinValue=1;
    }
    else{
        GPIO_voidSetPinValue(IOA, 1, Copy_u8LocalPinValue);
        Copy_u8LocalPinValue=0;
}
}
void App_BlinkLed2(){
    u8 Copy_u8LocalPinValue=0;
    if(Copy_u8LocalPinValue == 0){
        GPIO_voidSetPinValue(IOA, 2, Copy_u8LocalPinValue);
        Copy_u8LocalPinValue=1;
    }
    else{
        GPIO_voidSetPinValue(IOA, 2, Copy_u8LocalPinValue);
        Copy_u8LocalPinValue=0;
}
}
