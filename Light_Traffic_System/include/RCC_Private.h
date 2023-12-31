/***************************************************/
/* SWC : RCC Driver                                */
/* Author : Seif Hashad                            */
/* Version : V 1.0                                 */
/* Date : 21 Jul 2023                              */
/* Description : SWC for Reset and Control Clock   */
/***************************************************/
/*File Gaurd*/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

//Base Address of RCC is 0x40023800
#define RCC_CR          *((volatile u32*)0x40023800)
#define RCC_PLLCFGR     *((volatile u32*)0x40023804)
#define RCC_CFGR        *((volatile u32*)0x40023808)
#define RCC_AHB1ENR     *((volatile u32*)0x40023830)
#define RCC_AHB2ENR     *((volatile u32*)0x40023834)
#define RCC_APB1ENR     *((volatile u32*)0x40023840)
#define RCC_APB2ENR     *((volatile u32*)0x40023844)

//Private Macros
#define HSI         0
#define HSE         1
#define PLL         2

#endif