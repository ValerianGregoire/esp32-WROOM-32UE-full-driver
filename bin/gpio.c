#include <stdint.h>
#include "gpio_matrix_registers.h"
#include "io_mux_registers.h"
#include "gpio.h"

/* Sets a GPIO pad as output
 *  unsigned int n: Pin number (0 to 39)*/
void outputGPIO(uint8_t n)
{
    if (n < 32)
    {
        GPIO_ENABLE_W1TS_REG |= (1 << n);
    }
    else if (n >= 32 && n < 40)
    {
        GPIO_ENABLE1_W1TS_REG |= (1 << (n - 32));
    }
}

/* Sets a GPIO pad as input
 *  unsigned int n: Pin number (0 to 39)*/
void inputGPIO(uint8_t n)
{
    if (n < 32)
    {
        GPIO_ENABLE_W1TC_REG |= (1 << n);
    }
    else if (n >= 32 && n < 40)
    {
        GPIO_ENABLE1_W1TC_REG |= (1 << (n - 32));
    }
}

/* Sets an output GPIO pad HIGH
 *  unsigned int n: Pin number (0 to 39)*/
void setHighGPIO(uint8_t n)
{
    if (n < 32)
    {
        GPIO_OUT_W1TS_REG |= (1 << n);
    }
    else if (n >= 32 && n < 40)
    {
        GPIO_OUT1_W1TS_REG |= (1 << (n - 32));
    }
}

/* Sets an output GPIO pad LOW
 *  unsigned int n: Pin number (0 to 39)*/
void setLowGPIO(uint8_t n)
{
    if (n < 32)
    {
        GPIO_OUT_W1TC_REG |= (1 << n);
    }
    else if (n >= 32 && n < 40)
    {
        GPIO_OUT1_W1TC_REG |= (1 << (n - 32));
    }
}

/* Returns the value of an input GPIO pad
 *  unsigned int n: Pin number (0 to 39)*/
unsigned int readGPIO(uint8_t n)
{
    if (n < 32)
    {
        return (unsigned int)((GPIO_IN_REG >> n) & 1);
    }
    else if (n >= 32 && n < 40)
    {
        return (unsigned int)((GPIO_IN1_REG >> (n - 32)) & 1);
    }
    else
    {
        return 0;
    }
}