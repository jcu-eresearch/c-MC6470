#ifndef __MC6470_ACCEL_H__
#define __MC6470_ACCEL_H__

#include "mc6470.h"

uint32_t MC6470_Accel_Init(struct MC6470_Dev_t *dev);

uint32_t MC6470_Accel_ChipIDs(struct MC6470_Dev_t *dev, bool *found);
uint32_t MC6470_Accel_get_Rate(struct MC6470_Dev_t *dev, MC6470_ACCEL_SRTFR_RATE_e *rate);
uint32_t MC6470_Accel_set_Rate(struct MC6470_Dev_t *dev, MC6470_ACCEL_SRTFR_RATE_e rate);
uint32_t MC6470_Accel_get_Range(struct MC6470_Dev_t *dev, MC6470_ACCEL_OUTCFG_RANGE_e *range);
uint32_t MC6470_Accel_set_Range(struct MC6470_Dev_t *dev, MC6470_ACCEL_OUTCFG_RANGE_e range);
uint32_t MC6470_Accel_get_Resolution(struct MC6470_Dev_t *dev, MC6470_ACCEL_OUTCFG_RES_e *resolution);
uint32_t MC6470_Accel_set_Resolution(struct MC6470_Dev_t *dev, MC6470_ACCEL_OUTCFG_RES_e resolution);
uint32_t MC6470_Accel_get_Range_and_Resolution(struct MC6470_Dev_t *dev, MC6470_ACCEL_OUTCFG_RANGE_e *range, MC6470_ACCEL_OUTCFG_RES_e *resolution);
uint32_t MC6470_Accel_set_Range_and_Resolution(struct MC6470_Dev_t *dev, MC6470_ACCEL_OUTCFG_RANGE_e range, MC6470_ACCEL_OUTCFG_RES_e resolution);

uint32_t MC6470_Accel_set_OperationState(struct MC6470_Dev_t *dev, MC6470_ACCEL_MODE_OPCON_e state);

uint32_t MC6470_Accel_hasData(struct MC6470_Dev_t *dev, bool *has_data);
uint32_t MC6470_Accel_getData(struct MC6470_Dev_t *dev, float *x, float *y, float *z);

uint32_t MC6470_Accel_I2C_Write(struct MC6470_Dev_t *dev, MC6470_reg_addr reg_address, uint8_t *buffer, size_t buffer_length);
uint32_t MC6470_Accel_I2C_Read(struct MC6470_Dev_t *dev, MC6470_reg_addr reg_address, uint8_t *buffer, size_t buffer_length);


#endif
