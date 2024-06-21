#include <stdint.h>
#include "gpio_matrix_registers.h"
#include "io_mux_registers.h"

#ifndef __GPIO__
#define __GPIO__

// Basic GPIO configuration

void output_gpio(uint8_t);
void input_gpio(uint8_t);
void set_high_gpio(uint8_t);
void set_low_gpio(uint8_t);
unsigned int read_gpio(uint8_t);

// IO_MUX

/*******************************************************************************
                                    CONCEPT
 * - Each GPIO pad is called a digital pad
 * - The IO_MUX connects digital pads to the GPIO matrix or to direct I/O peripherals
 * - Direct I/O peripherals are used for high speed applications
 * - The GPIO matrix connects all peripherals to the IO_MUX
 * - The GPIO matrix has 34 pads, 162 periph inputs and 176 periph outputs
 * - Each peripheral can select a pad from the matrix to read its inputs from
 * - Each pad can select a peripheral from the matrix to read its inputs from
 * - RTC IO_MUX is used to connect digital pads to low-power functions
 * - Each pad has a function in the IO_MUX which determines its routing

 * - GPIO outputs: 0-­19, 21-­23, 25-­27, 32-33 (28)
 * - GPIO iputs: 0-­19, 21-­23, 25-­27, 32-­39 (34)
 * - Periph outputs: 0-18, 23-37, 61-121, 140-125, 224-228 (176)
 * - Periph inputs: 0-18, 23-36, 39-58, 61-90, 95-124, 140-155, 164-181, 190-195, 198-206 (162)

                                Peripheral Input
 * To Read the value of GPIO X and send it to periph input Y:
 * - In GPIO_FUNC(Y)_IN_SEL_CFG_REG:
 *      - Set GPIO_SIG(Y)_IN_SEL to connect peripheral signal Y to the GPIO matrix as input
 *      - Set GPIO_FUNC(Y)_IN_INV_SEL to invert the input value (optional)
 *      - Set GPIO_FUNC(Y)_IN_SEL value to X to read from digital pad X
 *
 * - Set the pad as input using the input_gpio(X) function
 *
 * - In GPIO_FUNC(X)_OUT_SEL_CFG_REG:
 *      - Set GPIO_FUNC(X)_OEN_SEL to set the digital pad as an input
 *
 * - In IO_MUX_(X)_REG:
 *      - Set MCU_SEL value to 0x2
 *      - Set FUN_IE to enable the input of the pad
 *      - Set FUN_WPD/FUN_WPU to enable pull-down/pull-up resistors (optional)

*******************************************************************************/

/* ### Connect the input of a peripheral to a GPIO pad
 * - Switches the GPIO pad to input mode
 * - Y (Peripheral signal) must be one of these values: 0-18, 23-36, 39-58, 61-90, 95-124, 140-155, 164-181, 190-195, 198-206
 * - X (GPIO number) must be one of these values: 0-­19, 21-­23, 25-­27, 32-33
 */
void peripheral_input_gpio(uint8_t, uint8_t);

/* ### Invert the input value of a peripheral signal
 * - Y (Peripheral signal) must be one of these values: 0-18, 23-36, 39-58, 61-90, 95-124, 140-155, 164-181, 190-195, 198-206
 */
void peripheral_input_invert(uint8_t);

/* ### Connect the output of a peripheral to a GPIO pad
 * - Switches the GPIO pad to output mode
 * - Y (Peripheral signal) must be one of these values: 0-18, 23-37, 61-121, 140-125, 224-228
 * - X (GPIO number) must be one of these values: 0-­19, 21-­23, 25-­27, 32-­39
 */
void peripheral_output_gpio(uint8_t, uint8_t);

#endif