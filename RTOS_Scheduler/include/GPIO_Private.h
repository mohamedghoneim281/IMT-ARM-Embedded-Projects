/***************************************************/
/* SWC : GPIO Driver                               */
/* Author : Seif Hashad                            */
/* Version : V 1.0                                 */
/* Date : 28 Jul 2023                              */
/* Description : SWC for General Purpose I/O       */
/***************************************************/
/*File Gaurd*/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

//GPIOA, GPIOB, GPIOC is on AHB1
//GPIOA Base Add is 0x40020000
//GPIOB Base Add is 0x40020400
//GPIOC Base Add is 0x40020800

typedef struct 
{
    volatile u32 MODER;
    volatile u32 OTYPER;
    volatile u32 OSPEEDR;
    volatile u32 PUPDR;
    volatile u32 IDR;
    volatile u32 ODR;
    volatile u32 BSRR;
    volatile u32 LCKR;
    volatile u32 AFRL;
    volatile u32 AFRH;
}GPIO_t;

#define GPIOA       ((volatile GPIO_t*)0x40020000)   //GPIOA->MODER
#define GPIOB       ((volatile GPIO_t*)0x40020400)   //GPIOA->MODER
#define GPIOC       ((volatile GPIO_t*)0x40020800)   //GPIOA->MODER

#endif