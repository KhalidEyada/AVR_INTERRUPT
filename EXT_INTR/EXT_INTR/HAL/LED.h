/*
 * LED.h
 *
 * Created: 7/31/2023 11:26:43 AM
 *  Author: khale
 */ 


#ifndef LED_H_
#define LED_H_

/**
@brief Initialize and enable an external interrupt.
This function initializes and enables the specified external interrupt (INT0, INT1, or INT2) with the provided edge triggering mode.
Additionally, it sets the necessary configuration for the interrupt pin (direction and initial value).
@param Copy_u8ExtIntNum: The external interrupt number (INT0, INT1, or INT2) to be initialized and enabled.
@param Copy_u8EdgeIntSource: The edge triggering mode for the external interrupt (Falling, Rising, Any Change, Low Level).
*/
void LED_Interrupt_INIT(u8 Copy_u8ExtIntNum , u8 Copy_u8EdgeIntSource);

/**
@brief Initialize the LED pin as an output.
This function sets the direction of the LED pin (connected to PORTA, PIN0) as an output.
It prepares the pin to be used to control an LED, allowing it to be turned ON or OFF by writing to the pin.
*/
void LED_INIT(u8 Copy_u8PortId, u8 Copy_u8PinId);

/**
@brief LED Interrupt Service Routine (ISR) callback function.
This function is an Interrupt Service Routine (ISR) callback that is called when the external interrupt INT0 is triggered.
When the INT0 external interrupt occurs, this function is executed, and it calls the LED_Toggle() function to toggle the state of the LED.
*/
void LED_ISR(u8 Copy_u8EdgeIntSource);



#endif /* LED_H_ */