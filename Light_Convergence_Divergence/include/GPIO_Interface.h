/***************************************************/
/* SWC : GPIO Driver                               */
/* Author : Seif Hashad                            */
/* Version : V 1.0                                 */
/* Date : 28 Jul 2023                              */
/* Description : SWC for General Purpose I/O       */
/***************************************************/
/*File Gaurd*/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

void GPIO_voidSetPinMode(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinMode);
void GPIO_voidSetPinType(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinType);
void GPIO_voidSetPinSpeed(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinSpeed);
void GPIO_voidSetPinPUPD(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinPUPDOption);
void GPIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue);
void GPIO_voidSetPinValueDirectAccess(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinSetMode);
u8   GPIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);

#define IOA           0
#define IOB           1
#define IOC           2

#define PIN0            0 
#define PIN1            1 
#define PIN2            2 
#define PIN3            3 
#define PIN4            4 
#define PIN5            5 
#define PIN6            6 
#define PIN7            7 
#define PIN8            8 
#define PIN9            9 
#define PIN10           10
#define PIN11           11
#define PIN12           12
#define PIN13           13
#define PIN14           14
#define PIN15           15

#define INPUT           0
#define OUTPUT          1
#define AF              2
#define ANALOG          3

#define OUTPUT_PP       0
#define OUTPUT_OD       1

#define OUTPUT_LS       0
#define OUTPUT_MS       1
#define OUTPUT_HS       2
#define OUTPUT_VHS      3

#define LOW             0
#define HIGH            1

#define RST             0
#define SET             1

#define FLOATING        0
#define PU              1
#define PD              2

#endif