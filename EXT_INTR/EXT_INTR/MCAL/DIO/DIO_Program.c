/***************************************************************************************/
/***************************************************************************************/
/* Header Inclusions					     	    */
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"

/*****************************************************************************************************/
/* Function: DIO_voidSetPinValue	                        										 */
/* Input/outPut Parameters:Input params(port number	- Pin number - set value)						 */
/* Returns: void                                													 */
/* Description:	function used to put a certain value 0v/5v on a specific pin inside a defined port   */
/*****************************************************************************************************/

void DIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value)
{
	
		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA:  switch(Copy_u8Value)
			{
				case  DIO_u8_LOW:   CLR_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);     break;
				case  DIO_u8_HIGH:  SET_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);     break;
			}
			break;
			case DIO_u8_PORTB:  switch(Copy_u8Value)
			{
				case  DIO_u8_LOW:   CLR_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);     break;
				case  DIO_u8_HIGH:  SET_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);     break;
			}
			break;
			case DIO_u8_PORTC:  switch(Copy_u8Value)
			{
				case  DIO_u8_LOW:   CLR_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);     break;
				case  DIO_u8_HIGH:  SET_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);     break;
			}
			break;
			case DIO_u8_PORTD:  switch(Copy_u8Value)
			{
				case  DIO_u8_LOW:   CLR_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);     break;
				case  DIO_u8_HIGH:  SET_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);     break;
			}
			break;
			
		}
}


/********************************************************************************************************************/
/* Function: DIO_voidSetPinDirection	                        													*/
/* Input/outPut Parameters:Input params(port number	- Pin number - direction)										*/
/* Returns: void  (nothing)                              															*/
/* Description:	function used to decide the usage of a specific pin inside a defined port either input or output    */
/********************************************************************************************************************/
void DIO_voidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction)
{

		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA:  switch(Copy_u8Direction)
			{
				case  DIO_u8_INPUT:   CLR_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);     break;
				case  DIO_u8_OUTPUT:  SET_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);     break;
			}
			break;
			case DIO_u8_PORTB:  switch(Copy_u8Direction)
			{
				case  DIO_u8_INPUT:   CLR_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);     break;
				case  DIO_u8_OUTPUT:  SET_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);     break;
			}
			break;
			case DIO_u8_PORTC:  switch(Copy_u8Direction)
			{
				case  DIO_u8_INPUT:   CLR_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);     break;
				case  DIO_u8_OUTPUT:  SET_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);     break;
			}
			break;
			case DIO_u8_PORTD:  switch(Copy_u8Direction)
			{
				case  DIO_u8_INPUT:   CLR_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);     break;
				case  DIO_u8_OUTPUT:  SET_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);     break;
			}
			break;
			
		}
}

/********************************************************************************************************************/
/* Function: DIO_voidTogglePin	                        													*/
/* Input/outPut Parameters:Input params(port number	- Pin number)										*/
/* Returns: void  (nothing)                              															*/
/* Description:	function used to toggle pins of ports  */
/********************************************************************************************************************/
void DIO_voidTogglePin(u8 Copy_u8PortId, u8 Copy_u8PinId)
{

	switch(Copy_u8PortId)
	{
		case DIO_u8_PORTA: TOG_BIT(DIO_u8_PORTA_REG,Copy_u8PinId); break;
		
		case DIO_u8_PORTB: TOG_BIT(DIO_u8_PORTA_REG,Copy_u8PinId); break;
		
		case DIO_u8_PORTC: TOG_BIT(DIO_u8_PORTA_REG,Copy_u8PinId); break;
		
		case DIO_u8_PORTD: TOG_BIT(DIO_u8_PORTA_REG,Copy_u8PinId); break;
		break;
		
	}
}

/****************************************************************************************************/
/* Function: DIO_voidGetPinValue	                        										*/
/* Input/outPut Parameters:Input params(port number	- Pin number)									*/
/* Returns: unsigned character with 8 bit size                               						*/
/* Description:	function used to read the value 0v/5v of a specific pin inside a defined port       */
/****************************************************************************************************/
u8 DIO_voidGetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
	
	u8 Local_u8PinValue = 5;
	
		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA:  Local_u8PinValue = GET_BIT(DIO_u8_PINA_REG,Copy_u8PinId);  break;
			case DIO_u8_PORTB:  Local_u8PinValue = GET_BIT(DIO_u8_PINB_REG,Copy_u8PinId);  break;
			case DIO_u8_PORTC:  Local_u8PinValue = GET_BIT(DIO_u8_PINC_REG,Copy_u8PinId);  break;
			case DIO_u8_PORTD:  Local_u8PinValue = GET_BIT(DIO_u8_PIND_REG,Copy_u8PinId);  break;
		}

	return Local_u8PinValue;
}

/****************************************************************************************/
/* Function: DIO_voidSetPortValue	                        							*/
/* Input/outPut Parameters:Input params(port number - set value)						*/
/* Returns: void (no thing)                                								*/
/* Description:	function used to put a certain value 0v/1v on an entire pins of a specific port     */
/****************************************************************************************/
void DIO_voidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value)
{

		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA:  switch(Copy_u8Value)
			{
				case  DIO_u8_LOW:   CLR_PORT(DIO_u8_PORTA_REG);     break;
				case  DIO_u8_HIGH:  SET_PORT(DIO_u8_PORTA_REG);     break;
			}
			break;
			case DIO_u8_PORTB:  switch(Copy_u8Value)
			{
				case  DIO_u8_LOW:   CLR_PORT(DIO_u8_PORTB_REG);     break;
				case  DIO_u8_HIGH:  SET_PORT(DIO_u8_PORTB_REG);     break;
			}
			break;
			case DIO_u8_PORTC:  switch(Copy_u8Value)
			{
				case  DIO_u8_LOW:   CLR_PORT(DIO_u8_PORTC_REG);     break;
				case  DIO_u8_HIGH:  SET_PORT(DIO_u8_PORTC_REG);     break;
			}
			break;
			case DIO_u8_PORTD:  switch(Copy_u8Value)
			{
				case  DIO_u8_LOW:   CLR_PORT(DIO_u8_PORTD_REG);     break;
				case  DIO_u8_HIGH:  SET_PORT(DIO_u8_PORTD_REG);     break;
			}
			break;
			
		}

}

/********************************************************************************************************************/
/* Function: DIO_voidSetPortDirection	                        													*/
/* Input/outPut Parameters:Input params(port number - direction)													*/
/* Returns: void (no thing)                                															*/
/* Description:	function used to decide the usage of the pins of an entire defined port either input or output		*/
/********************************************************************************************************************/
void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction)
{

		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA:  switch(Copy_u8Direction)
			{
				case  DIO_u8_INPUT:   CLR_PORT(DIO_u8_DDRA_REG);     break;
				case  DIO_u8_OUTPUT:  SET_PORT(DIO_u8_DDRA_REG);     break;
			}
			break;
			case DIO_u8_PORTB:  switch(Copy_u8Direction)
			{
				case  DIO_u8_INPUT:   CLR_PORT(DIO_u8_DDRB_REG);     break;
				case  DIO_u8_OUTPUT:  SET_PORT(DIO_u8_DDRB_REG);     break;
			}
			break;
			case DIO_u8_PORTC:  switch(Copy_u8Direction)
			{
				case  DIO_u8_INPUT:   CLR_PORT(DIO_u8_DDRC_REG);     break;
				case  DIO_u8_OUTPUT:  SET_PORT(DIO_u8_DDRC_REG);     break;
			}
			break;
			case DIO_u8_PORTD:  switch(Copy_u8Direction)
			{
				case  DIO_u8_INPUT:   CLR_PORT(DIO_u8_DDRD_REG);     break;
				case  DIO_u8_OUTPUT:  SET_PORT(DIO_u8_DDRD_REG);     break;
			}
			break;
			
		}
	
}

/****************************************************************************************************/
/* Function: DIO_voidGetPortValue	                        										*/
/* Input/outPut Parameters:Input params(port number - direction)									*/
/* Returns: unsigned character with 8 bit size                               						*/
/* Description:	function used to read the value 0v/5v of the entire pins of a defined port			*/
/****************************************************************************************************/
u8 DIO_voidGetPortValue(u8 Copy_u8PortId)
{
	u8 Local_u8PortValue = 0;
	
		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA:  Local_u8PortValue = DIO_u8_PINA_REG;  break;
			case DIO_u8_PORTB:  Local_u8PortValue = DIO_u8_PINB_REG;  break;
			case DIO_u8_PORTC:  Local_u8PortValue = DIO_u8_PINC_REG;  break;
			case DIO_u8_PORTD:  Local_u8PortValue = DIO_u8_PIND_REG;  break;
		}
	
	return Local_u8PortValue;
}
