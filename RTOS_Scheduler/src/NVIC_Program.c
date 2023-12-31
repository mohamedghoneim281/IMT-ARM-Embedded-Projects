/***************************************************/
/* SWC : NVIC Driver                               */
/* Author : Seif Hashad                            */
/* Version : V 1.0                                 */
/* Date : 12 AUG 2023                              */
/* Description : SWC for Nested Vectored Int. Cont.*/
/***************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_Interface.h"
#include "NVIC_Private.h"
#include "NVIC_Config.h"

u8 Global_u8Priroity = 0;

void NVIC_voidEnablePeriInt(u8 Copy_u8PerIntId)
{
    NVIC->ISER[Copy_u8PerIntId/32] = (1 << (Copy_u8PerIntId%32));
}

void NVIC_voidDisablePeriInt(u8 Copy_u8PerIntId)
{
    NVIC->ICER[Copy_u8PerIntId/32] = (1 << (Copy_u8PerIntId%32));
}

void NVIC_voidSetPendingFlag(u8 Copy_u8PerIntId)
{

    NVIC->ISPR[Copy_u8PerIntId/32] = (1 << (Copy_u8PerIntId%32));
}

void NVIC_voidClrPendingFlag(u8 Copy_u8PerIntId)
{
    NVIC->ICPR[Copy_u8PerIntId/32] = (1 << (Copy_u8PerIntId%32));
}


/******************************************************************************************/
/* Func. Name : NVIC_voidSetPriorityConfig                                                */
/* I/p Arguments : Copy_u8PriorityConfig Options: G16_SG0, G8_SG2, G4_SG4, G2_SG8, G0_SG16*/
/* Return : Nothing                                                                       */
/* Desc. : This Api allows the user to Set the The no. of Groups & Sub Groups in the sys. */
/******************************************************************************************/
void NVIC_voidSetPriorityConfig(u8 Copy_u8PriorityConfig)
{
    switch (Copy_u8PriorityConfig)
    {
        case G16_SG0:   SCB -> AIRCR = VECT_KEY | (G4BITS_SG0BITS << 8);
                        Global_u8Priroity = G4BITS_SG0BITS;
                        break;
        case G8_SG2:    SCB -> AIRCR = VECT_KEY | (G3BITS_SG1BITS << 8);
                        Global_u8Priroity = G3BITS_SG1BITS;
                        break;
        case G4_SG4:    SCB -> AIRCR = VECT_KEY | (G2BITS_SG2BITS << 8);
                        Global_u8Priroity = G2BITS_SG2BITS;
                        break;
        case G2_SG8:    SCB -> AIRCR = VECT_KEY | (G1BITS_SG3BITS << 8);
                        Global_u8Priroity = G1BITS_SG3BITS;
                        break;
        case G0_SG16:   SCB -> AIRCR = VECT_KEY | (G0BITS_SG4BITS << 8);
                        Global_u8Priroity = G0BITS_SG4BITS;
                        break;  
        default:        /*Do Nothing*/
                        break;                       
    }
}

void NVIC_voidSetPerPripority(s8 Copy_s8PerIntId, u8 Copy_u8GroupId, u8 Copy_u8SubGroupId)
{
    u8 Local_u8Priority = Copy_u8SubGroupId | Copy_u8GroupId << (Global_u8Priroity - G4BITS_SG0BITS);

    /*i/p validation*/
    if(Copy_s8PerIntId < 0)
    {
        /*Do Nothing*/
    }
    else if((Copy_s8PerIntId >= 0) && (Copy_s8PerIntId < 85))
    {
        NVIC->IP[Copy_s8PerIntId] = (Local_u8Priority << 4);
    }
}


