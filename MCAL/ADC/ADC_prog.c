#include "../../Service/Std_type.h"
#include "../../Service/bit_math.h"
#include "../reg.h"
#include "ADC_int.h"



void ADC_voidInit(){
	//	select prescalar
	//	select 128
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADPS0);
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADPS1);
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADPS2);

	//	select reference voltage
	//	select AVCC
	SET_BIT(ADC_ADMUX_REG,ADC_ADMUX_REFS0);
	CLR_BIT(ADC_ADMUX_REG,ADC_ADMUX_REFS1);

	//	enable ADC
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADEN);

}
u16 ADC_u16StartConversion(u8 Copy_u8ChannelID){
	//	 select channel
	ADC_ADMUX_REG &= 0b11111000;   //mask
	ADC_ADMUX_REG |= Copy_u8ChannelID;   //mask

	//   start conversion
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADSC);


	//	check on flag

	while (GET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADIF) == 0 )
	{
		/*pooling */
	}
	//	return ADC val
	return ADC_ADC_REG ;
}
