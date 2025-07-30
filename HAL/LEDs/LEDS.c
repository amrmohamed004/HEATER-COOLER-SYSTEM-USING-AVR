/*
 * LEDS.c
 *
 * Created: 09/07/2025 11:17:20 ص
 *  Author: 3mR
 */ 
#include "../../MCAL/reg.h"
#include "LEDS.h"
#include "LEDS_cfg.h"
#include "../../MCAL/DIO/DIO_int.h"


#include "../../Service/Std_type.h"


void leds_init(void) {
	DIO_voidSetPinDirection(RED_LED_PORT,RED_LED_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(BLUE_LED_PORT,BLUE_LED_PIN,DIO_PIN_OUTPUT);
	
	DIO_voidSetPinValue(RED_LED_PORT,RED_LED_PIN,DIO_PIN_LOW);
	DIO_voidSetPinValue(BLUE_LED_PORT,BLUE_LED_PIN,DIO_PIN_LOW);
	
	
}


void red_led_on(void) {
	DIO_voidSetPinValue(RED_LED_PORT,RED_LED_PIN,DIO_PIN_HIGH);
}

void red_led_off(void) {
	DIO_voidSetPinValue(RED_LED_PORT,RED_LED_PIN,DIO_PIN_LOW);
	
}

void blue_led_on(void) {
	DIO_voidSetPinValue(BLUE_LED_PORT,BLUE_LED_PIN,DIO_PIN_HIGH);
	
}

void blue_led_off(void) {
	DIO_voidSetPinValue(BLUE_LED_PORT,BLUE_LED_PIN,DIO_PIN_LOW);
	
}