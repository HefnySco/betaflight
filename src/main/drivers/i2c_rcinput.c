#include <stdio.h>
#include "platform.h"
#ifdef USE_RCINPUT_I2C
#include "config/config.h"
#include "drivers/i2c_rcinput.h"
#include "cli/cli.h"
#include "drivers/light_ledx.h"
#include "drivers/rx/rx_pwm.h"



void i2c_rcin_init()
{
    
}


/**
 * @brief parse i2c set command form i2c master.
 * 
 * @param cmd 
 * @param value 
 */
void i2c_rcin_parseCommand(const uint8_t cmd, const uint16_t value)
{
    UNUSED(cmd);
    UNUSED(value);
}


/**
 * @brief parse i2cget command from i2c master.
 * 
 * @param cmd 
 * @param ret 
 * @param length 
 */
void i2c_rcin_getReply(const uint8_t cmd, uint8_t *ret, uint8_t* length)
{
    
    switch (cmd)
    {
        case STM32_RCINPUT_CH1_READ:
        case STM32_RCINPUT_CH2_READ:
        case STM32_RCINPUT_CH3_READ:
        case STM32_RCINPUT_CH4_READ:
        case STM32_RCINPUT_CH5_READ:
        case STM32_RCINPUT_CH6_READ:
        case STM32_RCINPUT_CH7_READ:
        case STM32_RCINPUT_CH8_READ:
        case STM32_RCINPUT_CH9_READ:
        case STM32_RCINPUT_CH10_READ:
        case STM32_RCINPUT_CH11_READ:
        case STM32_RCINPUT_CH12_READ:
        case STM32_RCINPUT_CH13_READ:
        case STM32_RCINPUT_CH14_READ:
        case STM32_RCINPUT_CH15_READ:
        case STM32_RCINPUT_CH16_READ:
        {
            uint16_t pwm = pwmRead(cmd);

            ret[0]= (pwm & 0xff);
            ret[1]= (pwm >> 8) & 0xff;
            *length = 2;
        }
        break;

        case STM32_RCINPUT_CHANNEL_COUNT:
            ret[0] = PWM_PORTS_OR_PPM_CAPTURE_COUNT;
            *length = 1;
        break;

        case STM32_RCINPUT_REGID:
            ret[0] = STM32_RCINPUT_REGID_VALUE;
            *length = 1;
        break;

        default:
            ret[0] = 0x0;
            *length = 1;
        return;
    }

    
    // if (cliMode) {
    //     char msg[80];
    //     sprintf(msg,"set cmd: %d, value %d", cmd,ret[0]);
    //     cliPrintLine(msg);
    // }
    
    return ;
}

#endif