/*
 * Delta_Robot_P.c
 *
 *  Created on: Nov 12, 2024
 *      Author: win10
 */

#include "Delta_Robot_P.h"


void Relay_0_Set(void)
{
	HAL_GPIO_WritePin(RELAY0_PORT, RELAY0_PIN, GPIO_PIN_SET);
}

void Relay_0_Reset(void)
{
	HAL_GPIO_WritePin(RELAY0_PORT, RELAY0_PIN, GPIO_PIN_RESET);
}

void Relay_1_Set(void)
{
	HAL_GPIO_WritePin(RELAY1_PORT, RELAY1_PIN, GPIO_PIN_SET);
}

void Relay_1_Reset(void)
{
	HAL_GPIO_WritePin(RELAY1_PORT, RELAY1_PIN, GPIO_PIN_RESET);
}