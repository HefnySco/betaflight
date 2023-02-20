#pragma once

#ifdef USE_RCOUT_I2C

#define STM32_RCOUT_REGID_VALUE     0x91
#define CMD_MOTOR_DISABLED          0x0







/**
 * @brief when value output is disabled.
 * when value 1 output is enabled. 
 * pressing key superseeds this action.
 */
#define STM32_RCOUT_ENABLE_OUTPUT      0xFA
/**
 * @brief input signal timeout.
 * 0x0: no timeout.
 * timeout = value * 100ms  
 */
#define STM32_RCOUT_TIMEOUT             0xFB
#define STM32_RCOUT_CHANGE_PWM_PROTOCOL 0xFE


/**
* @brief gets number of motors currently supported.
* this can be determined in MAX_SUPPORTED_MOTORS in target.h
* 
*/
#define STM32_RCOUT_GET_MOTOR_COUNT     0xFC

/**
 * @brief gets module signature
 * 
 */
#define STM32_RCOUT_REGID               0xFF


void i2c_rcout_init();

void i2c_rcout_getReply(const uint8_t cmd, uint8_t *ret, uint8_t* length);


//void i2c_rcout_parseCommand(const uint8_t cmd, const uint8_t value);

void i2c_rcout_parseCommand(const uint8_t cmd, const uint16_t value);

/*
// update motor output.
*/
void i2c_rcout_motor(const uint8_t motorNumber, const uint16_t value);

/*
// Change output protocol.
// returns true if mode changed.
*/
bool i2c_rcout_changeMotorPwmProtocol(const uint8_t pwm_protocol);

/*
// Update motor status. This function is called form a task.
*/
void i2c_rcout_writeMotors();


void i2c_rcout_writeReadEeprom();

void i2c_rcout_execute();
void debug_PrintLine(const char *str);

#endif