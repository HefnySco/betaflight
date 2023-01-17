#include <stdio.h>
#include "platform.h"
#ifdef USE_BATTERY
#include "i2c_battery.h"
#include "cli/cli.h"
#include "adc.h"
#include "sensors/battery.h"
#include "drivers/adc_impl.h"

void i2c_battery_init()
{

}

void i2c_battery_parseCommand(const uint8_t cmd, const uint8_t value)
{
    UNUSED (cmd);
    UNUSED (value);

    // if (cliMode) {
    //     char msg[80];
    //     sprintf(msg,"set cmd: %d, value %d", cmd,value);
    //     cliPrintLine(msg);
    // }

}



void i2c_battery_getReply(const uint8_t cmd, uint8_t *ret, uint8_t* length)
{
    uint16_t  value;
    if (cmd <= STM32_ADC_SENSOR_3)
    {
        value =  adcValues[adcOperatingConfig[cmd].dmaIndex];
        ret[0] = (uint8_t) (value & 0x00ff);
        ret[1] = (uint8_t) ((value & 0xff00) >> 8);
        *length = 2;
    }
    else if (cmd == STM32_ADC_REGID)
    {
        ret[0] = STM32_ADC_REGID_VALUE;
        ret[1] = 0;
        *length = 1;
    }
    else
    {
        ret[0]=0;
        ret[1]= 0;
        *length = 2;
    }
    
    // static int v = 0;
    // v++;
    // if (cliMode && (v%10==0)) {
    //     char msg[80];
    //     sprintf(msg,"get cmd: %d - %d %x:%x", cmd , value, ret[1], ret[0]);
    //     cliPrintLine(msg);
    // }
    
    return ;
}

#endif
