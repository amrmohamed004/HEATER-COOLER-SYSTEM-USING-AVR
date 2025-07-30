
#ifndef HAL_CLCD_CLCD_CFG_H_
#define HAL_CLCD_CLCD_CFG_H_

/*mode*/
/*CLCD_4_BIT*/
/*CLCD_8_BIT*/
#define CLCD_MODE CLCD_4_BIT


#define CLCD_DATA_PORT DIO_PORTA /*Configure data port */
#if CLCD_MODE == CLCD_4_BIT
#define CLCD_DATA_PIN_1 DIO_PIN_4
#define CLCD_DATA_PIN_2 DIO_PIN_5
#define CLCD_DATA_PIN_3 DIO_PIN_6
#define CLCD_DATA_PIN_4 DIO_PIN_7
#endif

#define CLCD_CTRL_PORT DIO_PORTB /*Configure data port */

#define CLCD_RS_PIN    DIO_PIN_0 /*Rs*/
#define CLCD_RW_PIN    DIO_PIN_1 /*Rs*/
#define CLCD_EN_PIN    DIO_PIN_2 /*Rs*/
/*RW*/
/*EN*/



#endif /* HAL_CLCD_CLCD_CFG_H_ */
