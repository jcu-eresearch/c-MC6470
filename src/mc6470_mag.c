#include "mc6470.h"

uint32_t MC6470_Mag_Init(struct MC6470_Dev_t *dev)
{
    return MC6470_Status_OK;
}

uint32_t MC6470_Mag_I2C_Write(struct MC6470_Dev_t *dev, MC6470_reg_addr reg_address, uint8_t *buffer, size_t buffer_length)
{
    if(dev == NULL)
    {
        return MC6470_Status_Null_PTR_ERROR;
    }    
    return MC6470_I2C_Write(dev, dev->mag_address, reg_address, buffer, buffer_length);
};

uint32_t MC6470_Mag_I2C_Read(struct MC6470_Dev_t *dev, MC6470_reg_addr reg_address, uint8_t *buffer, size_t buffer_length)
{
    if(dev == NULL)
    {
        return MC6470_Status_Null_PTR_ERROR;
    }
    return MC6470_I2C_Read(dev, dev->mag_address, reg_address, buffer, buffer_length);
};