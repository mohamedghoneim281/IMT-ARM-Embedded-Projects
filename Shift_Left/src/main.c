#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "Delay_Interface.h"
#include "GPIO_Interface.h"

int main()
{
	/*Init System Clock*/
	RCC_voidInitSysClk();
	/*Enable Clock for GPIOA*/
	RCC_voidEnablePeripheralClk(AHB1, 0);
	/*PORTA is OUTPUT, Push Pull, LS*/
	/*GPIO_voidSetPinMode(IOA, PIN0, OUTPUT);
	GPIO_voidSetPinType(IOA, PIN0, OUTPUT_PP);
	GPIO_voidSetPinSpeed(IOA, PIN0, OUTPUT_LS);
	GPIO_voidSetPinMode(IOA, PIN1, OUTPUT);
	GPIO_voidSetPinType(IOA, PIN1, OUTPUT_PP);
	GPIO_voidSetPinSpeed(IOA, PIN1, OUTPUT_LS);
	GPIO_voidSetPinMode(IOA, PIN2, OUTPUT);
	GPIO_voidSetPinType(IOA, PIN2, OUTPUT_PP);
	GPIO_voidSetPinSpeed(IOA, PIN2, OUTPUT_LS);
	GPIO_voidSetPinMode(IOA, PIN3, OUTPUT);
	GPIO_voidSetPinType(IOA, PIN3, OUTPUT_PP);
	GPIO_voidSetPinSpeed(IOA, PIN3, OUTPUT_LS);
	GPIO_voidSetPinMode(IOA, PIN4, OUTPUT);
	GPIO_voidSetPinType(IOA, PIN4, OUTPUT_PP);
	GPIO_voidSetPinSpeed(IOA, PIN4, OUTPUT_LS);
	GPIO_voidSetPinMode(IOA, PIN5, OUTPUT);
	GPIO_voidSetPinType(IOA, PIN5, OUTPUT_PP);
	GPIO_voidSetPinSpeed(IOA, PIN5, OUTPUT_LS);
	GPIO_voidSetPinMode(IOA, PIN6, OUTPUT);
	GPIO_voidSetPinType(IOA, PIN6, OUTPUT_PP);
	GPIO_voidSetPinSpeed(IOA, PIN6, OUTPUT_LS);
	GPIO_voidSetPinMode(IOA, PIN7, OUTPUT);
	GPIO_voidSetPinType(IOA, PIN7, OUTPUT_PP);
	GPIO_voidSetPinSpeed(IOA, PIN7, OUTPUT_LS);*/
	for(u8 i=PIN0; i<PIN8; i++){
		GPIO_voidSetPinMode(IOA, i, OUTPUT);
		GPIO_voidSetPinType(IOA, i, OUTPUT_PP);
		GPIO_voidSetPinSpeed(IOA, i, OUTPUT_LS);
	}
	while(1)
	{
		for(u8 j=PIN7; j>=PIN0; j--){
			GPIO_voidSetPinValue(IOA, j+1, LOW);
			GPIO_voidSetPinValue(IOA, j, HIGH);
			for(u32 i=0; i<3000000;i++){
				__asm("NOP");}}

	}
}
