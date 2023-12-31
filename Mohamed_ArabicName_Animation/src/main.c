#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"
#include "LEDMTRX_Interface.h"

u8 Frame1[8] = {20, 20, 24, 16, 16, 56, 40, 56};
u8 Frame2[8] = {16, 20, 20, 24, 16, 16, 56, 40};
u8 Frame3[8] = {56, 16, 20, 20, 24, 16, 16, 56};
u8 Frame4[8] = {40, 56, 16, 20, 20, 24, 16, 16};
u8 Frame5[8] = {56, 40, 56, 16, 20, 20, 24, 16};
u8 Frame6[8] = {16, 56, 40, 56, 16, 20, 20, 24};
u8 Frame7[8] = {16, 16, 56, 40, 56, 16, 20, 20};
u8 Frame8[8] = {28, 16, 16, 56, 40, 56, 16, 20};
u8 Frame9[8] = {20, 28, 16, 16, 56, 40, 56, 16};
u8 Frame10[8] = {20, 20, 28, 16, 16, 56, 40, 56};
u8 Frame11[8] = {0, 20, 20, 28, 16, 16, 56, 40};
u8 Frame12[8] = {0, 0, 20, 20, 28, 16, 16, 56};
u8 Frame13[8] = {0, 0, 0, 20, 20, 28, 16, 16};
u8 Frame14[8] = {56, 0, 0, 0, 20, 20, 28, 16};
u8 Frame15[8] = {40, 56, 0, 0, 0, 20, 20, 28};
u8 Frame16[8] = {56, 40, 56, 0, 0, 0, 20, 20};
u8 Frame17[8] = {16, 56, 40, 56, 0, 0, 0, 20};
u8 Frame18[8] = {16, 16, 56, 40, 56, 0, 0, 0};
u8 Frame19[8] = {24, 16, 16, 56, 40, 56, 0, 0};
u8 Frame20[8] = {20, 24, 16, 16, 56, 40, 56, 0};
void main(void)
{
	/*Step 1 : System Clock is 16 MHz From HSI*/
	RCC_voidInitSysClk();

	/*Step 2 : Enable GPIO Peripherial Clock For Port A*/
	RCC_voidEnablePeripheralClk(AHB1,0);

	/*Step 3 : Enable GPIO Peripherial Clock For Port B*/
    RCC_voidEnablePeripheralClk(AHB1,1);

	/*Step 4 : Initialize For LED Matrix*/
    HLEDMAT_voidInit() ;

	/* Loop forever */
	while(1)
	{

      /*Send Frame To Led Matrix*/
		for(u8 i=0; i<10; i++){
		HLEDMAT_voidDisplay(Frame1) ;}

	  /*Send Frame To Led Matrix*/
			for(u8 i=0; i<10; i++){
			HLEDMAT_voidDisplay(Frame2) ;}
		      /*Send Frame To Led Matrix*/
				for(u8 i=0; i<10; i++){
				HLEDMAT_voidDisplay(Frame3) ;}
			      /*Send Frame To Led Matrix*/
					for(u8 i=0; i<10; i++){
					HLEDMAT_voidDisplay(Frame4) ;}
				      /*Send Frame To Led Matrix*/
						for(u8 i=0; i<10; i++){
						HLEDMAT_voidDisplay(Frame5) ;}
					      /*Send Frame To Led Matrix*/
							for(u8 i=0; i<10; i++){
							HLEDMAT_voidDisplay(Frame6) ;}
						      /*Send Frame To Led Matrix*/
								for(u8 i=0; i<10; i++){
								HLEDMAT_voidDisplay(Frame7) ;}
							      /*Send Frame To Led Matrix*/
									for(u8 i=0; i<10; i++){
									HLEDMAT_voidDisplay(Frame8) ;}
								      /*Send Frame To Led Matrix*/
										for(u8 i=0; i<10; i++){
										HLEDMAT_voidDisplay(Frame9) ;}
									      /*Send Frame To Led Matrix*/
											for(u8 i=0; i<10; i++){
											HLEDMAT_voidDisplay(Frame10) ;}
										      /*Send Frame To Led Matrix*/
												for(u8 i=0; i<10; i++){
												HLEDMAT_voidDisplay(Frame11) ;}
											      /*Send Frame To Led Matrix*/
													for(u8 i=0; i<10; i++){
													HLEDMAT_voidDisplay(Frame12) ;}
												      /*Send Frame To Led Matrix*/
														for(u8 i=0; i<10; i++){
														HLEDMAT_voidDisplay(Frame13) ;}
													      /*Send Frame To Led Matrix*/
															for(u8 i=0; i<10; i++){
															HLEDMAT_voidDisplay(Frame14) ;}
														      /*Send Frame To Led Matrix*/
																for(u8 i=0; i<10; i++){
																HLEDMAT_voidDisplay(Frame15) ;}
															      /*Send Frame To Led Matrix*/
																	for(u8 i=0; i<10; i++){
																	HLEDMAT_voidDisplay(Frame16) ;}
																      /*Send Frame To Led Matrix*/
																		for(u8 i=0; i<10; i++){
																		HLEDMAT_voidDisplay(Frame17) ;}
																	      /*Send Frame To Led Matrix*/
																			for(u8 i=0; i<10; i++){
																			HLEDMAT_voidDisplay(Frame18) ;}
																		      /*Send Frame To Led Matrix*/
																				for(u8 i=0; i<10; i++){
																				HLEDMAT_voidDisplay(Frame19) ;}
																			      /*Send Frame To Led Matrix*/
																					for(u8 i=0; i<10; i++){
																					HLEDMAT_voidDisplay(Frame20) ;}
	}

}

