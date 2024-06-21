#include "clock.h"

void set_cpu_clk(CPU_CLK_source source)
{
    RTC_CNTL_CLK_CONF_REG &= ~(3 << 27);
    RTC_CNTL_CLK_CONF_REG |= (((source & 0xf0) >> 4) << 27);
    DPORT_CPU_PER_CONF_REG = (source & 0x0f);
}

void set_cpu_clk_prescaling(uint16_t x){
    (x > 0x3FE) ? (x = 0x3FE) : x;
    SYSCON_SYSCLK_CONF_REG = x;
}

void set_ref_tick(uint8_t x)
{
    switch ((RTC_CNTL_CLK_CONF_REG & (0x3 << 27)) >> 27)
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

void set_LEDC_SCLK(LEDC_SCLK_source source){
    LEDC_APB_CLK_SEL = source;
}

void force_apll_power_up(){
    RTC_CNTL_ANA_CONF_REG &= ~(1 << 23);
    RTC_CNTL_ANA_CONF_REG |= 1 << 24;
}

void force_apll_power_down(){
    RTC_CNTL_ANA_CONF_REG &= ~(1 << 23);
    RTC_CNTL_ANA_CONF_REG |= 1 << 24;
}

void force_apll_free(){
    RTC_CNTL_ANA_CONF_REG &= ~(0x3 << 23);
}