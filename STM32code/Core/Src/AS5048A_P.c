/*
 * AS5048A_P.c
 *
 *  Created on: Nov 12, 2024
 *      Author: win10
 */

#include "AS5048A_P.h"

uint16_t Hall_Sensor_Read_Magnitude(SPI_HandleTypeDef* SPI,GPIO_TypeDef* SS_PORT, uint16_t SS_PIN)
{
	uint16_t tmp;
	tmp = magnitude_adress;
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(SPI, &tmp, &tmp, 1, 100);
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_SET);
	tmp = NOP_command;
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(SPI, &tmp, &tmp, 1, 100);
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_SET);
	tmp = NOP_command;
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(SPI, &tmp, &tmp, 1, 100);
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_SET);
	return tmp;
}



uint16_t Hall_Sensor_Read_Angle(SPI_HandleTypeDef* SPI,GPIO_TypeDef* SS_PORT, uint16_t SS_PIN)
{
	uint16_t tmp;
	tmp = angle_adress;
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(SPI, &tmp, &tmp, 1, 100);
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_SET);
	tmp = NOP_command;
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(SPI, &tmp, &tmp, 1, 100);
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_SET);
	tmp = NOP_command;
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(SPI, &tmp, &tmp, 1, 100);
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_SET);
	return tmp;
}

uint16_t Clear_ERROR_Flag(SPI_HandleTypeDef* SPI,GPIO_TypeDef* SS_PORT, uint16_t SS_PIN)
{
	uint16_t tmp;
	tmp = Clear_ERROR_Flag_Command;
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(SPI, &tmp, &tmp, 1, 100);
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_SET);
	tmp = NOP_command;
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(SPI, &tmp, &tmp, 1, 100);
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_SET);
	tmp = NOP_command;
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(SPI, &tmp, &tmp, 1, 100);
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_SET);
	return tmp;
}

uint16_t Parity_ERROR(SPI_HandleTypeDef* SPI,GPIO_TypeDef* SS_PORT, uint16_t SS_PIN)
{
	uint16_t tmp;
	tmp = Parity_ERROR_Command;
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(SPI, &tmp, &tmp, 1, 100);
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_SET);
	tmp = NOP_command;
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(SPI, &tmp, &tmp, 1, 100);
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_SET);
	tmp = NOP_command;
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(SPI, &tmp, &tmp, 1, 100);
	HAL_GPIO_WritePin(SS_PORT, SS_PIN, GPIO_PIN_SET);
	return tmp;
}




/*


#define Hall_SS0_PORT GPIOA
#define Hall_SS0_PIN GPIO_PIN_8
#define Hall_SS1_PORT GPIOB
#define Hall_SS1_PIN GPIO_PIN_10
#define Hall_SS2_PORT GPIOB
#define Hall_SS2_PIN GPIO_PIN_5
#define Hall_SPI hspi1





*/
