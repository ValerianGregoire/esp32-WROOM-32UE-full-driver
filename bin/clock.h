/******************************************************************************
                                UNIMPLEMENTED
 * Audio PPL Clock frequency control:
    f_appl = (f_xtal*(sdm2 + sdm1/256 + sdm0/65536 + 4))/(2*(odiv+2))
    Defaults at an unknown frequency. Missing control over sdm0-2/odiv.

 * RTC_FAST_CLK frequency control:
    Defaults at 8MHz. Frequency control in EFUSE_BLK0_WDATA4_REG.
*******************************************************************************/


#include <stdint.h>
#include <stdio.h>
#include "clock_registers.h"

#ifndef __CLOCK__
#define __CLOCK__

typedef enum
{
    XTL_CLK_cpu = 0x00,
    PLL_CLK_80MHz_cpu = 0x10,
    PLL_CLK_160MHz_cpu = 0x11,
    PLL_CLK_240MHz_cpu = 0x12,
    RC_FAST_CLK_cpu = 0x20,
    APLL_CLK_4_cpu = 0x30,
    APLL_CLK_2_cpu = 0x31,
} CPU_CLK_source;

typedef enum
{
    RC_FAST_CLK_ledc,
    APB_CLK_ledc,
} LEDC_SCLK_source;

/* ### Set the source and/or prescaling of CPU_CLK
 *
 * Source -> CPU_CLK freq:
 *                         - XTL_CLK            ->  XTL_CLK/Prescaling
 *                         - PLL_CLK (320 MHz)  ->  80  MHz
 *                         - PLL_CLK (320 MHz)  ->  160 MHz
 *                         - PLL_CLK (480 MHz)  ->  240 MHz
 *                         - RC_FAST_CLK        ->  RC_FAST_CLK/Prescaling
 *                         - APLL_CLK           ->  APLL_CLK/4
 *
 * CPU_CLK source -> APB_CLK freq:
 *                         - PLL_CLK            ->  80  MHz
 *                         - APLL_CLK           ->  CPU_CLK/2
 *                         - XTL_CLK            ->  CPU_CLK
 *                         - RC_FAST_CLK        ->  CPU_CLK */
void set_cpu_clk(CPU_CLK_source);

/* ### Set the prescaling of CPU_CLK when sourced from XTL_CLK or RC_FAST_CLK
 * - x_max = 0x3FE
 * - CPU_CLK frequency = Source/(x+1) */
void set_cpu_clk_prescaling(uint16_t);

/* ### Set the prescaling of REF_TICK
 *                         - REF_TICK frequency = APB_CLK/(x+1) */
void set_ref_tick(uint8_t);

/* ### Set the source and/or prescaling of LEDC_SCLK
 *
 * Source -> LEDC_SCLK freq:
 *                         - RC_FAST_CLK    ->      8   MHz
 *                         - APB_CLK        ->      APB_CLK*/
void set_LEDC_SCLK(LEDC_SCLK_source);

// ### Force the APLL clock to run even in sleep mode
void force_apll_power_up();

// ### Force the APLL clock to be disabled
void force_apll_power_down();

// ### Lets the APLL turn on when the board wakes up and turn off in sleep mode 
void force_apll_free();

#endif