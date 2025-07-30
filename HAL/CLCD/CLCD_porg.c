#define F_CPU 16000000UL
#include "avr/delay.h"
#include "../../Service/Std_type.h"
#include "../../Service/bit_math.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "CLCD_prv.h"
#include "CLCD_cfg.h"
#include "CLCD_int.h"
void CLCD_voidSendEnablePulse(){
	//	send Enable Pulse ---> e
	DIO_voidSetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN,DIO_PIN_HIGH );
	_delay_ms(10);
	DIO_voidSetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN,DIO_PIN_LOW );
}
#if CLCD_MODE == CLCD_4_BIT
void CLCD_voidSetHalfPort(u8 Copy_u8Data)
{
	DIO_voidSetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_1, GET_BIT(Copy_u8Data,0));
	DIO_voidSetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_2, GET_BIT(Copy_u8Data,1));
	DIO_voidSetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_3, GET_BIT(Copy_u8Data,2));
	DIO_voidSetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_4, GET_BIT(Copy_u8Data,3));
}
#endif
void CLCD_voidWriteData(u8 Copy_u8Data){
	//	rw ---> low
	DIO_voidSetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN,DIO_PIN_LOW );
	//	rs ---> High
	DIO_voidSetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN,DIO_PIN_HIGH );
#if CLCD_MODE == CLCD_8_BIT
	//data port = data
	DIO_voidSetPortValue(CLCD_DATA_PORT,Copy_u8Data);
	CLCD_voidSendEnablePulse();
#elif CLCD_MODE == CLCD_4_BIT
	/*Dend High Nibble */
	CLCD_voidSetHalfPort(Copy_u8Data>>4);
	/*send enable pulse */
	CLCD_voidSendEnablePulse();
	CLCD_voidSetHalfPort(Copy_u8Data);
	/*send Enable pulse */
	CLCD_voidSendEnablePulse();

#endif



}
void CLCD_voidWriteInst(u8 Copy_u8Inst){
	//	rw ---> low
	DIO_voidSetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN,DIO_PIN_LOW );
	//	rs ---> LOW
	DIO_voidSetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN,DIO_PIN_LOW );
#if CLCD_MODE == CLCD_8_BIT
	//data port = data
	DIO_voidSetPortValue(CLCD_DATA_PORT,Copy_u8Inst);
	CLCD_voidSendEnablePulse();
#elif CLCD_MODE == CLCD_4_BIT
	/*Dend High Nibble */
	CLCD_voidSetHalfPort(Copy_u8Inst>>4);
	/*send enable pulse */
	CLCD_voidSendEnablePulse();
	CLCD_voidSetHalfPort(Copy_u8Inst);
	/*send Enable pulse */
	CLCD_voidSendEnablePulse();
#endif

}
void CLCD_voidInit(void)
{
	DIO_voidSetPinDirection(CLCD_DATA_PORT,CLCD_DATA_PIN_1,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(CLCD_DATA_PORT,CLCD_DATA_PIN_2,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(CLCD_DATA_PORT,CLCD_DATA_PIN_3,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(CLCD_DATA_PORT,CLCD_DATA_PIN_4,DIO_PIN_OUTPUT);
	
	DIO_voidSetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CTRL_PORT,CLCD_EN_PIN,DIO_PIN_OUTPUT);
	
	// delay 4 ms
	_delay_ms(40);
	//send function set    command 0x38
#if CLCD_MODE == CLCD_8_BIT
	CLCD_voidWriteInst(0x38);
#elif CLCD_MODE == CLCD_4_BIT
	CLCD_voidSetHalfPort(0b0010);
	CLCD_voidSendEnablePulse();
	CLCD_voidSetHalfPort(0b0010);
	CLCD_voidSendEnablePulse();
	CLCD_voidSetHalfPort(0b1000);
	CLCD_voidSendEnablePulse();
#endif
	//send function on/off command 0x0E
	CLCD_voidWriteInst(0x0F);
	//send function clear  command  1
	CLCD_voidWriteInst(1);

}


void CLCD_voidSendString(const u8 * str )
{
	while (*str != '\0')
	{
		CLCD_voidWriteData(*str);
		str++;
	}
}

void CLCD_voidSendNumber(u32 number)
{

}

void CLCD_voidGoToX_Y(u8 Copy_u8_X,u8 Copy_u8_Y)
{
	u8 Local_u8address = Copy_u8_X + (Copy_u8_Y * 0x40);
	SET_BIT(Local_u8address, 7);
	CLCD_voidWriteInst(Local_u8address);


}
void CLCD_voidClearDisp()
{
	//send function clear  command  1
	CLCD_voidWriteInst(1);

}




void CLCD_voidWriteSpecialChar(u8 * Copy_pu8Patarn , u8 Copy_u8PattarnNumber , u8 Copy_u8_X,u8 Copy_u8_Y  ){
//	calculate address to write
	u8 Local_u8Adrress = Copy_u8PattarnNumber * 8 ;

	SET_BIT(Local_u8Adrress,6);
//	send command set address to write
	CLCD_voidWriteInst(Local_u8Adrress);
//	write 8 bytes
	for(u8 Local_u8Counter=0  ; Local_u8Counter < 8 ;Local_u8Counter++ )
	{
		CLCD_voidWriteData(Copy_pu8Patarn[Local_u8Counter]);
	}
//	set x axis and y axis
	CLCD_voidGoToX_Y(Copy_u8_X,Copy_u8_Y);
//	display char
	CLCD_voidWriteData(Copy_u8PattarnNumber);
}












