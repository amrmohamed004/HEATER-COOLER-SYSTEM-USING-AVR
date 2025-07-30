
#include "../../Service/Std_type.h"


 #ifndef DIO_INT_H
 #define DIO_INT_H
/*Define POrts */
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3
/*define pins */
#define DIO_PIN_0 0
#define DIO_PIN_1 1
#define DIO_PIN_2 2
#define DIO_PIN_3 3
#define DIO_PIN_4 4
#define DIO_PIN_5 5
#define DIO_PIN_6 6
#define DIO_PIN_7 7

/*Define Direction */
#define DIO_PORT_OUTPUT 0xff
#define DIO_PORT_INPUT  0x00
#define DIO_PORT_HIGH   0xff
#define DIO_PORT_LOW    0x00

#define DIO_PIN_INPUT  0
#define DIO_PIN_OUTPUT 1
#define DIO_PIN_HIGH   1
#define DIO_PIN_LOW    0

void DIO_voidSetPinDirection(u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8direction);
void DIO_voidSetPinValue    (u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8value);
u8   DIO_u8GetPinValue      (u8 Copy_u8port, u8 Copy_u8pin);

void DIO_voidSetPortDirection(u8 Copy_u8port,  u8 Copy_u8direction);
void DIO_voidSetPortValue    (u8 Copy_u8port,  u8 Copy_u8value);
u8   DIO_u8GetPortValue      (u8 Copy_u8port);
void DIO_voidEnablePullUp(u8 Copy_u8port, u8 Copy_u8pin);
void DIO_voidTogPinValue    (u8 Copy_u8port, u8 Copy_u8pin);

 #endif
