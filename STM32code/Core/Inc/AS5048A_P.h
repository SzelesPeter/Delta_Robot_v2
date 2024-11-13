/*
 * AS5048A_P.h
 *
 *  Created on: Nov 12, 2024
 *      Author: win10
 */

#include "stm32h5xx_hal.h"

#define Hall_SS0_PORT GPIOA
#define Hall_SS0_PIN GPIO_PIN_8
#define Hall_SS1_PORT GPIOB
#define Hall_SS1_PIN GPIO_PIN_10
#define Hall_SS2_PORT GPIOB
#define Hall_SS2_PIN GPIO_PIN_5
#define Hall_SPI hspi1

//AS5048A commands
#define angle_adress 0xFFFF;
#define magnitude_adress 0x7FFE;
#define NOP_command 0x0000;
#define Clear_ERROR_Flag_Command 0x4001;
#define Parity_ERROR_Command 0x7FFF;


uint16_t Hall_Sensor_Read_Magnitude(SPI_HandleTypeDef* SPI,GPIO_TypeDef* SS_PORT, uint16_t SS_PIN);
uint16_t Hall_Sensor_Read_Angle(SPI_HandleTypeDef* SPI,GPIO_TypeDef* SS_PORT, uint16_t SS_PIN);
uint16_t Clear_ERROR_Flag(SPI_HandleTypeDef* SPI,GPIO_TypeDef* SS_PORT, uint16_t SS_PIN);
uint16_t Parity_ERROR(SPI_HandleTypeDef* SPI,GPIO_TypeDef* SS_PORT, uint16_t SS_PIN);

#ifndef INC_AS5048A_P_H_
#define INC_AS5048A_P_H_

#endif /* INC_AS5048A_P_H_ */
