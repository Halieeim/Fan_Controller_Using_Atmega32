 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega32 ADC driver
 *
 * Author: Ahmed Abd El-Halim Ahmed
 *
 *******************************************************************************/

#include <avr/io.h>
#include "common_macros.h"
#include "adc.h"

void ADC_init(const ADC_ConfigType * Config_Ptr){
	/* setup voltage reference */
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt)<<6);
	/*
	 * Enable ADC
	 * setting prescaler
	 */
	ADCSRA = (1<<ADEN) | ((ADMUX & 0xF8) | (Config_Ptr->prescaler));
}


uint16 ADC_readChannel(uint8 ch_num){
	ADMUX &= 0xE0;
	ADMUX |= (0x07)&(ch_num); /* channel number must be from 0 to 7 */
	ADCSRA |= 1<<ADSC;
	while(BIT_IS_CLEAR(ADCSRA,ADIF)){ /* Polling till ADC interrupt flag is set */

	}
	SET_BIT(ADCSRA,ADIF); /* clearing ADC interrupt flag */
	return ADC;
}




