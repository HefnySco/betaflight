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

#define USE_TARGET_CONFIG
#define LED0_PIN                PC13


#define INVERTER_PIN_UART2      PC14

#define USE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_ACC_SPI_MPU6000

#define USE_GYRO
#define USE_GYRO_SPI_MPU6500
#define USE_GYRO_SPI_MPU6000



// #define GYRO_1_EXTI_PIN         PA8

#define USE_VCP
#define USE_USB_DETECT






#define SERIAL_PORT_COUNT       3 //VCP, USART1, USART2, SOFTSERIAL1, SOFTSERIAL2

#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C_DEVICE              (I2CDEV_1)
#define I2C1_SDA                PB7
#define I2C1_SCL                PB6
#define BARO_I2C_INSTANCE       (I2CDEV_1)

#define USE_UART1
#define UART1_RX_PIN            PA10
#define UART1_TX_PIN            PA9

#define USE_UART2
#define UART2_RX_PIN            PA3
#define UART2_TX_PIN            PA2



#define USE_SPI

#define USE_SPI_DEVICE_1 //MPU9250
#define SPI1_SCK_PIN            NONE
#define SPI1_MISO_PIN           NONE
#define SPI1_MOSI_PIN           NONE
#define SPI1_NSS_PIN            NONE


#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN            PB13
#define SPI2_MISO_PIN           PB14
#define SPI2_MOSI_PIN           PB15
#define SPI2_NSS_PIN            PB12

#define USE_SPI_DEVICE_3
#define SPI3_SCK_PIN            NONE
#define SPI3_MISO_PIN           NONE
#define SPI3_MOSI_PIN           NONE

#define USE_ADC
#define CURRENT_METER_ADC_PIN   PA0
#define VBAT_ADC_PIN            PA6


#define USE_ACC
#define USE_ACC_SPI_MPU9250

#define USE_GYRO
#define USE_GYRO_SPI_MPU9250
#define GYRO_1_CS_PIN           SPI2_NSS_PIN
#define GYRO_1_SPI_INSTANCE     SPI2
//#define GYRO_1_EXTI_PIN         PC15
#define ENSURE_MPU_DATA_READY_IS_LOW


#define USE_MAG
#ifdef  USE_MAG
#define USE_MAG_DATA_READY_SIGNAL
#define USE_MAG_AK8963
#endif

#define USE_BARO
#ifdef  USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_BMP085
#endif

#define SERIALRX_UART           SERIAL_PORT_USART2

#define USE_TRANSPONDER

#define DEFAULT_RX_FEATURE      FEATURE_RX_PARALLEL_PWM
#define SERIALRX_PROVIDER       SERIALRX_SBUS

#define DEFAULT_FEATURES        (FEATURE_OSD | FEATURE_SOFTSERIAL | FEATURE_RX_PPM )

#define USE_USB_DETECT

#define TARGET_IO_PORTA (0xffff & ~(BIT(14)|BIT(13)))
#define TARGET_IO_PORTB (0xffff & ~(BIT(2)|BIT(11)))
#define TARGET_IO_PORTC (BIT(13)|BIT(14)|BIT(15))

#define USE_TIMER
#define USE_PPM
#define USE_PWM_OUTPUT
#define USE_MOTOR
#define USE_SERVOS
#define ENABLE_DSHOT_DMAR       DSHOT_DMAR_ON

#define USABLE_TIMER_CHANNEL_COUNT 8
#define USED_TIMERS             (TIM_N(1)|TIM_N(2)|TIM_N(3)|TIM_N(4))
