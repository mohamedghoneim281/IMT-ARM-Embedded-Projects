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

	// Setting port A as output
	for (u8 i = PIN0; i < PIN8; i++)
	{
		GPIO_voidSetPinMode(IOA, i, OUTPUT);
		GPIO_voidSetPinType(IOA, i, OUTPUT_PP);
		GPIO_voidSetPinSpeed(IOA, i, OUTPUT_LS);
	}

	u8 snake_position = 0; // Current position of the snake
	u8 direction = 1;      // 1 for moving right, 0 for moving left

	while (1)
	{
		// Turning off all LEDs
		for (u8 i = PIN0; i < PIN8; i++)
		{
			GPIO_voidSetPinValue(IOA, i, LOW);
		}

		// Setting the current snake position HIGH
		GPIO_voidSetPinValue(IOA, snake_position, HIGH);

		// Delay to control the speed of the snake movement
		for (u32 i = 0; i < 100000; i++)
		{
			__asm("NOP");
		}

		// Update snake position based on the direction
		if (direction == 1) // Moving right
		{
			snake_position++;
			if (snake_position == 7)
			{
				direction = 0; // Change direction when reaching the rightmost LED (LED7)
			}
		}
		else // Moving left
		{
			snake_position--;
			if (snake_position == 0)
			{
				direction = 1; // Change direction when reaching the leftmost LED (LED0)
			}
		}
	}

	return 0;
}
