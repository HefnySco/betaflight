#include <stdio.h>
#include "platform.h"
#ifdef USE_LEDX
#include "i2c_ledx.h"
#include "drivers/light_ledx.h"
#include "cli/cli.h"
#include "adc.h"


volatile uint16_t led_status[STATUS_LEDX_NUMBER-1];
volatile  uint16_t led_counter[STATUS_LEDX_NUMBER-1];

void i2c_ledx_init()
{
    for (uint8_t i=0; i<(STATUS_LEDX_NUMBER-1); ++i)
    {
        led_status[i]   = 0; // OFF
        led_counter[i]  = 0;
    }
}

void i2c_ledx_execute()
{
    for (uint8_t i=0; i<(STATUS_LEDX_NUMBER-1); ++i)
    {
        const uint16_t status = led_status[i];
        if ((status!=0) && (status!=0xffff))
        {   // not a fixed led
            led_counter[i]+=1;
            if ((led_counter[i]%status)==0)
            {
                ledxToggle(i);
            }
        }
    }

    // if (cliMode) {
    //     char msg[80];
    //     sprintf(msg,"set c: %d, s %d", led_counter[1],led_status[1]);
    //     cliPrintLine(msg);
    // }
}


void i2c_ledx_parseCommand(const uint8_t cmd, const uint16_t value)
{
    UNUSED (cmd);
    UNUSED (value);

    if ((cmd >= STM32_LEDX_LED_1) && (cmd<= STM32_LEDX_LED_7))
    {   // value = 0        Always OFF
        // value = 0xFF     Always ON
        // Othervalues .... toggling
        const uint8_t cmd_updated = cmd - STM32_LEDX_LED_1;
        if (cliMode) {
        char msg[80];
        sprintf(msg,"set c: %d, s %d , s %d", cmd_updated, led_status[cmd_updated],value);
        cliPrintLine(msg);
        }
        led_status[cmd_updated] = value;
        if (value == 0xffff)
        {
            ledxSet(cmd_updated,true);
            return ;
        }
        if (value == 0x0000)
        {
            ledxSet(cmd_updated,false);
            return ;
        }
        return ;
    }
    // if (cliMode) {
    //     char msg[80];
    //     sprintf(msg,"set cmd: %d, value %d", cmd,value);
    //     cliPrintLine(msg);
    // }

}



void i2c_ledx_getReply(const uint8_t cmd, uint8_t *ret, uint8_t* length)
{
    
    ret[0]=0;
    ret[1]= 0;
    *length = 2;
    if (cmd <= STM32_LEDX_REGID)
    {
        ret[0] = STM32_LEDX_REGID_VALUE;
        ret[1] = 0;
        *length = 1;
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
