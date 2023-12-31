/***************************************************/
/* SWC : Delay Driver                              */
/* Author : Mohamed Ghoneim                        */
/* Version : V 1.0                                 */
/* Date : 29 Jul 2023                              */
/* Description : Delay for a second using NOP      */
/***************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Delay_Interface.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"
void sec_delay(void){
for(u32 i=0; i<50;i++){
	asm("NOP");}}
