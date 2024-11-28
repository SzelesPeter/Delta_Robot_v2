/*
 * Inverz_Kinematika_P.h
 *
 *  Created on: Nov 12, 2024
 *      Author: win10
 */

#include <math.h>
#include "Stepper_Motor_P.h"
// [mm]
#define effektor_offset 35
#define motor_offset 40
#define motor_height 410
#define upper_arm_lenght 143
#define also_arm_lenght 330

void  Move_to_XYZ(double X_target, double Y_target, double Z_target,TIM_HandleTypeDef* tim1,uint32_t Channel1, TIM_HandleTypeDef* tim2,uint32_t Channel2, TIM_HandleTypeDef* tim3,uint32_t Channel3);
void  Zero_XYZ(double X_target, double Y_target, double Z_target);

#ifndef INC_INVERZ_KINEMATIKA_P_H_
#define INC_INVERZ_KINEMATIKA_P_H_



#endif /* INC_INVERZ_KINEMATIKA_P_H_ */
