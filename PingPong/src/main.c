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

	// Setting port A as output
	for (u8 i = PIN0; i < PIN8; i++)
	{
		GPIO_voidSetPinMode(IOA, i, OUTPUT);
		GPIO_voidSetPinType(IOA, i, OUTPUT_PP);
		GPIO_voidSetPinSpeed(IOA, i, OUTPUT_LS);
	}

	u8 direction = 1; // 1 for LED0 to LED8, 0 for LED8 to LED0
	u8 LED_ID = 0;

	while (1)
	{
		// Setting the current LED (LED_ID) HIGH and the previous LED LOW
		GPIO_voidSetPinValue(IOA, LED_ID, HIGH);
		GPIO_voidSetPinValue(IOA, (LED_ID + 1) % 8, LOW);
		LED_ID += direction;

		// Reverse direction when reaching either end (LED0 or LED8)
		if (LED_ID == 0 || LED_ID == 7)
		{
			direction = !direction;
		}

		// Delay to control the speed of ping-pong effect
		for (u32 i = 0; i < 50000; i++)
		{
			__asm("NOP");
		}
	}

	return 0;
}
