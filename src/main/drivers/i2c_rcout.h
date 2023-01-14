#pragma once

#ifdef USE_I2C_RCOUT

#define PCA9685_REGID_VALUE         0x91
#define CMD_MOTOR_DISABLED          0x0





/**
 * @brief when value output is disabled.
 * when value 1 output is enabled. 
 * pressing key superseeds this action.
 */
#define PCA9685_ENABLE_OUTPUT      0xFA
/**
 * @brief input signal timeout.
 * 0x0: no timeout.
 * timeout = value * 100ms  
 */
#define PCA9685_TIMEOUT             0xFB
#define PCA9685_CHANGE_PWM_PROTOCOL 0xFE
/**
 * @brief gets module signature
 * 
 */
#define PCA9685_REGID               0xFF


void i2c_rcout_init();

uint8_t i2c_rcout_getReply(uint8_t cmd);


void i2c_rcout_parseCommand(uint8_t cmd, uint8_t value);
/*
// update motor output.
*/
void i2c_rcout_motor(uint8_t motorNumber, uint8_t value);

/*
// Change output protocol.
// returns true if mode changed.
*/
bool i2c_rcout_changeMotorPwmProtocol(uint8_t pwm_protocol);

/*
// Update motor status. This function is called form a task.
*/
void i2c_rcout_writeMotors();


void i2c_rcout_writeReadEeprom();

void i2c_rcout_execute();
void debug_PrintLine(const char *str);

#endif