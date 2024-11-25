/*
 * Stepper_Motor_P.h
 *
 *  Created on: Nov 10, 2024
 *      Author: win10
 */

#include "stm32h5xx_hal.h"
#include <math.h>

#define Timer_F 125000000
#define Devider 249

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim5;

#define M0_TIM &htim5
#define M0_CHANNEL TIM_CHANNEL_1
#define M1_TIM &htim2
#define M1_CHANNEL TIM_CHANNEL_2
#define M2_TIM &htim3
#define M2_CHANNEL TIM_CHANNEL_4

#define M0_PLS_PORT GPIOA
#define M0_PLS_PIN GPIO_PIN_0
#define M1_PLS_PORT GPIOA
#define M1_PLS_PIN GPIO_PIN_1
#define M2_PLS_PORT GPIOB
#define M2_PLS_PIN GPIO_PIN_1

#define M0_ENA_PORT GPIOC
#define M0_ENA_PIN GPIO_PIN_13
#define M1_ENA_PORT GPIOC
#define M1_ENA_PIN GPIO_PIN_14
#define M2_ENA_PORT GPIOC
#define M2_ENA_PIN GPIO_PIN_15

#define M0_DIR_PORT GPIOB
#define M0_DIR_PIN GPIO_PIN_0
#define M1_DIR_PORT GPIOC
#define M1_DIR_PIN GPIO_PIN_1
#define M2_DIR_PORT GPIOC
#define M2_DIR_PIN GPIO_PIN_0

void Frequency_Out(TIM_HandleTypeDef* htim,uint32_t f);
uint32_t Frequency_To_Period(uint32_t f);
void Period_Out(TIM_HandleTypeDef* htim,uint32_t T);
void Mototr_Poz_Inc(uint32_t M);
void Ramp(uint32_t M);
void Ramp_Out(TIM_HandleTypeDef* htim,uint32_t Channel, uint32_t M);
void move (int32_t theta0_target,int32_t theta1_target,int32_t theta2_target,TIM_HandleTypeDef* tim1,uint32_t Channel1, TIM_HandleTypeDef* tim2,uint32_t Channel2, TIM_HandleTypeDef* tim3,uint32_t Channel3);
void Set_f_MAX(uint32_t tmp);
void Set_f_MIN(uint32_t tmp);
void Set_a_MAX(uint32_t tmp);
uint32_t Get_f_MAX(void);
uint32_t Get_f_MIN(void);
uint32_t Get_a_MAX(void);
uint32_t M_Poz_0(void);
uint32_t M_Poz_1(void);
uint32_t M_Poz_2(void);
void Set_M_Poz_0(uint32_t);
void Set_M_Poz_1(uint32_t);
void Set_M_Poz_2(uint32_t);


#ifndef INC_STEPPER_MOTOR_P_H_
#define INC_STEPPER_MOTOR_P_H_



#endif /* INC_STEPPER_MOTOR_P_H_ */
