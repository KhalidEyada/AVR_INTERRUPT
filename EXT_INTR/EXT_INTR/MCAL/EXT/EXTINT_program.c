
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/EXT/EXTINT_interface.h"
#include "../MCAL/EXT/EXTINT_private.h"
#include "../MCAL/EXT/EXTINT_reg.h"


/*Global Pointer to function*/
static void (*EXTINT_ApfuncEXTINT[3])(void);

/**
@brief Enable specified external interrupt with the given edge triggering mode.
This function enables external interrupts (INT0, INT1, or INT2) with the specified edge triggering mode.
It configures the hardware registers accordingly and enables the global interrupt for the selected interrupt.
@param Copy_u8ExtIntNum: The external interrupt number (INT0, INT1, or INT2) to be enabled.
@param Copy_u8EdgeIntSource: The edge triggering mode for the external interrupt (Falling, Rising, Any Change, Low Level).
*/
void EXTINT_voidEnable(u8 Copy_u8ExtIntNum , u8 Copy_u8EdgeIntSource)
{
	switch(Copy_u8ExtIntNum)
	{
	case EXTINT_INT0:
			switch(Copy_u8EdgeIntSource)
			{
				//PUT SOME CODE HERE
				case EXTINT_FALLING_EDGE: 
					 CLR_BIT(MCUCR,MCUCR_ISC00);
					 SET_BIT(MCUCR,MCUCR_ISC01);
					 break;
				case EXTINT_RAISING_EDGE:
				   	 SET_BIT(MCUCR,MCUCR_ISC00);
					 SET_BIT(MCUCR,MCUCR_ISC01);
				break;
				case EXTINT_ANY_LOGICAL_CHANGE:
					SET_BIT(MCUCR,MCUCR_ISC00);
					CLR_BIT(MCUCR,MCUCR_ISC01);
				break;
				case EXTINT_LOW_LEVEL:
					CLR_BIT(MCUCR,MCUCR_ISC00);
					CLR_BIT(MCUCR,MCUCR_ISC01);
				break;
				
			}
			/* Enable Ext Int 0 */
			SET_BIT(GICR,GICR_INT0);
	break;
	case EXTINT_INT1:
			switch(Copy_u8EdgeIntSource)
			{
				//PUT SOME CODE HERE
				case EXTINT_FALLING_EDGE:
				CLR_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				break;
				case EXTINT_RAISING_EDGE:
				SET_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				break;
				case EXTINT_ANY_LOGICAL_CHANGE:
				SET_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				break;
				case EXTINT_LOW_LEVEL:
				CLR_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				break;
				
			}
			/* Enable Ext Int 1 */
			SET_BIT(GICR,GICR_INT1);
	break;
	case EXTINT_INT2:
				switch(Copy_u8EdgeIntSource)
				{
					//PUT SOME CODE HERE
					case EXTINT_FALLING_EDGE: CLR_BIT(MCUCSR,MCUCSR_ISC2); break;
					case EXTINT_RAISING_EDGE: SET_BIT(MCUCSR,MCUCSR_ISC2); break;
				}
				/* Enable Ext Int 2 */
				SET_BIT(GICR,GICR_INT2);
	break;

	}
}

/**
@brief Disable specified external interrupt.
This function disables the specified external interrupt (INT0, INT1, or INT2) by clearing its corresponding global interrupt bit.
@param Copy_u8ExtIntNum: The external interrupt number (INT0, INT1, or INT2) to be disabled.
*/
void EXTINT_voidDisable(u8 Copy_u8ExtIntNum)
{
	switch (Copy_u8ExtIntNum)
	{
		//PUT SOME CODE HERE
		case EXTINT_INT0:	CLR_BIT(GICR,GICR_INT0);	break;
		case EXTINT_INT1:	CLR_BIT(GICR,GICR_INT1);	break;
		case EXTINT_INT2:	CLR_BIT(GICR,GICR_INT2);	break;
	}
}

/*
@brief Set the callback function for a specific external interrupt.
This function sets the callback function to be executed when a specific external interrupt (INT0, INT1, or INT2) occurs.
@param Copy_pfun: Pointer to the function to be called when the external interrupt occurs.
@param Copy_u8ExtIntIndex: The index of the external interrupt (INT0, INT1, or INT2) for which the callback is set.
*/
void EXTINT_voidSetCallBack(void(*Copy_pfun)(void),u8 Copy_u8ExtIntIndex)
{
	EXTINT_ApfuncEXTINT[Copy_u8ExtIntIndex] = Copy_pfun;
}


/* ISR Function for External Interrupt 0 */
// __vector_1 for linker
// __attribute__((signal)) to prevent optimization
void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	EXTINT_ApfuncEXTINT[EXTINT_INT0]();
}
/* ISR Function for External Interrupt 0 */
void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
	EXTINT_ApfuncEXTINT[EXTINT_INT1]();
}
/* ISR Function for External Interrupt 0 */
void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
	EXTINT_ApfuncEXTINT[EXTINT_INT2]();
}


