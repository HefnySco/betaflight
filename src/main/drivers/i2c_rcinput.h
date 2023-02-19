#pragma once

#ifdef USE_RC_INPUT

#define STM32_RCINPUT_REGID_VALUE       0x92
#define CMD_MOTOR_DISABLED              0x0






#define STM32_RCINPUT_REGID             0xFF


void i2c_rcin_init();

void i2c_rcin_getReply(const uint8_t cmd, uint8_t *ret, uint8_t* length);


//void i2c_rcout_parseCommand(const uint8_t cmd, const uint8_t value);

void i2c_rcin_parseCommand(const uint8_t cmd, const uint16_t value);

#endif