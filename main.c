/*
 * HEATER_COOLER_SYSTEM.c
 *
 * Created: 27/07/2025 04:57:58 م
 * Author : 3mR
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>

#include "MCAL/ADC/ADC_int.h"
#include "MCAL/DIO/DIO_int.h"
#include "HAL/BUTTONS/BUTTONS.h"
#include "HAL/HEAT_COOL/HEAT_COOL_INT.h"
#include "MCAL/IN_EEPROM/IN_EEPROM_int.h"
#include "HAL/LEDS/LEDS.h"
#include "HAL/CLCD/CLCD_int.h"
#include "Service/Std_type.h"

#define INIT_TEMP       60
#define MIN_TEMP        35
#define MAX_TEMP        75
#define MARGIN_TEMP     5
#define TEMP_AVG_COUNT  10
#define STABLE_LIMIT    5

u8 desired_temp;
u16 actual_temp;
u8 blink_flag = 0;
u8 setting_mode = 0;
u8 system_state = 0;
u16 temp_read[TEMP_AVG_COUNT] = {0};
u8 temp_index = 0;

u8 heating_sim = 0;
u8 cooling_sim = 0;
u8 failure_flag = 0;
u8 stable_count = 0;
u16 last_sensor_temp = 0;

char status_msg[16] = "Stable    ";

void setup() {
	CLCD_voidInit();
	ADC_voidInit();
	buttons_init();
	heat_cool_init();
	leds_init();

	u8 saved;
	IN_EEPROM_voidReadDataByte(0x00, &saved);
	desired_temp = (saved >= MIN_TEMP && saved <= MAX_TEMP) ? saved : INIT_TEMP;
}

u16 get_avg_temp() {
	u32 sum = 0;
	for (u8 i = 0; i < TEMP_AVG_COUNT; i++) {
		sum += temp_read[i];
	}
	return (u16)(sum / TEMP_AVG_COUNT);
}

void buttons() {
	if (button_on_off_pressed()) {
		system_state = !system_state;

		if (!system_state) {
			CLCD_voidClearDisp();
			heat_off();
			cool_off();
			red_led_off();
			blue_led_off();
			strcpy(status_msg, "System Off ");
		}
		_delay_ms(10);
	}

	if (system_state) {
		if (button_up_pressed()) {
			if (!setting_mode) setting_mode = 1;
			if (desired_temp < MAX_TEMP) {
				desired_temp += 5;
				IN_EEPROM_voidWriteDataByte(0x00, desired_temp);
			}
			_delay_ms(10);
		}

		if (button_down_pressed()) {
			if (!setting_mode) setting_mode = 1;
			if (desired_temp > MIN_TEMP) {
				desired_temp -= 5;
				IN_EEPROM_voidWriteDataByte(0x00, desired_temp);
			}
			_delay_ms(10);
		}
	}
}

void display() {
	char str[16];
	CLCD_voidGoToX_Y(0, 0);
	CLCD_voidSendString((u8 *)"Act:");
	itoa(actual_temp, str, 10);
	CLCD_voidSendString((u8 *)str);

	CLCD_voidGoToX_Y(8, 0);
	CLCD_voidSendString((u8 *)"Set:");
	itoa(desired_temp, str, 10);
	CLCD_voidSendString((u8 *)str);

	CLCD_voidGoToX_Y(0, 1);
	CLCD_voidSendString((u8 *)status_msg);
}

void heat_cool() {
	if (actual_temp >= desired_temp + MARGIN_TEMP) {
		heat_off();
		cool_on();
		red_led_off();
		blue_led_on();
		cooling_sim = 1;
		heating_sim = 0;

		if (failure_flag){
			strcpy(status_msg, "Cool FAIL");
			cool_off();
			blue_led_off();
		}
		else
		strcpy(status_msg, "Cooling ");
	}
	else if (actual_temp <= desired_temp - MARGIN_TEMP) {
		cool_off();
		heat_on();
		blue_led_off();

		if (blink_flag) red_led_on();
		else red_led_off();
		blink_flag = !blink_flag;

		heating_sim = 1;
		cooling_sim = 0;

		if (failure_flag){
			strcpy(status_msg, "Heat FAIL");
			heat_off();
			red_led_off();
		}
		else
		strcpy(status_msg, "Heating ");
	}
	else {
		heat_off();
		cool_off();
		red_led_off();
		blue_led_off();
		heating_sim = 0;
		cooling_sim = 0;
		failure_flag = 0;
		stable_count = 0;
		strcpy(status_msg, "Stable     ");
	}
}

int main() {
	setup();

	while (1) {
		buttons();

		if (system_state) {
			u16 new_temp = (ADC_u16StartConversion(0) * 500UL) / 1024;
			temp_read[temp_index++] = new_temp;
			if (temp_index >= TEMP_AVG_COUNT) temp_index = 0;
			u16 sensor_temp = get_avg_temp();

			actual_temp = sensor_temp;

			
			if (heating_sim || cooling_sim) {
				if (sensor_temp == last_sensor_temp) {
					stable_count++;
					if (stable_count >= STABLE_LIMIT) {
						failure_flag = 1;
					}
					} else {
					stable_count = 0;
					failure_flag = 0;
				}
				} else {
				stable_count = 0;
				failure_flag = 0;
			}
			last_sensor_temp = sensor_temp;

			display();
			heat_cool();
		}

		_delay_ms(100);
	}
}

