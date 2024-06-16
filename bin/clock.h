#include <stdint.h>

#ifndef __CLOCK__
#define __CLOCK__

// CPU_CLK REGISTERS
#define RTC_CNTL_CLK_CONF_REG (*((unsigned long *)0x3FF48070))
#define DPORT_CPU_PER_CONF_REG (*((unsigned long *)0x3FF0003C))

// REF_TICK REGISTERS
#define SYSCON_XTAL_TICK_CONF_REG (*((unsigned long *)0x0004))
#define SYSCON_PLL_TICK_CONF_REG (*((unsigned long *)0x0008))
#define SYSCON_CK8M_TICK_CONF_REG (*((unsigned long *)0x000C))
#define SYSCON_APLL_TICK_CONF_REG (*((unsigned long *)0x003C))

// LEDC_SCLK REGISTERS
#define LEDC_APB_CLK_SEL (*((unsigned long *)0x0190))

typedef enum
{
    XTL_CLK = 0x00,
    PLL_CLK_80MHz = 0x10,
    PLL_CLK_160MHz = 0x11,
    PLL_CLK_240MHz = 0x12,
    RC_FAST_CLK = 0x20,
    APLL_CLK_4 = 0x30,
    APLL_CLK_2 = 0x31,
} CPU_CLK_Source;

typedef enum
{
    RC_FAST_CLK,
    APB_CLK,
} LEDC_SCLK_Source;

/* ### Sets the source and prescaling of CPU_CLK
 * CPU_CLK affects APB_CLK:
 *                         - PLL_CLK        ->      80MHz
 *                         - APLL_CLK       ->      CPU_CLK/2
 *                         - XTL_CLK        ->      CPU_CLK
 *                         - RC_FAST_CLK    ->      CPU_CLK
 */
void set_CPU_CLK(CPU_CLK_Source);

/* ### Sets the prescaling of REF_TICK
 * REF_TICK frequency = APB_CLK/(x+1)
 */
void set_REF_TICK(uint8_t);

void set_LEDC_SCLK(LEDC_SCLK_Source);

#endif