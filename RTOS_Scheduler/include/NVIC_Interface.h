/***************************************************/
/* SWC : NVIC Driver                               */
/* Author : Seif Hashad                            */
/* Version : V 1.0                                 */
/* Date : 12 AUG 2023                              */
/* Description : SWC for Nested Vectored Int. Cont.*/
/***************************************************/
/*File Guard*/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void NVIC_voidEnablePeriInt(u8 Copy_u8PerIntId);
void NVIC_voidDisablePeriInt(u8 Copy_u8PerIntId);
void NVIC_voidSetPendingFlag(u8 Copy_u8PerIntId);
void NVIC_voidClrPendingFlag(u8 Copy_u8PerIntId);
void NVIC_voidSetPriorityConfig(u8 Copy_u8PriorityOption);
void NVIC_voidSetPerPripority(s8 Copy_s8PerIntId, u8 Copy_u8GroupId, u8 Copy_u8SubGroupId);


#define G16_SG0             0
#define G8_SG2              1
#define G4_SG4              2
#define G2_SG8              3
#define G0_SG16             4

#endif
