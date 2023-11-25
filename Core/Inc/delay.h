/*
 * delay.h
 *
 *  Created on: Sep 25, 2023
 *      Author: R D Indu Priya
 */

#ifndef INC_DELAY_H_
#define INC_DELAY_H_

#include <stdint.h>
uint64_t millis(void);
void systick_init_ms(uint32_t freq);
void delay (uint16_t us);


#endif /* INC_DELAY_H_ */
