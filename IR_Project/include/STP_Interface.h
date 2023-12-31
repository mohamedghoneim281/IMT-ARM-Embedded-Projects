/***************************************************/
/* SWC : STP Driver                                */
/* Author : Mohamed Ghoneim                        */
/* Version : V 1.0                                 */
/* Date : 05 AUG 2023                              */
/* Description : SWC for Serial to Parallel        */
/***************************************************/
/*File Gaurd*/
#ifndef STP_INTERFACE_H
#define STP_INTERFACE_H

void STP_voidInit();
void STP_voidSendSynch1(u8 Copy_u8Data);
void STP_voidSendSynch2(u8 Copy_u8Data);

#endif
