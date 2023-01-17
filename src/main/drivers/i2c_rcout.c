#include <stdio.h>
#include "platform.h"
#ifdef USE_I2C_RCOUT
#include "config/config.h"
#include "drivers/i2c_rcout.h"
#include "cli/cli.h"
#include "drivers/light_ledx.h"
#include "flight/mixer.h"
#include "drivers/motor.h"
#include "drivers/buttons.h"
#include "drivers/system.h"

#define ARDUPILOT_PWM_TYPE_PWM_OFF      0
#define ARDUPILOT_PWM_TYPE_NORMAL       1
#define ARDUPILOT_PWM_TYPE_ONESHOT      2
#define ARDUPILOT_PWM_TYPE_ONESHOT125   3
#define ARDUPILOT_PWM_TYPE_BRUSHED      4
#define ARDUPILOT_PWM_TYPE_DSHOT150     5
#define ARDUPILOT_PWM_TYPE_DSHOT300     6
#define ARDUPILOT_PWM_TYPE_DSHOT600     7
#define ARDUPILOT_PWM_TYPE_DSHOT1200    8
#define ARDUPILOT_PWM_TYPE_PWM_RANGE    9


#define RCOUT_STATUS_NO_ERROR           0x0
#define RCOUT_STATUS_NO_INPUT           0x1
#define RCOUT_NO_INPUT_DELAY            0x2
#define RCOUT_OUTPUT_LOCKED             0x4

/**
 * @brief i2crcout_motor_values value is always updated from i2c.
 * you can block output and preset i2crcout_motor_values then enable output
 * so each channel will be initialized with each own value.
 * 
 */
static uint8_t FAST_DATA_ZERO_INIT i2crcout_motor_values[MAX_SUPPORTED_MOTORS];
static float FAST_DATA_ZERO_INIT i2crcout_motor[MAX_SUPPORTED_MOTORS];
static bool busy = false;

static uint8_t status = RCOUT_STATUS_NO_INPUT;
static bool lock_by_user = true;
static bool lock_by_cmd = false;

static bool button_lock = false;
static uint8_t watch_dog_counter = 0;
static uint8_t watch_dog_timeout = 0xa;


void i2c_rcout_disableMotor()
{
    status = status | RCOUT_OUTPUT_LOCKED ;

    motorDisable();
}

void i2c_rcout_init()
{
    i2c_rcout_disableMotor();
}

void i2c_rcout_motor(const uint8_t motorRegister, const uint16_t value)
{
    // each motor has two registers.
    const uint8_t motorNumber = motorRegister >> 1;
    watch_dog_counter = 0;
    // motor number higher than supported motors.
    if (motorNumber >= MAX_SUPPORTED_MOTORS) return ;
    
    status = status & (~RCOUT_STATUS_NO_INPUT) ;
    
    if (!(motorRegister & 0x1))
    {   // odd register .. lower value part.
        i2crcout_motor_values[motorNumber] = value;
    }
    else
    {   // even register .. higher value part.
        // calculate full value. 
        //const uint16_t tmp = (value << 8) | (i2crcout_motor_values[motorNumber] & 0xFF);
        
        
        // write in i2crcout_motor motor array.
        busy = true;
        i2crcout_motor[motorNumber] = value; //tmp;
        busy = false;
        
        return ;
    }
}

bool i2c_rcout_changeMotorPwmProtocol(const uint8_t pwm_protocol)
{
    // maping ardupilot pwm protocol to betaflight.
    switch (pwm_protocol)
    {
        case ARDUPILOT_PWM_TYPE_PWM_OFF:
            if (motorConfigMutable()->dev.motorPwmProtocol == PWM_TYPE_DISABLED) return false;
            motorConfigMutable()->dev.motorPwmProtocol = PWM_TYPE_DISABLED;
        break;
        case ARDUPILOT_PWM_TYPE_NORMAL:
            if (motorConfigMutable()->dev.motorPwmProtocol == PWM_TYPE_STANDARD) return false;
            motorConfigMutable()->dev.motorPwmProtocol = PWM_TYPE_STANDARD;
        break;
        case ARDUPILOT_PWM_TYPE_ONESHOT:
            if (motorConfigMutable()->dev.motorPwmProtocol == PWM_TYPE_ONESHOT42) return false;
            motorConfigMutable()->dev.motorPwmProtocol = PWM_TYPE_ONESHOT42;
        break;
        case ARDUPILOT_PWM_TYPE_ONESHOT125:
            if (motorConfigMutable()->dev.motorPwmProtocol == PWM_TYPE_ONESHOT125) return false;
            motorConfigMutable()->dev.motorPwmProtocol = PWM_TYPE_ONESHOT125;
        break;
        case ARDUPILOT_PWM_TYPE_BRUSHED:
            if (motorConfigMutable()->dev.motorPwmProtocol == PWM_TYPE_BRUSHED) return false;
            motorConfigMutable()->mincommand = 1000;
            motorConfigMutable()->dev.motorPwmProtocol = PWM_TYPE_BRUSHED;
            return true;
        case ARDUPILOT_PWM_TYPE_DSHOT150:
            if (motorConfigMutable()->dev.motorPwmProtocol == PWM_TYPE_DSHOT150) return false;
            motorConfigMutable()->dev.motorPwmProtocol = PWM_TYPE_DSHOT150;
        break;
        case ARDUPILOT_PWM_TYPE_DSHOT300:
            if (motorConfigMutable()->dev.motorPwmProtocol == PWM_TYPE_DSHOT300) return false;
            motorConfigMutable()->dev.motorPwmProtocol = PWM_TYPE_DSHOT300;
        break;
        case ARDUPILOT_PWM_TYPE_DSHOT600:
            if (motorConfigMutable()->dev.motorPwmProtocol == PWM_TYPE_DSHOT600) return false;
            motorConfigMutable()->dev.motorPwmProtocol = PWM_TYPE_DSHOT600;
        break;
        case ARDUPILOT_PWM_TYPE_DSHOT1200:
            if (motorConfigMutable()->dev.motorPwmProtocol == PWM_TYPE_DISABLED) return false;
            motorConfigMutable()->dev.motorPwmProtocol = PWM_TYPE_DISABLED;
        break;
        case ARDUPILOT_PWM_TYPE_PWM_RANGE:
            if (motorConfigMutable()->dev.motorPwmProtocol == PWM_TYPE_DISABLED) return false;
            motorConfigMutable()->dev.motorPwmProtocol = PWM_TYPE_DISABLED;
        break;
        default:
            if (motorConfigMutable()->dev.motorPwmProtocol == PWM_TYPE_DISABLED) return false;
            motorConfigMutable()->dev.motorPwmProtocol = PWM_TYPE_DISABLED;
        break;
    }

    motorConfigMutable()->dev.motorPwmRate = BRUSHLESS_MOTORS_PWM_RATE;

    return true;
}



void i2c_rcout_enableMotor()
{
    status = status & (~RCOUT_OUTPUT_LOCKED) ;
            
    motorPostInit();
    motorEnable();
}

void i2c_rcout_toggleMotor()
{
    if (status & RCOUT_OUTPUT_LOCKED) {
        i2c_rcout_enableMotor();
    }
    else {
        i2c_rcout_disableMotor();
    }
}

/*
// called by subTaskMotorUpdate
*/
void i2c_rcout_writeMotors ()
{
    if (status & RCOUT_OUTPUT_LOCKED) {
        return ;
    }

    if (busy) return ;

    motorWriteAll(i2crcout_motor);
}


void i2c_rcout_writeReadEeprom()
{
        writeEEPROM();
}


void i2c_rcout_execute()
{
    static uint16_t led_counter =0;
    static uint16_t key_press_counter = 0;
    static uint8_t dev = 2;
    
    if (buttonAPressed()) {

        if (!button_lock) {
            key_press_counter++;
        }
        
        if (key_press_counter > 10) {
            // long press mode active
            button_lock = true;
            
            // long-press to lock or unlock.
            lock_by_user = false;
            if (lock_by_cmd == false)
            {   // do not enable motors if the last software command was to lock it.
                i2c_rcout_enableMotor();
            }
            key_press_counter = 0; // to cancel fast click count when unpress.
        }
    }
    else
    {
        // short press mode active
        button_lock = false;
        
        if (key_press_counter != 0) {
            // key_press_counter < 10 short press key_press_counter >= 10 long press
            if (key_press_counter < 10)
            {
                i2c_rcout_disableMotor();
                lock_by_user = true;
            }
            key_press_counter = 0;
        }
    }

    /*
        LED Logic:
        off: locked by user.
        on solid: locked by software but enabled by user.
        blinking slow: no input signale.
        blinking fast: input signal and output is active.
    */
    dev = (status & RCOUT_STATUS_NO_INPUT)?4:2;    
    if (lock_by_user == true)
    {
        LEDX0_OFF;
    }
    else if (lock_by_cmd == true) 
    {
        LEDX0_ON;
    }
    else if ((led_counter%dev)==0) 
    {
        LEDX0_OFF;
    }
    else
    {
        LEDX0_ON;
    }
    led_counter++;
    
    watch_dog_counter++;
    if ((watch_dog_timeout!=0) && (watch_dog_counter > watch_dog_timeout) && ((status & RCOUT_OUTPUT_LOCKED) == 0)){
        watch_dog_counter = 0;
        status = status | RCOUT_STATUS_NO_INPUT ;
        i2c_rcout_disableMotor();
        return ;
    }

    if ( (lock_by_cmd == false) && (lock_by_user == false) && (status & (RCOUT_OUTPUT_LOCKED | RCOUT_STATUS_NO_INPUT))==RCOUT_OUTPUT_LOCKED) {
        i2c_rcout_enableMotor();
    }
}

void debug_PrintLine(const char *str)
{
    if (cliMode) {
        cliPrintLine(str);
    }

    return;
}

void i2c_rcout_disable_output (const uint8_t value)
{
    if (value == CMD_MOTOR_DISABLED){
        lock_by_cmd = true;
        i2c_rcout_disableMotor();
    }
    else {
        lock_by_cmd = false;
        if (lock_by_user == false)
        {
            i2c_rcout_enableMotor();
        }
    }
}



/**
 * @brief parse i2c set command form i2c master.
 * 
 * @param cmd 
 * @param value 
 */
void i2c_rcout_parseCommand(const uint8_t cmd, const uint16_t value)
{
    //  static int counter = 0;   
    //  counter++;
    // if ((cliMode) && (counter%50)) {
    //     char msg[80];
    //     sprintf(msg,"set motor: %d - %d", cmd , value);
    //     cliPrintLine(msg);
    // }

    switch (cmd)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7: 
        case 8:
        case 9: 
        case 10:
        case 11: 
        case 12:
        case 13: 
        case 14:
        case 15: 
            // < MAX_SUPPORTED_MOTORS
            i2c_rcout_motor(cmd,value);
        return ;

        case STM32_RCOUT_ENABLE_OUTPUT:
                // command disable output
            i2c_rcout_disable_output(value);
        return ;
    
        case STM32_RCOUT_TIMEOUT:
                watch_dog_timeout = value;
                status = status & (~RCOUT_STATUS_NO_INPUT) ;
        return ;

        case STM32_RCOUT_CHANGE_PWM_PROTOCOL:
            // i2cset 1 0x66 0xFE 0x04brushed mode.
            if (i2c_rcout_changeMotorPwmProtocol(value ))
            {
                i2c_rcout_writeReadEeprom();
                systemReset();
            }
        return ;

    }
}


/**
 * @brief parse i2cget command from i2c master.
 * 
 * @param cmd 
 * @param ret 
 * @param length 
 */
void i2c_rcout_getReply(const uint8_t cmd, uint8_t *ret, uint8_t* length)
{

    if (cmd < MAX_SUPPORTED_MOTORS)
    {   // motor values.
        ret[0] = i2crcout_motor_values[cmd];
        *length = 1;
        return ;
    }


    *length = 1;
        
    switch (cmd)
    {
        case STM32_RCOUT_REGID:
        ret[0] =  STM32_RCOUT_REGID_VALUE;
        return ;
        default:
        ret[0] = 0x0;
        return;
    }

    

    return ;
}

#endif