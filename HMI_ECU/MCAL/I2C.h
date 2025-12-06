#ifndef I2C_H
#define I2C_H
#include "../UTILS/std_types.h"

void I2C0_Init(void);
void I2C0_WriteByte(u8 SlaveAddress, u8 Data);

#endif