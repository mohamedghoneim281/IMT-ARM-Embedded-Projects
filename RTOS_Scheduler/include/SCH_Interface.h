/***************************************************/
/* SWC : OS Driver                                 */
/* Author : Mohamed Ghoneim                        */
/* Version : V 1.0                                 */
/* Date : 02 Sep 2023                              */
/* Description : SWC for OS                        */
/***************************************************/
#ifndef SCH_Interface_h
#define SCH_Interface_h

void SCH_voidCreateTask(u8 Copy_u8Priority, u32 Copy_u32Periodicity, u32 Copy_u32FirstDelay, void(*Lpf)(void));
void SCH_voidStartOS();
#endif