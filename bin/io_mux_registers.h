#ifndef __IOMUXREGISTERS__
#define __IOMUXREGISTERS__

// IO MUX registers
#define IO_MUX_PIN_CTRL (*((unsigned long *)0x3FF49000))
#define IO_MUX_MTMS_REG (*((unsigned long *)0x3FF49030))
#define IO_MUX_MTDI_REG (*((unsigned long *)0x3FF49034))
#define IO_MUX_MTCK_REG (*((unsigned long *)0x3FF49038))
#define IO_MUX_MTDO_REG (*((unsigned long *)0x3FF4903C))
#define IO_MUX_SD_DATA0_REG (*((unsigned long *)0x3FF49064))
#define IO_MUX_SD_DATA1_REG (*((unsigned long *)0x3FF49068))
#define IO_MUX_SD_DATA2_REG (*((unsigned long *)0x3FF49054))
#define IO_MUX_SD_DATA3_REG (*((unsigned long *)0x3FF49058))
#define IO_MUX_SD_CMD_REG (*((unsigned long *)0x3FF4905C))
#define IO_MUX_SD_CLK_REG (*((unsigned long *)0x3FF49060))
#define IO_MUX_U0RXD_REG (*((unsigned long *)0x3FF49084))
#define IO_MUX_U0TXD_REG (*((unsigned long *)0x3FF49088))

// Pads configuration registers (missing pads 1,3,6-15,28-31)
#define IO_MUX_GPIO0_REG (*((unsigned long *)0x3FF49044))
#define IO_MUX_GPIO2_REG (*((unsigned long *)0x3FF49040))
#define IO_MUX_GPIO4_REG (*((unsigned long *)0x3FF49048))
#define IO_MUX_GPIO5_REG (*((unsigned long *)0x3FF4906C))
#define IO_MUX_GPIO16_REG (*((unsigned long *)0x3FF4904C))
#define IO_MUX_GPIO17_REG (*((unsigned long *)0x3FF49050))
#define IO_MUX_GPIO18_REG (*((unsigned long *)0x3FF49070))
#define IO_MUX_GPIO19_REG (*((unsigned long *)0x3FF49074))
#define IO_MUX_GPIO20_REG (*((unsigned long *)0x3FF49078))
#define IO_MUX_GPIO21_REG (*((unsigned long *)0x3FF4907C))
#define IO_MUX_GPIO22_REG (*((unsigned long *)0x3FF49080))
#define IO_MUX_GPIO23_REG (*((unsigned long *)0x3FF4908C))
#define IO_MUX_GPIO24_REG (*((unsigned long *)0x3FF49090))
#define IO_MUX_GPIO25_REG (*((unsigned long *)0x3FF49024))
#define IO_MUX_GPIO26_REG (*((unsigned long *)0x3FF49028))
#define IO_MUX_GPIO27_REG (*((unsigned long *)0x3FF4902C))
#define IO_MUX_GPIO32_REG (*((unsigned long *)0x3FF4901C))
#define IO_MUX_GPIO33_REG (*((unsigned long *)0x3FF49020))
#define IO_MUX_GPIO34_REG (*((unsigned long *)0x3FF49014))
#define IO_MUX_GPIO35_REG (*((unsigned long *)0x3FF49018))
#define IO_MUX_GPIO36_REG (*((unsigned long *)0x3FF49004))
#define IO_MUX_GPIO37_REG (*((unsigned long *)0x3FF49008))
#define IO_MUX_GPIO38_REG (*((unsigned long *)0x3FF4900C))
#define IO_MUX_GPIO39_REG (*((unsigned long *)0x3FF49010))

// RTC IO MUX registers
#define RTCIO_RTC_GPIO_IN_REG (*((unsigned long *)0x3FF48424))
#define RTCIO_RTC_GPIO_OUT_REG (*((unsigned long *)0x3FF48400))
#define RTCIO_RTC_GPIO_OUT_W1TS_REG (*((unsigned long *)0x3FF48404))
#define RTCIO_RTC_GPIO_OUT_W1TC_REG (*((unsigned long *)0x3FF48408))
#define RTCIO_RTC_GPIO_OUT_ENABLE_REG (*((unsigned long *)0x3FF4840C))
#define RTCIO_RTC_GPIO_OUT_ENABLE_W1TS_REG (*((unsigned long *)0x3FF48410))
#define RTCIO_RTC_GPIO_OUT_ENABLE_W1TC_REG (*((unsigned long *)0x3FF48414))
#define RTCIO_RTC_GPIO_OUT_STATUS_REG (*((unsigned long *)0x3FF48418))
#define RTCIO_RTC_GPIO_OUT_STATUS_W1TS_REG (*((unsigned long *)0x3FF4841C))
#define RTCIO_RTC_GPIO_OUT_STATUS_W1TC_REG (*((unsigned long *)0x3FF48420))
#define RTCIO_DIG_PAD_HOLD_REG (*((unsigned long *)0x3FF48474))
#define RTCIO_SENSOR_PADS_REG (*((unsigned long *)0x3FF4847C))
#define RTCIO_ADC_PAD_REG (*((unsigned long *)0x3FF48480))
#define RTCIO_PAD_DAC1_REG (*((unsigned long *)0x3FF48484))
#define RTCIO_PAD_DAC2_REG (*((unsigned long *)0x3FF48488))
#define RTCIO_XTAL_32K_PAD_REG (*((unsigned long *)0x3FF4848C))
#define RTCIO_TOUCH_CFG_REG (*((unsigned long *)0x3FF48490))
#define RTCIO_EXT_WAKEUP0_REG (*((unsigned long *)0x3FF484BC))
#define RTCIO_XTL_EXT_CTR_REG (*((unsigned long *)0x3FF484C0))
#define RTCIO_SAR_I2C_IO_REG (*((unsigned long *)0x3FF484C4))

// Pins RTC configuration registers
#define RTCIO_RTC_GPIO_PIN0_REG (*((unsigned long *)0x3FF48428))
#define RTCIO_RTC_GPIO_PIN1_REG (*((unsigned long *)0x3FF4842C))
#define RTCIO_RTC_GPIO_PIN2_REG (*((unsigned long *)0x3FF48430))
#define RTCIO_RTC_GPIO_PIN3_REG (*((unsigned long *)0x3FF48434))
#define RTCIO_RTC_GPIO_PIN4_REG (*((unsigned long *)0x3FF48438))
#define RTCIO_RTC_GPIO_PIN5_REG (*((unsigned long *)0x3FF4843C))
#define RTCIO_RTC_GPIO_PIN6_REG (*((unsigned long *)0x3FF48440))
#define RTCIO_RTC_GPIO_PIN7_REG (*((unsigned long *)0x3FF48444))
#define RTCIO_RTC_GPIO_PIN8_REG (*((unsigned long *)0x3FF48448))
#define RTCIO_RTC_GPIO_PIN9_REG (*((unsigned long *)0x3FF4844C))
#define RTCIO_RTC_GPIO_PIN10_REG (*((unsigned long *)0x3FF48450))
#define RTCIO_RTC_GPIO_PIN11_REG (*((unsigned long *)0x3FF48454))
#define RTCIO_RTC_GPIO_PIN12_REG (*((unsigned long *)0x3FF48458))
#define RTCIO_RTC_GPIO_PIN13_REG (*((unsigned long *)0x3FF4845C))
#define RTCIO_RTC_GPIO_PIN14_REG (*((unsigned long *)0x3FF48460))
#define RTCIO_RTC_GPIO_PIN15_REG (*((unsigned long *)0x3FF48464))
#define RTCIO_RTC_GPIO_PIN16_REG (*((unsigned long *)0x3FF48468))
#define RTCIO_RTC_GPIO_PIN17_REG (*((unsigned long *)0x3FF4846C))

// Touch pads configuration registers
#define RTCIO_TOUCH_PAD0_REG (*((unsigned long *)0x3FF48494))
#define RTCIO_TOUCH_PAD1_REG (*((unsigned long *)0x3FF48498))
#define RTCIO_TOUCH_PAD2_REG (*((unsigned long *)0x3FF4849C))
#define RTCIO_TOUCH_PAD3_REG (*((unsigned long *)0x3FF484A0))
#define RTCIO_TOUCH_PAD4_REG (*((unsigned long *)0x3FF484A4))
#define RTCIO_TOUCH_PAD5_REG (*((unsigned long *)0x3FF484A8))
#define RTCIO_TOUCH_PAD6_REG (*((unsigned long *)0x3FF484AC))
#define RTCIO_TOUCH_PAD7_REG (*((unsigned long *)0x3FF484B0))
#define RTCIO_TOUCH_PAD8_REG (*((unsigned long *)0x3FF484B4))
#define RTCIO_TOUCH_PAD9_REG (*((unsigned long *)0x3FF484B8))

#endif