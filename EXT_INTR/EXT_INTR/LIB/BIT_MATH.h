/***************************************************************************************/
/***************************************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BitNo)              (REG |= (1<<BitNo)) //function like macro used to set a specific bit
#define CLR_BIT(REG,BitNo)              (REG &= ~(1<<BitNo))//function like macro used to clear a specific bit
#define ASS_BIT(REG,BitNo,VAL)          ((VAL==0)? CLR_BIT(REG,BitNo) : SET_BIT(REG,BitNo))//function like macro used to assert a specific bit
#define TOG_BIT(REG,BitNo)              (REG ^= (1<<BitNo))//function like macro used to toggle a specific bit
#define GET_BIT(REG,BitNo)              ((REG>>BitNo) & 0x01)//function like macro used to get a specific bit

#define SET_NIBBLE(REG,NibbleHalf)      ((NibbleHalf == LOW)? (REG |= 00001111) : (REG |= 11110000)) //function like macro used to set half of a register
#define CLR_NIBBLE(REG,NibbleHalf)      ((NibbleHalf == LOW)? (REG &= 11110000) : (REG &= 00001111)) //function like macro used to clear half of a register
#define ASS_NIBBLE(REG,NibbleHalf,VAL)  ((VAL == 0)? (CLR_NIBBLE(REG,NibbleHalf)) : (SET_NIBBLE(REG,NibbleHalf))) //function like macro used to assert half of a register

#define SET_PORT(REG)					(REG |= (0xFF)) //function like macro used to set a register
#define CLR_PORT(REG)					(REG &= (0x00)) //function like macro used to set clear a register

#endif
/***************************************************************************************/
