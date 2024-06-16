#include <stdint.h>
#ifndef __GPIO__
#define __GPIO__

// Basic GPIO configuration

void outputGPIO(uint8_t);
void inputGPIO(uint8_t);
void setHighGPIO(uint8_t);
void setLowGPIO(uint8_t);
unsigned int readGPIO(uint8_t);

// IO_MUX FUNC p60

#endif