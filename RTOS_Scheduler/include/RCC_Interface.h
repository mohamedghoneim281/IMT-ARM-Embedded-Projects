/***************************************************/
/* SWC : RCC Driver                                */
/* Author : Seif Hashad                            */
/* Version : V 1.0                                 */
/* Date : 21 Jul 2023                              */
/* Description : SWC for Reset and Control Clock   */
/***************************************************/
/*File Gaurd*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*Functions Prototypes*/
void  RCC_voidInitSysClk(void);
void  RCC_voidEnablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);
void  RCC_voidDisablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);

/*Interface Macros*/
#define AHB1            0
#define AHB2            1
#define APB1            2
#define APB2            3


#endif