#include "../../Service/Std_type.h"
#include "../../Service/bit_math.h"
#include "../reg.h"
#include "IN_EEPROM_int.h"


void IN_EEPROM_voidReadDataByte (u16 Copy_u16Address, u8* Copy_u8Data){
	/* Wait for completion of previous write */
	while(GET_BIT(IN_EEPROM_CTRL_REG,IN_EEPROM_CTRL_EEWE) == 1 );
	/* Set up address register */
	IN_EEPROM_ADDR_REG = Copy_u16Address ;
	/* Start eeprom read by writing EERE */
	SET_BIT(IN_EEPROM_CTRL_REG,IN_EEPROM_CTRL_EERE);
	/* Return data from data register */
	*Copy_u8Data = IN_EEPROM_DATA_REG ;
}
void IN_EEPROM_voidWriteDataByte(u16 Copy_u16Address, u8  Copy_u8Data){
	/* Wait for completion of previous write */
	while(GET_BIT(IN_EEPROM_CTRL_REG,IN_EEPROM_CTRL_EEWE) == 1 );
	/* Set up address register */
	IN_EEPROM_ADDR_REG = Copy_u16Address ;
	/* Write logical one to EEMWE */
	/* Start eeprom write by setting EEWE */
	IN_EEPROM_CTRL_REG = (1<<IN_EEPROM_CTRL_EEMWE) | (1<<IN_EEPROM_CTRL_EEWE) ;

	/*todo Diable Global Interupt before write */
	/*todo enable Global Interupt after write */
}

