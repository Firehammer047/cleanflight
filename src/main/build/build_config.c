/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight is distributed in the hope that it
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include "stdbool.h"
#include "stdint.h"

#include "platform.h"

#include "build_config.h"

#ifdef USE_CLI_DEBUG_PRINT
#warning Do not use USE_CLI_DEBUG_PRINT for production builds.
#endif

mcuTypeId_e getMcuTypeId(void)
{
#if defined(SIMULATOR_BUILD)
    return MCU_TYPE_SIMULATOR;
#elif defined(STM32F1)
    return MCU_TYPE_F103;
#elif defined(STM32F3)
    return MCU_TYPE_F303;
#elif defined(STM32F40_41xxx)
    return MCU_TYPE_F40X;
#elif defined(STM32F411xE)
    return MCU_TYPE_F411;
#elif defined(STM32F446xx)
    return MCU_TYPE_F446;
#elif defined(STM32F722xx)
    return MCU_TYPE_F722;
#elif defined(STM32F745xx)
    return MCU_TYPE_F745;
#elif defined(STM32F746xx)
    return MCU_TYPE_F746;
#elif defined(STM32F765xx)
    return MCU_TYPE_F765;
#elif defined(STM32H750xx)
    return MCU_TYPE_H750;
#elif defined(STM32H743xx)
    switch (HAL_GetREVID()) {
    case REV_ID_Y:
        return MCU_TYPE_H743_REV_Y;
    case REV_ID_X:
        return MCU_TYPE_H743_REV_X;
    case REV_ID_V:
        return MCU_TYPE_H743_REV_V;
    default:
        return MCU_TYPE_H743_REV_UNKNOWN;
    }
#else
    return MCU_TYPE_UNKNOWN;
#endif
}
