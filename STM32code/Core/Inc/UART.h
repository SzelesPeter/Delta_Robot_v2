/*
 * UART.h
 *
 *  Created on: Feb 18, 2025
 *      Author: win10
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "stm32h5xx_hal.h"

void UART_Out(UART_HandleTypeDef *huart, uint8_t* p);
void UART_In(UART_HandleTypeDef *huart, uint8_t* p, uint8_t len);

#endif /* INC_UART_H_ */
