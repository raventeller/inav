/*
 * This file is part of INAV.
 *
 * INAV is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * INAV is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with INAV.  If not, see <http://www.gnu.org/licenses/>.
 */

/* * This file is part of INAV. * * INAV is free software: you can redistribute it and/or modify * it under the terms of the GNU General Public License as published by * the Free Software Foundation, either version 3 of the License, or * (at your option) any later version. * * INAV is distributed in the hope that it will be useful, * but WITHOUT ANY WARRANTY; without even the implied warranty of * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the * GNU General Public License for more details. * * You should have received a copy of the GNU General Public License * along with INAV. If not, see <http://gnu.org>. */

#include <stdint.h>
#include "platform.h"
#include "drivers/bus.h"
#include "drivers/io.h"
#include "drivers/pwm_mapping.h"
#include "drivers/timer.h"
#include "drivers/pinio.h"
#include "drivers/sensor.h"

// Explicitly register the physical Gyro units onto the SPI1 bus local configuration
BUSDEV_REGISTER_SPI_TAG(busdev_mpu6000, DEVHW_MPU6000, BUS_SPI1, PA15, NONE, 0, DEVFLAGS_NONE, CW180_DEG_FLIP);
BUSDEV_REGISTER_SPI_TAG(busdev_mpu6500, DEVHW_MPU6500, BUS_SPI1, PD2, NONE, 1, DEVFLAGS_NONE, CW90_DEG);

timerHardware_t timerHardware[] = {
    DEF_TIM(TIM3, CH1, PB4, TIM_USE_OUTPUT_AUTO, 0, 0), // S1 Motor 1 OUT
    DEF_TIM(TIM3, CH2, PB5, TIM_USE_OUTPUT_AUTO, 0, 0), // S2 Motor 2 OUT
    DEF_TIM(TIM3, CH3, PB0, TIM_USE_OUTPUT_AUTO, 0, 0), // S3 Motor 3 OUT
    DEF_TIM(TIM3, CH4, PB1, TIM_USE_OUTPUT_AUTO, 0, 0), // S4 Motor 4 OUT
    
    DEF_TIM(TIM2, CH2, PB3, TIM_USE_OUTPUT_AUTO, 0, 0), // S6 OUT
    DEF_TIM(TIM4, CH1, PB6, TIM_USE_OUTPUT_AUTO, 0, 0), // S7 OUT (Motor 5)
    DEF_TIM(TIM4, CH2, PB7, TIM_USE_OUTPUT_AUTO, 0, 0), // S8 OUT (Motor 6)
    
    DEF_TIM(TIM1, CH1, PA8, TIM_USE_LED, 0, 2),         // LED Strip
    DEF_TIM(TIM5, CH3, PA2, TIM_USE_ANY, 0, 0),         // TX2 & Softserial1
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware);
