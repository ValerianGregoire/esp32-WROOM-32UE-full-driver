#include "clock.h"

void set_CPU_CLK(CPU_CLK_Source source)
{
    RTC_CNTL_CLK_CONF_REG &= ~(3 << 27);
    RTC_CNTL_CLK_CONF_REG |= (((source & 0xf0) >> 4) << 27);
    DPORT_CPU_PER_CONF_REG = (source & 0x0f);
}

void set_REF_TICK(int x)
{
    (x > 0xFF) ? (x = 0xFF) : x;

    switch (RTC_CNTL_CLK_CONF_REG & (0x3 << 27))
    {
    case 0x0:
        SYSCON_XTAL_TICK_CONF_REG = x;
        break;
    case 0x1:
        SYSCON_PLL_TICK_CONF_REG = x;
        break;
    case 0x2:
        SYSCON_CK8M_TICK_CONF_REG = x;
        break;
    case 0x3:
        SYSCON_APLL_TICK_CONF_REG = x;
        break;
    default:
        break;
    }
}

void set_LEDC_SCLK(LEDC_SCLK_Source source){
    LEDC_APB_CLK_SEL = source;
}