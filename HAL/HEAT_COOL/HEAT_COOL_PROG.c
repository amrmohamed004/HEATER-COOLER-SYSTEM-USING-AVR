/*
 * HEAT_COOL_PROG.c
 *
 * Created: 09/07/2025 11:14:41 ص
 *  Author: 3mR
 */ 
#include "../../Service/Std_type.h"
#include "../../MCAL/reg.h"
#include "HEAT_COOL_INT.h"
#include "HEAT_COOL_cfg.h"
#include "../../MCAL/DIO/DIO_int.h"


void heat_cool_init() {
	DIO_voidSetPinDirection(HEATER_PORT,HEATER_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(COOLER_PORT,COOLER_PIN,DIO_PIN_OUTPUT);
	
DIO_voidSetPinValue(HEATER_PORT,HEATER_PIN,DIO_PIN_LOW);
DIO_voidSetPinValue(COOLER_PORT,COOLER_PIN,DIO_PIN_LOW);

}

void heat_on()  { 
DIO_voidSetPinValue(HEATER_PORT,HEATER_PIN,DIO_PIN_HIGH);
 }
void heat_off() { 
DIO_voidSetPinValue(HEATER_PORT,HEATER_PIN,DIO_PIN_LOW);

 }

void cool_on()  {
DIO_voidSetPinValue(COOLER_PORT,COOLER_PIN,DIO_PIN_HIGH);

 }
void cool_off() { 
DIO_voidSetPinValue(COOLER_PORT,COOLER_PIN,DIO_PIN_LOW);

}