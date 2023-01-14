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

#include <stdbool.h>
#include <stdint.h>

#include "platform.h"

#ifdef USE_TARGET_CONFIG

#include "io/serial.h"
#include "pg/motor.h"
#include "drivers/motor.h"

#include "build/debug.h"


void targetConfiguration(void)
{
    motorConfigMutable()->dev.motorPwmProtocol = PWM_TYPE_STANDARD;
    motorConfigMutable()->minthrottle = 700;
    motorConfigMutable()->maxthrottle = 2000;
    motorConfigMutable()->mincommand = 700;

}
#endif
