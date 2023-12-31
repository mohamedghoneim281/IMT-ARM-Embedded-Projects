/***************************************************/
/* SWC : RCC Driver                                */
/* Author : Seif Hashad                            */
/* Version : V 1.0                                 */
/* Date : 21 Jul 2023                              */
/* Description : SWC for Reset and Control Clock   */
/***************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"

void  RCC_voidInitSysClk(void)
{
    #if RCC_CLK_SRC == HSI
        /*1- Turn On HSI*/
        SET_BIT(RCC_CR, 0);
        /*2- Select HSI as the System CLK Src*/
        CLR_BIT(RCC_CFGR, 0);
        CLR_BIT(RCC_CFGR, 1);
    #elif RCC_CLK_SRC == HSE
        /*1- Turn On HSE*/
        SET_BIT(RCC_CR, 16);
        /*2- Select HSE as the System CLK Src*/
        SET_BIT(RCC_CFGR, 0);
        CLR_BIT(RCC_CFGR, 1);
    #elif RCC_CLK_SRC == PLL
        /*Assignment*/
    #else
        #warning "Lol"
    #endif
}

/******************************************************************************/
/* Func. Name : RCC_voidEnablePeripheralClk                                   */
/* I/p Arguments : Copy_u8BusId Options: AHB1, AHB2, APB1, APB2               */
/* I/p Arguments : Copy_u8PeripheralId Options: 0 --> 31                      */
/* Return : Nothing                                                           */
/* Desc. : This Api allows the user to enable the clk of a spscific peripheral*/
/******************************************************************************/
void  RCC_voidEnablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
    /*i/p validation*/
    if((Copy_u8BusId > APB2) || (Copy_u8PeripheralId > 31))
    {
        /*Do Nothing*/
    }
    else
    {
        switch(Copy_u8BusId)
        {
            case AHB1:  SET_BIT(RCC_AHB1ENR, Copy_u8PeripheralId);
                        break;
            case AHB2:  if(Copy_u8PeripheralId != 7)
                        {
                            /*Do Nothing*/
                        }
                        else
                        {
                            SET_BIT(RCC_AHB2ENR, Copy_u8PeripheralId);
                        }
                        break;
            case APB1:  SET_BIT(RCC_APB1ENR, Copy_u8PeripheralId);
                        break;
            case APB2:  SET_BIT(RCC_APB2ENR, Copy_u8PeripheralId);
                        break;
        }
    }
}


/******************************************************************************/
/* Func. Name : RCC_voidDisablePeripheralClk                                  */
/* I/p Arguments : Copy_u8BusId Options: AHB1, AHB2, APB1, APB2               */
/* I/p Arguments : Copy_u8PeripheralId Options: 0 --> 31                      */
/* Return : Nothing                                                           */
/* Desc. : This Api allows the user to disable the clk of a spscific peripheral*/
/******************************************************************************/
void  RCC_voidDisablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
    /*i/p validation*/
    if((Copy_u8BusId > APB2) || (Copy_u8PeripheralId > 31))
    {
        /*Do Nothing*/
    }
    else
    {
        switch(Copy_u8BusId)
        {
            case AHB1:  CLR_BIT(RCC_AHB1ENR, Copy_u8PeripheralId);
                        break;
            case AHB2:  if(Copy_u8PeripheralId != 7)
                        {
                            /*Do Nothing*/
                        }
                        else
                        {
                            CLR_BIT(RCC_AHB2ENR, Copy_u8PeripheralId);
                        }
                        break;
            case APB1:  CLR_BIT(RCC_APB1ENR, Copy_u8PeripheralId);
                        break;
            case APB2:  CLR_BIT(RCC_APB2ENR, Copy_u8PeripheralId);
                        break;
        }
    }
}
