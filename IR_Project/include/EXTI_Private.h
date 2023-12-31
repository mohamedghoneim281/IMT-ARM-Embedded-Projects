/*****************************************/
/* Author  :  Seif Hashad                */
/* Version :  V01                        */
/* Date    : 18 May 2023                 */
/*****************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

//EXTI BASEADDRESS --> 0x40013C00
typedef struct 
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXTI_t;

#define EXTI        ((volatile EXTI_t*)0x40013C00)

typedef struct 
{
    volatile u32 MEMRMP;
    volatile u32 PMC;
    volatile u32 EXTICR1;
    volatile u32 EXTICR2;
    volatile u32 EXTICR3;
    volatile u32 EXTICR4;
    volatile u32 CMPCR;
}SYSCFG_t;

#define SYSCFG      ((volatile SYSCFG_t*)0x40013800)



#endif
