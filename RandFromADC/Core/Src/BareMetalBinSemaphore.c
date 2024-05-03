/*
 * BareMetalBinSemaphore.c
 *
 *  Created on: May 3, 2024
 *      Author: Giuseppe Gambardella
 *		Email:	giuseppe.gambardella.gng@gmail.com
 */


/* Includes ------------------------------------------------------------------*/
#include "BareMetalBinSemaphore.h"
#include "main.h"
/* Private includes ----------------------------------------------------------*/


/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/


/* Private code --------------------------------------------------------------*/
void BareMetalBinSemaphore_init(BareMetalBinSem_t *binarySem)
{
	*binarySem = 0;
}

uint32_t BareMetalBinSemaphore_release(BareMetalBinSem_t *binarySem)
{
	if(*binarySem != 0)
	{
		if(*binarySem != 1)
		{
			return BAREMETALBINSEM_ERR;
		}
		else
		{
			return BAREMETALBINSEM_OK;
		}
	} else {/*do nothing*/}
	ATOMIC_SET_BIT(*binarySem, 1);
	return BAREMETALBINSEM_OK;
}

uint32_t BareMetalBinSemaphore_get(BareMetalBinSem_t *binarySem, uint32_t timeout)
{
	uint32_t timePassed = 0;
	while(*binarySem != 1)
	{
		HAL_Delay(1);
		timePassed+=1;
		if(timeout != HAL_MAX_DELAY && timePassed == timeout)
		{
			return BAREMETALBINSEM_TIMEOUT;
		}
	}
	ATOMIC_CLEAR_BIT(*binarySem, 1);
	return BAREMETALBINSEM_OK;
}

