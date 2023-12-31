#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "Delay_Interface.h"
#include "GPIO_Interface.h"
void GPIO_voidSetLowerNibblePortValue(u8 Copy_u8PortId, u32 Copy_u8PortValue);
void DisplayNumberOn7SegmentA(u8 number) {
    // Seven-segment display lookup table for common anode configuration
    const u8 seven_seg_table[10] = {
    		0xc0, 0xf9, 0xa4, 0xb0, 0x99,
    		    0x92, 0x82, 0xf8, 0x80, 0x90
    };

    // Set the number to be displayed on the first 7-segment (Port A)
    GPIO_voidSetLowerNibblePortValue(IOA, seven_seg_table[number]);}
void DisplayNumberOn7SegmentB(u8 number) {
    // Seven-segment display lookup table for common anode configuration
    const u8 seven_seg_table[10] = {
    		0xc0, 0xf9, 0xa4, 0xb0, 0x99,
    		    0x92, 0x82, 0xf8, 0x80, 0x90
    };
    // Set the number to be displayed on the second 7-segment (Port B)
    GPIO_voidSetLowerNibblePortValue(IOB, seven_seg_table[number]);
    }
int main()
{
	/*Init System Clock*/
	RCC_voidInitSysClk();
	/*Enable Clock for GPIOA,B*/
	RCC_voidEnablePeripheralClk(AHB1, 0);
	RCC_voidEnablePeripheralClk(AHB1, 1);
	// Setting port A as output
	for (s8 i = PIN0; i < PIN15; i++)
		{
			GPIO_voidSetPinMode(IOA, i, OUTPUT);
			GPIO_voidSetPinType(IOA, i, OUTPUT_PP);
			GPIO_voidSetPinSpeed(IOA, i, OUTPUT_LS);}
	// Setting port B as output
	for (s8 i = PIN0; i < PIN15; i++)
		{
			GPIO_voidSetPinMode(IOB, i, OUTPUT);
			GPIO_voidSetPinType(IOB, i, OUTPUT_PP);
			GPIO_voidSetPinSpeed(IOB, i, OUTPUT_LS);}

	while(1)
	{	//First RED LIGHT
		GPIO_voidSetPinValue(IOA, PIN8, HIGH);
		for (s8 i = 3; i>=0; i--) {
			DisplayNumberOn7SegmentA(i);
		    for(s8 j=9; j>=0; j--){
		    	DisplayNumberOn7SegmentB(j);
		    	for(u32 i=0; i<3000000;i++){
		    		__asm("NOP");}
		    }
	}
		GPIO_voidSetPinValue(IOA, PIN8, LOW);
		//Second Green LIGHT
			GPIO_voidSetPinValue(IOA, PIN10, HIGH);
			for (s8 i = 3; i>=0; i--) {
				DisplayNumberOn7SegmentA(i);
			    for(s8 j=9; j>=0; j--){
			   	DisplayNumberOn7SegmentB(j);
			    	for(u32 i=0; i<3000000;i++){
			    		__asm("NOP");}
			    	//Third Yellow Light
			    	if(i==0 && j<6){
			    		GPIO_voidSetPinValue(IOA, PIN9, HIGH);
			    		//Enable the Buzzer
			    		GPIO_voidSetPinValue(IOB, PIN8, HIGH);
			    	}
			    	else{GPIO_voidSetPinValue(IOA, PIN9, LOW);
		    			 GPIO_voidSetPinValue(IOB, PIN8, LOW);}
			    }
		}
			GPIO_voidSetPinValue(IOA, PIN10, LOW);
			GPIO_voidSetPinValue(IOA, PIN9, LOW);
			GPIO_voidSetPinValue(IOB, PIN8, LOW);
}
}
