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

#pragma once

#include "drivers/dma.h"

// Macros expand to keep DMA descriptor table compatible with Betaflight
#define DEF_TIM_DMAMAP(variant, timch) CONCAT(DEF_TIM_DMAMAP__, PP_CALL(CONCAT(DEF_TIM_DMAMAP_VARIANT__, variant), CONCAT(DEF_TIM_DMA__BTCH_, timch), DMA_VARIANT_MISSING, DMA_VARIANT_MISSING))
#define DEF_TIM_DMAMAP_VARIANT__0(_0, ...)         _0
#define DEF_TIM_DMAMAP_VARIANT__1(_0, _1, ...)     _1
#define DEF_TIM_DMAMAP_VARIANT__2(_0, _1, _2, ...) _2

#if defined(STM32F3)

// #include "timer_def_stm32f3xx.h"

#elif defined(STM32F4)

// Mappings for STDLIB defines
#define DEF_TIM_CHNL_CH1    TIM_Channel_1
#define DEF_TIM_CHNL_CH2    TIM_Channel_2
#define DEF_TIM_CHNL_CH3    TIM_Channel_3
#define DEF_TIM_CHNL_CH4    TIM_Channel_4

#define DEF_TIM(tim, ch, pin, usage, flags, dmavar)     { tim, IO_TAG(pin), DEF_TIM_CHNL_##ch, flags, IOCFG_AF_PP, GPIO_AF_##tim, usage, DEF_TIM_DMAMAP(dmavar, tim##_##ch) }

#define DEF_TIM_DMAMAP__D(dma, stream, channel)         DMA_TAG(dma, stream, channel)
#define DEF_TIM_DMAMAP__NONE                            DMA_NONE

#define DEF_TIM_DMA__BTCH_TIM1_CH1    D(2, 6, 0),D(2, 1, 6),D(2, 3, 6)
#define DEF_TIM_DMA__BTCH_TIM1_CH2    D(2, 6, 0),D(2, 2, 6)
#define DEF_TIM_DMA__BTCH_TIM1_CH3    D(2, 6, 0),D(2, 6, 6)
#define DEF_TIM_DMA__BTCH_TIM1_CH4    D(2, 4, 6)

#define DEF_TIM_DMA__BTCH_TIM2_CH1    D(1, 5, 3)
#define DEF_TIM_DMA__BTCH_TIM2_CH2    D(1, 6, 3)
#define DEF_TIM_DMA__BTCH_TIM2_CH3    D(1, 1, 3)
#define DEF_TIM_DMA__BTCH_TIM2_CH4    D(1, 7, 3),D(1, 6, 3)

#define DEF_TIM_DMA__BTCH_TIM3_CH1    D(1, 4, 5)
#define DEF_TIM_DMA__BTCH_TIM3_CH2    D(1, 5, 5)
#define DEF_TIM_DMA__BTCH_TIM3_CH3    D(1, 7, 5)
#define DEF_TIM_DMA__BTCH_TIM3_CH4    D(1, 2, 5)

#define DEF_TIM_DMA__BTCH_TIM4_CH1    D(1, 0, 2)
#define DEF_TIM_DMA__BTCH_TIM4_CH2    D(1, 3, 2)
#define DEF_TIM_DMA__BTCH_TIM4_CH3    D(1, 7, 2)

#define DEF_TIM_DMA__BTCH_TIM5_CH1    D(1, 2, 6)
#define DEF_TIM_DMA__BTCH_TIM5_CH2    D(1, 4, 6)
#define DEF_TIM_DMA__BTCH_TIM5_CH3    D(1, 0, 6)
#define DEF_TIM_DMA__BTCH_TIM5_CH4    D(1, 1, 6),D(1, 3, 6)

#define DEF_TIM_DMA__BTCH_TIM8_CH1    D(2, 2, 0),D(2, 2, 7)
#define DEF_TIM_DMA__BTCH_TIM8_CH2    D(2, 2, 0),D(2, 3, 7)
#define DEF_TIM_DMA__BTCH_TIM8_CH3    D(2, 2, 0),D(2, 4, 7)
#define DEF_TIM_DMA__BTCH_TIM8_CH4    D(2, 7, 7)

#define DEF_TIM_DMA__BTCH_TIM4_CH4    NONE

#define DEF_TIM_DMA__BTCH_TIM9_CH1    NONE
#define DEF_TIM_DMA__BTCH_TIM9_CH2    NONE

#define DEF_TIM_DMA__BTCH_TIM10_CH1   NONE

#define DEF_TIM_DMA__BTCH_TIM11_CH1   NONE

#define DEF_TIM_DMA__BTCH_TIM12_CH1   NONE
#define DEF_TIM_DMA__BTCH_TIM12_CH2   NONE

#define DEF_TIM_DMA__BTCH_TIM13_CH1   NONE

#define DEF_TIM_DMA__BTCH_TIM14_CH1   NONE

#elif defined(STM32F7)

//#include "timer_def_stm32f7xx.h"

#else
#error "Unknown CPU defined"
#endif
