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

#include "platform.h"
#ifdef USE_LEDX
#include "pg/pg_ids.h"

#include "drivers/io.h"
#include "io_impl.h"

#include "light_ledx.h"

PG_REGISTER_WITH_RESET_FN(statusLedxConfig_t, statusLedxConfig, PG_STATUS_LEDX_CONFIG, 0);

static IO_t ledxs[STATUS_LEDX_NUMBER];
static uint8_t ledxInversion = 0;

#ifndef LEDX0_PIN
#define LEDX0_PIN NONE
#endif

#ifndef LEDX1_PIN
#define LEDX1_PIN NONE
#endif

#ifndef LEDX2_PIN
#define LEDX2_PIN NONE
#endif

void pgResetFn_statusLedxConfig(statusLedxConfig_t *statusLedxConfig)
{
    statusLedxConfig->ioTags[0] = IO_TAG(LEDX0_PIN);
    statusLedxConfig->ioTags[1] = IO_TAG(LEDX1_PIN);
    statusLedxConfig->ioTags[2] = IO_TAG(LEDX2_PIN);
    statusLedxConfig->ioTags[3] = IO_TAG(LEDX0_PIN);
    statusLedxConfig->ioTags[4] = IO_TAG(LEDX1_PIN);
    statusLedxConfig->ioTags[5] = IO_TAG(LEDX2_PIN);
    statusLedxConfig->ioTags[6] = IO_TAG(LEDX1_PIN);
    statusLedxConfig->ioTags[7] = IO_TAG(LEDX2_PIN);

    statusLedxConfig->inversion = 0
#ifdef LEDX0_INVERTED
    | BIT(0)
#endif
#ifdef LEDX1_INVERTED
    | BIT(1)
#endif
#ifdef LEDX2_INVERTED
    | BIT(2)
#endif
#ifdef LEDX3_INVERTED
    | BIT(3)
#endif
#ifdef LEDX4_INVERTED
    | BIT(4)
#endif
#ifdef LEDX5_INVERTED
    | BIT(5)
#endif
#ifdef LEDX6_INVERTED
    | BIT(6)
#endif
#ifdef LEDX7_INVERTED
    | BIT(7)
#endif
    ;
}

void ledxInit(const statusLedxConfig_t *statusLedConfig)
{
    ledxInversion = statusLedConfig->inversion;
    for (int i = 0; i < STATUS_LEDX_NUMBER; i++) {
        if (statusLedConfig->ioTags[i]) {
            ledxs[i] = IOGetByTag(statusLedConfig->ioTags[i]);
            IOInit(ledxs[i], OWNER_LED, RESOURCE_INDEX(i));
            IOConfigGPIO(ledxs[i], IOCFG_OUT_PP);
        } else {
            ledxs[i] = IO_NONE;
        }
    }

    LEDX0_OFF;
    LEDX1_OFF;
    LEDX2_OFF;
    LEDX3_OFF;
    LEDX4_OFF;
    LEDX5_OFF;
    LEDX6_OFF;
    LEDX7_OFF;

}

void ledxToggle(int led)
{
    IOToggle(ledxs[led]);
}

void ledxSet(int led, bool on)
{
    const bool inverted = (1 << (led)) & ledxInversion;
    IOWrite(ledxs[led], on ? inverted : !inverted);
}
#endif