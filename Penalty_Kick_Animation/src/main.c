#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"
#include "LEDMTRX_Interface.h"

u8 Frame1[8] = {235, 63, 235, 136, 0, 0, 129, 255};
u8 Frame2[8] = {235, 63, 107, 136, 64, 0, 129, 255};
u8 Frame3[8] = {235, 63, 235, 8, 0, 32, 129, 255};
u8 Frame4[8] = {235, 63, 235, 8, 0, 0, 145, 255};
u8 Frame5[8] = {8, 235, 63, 235, 8, 0, 0, 0};
u8 Frame6[8] = {0, 8, 235, 63, 235, 8, 0, 0};
u8 Frame7[8] = {0, 0, 8, 235, 63, 235, 8, 0};    //hands in the middle
u8 Frame8[8] = {0, 0, 16, 235, 63, 235, 16, 0}; //hands down
u8 Frame9[8] = {0, 0, 4, 235, 63, 235, 4, 0};  //hands up

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
																		HLEDMAT_voidDisplay(Frame7) ;}
																		/*Send Frame To Led Matrix*/
																				for(u8 i=0; i<10; i++){
																				HLEDMAT_voidDisplay(Frame9) ;}
																				/*Send Frame To Led Matrix*/
																						for(u8 i=0; i<10; i++){
																						HLEDMAT_voidDisplay(Frame7) ;}
																						/*Send Frame To Led Matrix*/
																								for(u8 i=0; i<10; i++){
																								HLEDMAT_voidDisplay(Frame8) ;}
																								/*Send Frame To Led Matrix*/
																										for(u8 i=0; i<10; i++){
																										HLEDMAT_voidDisplay(Frame7) ;}
																										/*Send Frame To Led Matrix*/
																												for(u8 i=0; i<10; i++){
																												HLEDMAT_voidDisplay(Frame9) ;}


	}

}

