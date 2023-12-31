#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT_NO)         REG |= (1 << BIT_NO)
#define CLR_BIT(REG,BIT_NO)         REG &= ~(1 << BIT_NO)
#define GET_BIT(REG,BIT_NO)         REG & (1 << BIT_NO)
#define TOG_BIT(REG,BIT_NO)         GET_BIT(REG,BIT_NO) == 1? SET_BIT(REG,BIT_NO):CLR_BIT(REG,BIT_NO)

#define NULL                        (void*)(0)

#endif
