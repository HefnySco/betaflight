#pragma once

#ifdef USE_RCINPUT_I2C

#define STM32_RCINPUT_REGID_VALUE       0x92



#define STM32_RCINPUT_CH1_READ           0x00
#define STM32_RCINPUT_CH2_READ           0x01
#define STM32_RCINPUT_CH3_READ           0x02
#define STM32_RCINPUT_CH4_READ           0x03
#define STM32_RCINPUT_CH5_READ           0x04
#define STM32_RCINPUT_CH6_READ           0x05
#define STM32_RCINPUT_CH7_READ           0x06
#define STM32_RCINPUT_CH8_READ           0x07
#define STM32_RCINPUT_CH9_READ           0x08
#define STM32_RCINPUT_CH10_READ          0x09
#define STM32_RCINPUT_CH11_READ          0x0a
#define STM32_RCINPUT_CH12_READ          0x0b
#define STM32_RCINPUT_CH13_READ          0x0c
#define STM32_RCINPUT_CH14_READ          0x0d
#define STM32_RCINPUT_CH15_READ          0x0e
#define STM32_RCINPUT_CH16_READ          0x0f



#define STM32_RCINPUT_CHANNEL_COUNT     0xFE
#define STM32_RCINPUT_REGID             0xFF


void i2c_rcin_init();

void i2c_rcin_getReply(const uint8_t cmd, uint8_t *ret, uint8_t* length);


//void i2c_rcout_parseCommand(const uint8_t cmd, const uint8_t value);

void i2c_rcin_parseCommand(const uint8_t cmd, const uint16_t value);

#endif