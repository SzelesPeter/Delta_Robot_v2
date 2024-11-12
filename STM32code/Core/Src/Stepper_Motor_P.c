/*
 * Stepper_Motor_P.c
 *
 *  Created on: Nov 10, 2024
 *      Author: win10
 */


#include "Stepper_Motor_P.h"

uint32_t M_direction[3] =  {1,1,1};
uint32_t M_f[3] =  {100,0,0};
int32_t M_poz[3] = {0,0,0};

uint32_t M_move_f[3] ={0,0,0};
uint16_t Period_ramp[3][40000];
int32_t M_move_l[3] =  {0,0,0};
uint32_t M_move_poz[3] = {0,0,0};

void Frequency_Out(TIM_HandleTypeDef* htim,uint32_t f)
{
	HAL_TIM_Base_Stop_IT(htim);
	__HAL_TIM_SET_AUTORELOAD(htim, (Timer_F/((Devider+1)*f*2)-1) );
	//__HAL_TIM_SET_COUNTER(htim,0);
	HAL_TIM_Base_Start_IT(htim);
}

uint32_t Frequency_To_Period(uint32_t f)
{
	return (Timer_F/((Devider+1)*f*2)-1);
}

void Period_Out(TIM_HandleTypeDef* htim,uint32_t T)
{
	HAL_TIM_Base_Stop_IT(htim);
	__HAL_TIM_SET_AUTORELOAD(htim, T );
	//__HAL_TIM_SET_COUNTER(htim,0);
	HAL_TIM_Base_Start_IT(htim);
}

void Mototr_Poz_Inc(uint32_t M)
{
	if(M_direction[M])
		M_poz[M]++;
	else
		M_poz[M]--;
}

void Ramp(uint32_t M)
{
	uint32_t tmp;
	for(uint32_t i = 0; i<M_move_l[M];i++)
	{
		if(i<M_move_l[M]/2)
		{
			tmp = f_MIN+(double)a_MAX*(double)sqrt((double)(2*i)/a_MAX);
			if(tmp > f_MAX)
				tmp = f_MAX;
		}
		else
		{
			tmp = f_MIN+(double)a_MAX*(double)sqrt((double)(2*(M_move_l[M]-i))/a_MAX);
			if(tmp > f_MAX)
				tmp = f_MAX;
		}

		Period_ramp[M][i] = Frequency_To_Period(tmp);
	}
}

void Ramp_Out(TIM_HandleTypeDef* htim,uint32_t Channel, uint32_t M)
{
	if(M_move_poz[M]>=M_move_l[M])
	{
		HAL_TIM_OC_Stop_IT(htim,Channel);
	}
	else
	{
		Period_Out(htim,Period_ramp[M][M_move_poz[M]]);

		M_move_poz[M]++;
	}
}

void move (int32_t theta0_target,int32_t theta1_target,int32_t theta2_target,TIM_HandleTypeDef* tim1,uint32_t Channel1, TIM_HandleTypeDef* tim2,uint32_t Channel2, TIM_HandleTypeDef* tim3,uint32_t Channel3)
{
	M_move_l[0] = theta0_target - M_poz[0];
	M_move_l[1] = theta1_target - M_poz[1];
	M_move_l[2] = theta2_target - M_poz[2];

	if(M_move_l[0]<0)
	{
		M_move_l[0] = M_move_l[0]*(-1);
		M_direction[0] = 0;
		HAL_GPIO_WritePin(M0_DIR_PORT, M0_DIR_PIN, GPIO_PIN_RESET);
	}
	else
	{
		M_direction[0] = 1;
		HAL_GPIO_WritePin(M0_DIR_PORT, M0_DIR_PIN, GPIO_PIN_SET);
	}

	if(M_move_l[1]<0)
	{
		M_move_l[1] = M_move_l[1]*(-1);
		M_direction[1] = 0;
		HAL_GPIO_WritePin(M1_DIR_PORT, M1_DIR_PIN, GPIO_PIN_RESET);
		}
	else
	{
		M_direction[1] = 1;
		HAL_GPIO_WritePin(M1_DIR_PORT, M1_DIR_PIN, GPIO_PIN_SET);
	}

	if(M_move_l[2]<0)
	{
		M_move_l[2] = M_move_l[2]*(-1);
		M_direction[2] = 0;
		HAL_GPIO_WritePin(M2_DIR_PORT, M2_DIR_PIN, GPIO_PIN_RESET);
	}
	else
	{
		M_direction[2] = 1;
		HAL_GPIO_WritePin(M2_DIR_PORT, M2_DIR_PIN, GPIO_PIN_SET);
	}

	Ramp(0);
	Ramp(1);
	Ramp(2);

	M_move_poz[0] =0;
	M_move_poz[1] =0;
	M_move_poz[2] = 0;

	__HAL_TIM_SET_COUNTER(tim1,0);
	__HAL_TIM_SET_COUNTER(tim2,0);
	__HAL_TIM_SET_COUNTER(tim3,0);

	HAL_TIM_OC_Start_IT(tim1,Channel1);
	HAL_TIM_OC_Start_IT(tim2,Channel2);
	HAL_TIM_OC_Start_IT(tim3,Channel3);

	while(M_move_l[0] >  M_move_poz[0] || M_move_l[1] >  M_move_poz[1] || M_move_l[2] >  M_move_poz[2])
	{

	}
}

