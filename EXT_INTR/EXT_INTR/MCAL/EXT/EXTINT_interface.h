
#ifndef EXTINT_INTERFACE_H_
#define EXTINT_INTERFACE_H_
#include "../LIB/STD_TYPES.h"

#define EXTINT_INT0         1
#define EXTINT_INT1         2
#define EXTINT_INT2         3

#define EXTINT_FALLING_EDGE       1
#define EXTINT_RAISING_EDGE       2
#define EXTINT_ANY_LOGICAL_CHANGE 3
#define EXTINT_LOW_LEVEL          4

/**
@brief Enable specified external interrupt with the given edge triggering mode.
This function enables external interrupts (INT0, INT1, or INT2) with the specified edge triggering mode.
It configures the hardware registers accordingly and enables the global interrupt for the selected interrupt.
@param Copy_u8ExtIntNum: The external interrupt number (INT0, INT1, or INT2) to be enabled.
@param Copy_u8EdgeIntSource: The edge triggering mode for the external interrupt (Falling, Rising, Any Change, Low Level).
*/
void EXTINT_voidEnable(u8 Copy_u8ExtIntNum , u8 Copy_u8EdgeIntSource);

/**
@brief Disable specified external interrupt.
This function disables the specified external interrupt (INT0, INT1, or INT2) by clearing its corresponding global interrupt bit.
@param Copy_u8ExtIntNum: The external interrupt number (INT0, INT1, or INT2) to be disabled.
*/
void EXTINT_voidDisable(u8 Copy_u8ExtIntNum);

/*
@brief Set the callback function for a specific external interrupt.
This function sets the callback function to be executed when a specific external interrupt (INT0, INT1, or INT2) occurs.
@param Copy_pfun: Pointer to the function to be called when the external interrupt occurs.
@param Copy_u8ExtIntIndex: The index of the external interrupt (INT0, INT1, or INT2) for which the callback is set.
*/
void EXTINT_voidSetCallBack(void(*Copy_pfun)(void),u8 Copy_u8ExtIntIndex);

#endif /* EXTINT_INTERFACE_H_ */
