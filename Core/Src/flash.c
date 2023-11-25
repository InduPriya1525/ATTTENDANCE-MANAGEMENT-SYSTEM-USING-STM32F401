/*
 * flash.c
 *
 *  Created on: Sep 12, 2023
 *      Author: SIRIAB
 */


#include "Flash.h"
#include "stm32f4xx.h"
#include<stdio.h>


void flash_unlock(void)
{

	/*Check if the Lock is active*/
	if(FLASH->CR & FLASH_CR_LOCK)
	{
		FLASH->KEYR = 0x45670123U;
		FLASH->KEYR = 0xCDEF89ABU;
  }
}


void flash_lock(void)
{
	FLASH->CR |= FLASH_CR_LOCK;
}


void flash_read32(uint32_t addrs, uint32_t *rd32, uint32_t len)
{
	//Read data can be accessed straight away
	uint32_t tempAddrs = addrs;

	for(uint32_t i=0; i<len; i++)
	{
		rd32[i] = *(__IO uint32_t*) tempAddrs;
		tempAddrs+=4;
//		printf("Address Where we are writing - %d\n",rd32[i]);
	}
}

void flash_write32(uint32_t addrs, uint32_t *wr32, uint32_t len)
{
	//Write data in 16-bit at a time
	uint32_t tempAddrs = addrs;

	/*Set the parallelism to 32-bit (x32)*/
	FLASH->CR |=FLASH_CR_PSIZE_1;

	for(uint32_t i=0; i<len; i++)
	{
		//Set PG bit
		FLASH->CR |= FLASH_CR_PG;
		*(__IO uint32_t*) tempAddrs = wr32[i];
		tempAddrs+=4;

		//Wait for BSY flag to be idle
		while(((FLASH->SR)&(FLASH_SR_BSY)));

	}
	//Wait for BSY flag to be idle
	while(((FLASH->SR)&(FLASH_SR_BSY)));
	//Disable PG bit
	FLASH->CR &=~ FLASH_CR_PG;
	//printf("data wrote sucessfully\n");

}
