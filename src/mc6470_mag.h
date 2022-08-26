#ifndef __MC6470_MAG_H__
#define __MC6470_MAG_H__

#include "mc6470.h"

uint32_t MC6470_Mag_Init(struct MC6470_Dev_t *dev);


uint32_t MC6470_Mag_I2C_Write(struct MC6470_Dev_t *dev, MC6470_reg_addr reg_address, uint8_t *buffer, size_t buffer_length);
uint32_t MC6470_Mag_I2C_Read(struct MC6470_Dev_t *dev, MC6470_reg_addr reg_address, uint8_t *buffer, size_t buffer_length);


#endif