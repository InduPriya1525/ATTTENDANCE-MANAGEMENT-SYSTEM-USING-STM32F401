/*
 * eeprom.c
 *
 *  Created on: Jul 7, 2023
 *      Author: SIRIAB
 */



#include "flash.h"
#include "eeprom.h"



uint16_t e_size=50;

uint32_t start_address=0x08010000;
uint32_t end_add;
//=0x0801FFFF;
void eeprom_init(uint32_t st_add, uint16_t size)
{
	end_add=st_add+(uint32_t)((size*4));
	start_address=st_add;
	e_size=size;


}

uint32_t get_eeprom_size()
{
	return e_size;
}

EEPROMTypedefStatus eeprom_read(uint16_t add, uint32_t *pData )
{

	uint32_t address= ((add)*4)+start_address;

	if(address > end_add) return EEPROM_ERROR;
	else
	{
		flash_read32(address,pData,1);
	}
	return EEPROM_OK;
}

EEPROMTypedefStatus eeprom_write(uint16_t add, uint32_t pData)
{
	/*Variable to hold the read data*/
	uint32_t data;

	/*Get the EEPROM address*/
	uint32_t address= ((add)*4)+start_address;

	/*Check if the address within the limit*/
	if(address > end_add) {return EEPROM_ERROR;}



	/*Check if data is the same*/
	eeprom_read(add,&data);

	/*Same data, don't write new data*/
	if(data==pData)
	{
		return EEPROM_OK;
	}
	/*If it is not the same data, write the new data*/

	flash_unlock();
	flash_write32(address,&pData,1);
	flash_lock();

	/*Return ok*/
	return EEPROM_OK;
}

