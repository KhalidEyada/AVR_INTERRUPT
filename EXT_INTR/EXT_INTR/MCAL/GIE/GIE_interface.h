
#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_

#define GICR_INT1          7
#define GICR_INT0          6
#define GICR_INT2          5

void GIE_voidGlobalInterruptEnable(void);

void GIE_voidGlobalInterruptDisable(void);

#endif /* GIE_INTERFACE_H_ */
