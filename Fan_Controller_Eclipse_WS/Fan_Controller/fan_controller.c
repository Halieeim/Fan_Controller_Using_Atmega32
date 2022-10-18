/******************************************************************************
 *
 * Module: Fan Controller APP
 *
 * File Name: fan_controller.c
 *
 * Description: source file for the Fan Controller APP
 *
 * Author: Ahmed Abd El-Halim Ahmed
 *
 *******************************************************************************/

#include "lcd.h"
#include "lm35_sensor.h"
#include "DcMotor.h"
#include "adc.h"

int main(){
	uint8 temperature;
	/* Configure ADC with required voltage reference and prescaler */
	ADC_ConfigType config = {INTERNAL_REF_2_56_V,PRESCALE_8};
	ADC_init(&config);
	LCD_init();			/* initializing LCD */
	DcMotor_Init();		/* initializing DC Motor */
	DcMotor_State state = STOP;

	for(;;){
		/* Read the temperature and control the DC motor depending on it */
		temperature = LM35_getTemperature();
		if(temperature < 30){
			state = STOP;
			DcMotor_Rotate(state, 0);
		}
		else if(temperature >= 120){
			state = CW;
			DcMotor_Rotate(state, 100);
		}
		else if(temperature >= 90){
			state = CW;
			DcMotor_Rotate(state, 75);
		}
		else if(temperature >= 60){
			state = CW;
			DcMotor_Rotate(state, 50);
		}
		else if(temperature >= 30){
			state = CW;
			DcMotor_Rotate(state, 25);
		}

		/* Print the state of the DC motor on the LCD */
		if(state == STOP){
			LCD_displayStringRowColumn(0, 3, "Fan is OFF");
		}
		else{
			LCD_displayStringRowColumn(0, 3, "Fan is ON ");
		}

		/* Print the temperature on the LCD */
		LCD_displayStringRowColumn(1, 3, "Temp = ");
		LCD_integerToString(temperature);
		if(temperature < 100){
			LCD_displayChar(' ');
		}
		LCD_displayString("C");
	}
}











