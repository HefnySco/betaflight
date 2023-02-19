#include <stdio.h>
#include "platform.h"
#ifdef USE_RC_INPUT
#include "config/config.h"
#include "drivers/i2c_rcinput.h"
#include "cli/cli.h"
#include "drivers/light_ledx.h"


void i2c_rcin_init()
{
    
}

// void i2c_rcout_writeReadEeprom()
// {
//         writeEEPROM();
// }





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
    //  static int counter = 0;   
    //  counter++;
    // if ((cliMode) && (counter%50)) {
    //     char msg[80];
    //     sprintf(msg,"set motor: %d - %d", cmd , value);
    //     cliPrintLine(msg);
    // }

    
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
    
    if (cmd < MAX_SUPPORTED_MOTORS)
    {   // motor values.
        
        *length = 1;
        return ;
    }


    *length = 1;
        
    switch (cmd)
    {
        default:
        ret[0] = 0x0;
        return;
    }

    

    return ;
}

#endif