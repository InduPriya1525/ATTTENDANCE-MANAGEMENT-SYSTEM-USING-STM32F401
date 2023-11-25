/*
 * eeprom.h
 *
 *  Created on: Sep 25, 2023
 *      Author: R D Indu Priya
 */

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_


typedef enum
{
	EEPROM_OK=0,
	EEPROM_ERROR=1
}EEPROMTypedefStatus;

void eeprom_init(uint32_t st_add, uint16_t size);

uint32_t get_eeprom_size();

EEPROMTypedefStatus eeprom_read(uint16_t add, uint32_t *pData );

EEPROMTypedefStatus eeprom_write(uint16_t add, uint32_t pData);

#endif /* INC_EEPROM_H_ */
