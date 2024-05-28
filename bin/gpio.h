#ifndef __GPIO__
#define __GPIO__

void outputGPIO(unsigned int n);
void inputGPIO(unsigned int n);

void setHighGPIO(unsigned int n);
void setLowGPIO(unsigned int n);

unsigned int readGPIO(unsigned int n);


#endif