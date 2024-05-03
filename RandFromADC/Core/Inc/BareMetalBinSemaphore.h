/*
 * BareMetalBinSemaphore.h
 *
 *  Created on: May 3, 2024
 *      Author: Giuseppe Gambardella
 *		Email:	giuseppe.gambardella.gng@gmail.com
 */

#ifndef INC_BAREMETALBINSEMAPHORE_H_
#define INC_BAREMETALBINSEMAPHORE_H_

/* Private includes ----------------------------------------------------------*/
#include <stdint.h>

/* Exported types ------------------------------------------------------------*/
typedef volatile uint32_t BareMetalBinSem_t;

/* Exported constants --------------------------------------------------------*/
#define		BAREMETALBINSEM_OK			0
#define		BAREMETALBINSEM_ERR			1
#define		BAREMETALBINSEM_TIMEOUT		2

/* Exported macro ------------------------------------------------------------*/


/* Exported functions prototypes ---------------------------------------------*/
/**
 * @fn void BareMetalBinSemaphore_init(volatile BareMetalBinSem_t*)
 * @brief Initialize a binary semaphore.
 *
 * @param binarySem 	semaphore to initialize.
 */
void BareMetalBinSemaphore_init(BareMetalBinSem_t *binarySem);

/**
 * @fn uint32_t BareMetalBinSemaphore_release(uint32_t*, uint32_t)
 * @brief Releases a binary semaphore.
 *
 * @param binarySem		semaphore to release.
 * @return
 */
uint32_t BareMetalBinSemaphore_release(BareMetalBinSem_t *binarySem);

/**
 * @fn uint32_t BareMetalBinSemaphore_get(uint32_t*, uint32_t)
 * @brief
 *
 * @param binarySem		semaphore to get.
 * @param timeout		time to wait for get.
 * @return
 */
uint32_t BareMetalBinSemaphore_get(BareMetalBinSem_t *binarySem, BareMetalBinSem_t timeout);

#endif /* INC_BAREMETALBINSEMAPHORE_H_ */
