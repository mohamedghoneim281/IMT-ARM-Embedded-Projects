#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
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
		for(u8 j=PIN4; j<PIN8; j++){
			// Turning off all LEDs
		for (u8 i = PIN0; i < PIN8; i++)
			{GPIO_voidSetPinValue(IOA, i, LOW);}
			//Light Divergence
			GPIO_voidSetPinValue(IOA, j, HIGH);
			GPIO_voidSetPinValue(IOA, PIN7-j, HIGH);
			for(u32 i=0; i<3000000;i++){
				__asm("NOP");}}
		for(u8 j=PIN7; j>PIN3; j--){
					// Turning off all LEDs
			for (u8 i = PIN0; i < PIN8; i++)
				{GPIO_voidSetPinValue(IOA, i, LOW);}
					//Light Convergence
				GPIO_voidSetPinValue(IOA, j, HIGH);
				GPIO_voidSetPinValue(IOA, PIN7-j, HIGH);
				for(u32 i=0; i<3000000;i++){
					__asm("NOP");}}


	}


}
