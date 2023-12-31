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

	for(u8 i=PIN0; i<PIN8; i++){
		GPIO_voidSetPinMode(IOA, i, OUTPUT);
		GPIO_voidSetPinType(IOA, i, OUTPUT_PP);
		GPIO_voidSetPinSpeed(IOA, i, OUTPUT_LS);
	}
	while(1)
	{
		for(u8 j=PIN0; j<=PIN8; j++){
			GPIO_voidSetPinValue(IOA, j, HIGH);
			GPIO_voidSetPinValue(IOA, j-1, LOW);
			for(u32 i=0; i<3000000;i++){
				__asm("NOP");}}
		GPIO_voidSetPinValue(IOA, PIN7, LOW);

	}
}
