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
#define MAX_SUPPORTED_MOTORS   4
#define MAX_SUPPORTED_RCINPUT  4

////HOW MANY MOTORS
#define DEFAULT_MIXER    MIXER_QUADP

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
#define USE_RCINPUT_I2C_DEBUG   0x2 // from 0 to total -4
//#define DEBUG_ADC_CHANNELS
///////END TASKS

#define USE_CLI_DEBUG_PRINT

#define USE_LEDX
#define LEDX0_PIN               PC13 



#define USE_GYRO
#define USE_ACC
#define USE_SUPER_FAKE_GYRO
#define USE_FAKE_ACC


#define USE_VCP
#define USE_USB_DETECT


#define SERIAL_PORT_COUNT       1 //VCP, USART1, USART2, SOFTSERIAL1, SOFTSERIAL2



#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C1_SDA                PB7
#define I2C1_SCL                PB6
#define I2C1_ADDRESS            0x66  // non zero address means slave


#define USE_I2C_DEVICE_2
#define I2C2_SDA                PB3
#define I2C2_SCL                PB10
#define I2C2_ADDRESS            0x27  // non zero address means slave


#define USE_I2C_DEVICE_3
#define I2C3_SDA                PB4
#define I2C3_SCL                PA8
#define I2C3_ADDRESS            0x33 // non zero address means slave
#define I2C3_ADDRESS_2          0x48

// RCINT:
#define PWM_PORTS_OR_PPM_CAPTURE_COUNT  6
#define USE_RCOUT_I2C           I2CDEV_1
#define USE_RCINPUT_I2C         I2CDEV_2
#define USE_ADC_I2C             I2CDEV_3

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

#define MAX_VOLTAGE_SENSOR_ADC  6
#define USE_ADC
#define USE_BATTERY
#define USE_TASK_RX
#define USE_ADC_INTERNAL

//#define DEBUG_ADC_CHANNELS
#define VBAT_ADC_PIN            PA1
#define CURRENT_METER_ADC_PIN   PA2
#define EXTERNAL1_ADC_PIN       PA4
#define EXTERNAL2_ADC_PIN       PA7
//#define EXTERNAL3_ADC_PIN       PA7
  

#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC






#define USE_TRANSPONDER

#define DEFAULT_RX_FEATURE      FEATURE_RX_PARALLEL_PWM




#define TARGET_IO_PORTA (0xffff & ~(BIT(14)|BIT(13)))
#define TARGET_IO_PORTB (0xffff & ~(BIT(2)|BIT(11)))
#define TARGET_IO_PORTC (BIT(13)|BIT(14)|BIT(15))

#define USE_TIMER
#define USE_PWM
#define USE_PWM_OUTPUT
#define USE_MOTOR

#define USABLE_TIMER_CHANNEL_COUNT 10
#define USED_TIMERS             (TIM_N(1)|TIM_N(2)|TIM_N(3)|TIM_N(4)|TIM_N(10))
