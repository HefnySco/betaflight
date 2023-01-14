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
#ifdef USE_LEDX

#include "pg/pg.h"
#include "drivers/io_types.h"
#include "common/utils.h"

#define STATUS_LEDX_NUMBER 3

typedef struct statusLedxConfig_s {
    ioTag_t ioTags[STATUS_LEDX_NUMBER];
    uint8_t inversion;
} statusLedxConfig_t;

PG_DECLARE(statusLedxConfig_t, statusLedxConfig);

// Helpful macros
#if defined(UNIT_TEST) || defined(USE_FAKE_LED)

#define LEDX0_TOGGLE              NOOP
#define LEDX0_OFF                 NOOP
#define LEDX0_ON                  NOOP

#define LEDX1_TOGGLE              NOOP
#define LEDX1_OFF                 NOOP
#define LEDX1_ON                  NOOP

#define LEDX2_TOGGLE              NOOP
#define LEDX2_OFF                 NOOP
#define LEDX2_ON                  NOOP

#else

#define LEDX0_TOGGLE              ledxToggle(0)
#define LEDX0_OFF                 ledxSet(0, false)
#define LEDX0_ON                  ledxSet(0, true)

#define LEDX1_TOGGLE              ledxToggle(1)
#define LEDX1_OFF                 ledxSet(1, false)
#define LEDX1_ON                  ledxSet(1, true)

#define LEDX2_TOGGLE              ledxToggle(2)
#define LEDX2_OFF                 ledxSet(2, false)
#define LEDX2_ON                  ledxSet(2, true)

void ledxInit(const statusLedxConfig_t *statusLedConfig);
void ledxToggle(int led);
void ledxSet(int led, bool state);

#endif
#endif