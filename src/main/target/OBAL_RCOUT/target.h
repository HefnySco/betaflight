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
#define TARGET_BOARD_IDENTIFIER "OBAL_RCOUT"
#define USBD_PRODUCT_STRING     "Betaflight OBAL"

#define USE_TARGET_CONFIG

//#define INVERTER_PIN_UART2      PC14
#define MAX_SUPPORTED_MOTORS    8

////HOW MANY MOTORS
#define DEFAULT_MIXER    MIXER_OCTOX8

//// TASKS SECTION
#undef USE_CAMERA_CONTROL
#undef USE_VTX_CONTROL
#undef USE_SPEKTRUM_BIND
#define USE_TASK_MOTORS
#undef USE_CMS
#undef TASK_GYROPID_DESIRED_PERIOD
#define TASK_GYROPID_DESIRED_PERIOD 10
#undef TASK_ACC_DESIRED_PERIOD
#define TASK_ACC_DESIRED_PERIOD 10
#define USE_BUTTONS
#define BUTTON_A_PIN            PA0
   
///////END TASKS

#define USE_CLI_DEBUG_PRINT
#define USE_I2C_RCOUT
#define USE_LEDX
#define LEDX0_PIN               PC13 



#define USE_GYRO
#define USE_ACC
#define USE_SUPER_FAKE_GYRO
#define USE_FAKE_ACC


#define USE_VCP
#define USE_USB_DETECT


#define SERIAL_PORT_COUNT       1 //VCP, USART1, USART2, SOFTSERIAL1, SOFTSERIAL2


#define USE_I2C_SLAVE

#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C1_SDA                PB7
#define I2C1_SCL                PB6
#define I2C1_ADDRESS            0x66

#define USE_RCOUT_I2C           I2CDEV_1

#define USE_SPI
#define USE_SPI_DEVICE_1 
#define SPI1_SCK_PIN            NONE
#define SPI1_MISO_PIN           NONE
#define SPI1_MOSI_PIN           NONE
#define SPI1_NSS_PIN            NONE



#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN            NONE
#define SPI2_MISO_PIN           NONE
#define SPI2_MOSI_PIN           NONE

#define USE_SPI_DEVICE_3
#define SPI3_SCK_PIN            NONE
#define SPI3_MISO_PIN           NONE
#define SPI3_MOSI_PIN           NONE

#define USE_ADC
//#define ADC_INSTANCE            ADC1  
//#define ADC1_DMA_OPT            0  // DMA 2 Stream 0 Channel 0 
#define VBAT_ADC_PIN            PA1
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC


// #define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ESC
// #define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ESC
// #define USE_ACC
// #define USE_ACC_SPI_MPU9250



//#define SERIALRX_UART           SERIAL_PORT_USART2

#define USE_TRANSPONDER

#define DEFAULT_RX_FEATURE      FEATURE_RX_PARALLEL_PWM
//#define SERIALRX_PROVIDER       SERIALRX_SBUS

//#define DEFAULT_FEATURES        (FEATURE_OSD | FEATURE_SOFTSERIAL | FEATURE_ESC_SENSOR)



#define TARGET_IO_PORTA (0xffff & ~(BIT(14)|BIT(13)))
#define TARGET_IO_PORTB (0xffff & ~(BIT(2)|BIT(11)))
#define TARGET_IO_PORTC (BIT(13)|BIT(14)|BIT(15))

#define USE_TIMER
#define USE_PWM
#define USE_PWM_OUTPUT
#define USE_MOTOR

#define USABLE_TIMER_CHANNEL_COUNT 8
#define USED_TIMERS             (TIM_N(1)|TIM_N(2)|TIM_N(3))
