/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#define TARGET_BOARD_IDENTIFIER "OBALF411"
#define USBD_PRODUCT_STRING     "Betaflight OBAL"

#define LED0_PIN                PC13

#undef USE_CAMERA_CONTROL
#undef LED_STRIP
#undef DEFAULT_CURRENT_METER_SOURCE


// *************** ADC *****************************
#define USE_ADC
#define ADC_INSTANCE            ADC1  
#define ADC1_DMA_OPT            0  // DMA 2 Stream 0 Channel 0 
#define VBAT_ADC_PIN            PA1
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC

#define USE_PPM
#define USE_PWM
#undef USE_SERIALRX_CRSF       // Team Black Sheep Crossfire protocol
#undef USE_SERIALRX_SBUS       // Frsky and Futaba receivers
#undef USE_SERIALRX_SPEKTRUM   // SRXL, DSM2 and DSMX protocol
#undef USE_SERIALRX_SUMD       // Graupner Hott protocol
#undef USE_SERIALRX_SUMH       // Graupner legacy protocol
#undef USE_SERIALRX_XBUS       // JR


#define USE_I2C_DEVICE_1


// *************** UART *****************************
#define USE_VCP
#define USE_USB_DETECT


#define USE_SOFTSERIAL1
#define USE_SOFTSERIAL2
//#define USE_INVERTER
#define USE_UART1
#define UART1_RX_PIN            PA10
#define UART1_TX_PIN            PA9

#define USE_UART2
#define UART2_RX_PIN            PA3
#define UART2_TX_PIN            PA2
#define SERIAL_PORT_COUNT     5




#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff
#define TARGET_IO_PORTD 0xffff
#define TARGET_IO_PORTE 0xffff


// Treat the target as unified, and expect manufacturer id / board name
// to be supplied when the board is configured for the first time
//#define USE_UNIFIED_TARGET    


#define USE_RX_CC2500_SPI_PA_LNA
#define USE_RX_CC2500_SPI_DIVERSITY


#undef TELEMETRY_FRSKY
#undef TELEMETRY_HOTT
#undef TELEMETRY_LTM

#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C_DEVICE              (I2CDEV_1)
#define I2C1_SDA                PB9
#define I2C1_SCL                PB8
#define BARO_I2C_INSTANCE       (I2CDEV_1)


#define USE_SPI

#define USE_SPI_DEVICE_1 //MPU9250
#define SPI1_SCK_PIN            PA5
#define SPI1_MISO_PIN           PA6
#define SPI1_MOSI_PIN           PA7
#define SPI1_NSS_PIN            PA4



#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN            NONE
#define SPI2_MISO_PIN           NONE
#define SPI2_MOSI_PIN           NONE

#define USE_SPI_DEVICE_3
#define SPI3_SCK_PIN            NONE
#define SPI3_MISO_PIN           NONE
#define SPI3_MOSI_PIN           NONE


#define USE_ACC
#define USE_ACC_SPI_MPU9250

#define USE_GYRO
#define USE_GYRO_SPI_MPU9250
#define GYRO_1_CS_PIN           SPI1_NSS_PIN
#define GYRO_1_SPI_INSTANCE     SPI1
#define GYRO_1_EXTI_PIN         PC15
#define ENSURE_MPU_DATA_READY_IS_LOW


#define USE_MAG
#ifdef  USE_MAG
#define USE_MAG_DATA_READY_SIGNAL
#define USE_MAG_AK8963
#endif

#define USE_BARO
#ifdef USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_BMP085
#endif

#define USE_FLASHFS
#define USE_FLASH_TOOLS
#define USE_FLASH_M25P16
#define USE_FLASH_W25N01G          // 1Gb NAND flash support
#define USE_FLASH_W25M             // Stacked die support
#define USE_FLASH_W25M512          // 512Kb (256Kb x 2 stacked) NOR flash support
#define USE_FLASH_W25M02G          // 2Gb (1Gb x 2 stacked) NAND flash support
#define USE_FLASH_W25Q128FV        // 16MB Winbond 25Q128

#define USE_USB_DETECT

#define USE_TIMER
#define USE_PWM_OUTPUT
#define USE_MOTOR

#define USABLE_TIMER_CHANNEL_COUNT 8
#define USED_TIMERS             (TIM_N(1)|TIM_N(2)|TIM_N(3)|TIM_N(4)|TIM_N(5))
