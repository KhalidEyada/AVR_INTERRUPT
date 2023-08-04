/*
 * LED.c
 *
 * Created: 7/31/2023 11:26:28 AM
 *  Author: khaled
 */ 

#include "../MCAL/EXT/EXTINT_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/DIO/DIO_Interface.h"

u8 Global_u8PortId =0; /*local variable for used port assigned on LED_INIT*/
u8 Global_u8PinId =0;  /*local variable for used pin assigned on LED_INIT*/

/**
@brief Initialize and enable an external interrupt.
This function initializes and enables the specified external interrupt (INT0, INT1, or INT2) with the provided edge triggering mode.
Additionally, it sets the necessary configuration for the interrupt pin (direction and initial value).
@param Copy_u8ExtIntNum: The external interrupt number (INT0, INT1, or INT2) to be initialized and enabled.
@param Copy_u8EdgeIntSource: The edge triggering mode for the external interrupt (Falling, Rising, Any Change, Low Level).
*/
void LED_Interrupt_INIT(u8 Copy_u8ExtIntNum , u8 Copy_u8EdgeIntSource){
	
	EXTINT_voidEnable(Copy_u8ExtIntNum,Copy_u8EdgeIntSource);
	switch (Copy_u8EdgeIntSource){
		case EXTINT_INT0:
			DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_INPUT);
			DIO_voidSetPinValue(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_HIGH);
			break;
		case EXTINT_INT1:
			DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN3,DIO_u8_INPUT);
			DIO_voidSetPinValue(DIO_u8_PORTD,DIO_u8_PIN3,DIO_u8_HIGH);
		break;	
		case EXTINT_INT2:
			DIO_voidSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_INPUT);
			DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);
		break;

	}
	
}

/**

@brief Initialize the LED pin as an output.
This function sets the direction of the LED pin (connected to PORTA, PIN0) as an output.
It prepares the pin to be used to control an LED, allowing it to be turned ON or OFF by writing to the pin.
*/
void LED_INIT(u8 Copy_u8PortId, u8 Copy_u8PinId){
	DIO_voidSetPinDirection(Copy_u8PortId,Copy_u8PinId,DIO_u8_OUTPUT);
	Global_u8PortId=Copy_u8PortId;
	Global_u8PinId=Copy_u8PinId ;
}

/**
@brief Toggle the state of the LED.
This function toggles the state of the LED connected to PORTA, PIN0.
If the LED is currently ON, it will be turned OFF, and vice versa.
*/
void LED_Toggle(){
	DIO_voidTogglePin(Global_u8PortId,Global_u8PinId);	
}

/**
@brief LED Interrupt Service Routine (ISR) callback function.
This function is an Interrupt Service Routine (ISR) callback that is called when the external interrupt INT0 is triggered.
When the INT0 external interrupt occurs, this function is executed, and it calls the LED_Toggle() function to toggle the state of the LED.
*/
void LED_ISR(u8 Copy_u8EdgeIntSource){
	EXTINT_voidSetCallBack(LED_Toggle,Copy_u8EdgeIntSource);	
}
