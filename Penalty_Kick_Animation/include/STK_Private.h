/***************************************************/
/* SWC : STK Driver                                */
/* Author : Seif Hashad                            */
/* Version : V 1.0                                 */
/* Date : 05 AUG 2023                              */
/* Description : SWC for System Timer              */
/***************************************************/
/*File Gaurd*/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define STK_CTRL                   *((volatile u32*)0xE000E010)
#define STK_LOAD                   *((volatile u32*)0xE000E014)
#define STK_VAL                    *((volatile u32*)0xE000E018)
    
#define AHB                        0
#define AHB_DIV_BY_8               1

#define SINGLE_INTERVAL            0
#define PERIODIC_INTERVAL          1

#endif
