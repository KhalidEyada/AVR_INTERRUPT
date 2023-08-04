/***************************************************************************************/
/***************************************************************************************/
/* Header Inclusions					     	    */
/****************************************************/

//File guard 
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "STD_TYPES.h"

//Registers macros
#define DIO_u8_PORTA      0
#define DIO_u8_PORTB      1
#define DIO_u8_PORTC      2
#define DIO_u8_PORTD      3

//Pins macros
#define DIO_u8_PIN0       0
#define DIO_u8_PIN1       1
#define DIO_u8_PIN2       2
#define DIO_u8_PIN3       3
#define DIO_u8_PIN4       4
#define DIO_u8_PIN5       5
#define DIO_u8_PIN6       6
#define DIO_u8_PIN7       7

//Other macros
#define DIO_u8_LOW        0
#define DIO_u8_HIGH       1
 
#define DIO_u8_INPUT      0
#define DIO_u8_OUTPUT     1


/*****************************************************************************************************/
/* Function: DIO_voidSetPinValue	                        										 */
/* Input/outPut Parameters:Input params(port number	- Pin number - set value)						 */
/* Returns: void                                													 */
/* Description:	function used to put a certain value 0v/5v on a specific pin inside a defined port   */
/*****************************************************************************************************/
void DIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value);

/********************************************************************************************************************/
/* Function: DIO_voidSetPinDirection	                        													*/
/* Input/outPut Parameters:Input params(port number	- Pin number - direction)										*/
/* Returns: void  (nothing)                              															*/
/* Description:	function used to decide the usage of a specific pin inside a defined port either input or output    */
/********************************************************************************************************************/

void DIO_voidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction);

/********************************************************************************************************************/
/* Function: DIO_voidTogglePin	                        													*/
/* Input/outPut Parameters:Input params(port number	- Pin number)										*/
/* Returns: void  (nothing)                              															*/
/* Description:	function used to toggle pins of ports  */
/********************************************************************************************************************/
void DIO_voidTogglePin(u8 Copy_u8PortId, u8 Copy_u8PinId);

/****************************************************************************************************/
/* Function: DIO_voidGetPinValue	                        										*/
/* Input/outPut Parameters:Input params(port number	- Pin number)									*/
/* Returns: unsigned character with 8 bit size                               						*/
/* Description:	function used to read the value 0v/5v of a specific pin inside a defined port       */
/****************************************************************************************************/
u8 DIO_voidGetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);

/****************************************************************************************/
/* Function: DIO_voidSetPortValue	                        							*/
/* Input/outPut Parameters:Input params(port number - set value)						*/
/* Returns: void (no thing)                                								*/
/* Description:	function used to put a certain value 0v/1v on an entire pins of a specific port     */
/****************************************************************************************/
void DIO_voidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value);

/********************************************************************************************************************/
/* Function: DIO_voidSetPortDirection	                        													*/
/* Input/outPut Parameters:Input params(port number - direction)													*/
/* Returns: void (no thing)                                															*/
/* Description:	function used to decide the usage of the pins of an entire defined port either input or output		*/
/********************************************************************************************************************/
void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction);

/****************************************************************************************************/
/* Function: DIO_voidGetPortValue	                        										*/
/* Input/outPut Parameters:Input params(port number - direction)									*/
/* Returns: unsigned character with 8 bit size                               						*/
/* Description:	function used to read the value 0v/5v of the entire pins of a  defined port			*/
/****************************************************************************************************/
u8 DIO_voidGetPortValue(u8 Copy_u8PortId);

#endif
/***************************************************************************************/