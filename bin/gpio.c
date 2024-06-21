#include "gpio.h"

/* ### Set a GPIO pad as output
 *      - n: Pin number from 0 to 33
 *      - Only pads 0-­19, 21-­23, 25-­27, 32-33 can be set as output (28)*/
void output_gpio(uint8_t n)
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

/* ### Set a GPIO pad as input
 *      - n: Pin number from 0 to 39
 *      - Only pads 0-­19, 21-­23, 25-­27, 32-­39 can be set as input (34)*/
void input_gpio(uint8_t n)
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

/* ### Set an output GPIO pad HIGH
 *      - n: Pin number from 0 to 39*/
void set_high_gpio(uint8_t n)
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

/* ### Set an output GPIO pad LOW
 *      - n: Pin number from 0 to 39*/
void set_low_gpio(uint8_t n)
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

/* ### Get the input at a GPIO pad
 *      - n: Pin number from 0 to 39*/
unsigned int read_gpio(uint8_t n)
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

void peripheral_input_gpio(uint8_t Y, uint8_t X){
    if (X < 64){
        // Set GPIO_FUNC(Y)_IN_SEL to X at position 0x00
        // Set GPIO_SIG(Y)_IN_SEL to 1 at position 0x80
        (*((unsigned long *)GPIO_FUNC_IN_SEL_CFG_REG + 0x4 * Y)) |= X | 0x80;
        input_gpio(X); // Set pad X as input
        (*((unsigned long *)GPIO_FUNC_OUT_SEL_CFG_REG + 0x4 * X)) |= (1 << 10);
        (*((unsigned long *)IO_MUX_GPIO_REG + 0x4 * X)) |= (0x2 << 12) | (1 << 9);
    }
}

void peripheral_input_invert(uint8_t Y){
    unsigned long reg = (*((unsigned long *)GPIO_FUNC_IN_SEL_CFG_REG + 0x4 * Y));
    (reg & 0x40) ? (reg &= ~0x40) : (reg |= 0x40);
}

void gpio_input_pullup(uint8_t X) {
    unsigned long reg = (*((unsigned long *)IO_MUX_GPIO_REG + 0x4 * X));
    reg &= ~(1 << 7);
    reg |= (1 << 8);
}

void gpio_input_pulldown(uint8_t X) {
    unsigned long reg = (*((unsigned long *)IO_MUX_GPIO_REG + 0x4 * X));
    reg &= ~(1 << 8);
    reg |= (1 << 7);
}

void gpio_input_floating(uint8_t X) {
    (*((unsigned long *)IO_MUX_GPIO_REG + 0x4 * X)) &= ~(3 << 7);
}

