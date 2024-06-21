#ifndef __CLOCKREGISTERS__
#define __CLOCKREGISTERS__

// CPU_CLK REGISTERS

#define RTC_CNTL_CLK_CONF_REG (*((unsigned long *)0x3FF48070))
#define DPORT_CPU_PER_CONF_REG (*((unsigned long *)0x3FF0003C))

// SYSCON REGISTERS

#define SYSCON_SYSCLK_CONF_REG (*((unsigned long *)0x3FF66000))
#define SYSCON_XTAL_TICK_CONF_REG (*((unsigned long *)0x3FF66004))
#define SYSCON_PLL_TICK_CONF_REG (*((unsigned long *)0x3FF66008))
#define SYSCON_CK8M_TICK_CONF_REG (*((unsigned long *)0x3FF6600C))
#define SYSCON_APLL_TICK_CONF_REG (*((unsigned long *)0x3FF6603C))
#define SYSCON_DATE_REG (*((unsigned long *)0x3FF6607C))

// LEDC_SCLK REGISTERS

#define LEDC_APB_CLK_SEL (*((unsigned long *)0x3FF59190))

// APLL REGISTERS

#define RTC_CNTL_ANA_CONF_REG (*((unsigned long *)0x3FF48030))

#endif