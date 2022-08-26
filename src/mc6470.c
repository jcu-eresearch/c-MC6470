#include "mc6470.h"
#include "mc6470_accel.h"
#include "mc6470_mag.h"

void MC6470_Init(struct MC6470_Dev_t *dev, MC6470_Address_e address)
{
    dev->accel_address = address;
    dev->mag_address = MC6470_MAG_ADDRESS;
};

uint32_t MC6470_begin(struct MC6470_Dev_t *dev)
{
    MC6470_printf(dev, "[MC6470 Accel] Address: 0x%02X\r\n", dev->accel_address);
    MC6470_printf(dev, "[MC6470 Mag  ] Address: 0x%02X\r\n", dev->mag_address);
    uint32_t result = MC6470_Accel_Init(dev);
    result |= MC6470_Mag_Init(dev);
    bool found = false;
    result |= MC6470_Accel_ChipIDs(dev, &found);
    if(!MC6470_IS_ERROR(result))
    {
        result |= MC6470_Accel_get_Range_and_Resolution(dev, NULL, NULL);
        result |= MC6470_Accel_set_Range_and_Resolution(dev, MC6470_ACCEL_OUTCFG_RANGE_8G, MC6470_ACCEL_OUTCFG_RES_14_Bits);
    }


    result |= MC6470_Accel_set_OperationState(dev, MC6470_ACCEL_MODE_OPCON_Wake);

    return result;
};

uint32_t MC6470_check_ids(struct MC6470_Dev_t *dev)
{
    uint32_t result = 0;
    bool found = false;
    result |= MC6470_Accel_ChipIDs(dev, &found);

    return result;

};

uint32_t MC6470_getData(struct MC6470_Dev_t *dev, MC6470_MagReading *mag_data, MC6470_AccelReading *accel_data)
{
    RETURN_ERROR_IF_NULL(dev);
    uint32_t result = 0;
    if(mag_data != NULL){

    }
    if(accel_data != NULL)
    {
        result |= MC6470_Accel_getData(dev, &accel_data->x, &accel_data->y, &accel_data->z);
    }

    return result;
};

