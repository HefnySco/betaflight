#pragma once

#ifdef USE_BATTERY

#define STM32_ADC_MIN_CMD_ID        0x00
#define STM32_ADC_MAX_CMD_ID        0x0F

#define STM32_ADC_SENSOR_0      0x00
#define STM32_ADC_SENSOR_1      0x01
#define STM32_ADC_SENSOR_2  `   0x02
#define STM32_ADC_SENSOR_3      0x03

#define STM32_ADC_REGID             0x0F
#define STM32_ADC_REGID_VALUE       0xFE


void i2c_battery_init();

void i2c_battery_parseCommand(const uint8_t cmd, const uint8_t value);

void i2c_battery_getReply(const uint8_t cmd, uint8_t *ret, uint8_t *length);

#endif
