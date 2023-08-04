/*
 * MAIN.c
 *
 * Created: 7/31/2023 11:26:28 AM
 *  Author: Khaled
 */ 
#include "../MCAL/EXT/EXTINT_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED.h"


int main(void)
{
	GIE_voidGlobalInterruptEnable();/*enable global interrupt*/
	
	LED_Interrupt_INIT(EXTINT_INT0,EXTINT_FALLING_EDGE);/*initiate the interrupt*/
	LED_INIT(DIO_u8_PORTA,DIO_u8_PIN0);/*initiate the LED*/
	LED_ISR(EXTINT_INT0);/*RUN LED ISR*/
	
    while (1) 
    {
		
    }
}

