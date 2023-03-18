#pragma once

#ifdef USE_LEDX

#define STM32_LEDX_MIN_CMD_ID        0x10
#define STM32_LEDX_MAX_CMD_ID        0x1F


#define STM32_LEDX_LED_1            0x11
#define STM32_LEDX_LED_2            0x12
#define STM32_LEDX_LED_3            0x13
#define STM32_LEDX_LED_4            0x14
#define STM32_LEDX_LED_5            0x15
#define STM32_LEDX_LED_6            0x16
#define STM32_LEDX_LED_7            0x17

#define STM32_LEDX_REGID            0x1F
#define STM32_LEDX_REGID_VALUE      0xFF


void i2c_ledx_init();

void i2c_ledx_execute();

void i2c_ledx_parseCommand(const uint8_t cmd, const uint16_t value);

void i2c_ledx_getReply(const uint8_t cmd, uint8_t *ret, uint8_t *length);


#endif
