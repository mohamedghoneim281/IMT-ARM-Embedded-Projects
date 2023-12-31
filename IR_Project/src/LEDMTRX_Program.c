/***************************************************/
/* SWC : LED Matrix Driver                                */
/* Author : Mohamed Ghoneim                        */
/* Version : V 2.0                                 */
/* Date : 23 SEP 2023                              */
/* Description : SWC for LED Matrix        */
/***************************************************/#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Interface.h"
#include "STK_Interface.h"
#include "STP_Interface.h"

#include "LEDMTRX_Interface.h"
#include "LEDMTRX_Config.h"
#include "LEDMTRX_Private.h"

void HLEDMAT_voidInit(void)
{
	//Init serial to parallel
	STP_voidInit();
}

void HLEDMAT_voidDisplay(u8 *Copy_u8Frame)
{	//Initialize Systick timer
	STK_voidInit();
	/*Column 0*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	STP_voidSendSynch1(Copy_u8Frame[0]) ;	//send row values corresponding to column 0 of the frame

	/*Enable Column0 (by setting it to low as columns are cathode enabled by setting it to zero in order for a one from anode(rows) make a difference) */
	STP_voidSendSynch2(0xFE) ;
	//shift it through Q7'
	STP_voidSendSynch1(Copy_u8Frame[0]) ;	//send row values corresponding to column 0 of the frame

	//Delay 2500 us
	STK_voidSetBusyWait(2500) ; //2.5ms

	/*Column 1*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	STP_voidSendSynch1(Copy_u8Frame[1]) ;	//send row values corresponding to column 1 of the frame

	/*Enable Column1 (by setting it to low as columns are cathode enabled by setting it to zero in order for 1 from anode(rows) make a difference) */
	STP_voidSendSynch2(0xFD) ;
	//shift it through Q7'
	STP_voidSendSynch1(Copy_u8Frame[1]) ;	//send row values corresponding to column 1 of the frame
	//Delay 2500 us
	STK_voidSetBusyWait(2500) ; //2.5ms

	/*Column 2*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	STP_voidSendSynch1(Copy_u8Frame[2]) ;	//send row values corresponding to column 2 of the frame

	/*Enable Column2 (by setting it to low as columns are cathode enabled by setting it to zero in order to make a 1 from anode(rows) make a difference) */
	STP_voidSendSynch2(0xFB) ;
	//shift it through Q7'
	STP_voidSendSynch1(Copy_u8Frame[2]) ;	//send row values corresponding to column 2 of the frame
	//Delay 2500 us
	STK_voidSetBusyWait(2500) ; //2.5ms

	/*Column 3*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	STP_voidSendSynch1(Copy_u8Frame[3]) ;	//send row values corresponding to column 3 of the frame

	/*Enable Column3 (by setting it to low as columns are cathode enabled by setting it to zero in order to make a 1 from anode(rows) make a difference) */
	STP_voidSendSynch2(0xF7) ;
	//shift it through Q7'
	STP_voidSendSynch1(Copy_u8Frame[3]) ;	//send row values corresponding to column 3 of the frame
	//Delay 2500 us
	STK_voidSetBusyWait(2500) ; //2.5ms

	/*Column 4*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	STP_voidSendSynch1(Copy_u8Frame[4]) ;	//send row values corresponding to column 4 of the frame

	/*Enable Column4 (by setting it to low as columns are cathode enabled by setting it to zero in order to make a 1 from anode(rows) make a difference) */
	STP_voidSendSynch2(0xEF) ;
	//shift it through Q7'
	STP_voidSendSynch1(Copy_u8Frame[4]) ;	//send row values corresponding to column 4 of the frame
	//Delay 2500 us
	STK_voidSetBusyWait(2500) ; //2.5ms
	/*Column 5*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	STP_voidSendSynch1(Copy_u8Frame[5]) ;	//send row values corresponding to column 5 of the frame

	/*Enable Column5 (by setting it to low as columns are cathode enabled by setting it to zero in order to make a 1 from anode(rows) make a difference) */
	STP_voidSendSynch2(0xDF) ;
	//shift it through Q7'
	STP_voidSendSynch1(Copy_u8Frame[5]) ;	//send row values corresponding to column 5 of the frame
	//Delay 2500 us
	STK_voidSetBusyWait(2500) ; //2.5ms


	/*Column 6*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	STP_voidSendSynch1(Copy_u8Frame[6]) ;	//send row values corresponding to column 6 of the frame

	/*Enable Column6 (by setting it to low as columns are cathode enabled by setting it to zero in order to make a 1 from anode(rows) make a difference) */
	STP_voidSendSynch2(0xBF) ;
	//shift it through Q7'
	STP_voidSendSynch1(Copy_u8Frame[6]) ;	//send row values corresponding to column 6 of the frame
	//Delay 2500 us
	STK_voidSetBusyWait(2500) ; //2.5ms

	/*Column 7*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	STP_voidSendSynch1(Copy_u8Frame[7]) ;	//send row values corresponding to column 7 of the frame

	/*Enable Column7 (by setting it to low as columns are cathode enabled by setting it to zero in order to make a 1 from anode(rows) make a difference) */
	STP_voidSendSynch2(0x7F) ;
	//shift it through Q7'
	STP_voidSendSynch1(Copy_u8Frame[7]) ;	//send row values corresponding to column 7 of the frame
	//Delay 2500 us
	STK_voidSetBusyWait(2500) ; //2.5ms

}


static void HLEDMAT_voidDisableCols(void)
{	//Columns are cathode should be all set to one to be disabled
	STP_voidSendSynch2(0xFF);

}

