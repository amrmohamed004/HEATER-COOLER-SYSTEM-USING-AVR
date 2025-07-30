/*
 * BOTTONS.c
 *
 * Created: 09/07/2025 11:15:50 ص
 *  Author: 3mR
 */ 
#include "../../Service/Std_type.h"
#include <util/delay.h>
#include "../../MCAL/reg.h"

#include "BUTTONS.h"
#include "BUTTONS_cfg.h"
#include "../../MCAL/DIO/DIO_int.h"



void buttons_init() {
	DIO_voidSetPinDirection(BUTTON_UP_PORT,BUTTON_UP_PIN,DIO_PIN_INPUT);
	DIO_voidSetPinDirection(BUTTON_DOWN_PORT,BUTTON_DOWN_PIN,DIO_PIN_INPUT);
	
	DIO_voidEnablePullUp(BUTTON_UP_PORT,BUTTON_UP_PIN);
	DIO_voidEnablePullUp(BUTTON_DOWN_PORT,BUTTON_DOWN_PIN);
	DIO_voidEnablePullUp(BUTTON_ON_OFF_PORT,BUTTON_ON_OFF_PIN);
	
	
}

u8 button_up_pressed() {
	
	return DIO_u8GetPinValue(BUTTON_UP_PORT,BUTTON_UP_PIN)==0;
}

u8 button_down_pressed() {
		return DIO_u8GetPinValue(BUTTON_DOWN_PORT,BUTTON_DOWN_PIN)==0;

}
u8 button_on_off_pressed() {
	static u8 last_state = 1;
	u8 current_state = DIO_u8GetPinValue(BUTTON_ON_OFF_PORT, BUTTON_ON_OFF_PIN); 

	if (last_state == 1 && current_state == 0) {
		_delay_ms(50); 
		last_state = 0;
		return 1;
	}
	if (current_state == 1) {
		last_state = 1;
	}
	return 0;
}
