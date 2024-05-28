#include <stdio.h>
#include "gpio-matrix-registers.h"
#include "io-mux-registers.h"
#include "gpio.h"

/* Sets a GPIO pad as output
 *  @input:
 *      unsigned int n: Pin number (0 to 39)*/
void outputGPIO(unsigned int n) {
    if (n < 32) {
        GPIO_ENABLE_REG |= (1 << n);
    }
    else if (n >= 32 && n < 40) {
        GPIO_ENABLE1_REG |= (1 << (n - 32));
    }
}

/* Sets a GPIO pad as input
 *  @input:
 *      unsigned int n: Pin number (0 to 39)*/
void inputGPIO(unsigned int n) {
    if (n < 32) {
        GPIO_ENABLE_REG &= ~(1 << n);
    }
    else if (n >= 32 && n < 40) {
        GPIO_ENABLE1_REG &= ~(1 << (n - 32));
    }
}

/* Sets an output GPIO pad HIGH
 *  @input:
 *      unsigned int n: Pin number (0 to 39)*/
void setHighGPIO(unsigned int n) {
    if (n < 32)
    {
        GPIO_OUT_REG |= (1 << n);
    }
    else if (n >= 32 && n < 40)
    {
        GPIO_OUT1_REG |= (1 << (n - 32));
    }
}

/* Sets an output GPIO pad LOW
 *  @input:
 *      unsigned int n: Pin number (0 to 39)*/
void setLowGPIO(unsigned int n){
    if (n < 32)
    {
        GPIO_OUT_REG &= ~(1 << n);
    }
    else if (n >= 32 && n < 40)
    {
        GPIO_OUT1_REG &= ~(1 << (n - 32));
    }
}

/* Returns the value of an input GPIO pad
 *  @input:
 *      unsigned int n: Pin number (0 to 39)*/
unsigned int readGPIO(unsigned int n){
    if (n < 32)
    {
        return GPIO_IN_REG & (1 << n);
    }
    else if (n >= 32 && n < 40)
    {
        return GPIO_IN1_REG & (1 << (n - 32));
    }
    else {
        return 0;
    }
}