/*
 * RandFromADC.c
 *
 *  Created on: May 3, 2024
 *      Author: Giuseppe Gambardella
 *		Email:	giuseppe.gambardella.gng@gmail.com
 */


/* Includes ------------------------------------------------------------------*/
#include "RandFromADC.h"

/* Private includes ----------------------------------------------------------*/
#include "adc.h"

/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/
#if (RANDFROMADC_RTOS_USED == 1)
	static osSemaphoreId_t adcCpltSem;
#else
	static BareMetalBinSem_t adcCpltSem;
#endif

/* Private function prototypes -----------------------------------------------*/
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc);

static void RandFromADC_fillRandomVar(uint16_t* array, uint32_t arraySize, uint32_t* out)
{
	if(out == NULL || array == NULL || arraySize != RANDFROMADC_NUM_OF_MEASURES)
	{
		return;
	}
	*out = 0;
	uint32_t shift = 0;
	for(int i = 0; i < RANDFROMADC_NUM_OF_MEASURES; i++)
	{
		array[i] &= RANDFROMADC_MASK_OF_RAND_BITS;
		*out += (array[i] << (shift));
		shift += RANDFROMADC_NUM_OF_RAND_BITS;
	}
	return;
}

/* Private code --------------------------------------------------------------*/
void RandFromADC_init()
{
	RANDFROMADC_SEM_INIT(&adcCpltSem);
	return;
}

int RandFromADC_getRandom(uint32_t* random)
{
	uint16_t array[RANDFROMADC_NUM_OF_MEASURES];
	if(HAL_ADC_Start_DMA(&hadc1, (uint32_t*) array, RANDFROMADC_NUM_OF_MEASURES) != HAL_OK)
	{
		return 1;
	}
	RANDFROMADC_SEM_GET(&adcCpltSem);
	RandFromADC_fillRandomVar(array, RANDFROMADC_NUM_OF_MEASURES, random);
	return 0;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	RANDFROMADC_SEM_SET(&adcCpltSem);
}
