/***************************************************/
/* SWC : OS Driver                                 */
/* Author : Mohamed Ghoneim                        */
/* Version : V 1.0                                 */
/* Date : 02 Sep 2023                              */
/* Description : SWC for OS                        */
/***************************************************/
#ifndef SCH_PRIVATE_h
#define SCH_PRIVATE_h
typedef struct{
    u32 priodicty;
    u32 FirstDelay;
    void(*pf)(void);
}TCB_t;

TCB_t Task[NO_OF_TASKS]= {NULL};
void Private_voidScheudlerStart();
#endif
