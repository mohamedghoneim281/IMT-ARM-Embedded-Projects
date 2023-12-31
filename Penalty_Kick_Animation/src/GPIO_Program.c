/***************************************************/
/* SWC : GPIO Driver                               */
/* Author : Seif Hashad                            */
/* Version : V 1.0                                 */
/* Date : 28 Jul 2023                              */
/* Description : SWC for General Purpose I/O       */
/***************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"

/******************************************************************************/
/* Func. Name : GPIO_voidSetPinMode                                           */
/* I/p Arguments : Copy_u8PortId Options: IOA, IOB, IOC                       */
/* I/p Arguments : Copy_u8PinId Options: PIN0 --> PIN15                       */
/* I/p Arguments : Copy_u8PinMode: INPUT, OUTPUT, AF, ANALOG                  */
/* Return : Nothing                                                           */
/* Desc. : This Api allows the user to Set the mode of any pin                */
/******************************************************************************/
void GPIO_voidSetPinMode(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinMode)  //(IOC, 3, ANALOG)
{
    /*i/p validation*/
    if((Copy_u8PortId > IOC) || (Copy_u8PinId > PIN15) || (Copy_u8PinMode > ANALOG))
    {
        /*Do Nothing*/
    }
    else
    {
        switch(Copy_u8PinMode)
        {
            case INPUT: switch(Copy_u8PortId)
                        {
                            case IOA:   CLR_BIT(GPIOA->MODER, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOA->MODER, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOB:   CLR_BIT(GPIOB->MODER, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOB->MODER, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOC:   CLR_BIT(GPIOC->MODER, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOC->MODER, ((Copy_u8PinId*2)+1));
                                        break;
                        }
                        break;
            case OUTPUT:switch(Copy_u8PortId)
                        {
                            case IOA:   SET_BIT(GPIOA->MODER, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOA->MODER, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOB:   SET_BIT(GPIOB->MODER, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOB->MODER, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOC:   SET_BIT(GPIOC->MODER, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOC->MODER, ((Copy_u8PinId*2)+1));
                                        break;
                        }
                        break;
            case AF:    switch(Copy_u8PortId)
                        {
                            case IOA:   CLR_BIT(GPIOA->MODER, (Copy_u8PinId*2));
                                        SET_BIT(GPIOA->MODER, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOB:   CLR_BIT(GPIOB->MODER, (Copy_u8PinId*2));
                                        SET_BIT(GPIOB->MODER, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOC:   CLR_BIT(GPIOC->MODER, (Copy_u8PinId*2));
                                        SET_BIT(GPIOC->MODER, ((Copy_u8PinId*2)+1));
                                        break;
                        }
                        break;
            case ANALOG:switch(Copy_u8PortId)
                        {
                            case IOA:   SET_BIT(GPIOA->MODER, (Copy_u8PinId*2));
                                        SET_BIT(GPIOA->MODER, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOB:   SET_BIT(GPIOB->MODER, (Copy_u8PinId*2));
                                        SET_BIT(GPIOB->MODER, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOC:   SET_BIT(GPIOC->MODER, (Copy_u8PinId*2));
                                        SET_BIT(GPIOC->MODER, ((Copy_u8PinId*2)+1));
                                        break;
                        }
                        break;
        }
    }
}

/******************************************************************************/
/* Func. Name : GPIO_voidSetPinType                                           */
/* I/p Arguments : Copy_u8PortId Options: IOA, IOB, IOC                       */
/* I/p Arguments : Copy_u8PinId Options: PIN0 --> PIN15                       */
/* I/p Arguments : Copy_u8PinType: OUTPUT_PP, OUTPUT_OD                       */
/* Return : Nothing                                                           */
/* Desc. : This Api allows the user to Set the Ttpe of output pin             */
/******************************************************************************/
void GPIO_voidSetPinType(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinType)
{
     /*i/p validation*/
    if((Copy_u8PortId > IOC) || (Copy_u8PinId > PIN15) || (Copy_u8PinType > OUTPUT_OD))
    {
        /*Do Nothing*/
    }
    else
    {
        switch(Copy_u8PinType)
        {
            case OUTPUT_PP: switch(Copy_u8PortId)
                            {
                                case IOA:   CLR_BIT(GPIOA->OTYPER, Copy_u8PinId);
                                            break;
                                case IOB:   CLR_BIT(GPIOB->OTYPER, Copy_u8PinId);
                                            break;
                                case IOC:   CLR_BIT(GPIOC->OTYPER, Copy_u8PinId);
                                            break;
                            }
                            break;
            case OUTPUT_OD: switch(Copy_u8PortId)
                            {
                                case IOA:   SET_BIT(GPIOA->OTYPER, Copy_u8PinId);
                                            break;
                                case IOB:   SET_BIT(GPIOB->OTYPER, Copy_u8PinId);
                                            break;
                                case IOC:   SET_BIT(GPIOC->OTYPER, Copy_u8PinId);
                                            break;
                            }
                            break;
        }
    }
}

/******************************************************************************/
/* Func. Name : GPIO_voidSetPinSpeed                                          */
/* I/p Arguments : Copy_u8PortId Options: IOA, IOB, IOC                       */
/* I/p Arguments : Copy_u8PinId Options: PIN0 --> PIN15                       */
/* I/p Arguments : Copy_u8PinSpeed: OUTPUT_LS, OUTPUT_MS, OUTPUT_HS, OUTPUT_VHS*/
/* Return : Nothing                                                           */
/* Desc. : This Api allows the user to Set the Speed of output pin            */
/******************************************************************************/
void GPIO_voidSetPinSpeed(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinSpeed)
{
    /*i/p validation*/
    if((Copy_u8PortId > IOC) || (Copy_u8PinId > PIN15) || (Copy_u8PinSpeed > OUTPUT_VHS))
    {
        /*Do Nothing*/
    }
    else
    {
        switch(Copy_u8PinSpeed)
        {
            case OUTPUT_LS: switch(Copy_u8PortId)
                        {
                            case IOA:   CLR_BIT(GPIOA->OSPEEDR, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOA->OSPEEDR, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOB:   CLR_BIT(GPIOB->OSPEEDR, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOB->OSPEEDR, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOC:   CLR_BIT(GPIOC->OSPEEDR, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOC->OSPEEDR, ((Copy_u8PinId*2)+1));
                                        break;
                        }
                        break;
            case OUTPUT_MS:switch(Copy_u8PortId)
                        {
                            case IOA:   SET_BIT(GPIOA->OSPEEDR, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOA->OSPEEDR, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOB:   SET_BIT(GPIOB->OSPEEDR, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOB->OSPEEDR, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOC:   SET_BIT(GPIOC->OSPEEDR, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOC->OSPEEDR, ((Copy_u8PinId*2)+1));
                                        break;
                        }
                        break;
            case OUTPUT_HS:    switch(Copy_u8PortId)
                        {
                            case IOA:   CLR_BIT(GPIOA->OSPEEDR, (Copy_u8PinId*2));
                                        SET_BIT(GPIOA->OSPEEDR, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOB:   CLR_BIT(GPIOB->OSPEEDR, (Copy_u8PinId*2));
                                        SET_BIT(GPIOB->OSPEEDR, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOC:   CLR_BIT(GPIOC->OSPEEDR, (Copy_u8PinId*2));
                                        SET_BIT(GPIOC->OSPEEDR, ((Copy_u8PinId*2)+1));
                                        break;
                        }
                        break;
            case OUTPUT_VHS:switch(Copy_u8PortId)
                        {
                            case IOA:   SET_BIT(GPIOA->OSPEEDR, (Copy_u8PinId*2));
                                        SET_BIT(GPIOA->OSPEEDR, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOB:   SET_BIT(GPIOB->OSPEEDR, (Copy_u8PinId*2));
                                        SET_BIT(GPIOB->OSPEEDR, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOC:   SET_BIT(GPIOC->OSPEEDR, (Copy_u8PinId*2));
                                        SET_BIT(GPIOC->OSPEEDR, ((Copy_u8PinId*2)+1));
                                        break;
                        }
                        break;
        }
    }
}


/******************************************************************************/
/* Func. Name : GPIO_voidSetPinPUPD                                           */
/* I/p Arguments : Copy_u8PortId Options: IOA, IOB, IOC                       */
/* I/p Arguments : Copy_u8PinId Options: PIN0 --> PIN15                       */
/* I/p Arguments : Copy_u8PinPUPDOption: FLOATING, PU, PD                     */
/* Return : Nothing                                                           */
/* Desc. : This Api allows the user to Set the type of i/p pin                */
/******************************************************************************/
void GPIO_voidSetPinPUPD(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinPUPDOption)
{
    /*i/p validation*/
    if((Copy_u8PortId > IOC) || (Copy_u8PinId > PIN15) || (Copy_u8PinPUPDOption > PD))
    {
        /*Do Nothing*/
    }
    else
    {
        switch(Copy_u8PinPUPDOption)
        {
            case FLOATING: switch(Copy_u8PortId)
                        {
                            case IOA:   CLR_BIT(GPIOA->PUPDR, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOA->PUPDR, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOB:   CLR_BIT(GPIOB->PUPDR, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOB->PUPDR, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOC:   CLR_BIT(GPIOC->PUPDR, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOC->PUPDR, ((Copy_u8PinId*2)+1));
                                        break;
                        }
                        break;
            case PU:switch(Copy_u8PortId)
                        {
                            case IOA:   SET_BIT(GPIOA->PUPDR, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOA->PUPDR, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOB:   SET_BIT(GPIOB->PUPDR, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOB->PUPDR, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOC:   SET_BIT(GPIOC->PUPDR, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOC->PUPDR, ((Copy_u8PinId*2)+1));
                                        break;
                        }
                        break;
            case PD:    switch(Copy_u8PortId)
                        {
                            case IOA:   CLR_BIT(GPIOA->PUPDR, (Copy_u8PinId*2));
                                        SET_BIT(GPIOA->PUPDR, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOB:   CLR_BIT(GPIOB->PUPDR, (Copy_u8PinId*2));
                                        SET_BIT(GPIOB->PUPDR, ((Copy_u8PinId*2)+1));
                                        break;
                            case IOC:   CLR_BIT(GPIOC->PUPDR, (Copy_u8PinId*2));
                                        SET_BIT(GPIOC->PUPDR, ((Copy_u8PinId*2)+1));
                                        break;
                        }
                        break;
        }
    }
}

/******************************************************************************/
/* Func. Name : GPIO_voidSetPinValue                                          */
/* I/p Arguments : Copy_u8PortId Options: IOA, IOB, IOC                       */
/* I/p Arguments : Copy_u8PinId Options: PIN0 --> PIN15                       */
/* I/p Arguments : Copy_u8PinValue: LOW, HIGH                                 */
/* Return : Nothing                                                           */
/* Desc. : This Api allows the user to Set the Value of the pin               */
/******************************************************************************/
void GPIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue)
{
     /*i/p validation*/
    if((Copy_u8PortId > IOC) || (Copy_u8PinId > PIN15) || (Copy_u8PinValue > HIGH))
    {
        /*Do Nothing*/
    }
    else
    {
        switch(Copy_u8PinValue)
        {
            case LOW: switch(Copy_u8PortId)
                      {
                          case IOA:   CLR_BIT(GPIOA->ODR, Copy_u8PinId);
                                      break;
                          case IOB:   CLR_BIT(GPIOB->ODR, Copy_u8PinId);
                                      break;
                          case IOC:   CLR_BIT(GPIOC->ODR, Copy_u8PinId);
                                      break;
                      }
                      break;
            case HIGH: switch(Copy_u8PortId)
                       {
                           case IOA:   SET_BIT(GPIOA->ODR, Copy_u8PinId);
                                       break;
                           case IOB:   SET_BIT(GPIOB->ODR, Copy_u8PinId);
                                       break;
                           case IOC:   SET_BIT(GPIOC->ODR, Copy_u8PinId);
                                       break;
                       }
                       break;
        }
    }
}

/******************************************************************************/
/* Func. Name : GPIO_voidSetPinValue                                          */
/* I/p Arguments : Copy_u8PortId Options: IOA, IOB, IOC                       */
/* I/p Arguments : Copy_u8PinId Options: PIN0 --> PIN15                       */
/* I/p Arguments : Copy_u8PinSetMode: RST, SET                                */
/* Return : Nothing                                                           */
/* Desc. : This Api allows the user to Set the Value of the pin directly      */
/******************************************************************************/
void GPIO_voidSetPinValueDirectAccess(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinSetMode)  //IOB, 6, SET
{
     /*i/p validation*/
    if((Copy_u8PortId > IOC) || (Copy_u8PinId > PIN15) || (Copy_u8PinSetMode > SET))
    {
        /*Do Nothing*/
    }
    else
    {
        switch(Copy_u8PinSetMode)
        {
            case RST: switch(Copy_u8PortId)
                            {
                                case IOA:   GPIOA->BSRR = (1 << (Copy_u8PinId + 16));
                                            break;
                                case IOB:   GPIOB->BSRR = (1 << (Copy_u8PinId + 16));
                                            break;
                                case IOC:   GPIOC->BSRR = (1 << (Copy_u8PinId + 16));
                                            break;
                            }
                            break;
            case SET: switch(Copy_u8PortId)
                            {
                                case IOA:   GPIOA->BSRR = (1 << Copy_u8PinId);
                                            break;
                                case IOB:   GPIOB->BSRR = (1 << Copy_u8PinId);
                                            break;
                                case IOC:   GPIOC->BSRR = (1 << Copy_u8PinId);
                                            break;
                            }
                            break;
        }
    }
}


/******************************************************************************/
/* Func. Name : GPIO_u8GetPinValue                                            */
/* I/p Arguments : Copy_u8PortId Options: IOA, IOB, IOC                       */
/* I/p Arguments : Copy_u8PinId Options: PIN0 --> PIN15                       */
/* Return : Nothing                                                           */
/* Desc. : This Api allows the user to Get the Value of the pin               */
/******************************************************************************/
u8   GPIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
	u8 LocaL_u8Variable=0;
    if((Copy_u8PortId > IOC) || (Copy_u8PinId > PIN15))
    {
        /*Do Nothing*/
    }
    else
    {
        switch(Copy_u8PortId)
        {
            case IOA:   LocaL_u8Variable = GET_BIT(GPIOA->IDR, Copy_u8PinId);
                        break;
            case IOB:   LocaL_u8Variable = GET_BIT(GPIOB->IDR, Copy_u8PinId);
                        break;
            case IOC:   LocaL_u8Variable = GET_BIT(GPIOC->IDR, Copy_u8PinId);
                        break;
        }
    }
    return LocaL_u8Variable;
}

void GPIO_voidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8PinValue)
{
	switch(Copy_u8PinValue)
	{
		case HIGH:
					switch(Copy_u8PortId)
					{
						case IOA:	GPIOA->ODR = 0x0000f0f0;
									break;

						case IOB:	GPIOB->ODR = 0x0000ffff;
									break;

						case IOC:	GPIOC->ODR = 0x0000ffff;
									break;
					}
					break;
		case LOW:
					switch(Copy_u8PortId)
					{
						case IOA:	GPIOA->ODR = 0x00000000;
									break;

						case IOB:	GPIOB->ODR = 0x00000000;
									break;

						case IOC:	GPIOC->ODR = 0x00000000;
									break;
					}
					break;
	}
}

