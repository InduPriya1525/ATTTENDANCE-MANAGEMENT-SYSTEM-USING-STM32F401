/*
 * flash.h
 *
 *  Created on: Sep 25, 2023
 *      Author: R D Indu Priya
 */

#ifndef INC_FLASH_H_
#define INC_FLASH_H_


#include "stdint.h"

void flash_unlock(void);
void flash_lock(void);
void flash_read32(uint32_t addrs, uint32_t *rd32, uint32_t len);
void flash_write32(uint32_t addrs, uint32_t *wr32, uint32_t len);

#endif /* INC_FLASH_H_ */
