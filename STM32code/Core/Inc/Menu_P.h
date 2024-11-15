/*
 * Menu_P.h
 *
 *  Created on: Nov 13, 2024
 *      Author: win10
 */

#include "stm32h5xx_hal.h"
#include "Delta_Robot_P.h"
#include "Stepper_Motor_P.h"

void Menu_UART_Start(UART_HandleTypeDef *huart);
void Menu_UART_Update(UART_HandleTypeDef *huart);
void Menu_UART_Main(UART_HandleTypeDef *huart);
void Menu_UART_Sensors(UART_HandleTypeDef *huart);
void Menu_UART_Relay(UART_HandleTypeDef *huart);
void Menu_UART_Out(UART_HandleTypeDef *huart, uint8_t** p, uint32_t size);
void UART_Out(UART_HandleTypeDef *huart, uint8_t* p);
void UART_In(UART_HandleTypeDef *huart, uint8_t* p, uint8_t len);

#ifndef INC_MENU_P_H_
#define INC_MENU_P_H_



#endif /* INC_MENU_P_H_ */
