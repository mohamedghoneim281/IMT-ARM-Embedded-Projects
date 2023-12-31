/***************************************************/
/* SWC : STK Driver                                */
/* Author : Seif Hashad                            */
/* Version : V 1.0                                 */
/* Date : 05 AUG 2023                              */
/* Description : SWC for System Timer              */
/***************************************************/
/*File Gaurd*/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void STK_voidInit(void);
void STK_voidSetBusyWait(u32 Copy_u32TicksCounts);
void STK_voidSetIntervalSingle(u32 Copy_u32TicksCounts, void (*Lpf)(void));
void STK_voidSetIntervalPeriodic(u32 Copy_u32TicksCounts, void (*Lpf)(void));
u32  STK_u32GetElapsedTime(void);
void  STK_u32GetRemaningTime(u32* RemaingTime);

//u32  STK_u32GetElapsedTime(void);
//u32  STK_u32GetRemaningTime(void);

#endif
