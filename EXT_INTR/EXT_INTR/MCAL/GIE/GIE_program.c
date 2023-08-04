
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/GIE/GIE_interface.h"

#define SREG    *((volatile u8*)0x5F)
//enable global interrupt
void GIE_voidGlobalInterruptEnable(void)
{
		//PUT SOME CODE HERE
		SET_BIT(SREG,GICR_INT1);
		SET_BIT(SREG,GICR_INT0);
		SET_BIT(SREG,GICR_INT2);
}
//disable interrupt
void GIE_voidGlobalInterruptDisable(void)
{
		//PUT SOME CODE HERE
		CLR_BIT(SREG,GICR_INT1);
		CLR_BIT(SREG,GICR_INT0);
		CLR_BIT(SREG,GICR_INT2);
}
