#include "../../Service/Std_type.h"
#include "../../Service/bit_math.h"
#include "../reg.h"
#include "DIO_int.h"


void DIO_voidSetPinDirection(u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8direction){
	//check if the pin is in the range of 0 to 7
	if(Copy_u8pin  <= 7 )
	{
		// check direction
		if(Copy_u8direction == DIO_PIN_INPUT)
		{
			//check port
			switch(Copy_u8port)
			{
			case DIO_PORTA:CLR_BIT(DIO_DDRA_REG,Copy_u8pin); break;
			case DIO_PORTB:CLR_BIT(DIO_DDRB_REG,Copy_u8pin); break;
			case DIO_PORTC:CLR_BIT(DIO_DDRC_REG,Copy_u8pin); break;
			case DIO_PORTD:CLR_BIT(DIO_DDRD_REG,Copy_u8pin); break;
			default:break ;
			//return error

			}
		}
		else if(Copy_u8direction == DIO_PIN_OUTPUT)
		{
			//check port
			switch(Copy_u8port)
			{
			case DIO_PORTA:SET_BIT(DIO_DDRA_REG,Copy_u8pin); break;
			case DIO_PORTB:SET_BIT(DIO_DDRB_REG,Copy_u8pin); break;
			case DIO_PORTC:SET_BIT(DIO_DDRC_REG,Copy_u8pin); break;
			case DIO_PORTD:SET_BIT(DIO_DDRD_REG,Copy_u8pin); break;
			default:break ;
			//return error
			}
		}
		else {
			//return error
		}


	}else {
		//return error
	}
}

void DIO_voidSetPinValue    (u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8value){
	//check if the pin is in the range of 0 to 7
	if(Copy_u8pin  <= 7 )
	{
		// check direction
		if(Copy_u8value == DIO_PIN_LOW)
		{
			//check port
			switch(Copy_u8port)
			{
			case DIO_PORTA:CLR_BIT(DIO_PORTA_REG,Copy_u8pin); break;
			case DIO_PORTB:CLR_BIT(DIO_PORTB_REG,Copy_u8pin); break;
			case DIO_PORTC:CLR_BIT(DIO_PORTC_REG,Copy_u8pin); break;
			case DIO_PORTD:CLR_BIT(DIO_PORTD_REG,Copy_u8pin); break;
			default:break ;
			//return error
			}
		}
		else if(Copy_u8value == DIO_PIN_HIGH)
		{
			//check port
			switch(Copy_u8port)
			{
			case DIO_PORTA:SET_BIT(DIO_PORTA_REG,Copy_u8pin); break;
			case DIO_PORTB:SET_BIT(DIO_PORTB_REG,Copy_u8pin); break;
			case DIO_PORTC:SET_BIT(DIO_PORTC_REG,Copy_u8pin); break;
			case DIO_PORTD:SET_BIT(DIO_PORTD_REG,Copy_u8pin); break;
			default:break ;
			//return error
			}
		}
		else {
			//return error
		}
	}else {
		//return error
	}
}
u8   DIO_u8GetPinValue      (u8 Copy_u8port, u8 Copy_u8pin){

	u8 Local_u8Val =0 ;
	switch(Copy_u8port)
	{
	case DIO_PORTA : Local_u8Val = GET_BIT(DIO_PINA_REG,Copy_u8pin); break ;
	case DIO_PORTB : Local_u8Val = GET_BIT(DIO_PINB_REG,Copy_u8pin); break ;
	case DIO_PORTC : Local_u8Val = GET_BIT(DIO_PINC_REG,Copy_u8pin); break ;
	case DIO_PORTD : Local_u8Val = GET_BIT(DIO_PIND_REG,Copy_u8pin); break ;
	default 	   : /* error */ break ;

	}
	return Local_u8Val;
}



void DIO_voidSetPortDirection(u8 Copy_u8port,  u8 Copy_u8direction){
	//	PA p 11111111 01010101 00000000
	switch(Copy_u8port)
	{
	case DIO_PORTA :DIO_DDRA_REG = Copy_u8direction; break ;
	case DIO_PORTB :DIO_DDRB_REG = Copy_u8direction; break ;
	case DIO_PORTC :DIO_DDRC_REG = Copy_u8direction; break ;
	case DIO_PORTD :DIO_DDRD_REG = Copy_u8direction; break ;
	default 	   : /* error */ break ;
	}
}
void DIO_voidSetPortValue    (u8 Copy_u8port,  u8 Copy_u8value){
	switch(Copy_u8port)
	{
	case DIO_PORTA :DIO_PORTA_REG = Copy_u8value ; break;
	case DIO_PORTB :DIO_PORTB_REG = Copy_u8value ; break;
	case DIO_PORTC :DIO_PORTC_REG = Copy_u8value ; break;
	case DIO_PORTD :DIO_PORTD_REG = Copy_u8value ; break;
	default 	   : /* error */ break ;
	}
}
u8   DIO_u8GetPortValue      (u8 Copy_u8port){
	u8 Local_u8Val =0 ;

	switch(Copy_u8port)
	{
	case DIO_PORTA : Local_u8Val = DIO_PINA_REG; break ;
	case DIO_PORTB : Local_u8Val = DIO_PINB_REG; break ;
	case DIO_PORTC : Local_u8Val = DIO_PINC_REG; break ;
	case DIO_PORTD : Local_u8Val = DIO_PIND_REG; break ;
	default 	   : /* error */ break ;
	}
	return Local_u8Val ;
}
void DIO_voidEnablePullUp(u8 Copy_u8port, u8 Copy_u8pin){
	switch(Copy_u8port)
	{
	case DIO_PORTA:SET_BIT(DIO_PORTA_REG,Copy_u8pin); break;
	case DIO_PORTB:SET_BIT(DIO_PORTB_REG,Copy_u8pin); break;
	case DIO_PORTC:SET_BIT(DIO_PORTC_REG,Copy_u8pin); break;
	case DIO_PORTD:SET_BIT(DIO_PORTD_REG,Copy_u8pin); break;
	default:break ;
	//return error
	}
}

void DIO_voidTogPinValue    (u8 Copy_u8port, u8 Copy_u8pin){
	//check if the pin is in the range of 0 to 7
	if(Copy_u8pin  <= 7 )
	{

			switch(Copy_u8port)
			{
			case DIO_PORTA:TOG_BIT(DIO_PORTA_REG,Copy_u8pin); break;
			case DIO_PORTB:TOG_BIT(DIO_PORTB_REG,Copy_u8pin); break;
			case DIO_PORTC:TOG_BIT(DIO_PORTC_REG,Copy_u8pin); break;
			case DIO_PORTD:TOG_BIT(DIO_PORTD_REG,Copy_u8pin); break;
			default:break ;
			//return error
			}

	}else {
		//return error
	}
}
