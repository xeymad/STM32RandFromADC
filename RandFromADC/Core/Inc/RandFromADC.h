/*
 * RandFromADC.h
 *
 *  Created on: May 3, 2024
 *      Author: Giuseppe Gambardella
 *		Email:	giuseppe.gambardella.gng@gmail.com
 */

#ifndef INC_RANDFROMADC_H_
#define INC_RANDFROMADC_H_

/* Private includes ----------------------------------------------------------*/
#include "main.h"

/* Exported types ------------------------------------------------------------*/


/* Exported constants --------------------------------------------------------*/
#define RANDFROMADC_NUM_OF_RAND_BITS		2
#define RANDFROMADC_RTOS_USED				0

/* Exported macro ------------------------------------------------------------*/
#define RANDFROMADC_MASK_OF_RAND_BITS		(0xFFFFFFFF >> (32 - RANDFROMADC_NUM_OF_RAND_BITS))
#define RANDFROMADC_NUM_OF_MEASURES			(32/RANDFROMADC_NUM_OF_RAND_BITS)

#if (RANDFROMADC_RTOS_USED == 1)
#include "cmsis_os.h"
#define RANDFROMADC_SEM_INIT(x)			(*x = osSemaphoreNew(1, 1, NULL))
#define RANDFROMADC_SEM_SET(x)			osSemaphoreRelease(*x)
#define RANDFROMADC_SEM_GET(x)			osSemaphoreAcquire(*x, osWaitForever)
#else
#include "BareMetalBinSemaphore.h"
#define RANDFROMADC_SEM_INIT(x)			BareMetalBinSemaphore_init(x)
#define RANDFROMADC_SEM_SET(x)			BareMetalBinSemaphore_release(x)
#define RANDFROMADC_SEM_GET(x)			BareMetalBinSemaphore_get(x, HAL_MAX_DELAY)
#endif

/* Exported functions prototypes ---------------------------------------------*/
void 		RandFromADC_init();
int			RandFromADC_getRandom(uint32_t* random);

#endif /* INC_RANDFROMADC_H_ */
