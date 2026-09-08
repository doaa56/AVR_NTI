#ifndef MATH_H
#define MATH_H



#define SET_BIT(REG,BIT)    ((REG) |= (1u << BIT))
#define CLEAR_BIT(REG,BIT)  ((REG) &= ~(1u << BIT))   
#define TOGGLE_BIT(REG,BIT) ((REG) ^= (1u << BIT))
#define GET_BIT(REG,BIT)    (((REG) >> (BIT)) & 1u)
#endif /* MATH_H */