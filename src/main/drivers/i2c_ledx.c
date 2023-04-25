#include <stdio.h>
#include "platform.h"
#ifdef USE_LEDX
#include "i2c_ledx.h"
#include "drivers/light_ledx.h"
#include "cli/cli.h"
#include "adc.h"


volatile uint8_t led_status[STATUS_LEDX_NUMBER-1];
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
        const uint8_t status = led_status[i];
        if ((status!=0) && (status!=0xff))
        {   // not a fixed led
            led_counter[i]+=1;
            if ((led_counter[i]%status)==0)
            {
                ledxToggle(i);
            }
        }
    }

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
    #ifdef DEBUG_LEDX_COMMANDS_IN_CLI
        if (cliMode) {
        char msg[80];
        sprintf(msg,"set c: %d, s %d , s %d", cmd_updated, led_status[cmd_updated],value);
        cliPrintLine(msg);
        }
    #endif
        if ((value & 0xff) == 0xff)
        {
            led_status[cmd_updated] = 0xff;
            ledxSet(cmd_updated,true);
            return ;
        }
        if ((value & 0x00ff)  == 0x00)
        {
            led_status[cmd_updated] = 0x0;
            ledxSet(cmd_updated,false);
            return ;
        }
        if ((value  & 0x0001) == 0x00)
        {
            ledxSet(cmd_updated,false);
        }
        else
        {
            ledxSet(cmd_updated,true);
        }
        led_status[cmd_updated] = value  ; // LSB is for staring OFF or ON
        return ;
    }
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
    
    return ;
}

#endif
