


 #ifndef REG_H
 #define REG_H


// $1B ($3B) PORTA 
// $1A ($3A) DDRA  
// $19 ($39) PINA  
// $18 ($38) PORTB 
// $17 ($37) DDRB  
// $16 ($36) PINB  
// $15 ($35) PORTC 
// $14 ($34) DDRC  
// $13 ($33) PINC  
// $12 ($32) PORTD 
// $11 ($31) DDRD  
// $10 ($30) PIND  
/***************************************DIO Register Summary ************************ */
/* I/O regsters for Port A */
#define DIO_PORTA_REG *((volatile u8 *)(0x3B))
#define DIO_DDRA_REG  *((volatile u8 *)(0x3A))
#define DIO_PINA_REG  *((volatile u8 *)(0x39))

/* I/O regsters for Port B */
#define DIO_PORTB_REG *((volatile u8 *)(0x38))
#define DIO_DDRB_REG  *((volatile u8 *)(0x37))  
#define DIO_PINB_REG  *((volatile u8 *)(0x36))

/* I/O regsters for Port C */
#define DIO_PORTC_REG *((volatile u8 *)(0x35))
#define DIO_DDRC_REG  *((volatile u8 *)(0x34))
#define DIO_PINC_REG  *((volatile u8 *)(0x33))

/* I/O regsters for Port D */
#define DIO_PORTD_REG *((volatile u8 *)(0x32))
#define DIO_DDRD_REG  *((volatile u8 *)(0x31))
#define DIO_PIND_REG  *((volatile u8 *)(0x30))

/********************************************************************************/
/************************************* SREG ****************/
//$3F ($5F) SREG

#define SREG_REG    *((volatile u8* )(0x3F))
#define GIE_BIT     7


/*********************************** EXTI ******************************/

#define EXTI_GICR_REG        *((volatile u8* )(0x5B))
#define EXTI_GICR_INT1       7
#define EXTI_GICR_INT0       6
#define EXTI_GICR_INT2       5

#define EXTI_GIFR_REG        *((volatile u8* )(0x5A))
#define EXTI_GIFR_INTF1      7
#define EXTI_GIFR_INTF0      6
#define EXTI_GIFR_INTF2      5

#define EXTI_MCUCR_REG       *((volatile u8* )(0x55))
#define EXTI_MCUCR_ISC00     0
#define EXTI_MCUCR_ISC01     1
#define EXTI_MCUCR_ISC10     2
#define EXTI_MCUCR_ISC11     3

#define EXTI_MCUCSR_REG      *((volatile u8* )(0x54))
#define EXTI_MCUCSR_ISC2     6

/**************************ADC Reg ***************************/


/*ADC Multiplexer Register */
#define ADC_ADMUX_REG        *((volatile u8* )(0x27))
#define ADC_ADMUX_REFS1      7
#define ADC_ADMUX_REFS0      6
#define ADC_ADMUX_ADLAR      5
/*ADC Control Register */
#define ADC_ADCSRA_REG       *((volatile u8* )(0x26))
#define ADC_ADCSRA_ADEN      7
#define ADC_ADCSRA_ADSC      6
#define ADC_ADCSRA_ADATE     5
#define ADC_ADCSRA_ADIF      4
#define ADC_ADCSRA_ADIE      3
#define ADC_ADCSRA_ADPS2     2
#define ADC_ADCSRA_ADPS1     1
#define ADC_ADCSRA_ADPS0     0

/*ADC Data Register */
#define ADC_ADC_REG          *((volatile u16*)(0x24))
#define ADC_ADCL_REG         *((volatile u8* )(0x24))
#define ADC_ADCH_REG         *((volatile u8* )(0x25))



/*******TIMER 0 Registers ****/

/*
$39 ($59) TIMSK OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0 82, 112, 130
$38 ($58) TIFR OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0 83, 112, 130
$33 ($53) TCCR0 FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00 80
$32 ($52) TCNT0 Timer/Counter0 (8 Bits) 82
$3C ($5C) OCR0 Timer/Counter0 Output Compare Register 82
*/
#define TIMER0_OCR0_REG            *((volatile u8* )(0x5C))

#define TIMER0_TIMSK_REG           *((volatile u8* )(0x59))

#define TIMER0_TIMSK_TOIE0         0
#define TIMER0_TIMSK_OCIE0         1

#define TIMER0_TIFR_REG            *((volatile u8* )(0x58))

#define TIMER0_TIFR_TOV0           0

#define TIMER0_TCCR0_REG          *((volatile u8* )(0x53))

#define TIMER0_TCCR0_FOC0          7
#define TIMER0_TCCR0_WGM00         6
#define TIMER0_TCCR0_COM01         5
#define TIMER0_TCCR0_COM00         4
#define TIMER0_TCCR0_WGM01         3


#define TIMER0_TCNT0_REG          *((volatile u8* )(0x52))


/************************* SPI Registers **************/

/*
 $0F ($2F) SPDR SPI Data Register 138
 $0E ($2E) SPSR SPIF WCOL––––– SPI2X 138
 $0D ($2D) SPCR SPIE SPE DORD MSTR CPOL CPHA SPR1 SPR0 136
 */


#define SPI_DATA_REG          *((volatile u8* )(0x2f))   /*spi data Register */

#define SPI_CTRL_REG          *((volatile u8* )(0x2D))   /*spi Control Register*/
#define SPI_CTRL_SPIE          7
#define SPI_CTRL_SPE           6
#define SPI_CTRL_DORD          5
#define SPI_CTRL_MSTR          4
#define SPI_CTRL_CPOL          3
#define SPI_CTRL_CPHA          2
#define SPI_CTRL_SPR1          1
#define SPI_CTRL_SPR0          0


#define SPI_STAT_REG          *((volatile u8* )(0x2E))  /*Spi Status Register */
#define SPI_STAT_SPIF         7
#define SPI_STAT_WCOL         6
#define SPI_STAT_SPI2X        0


/**************************************USART *******************/


#define UART_UDR_REG          *((volatile u8 *)(0x2c))
#define UART_UCSRA_REG        *((volatile u8 *)(0x2B))
#define UART_UCSRB_REG        *((volatile u8 *)(0x2A))
#define UART_UCSRC_REG        *((volatile u8 *)(0x40))
#define UART_UBRRH_REG        *((volatile u8 *)(0x40))
#define UART_UBRRL_REG        *((volatile u8 *)(0x29))


// $0B ($2B) UCSRA RXC TXC UDRE FE DOR PE U2X MPCM 160
// CONTROL REGISTER a
#define UART_RXC  7
#define UART_TXC  6
#define UART_UDRE 5
#define UART_FE   4
#define UART_DOR  3
#define UART_PE   2
#define UART_U2X  1
#define UART_MPCM 0


// $0A ($2A)  RXCIE TXCIE UDRIE RXEN TXEN UCSZ2 RXB8 TXB8 161
// CONTROL REGISTER a
#define UART_RXCIE   7
#define UART_TXCIE   6
#define UART_UDRIE   5
#define UART_RXEN    4
#define UART_TXEN    3
#define UART_UCSZ2   2
#define UART_RXB8    1
#define UART_TXB8    0

// The URSEL must be one when writing the UCSRC
// UCSRC ||  URSEL UMSEL UPM1 UPM0 USBS UCSZ1 UCSZ0 UCPOL 16
// CONTROL REGISTER C UPM1
#define UART_URSEL   7
#define UART_UMSEL   6
#define UART_UPM1    5
#define UART_UPM0    4
#define UART_USBS    3
#define UART_UCSZ1   2
#define UART_UCSZ0   1
#define UART_UCPOL   0



/*********************************** TWI Registers *************************/


/* $03 ($23) TWDR Two-wire Serial Interface Data Register 179
 $02 ($22) TWAR TWA6 TWA5 TWA4 TWA3 TWA2 TWA1 TWA0 TWGCE 179
 $01 ($21) TWSR TWS7 TWS6 TWS5 TWS4 TWS3–TWPS1 TWPS0 178
 $00 ($20) TWBR Two-wire Serial Interface Bit Rate Register
 $36 ($56) TWCR TWINT TWEA TWSTA TWSTO TWWC TWEN– TWIE*/




#define TWI_STATUS_REG             *((volatile u8* )(0x21))
#define TWI_STATUS_TWPS0           0
#define TWI_STATUS_TWPS1           1
#define TWI_ADDRESS_REG            *((volatile u8* )(0x32))
#define TWI_ADDRESS_TWGCE          0
#define TWI_BIT_RATE_REG           *((volatile u8* )(0x20))
#define TWI_Data_REG               *((volatile u8* )(0x23))

#define TWI_CTRL_REG               *((volatile u8* )(0x36))
#define TWI_CTRL_TWINT              7
#define TWI_CTRL_TWEA               6
#define TWI_CTRL_TWSTA              5
#define TWI_CTRL_TWSTO              4
#define TWI_CTRL_TWWC               3
#define TWI_CTRL_TWEN               2
#define TWI_CTRL_TWIE               0


/************************** Begin internal EEprom Registers ****************/
/*
$1F ($3F) EEARH – – – – – – EEAR9 EEAR8 19
$1E ($3E) EEARL EEPROM Address Register Low Byte 19
$1D ($3D) EEDR EEPROM Data Register 19
$1C ($3C) EECR – – – – EERIE EEMWE EEWE EERE 19
*/
#define IN_EEPROM_DATA_REG              *((volatile u8* )(0x3D))
#define IN_EEPROM_ADDR_REG              *((volatile u16*)(0x3E))
#define IN_EEPROM_CTRL_REG              *((volatile u8* )(0x3C))

#define IN_EEPROM_CTRL_EERE              0
#define IN_EEPROM_CTRL_EEWE              1
#define IN_EEPROM_CTRL_EEMWE             2
#define IN_EEPROM_CTRL_EERIE             3

/************************** End internal EEprom Registers ****************/
#endif










 
