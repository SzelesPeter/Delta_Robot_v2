/*
 * Delta_Robot_P.h
 *
 *  Created on: Nov 12, 2024
 *      Author: win10
 */
#include "stm32h5xx_hal.h"

#ifndef INC_DELTA_ROBOT_P_H_
#define INC_DELTA_ROBOT_P_H_

#endif /* INC_DELTA_ROBOT_P_H_ */

#define RELAY0_PORT GPIOC
#define RELAY0_PIN GPIO_PIN_4
#define RELAY1_PORT GPIOB
#define RELAY1_PIN GPIO_PIN_8

void Relay_0_Set(void);
void Relay_0_Reset(void);
void Relay_1_Set(void);
void Relay_1_Reset(void);
