/*
 * Inverz_Kinematika_P.c
 *
 *  Created on: Nov 12, 2024
 *      Author: win10
 */

#include "Inverz_Kinematika_P.h"
void  Move_to_XYZ(double X_target, double Y_target, double Z_target,TIM_HandleTypeDef* tim1,uint32_t Channel1, TIM_HandleTypeDef* tim2,uint32_t Channel2, TIM_HandleTypeDef* tim3,uint32_t Channel3)
{
	double also_arm_lenght_XZ;
	double Theta0;
	double Theta1;
	double Theta2;

	double X_target_forgatott;
	double Y_target_forgatott;
	const double PI = 3.141592653589793;
	double alpha;
	double r;

	double d;
	double l;
	double h;
	double Arm_joint_X;
	double Arm_joint_Z;

	//-----------------------------Motor 0
	X_target_forgatott = X_target;
	Y_target_forgatott = Y_target;

	also_arm_lenght_XZ = sqrt(pow(also_arm_lenght, 2) - pow((Y_target_forgatott), 2));
	d = sqrt(pow(motor_offset-(X_target_forgatott+effektor_offset), 2) + pow(motor_height-Z_target, 2));
	l = (pow(upper_arm_lenght, 2) - pow(also_arm_lenght_XZ, 2) + pow(d, 2))/(2*d);
	h = sqrt(pow(upper_arm_lenght, 2) - pow(l, 2));

	Arm_joint_X = l*((X_target_forgatott+effektor_offset) - motor_offset)/d + h*(Z_target - motor_height)/d + motor_offset;
	Arm_joint_Z = l*((Z_target - motor_height)/d + h*(X_target_forgatott+effektor_offset) - motor_offset)/d + motor_height;

	Theta0 =40000 * atan2((Arm_joint_Z-motor_height),(Arm_joint_X-motor_offset)) /(2*PI);

	//-----------------------------Motor 1
	alpha = atan2(Y_target,X_target);
	r = sqrt(pow(X_target,2)+pow(Y_target,2));
	X_target_forgatott = r*sin(alpha + 2*PI/3);
	Y_target_forgatott = r*cos(alpha + 2*PI/3);

	also_arm_lenght_XZ = sqrt(pow(also_arm_lenght, 2) - pow((Y_target_forgatott), 2));
	d = sqrt(pow(motor_offset-(X_target+effektor_offset), 2) + pow(motor_height-Z_target, 2));
	l = (pow(upper_arm_lenght, 2) - pow(also_arm_lenght_XZ, 2) + pow(d, 2))/(2*d);
	h = sqrt(pow(upper_arm_lenght, 2) - pow(l, 2));

	Arm_joint_X = l*((X_target+effektor_offset) - motor_offset)/d + h*(Z_target - motor_height)/d + motor_offset;
	Arm_joint_Z = l*((Z_target - motor_height)/d + h*(X_target+effektor_offset) - motor_offset)/d + motor_height;

	Theta1 =40000 * atan2((Arm_joint_Z-motor_height),(Arm_joint_X-motor_offset)) /(2*PI);

	//-----------------------------Motor 2
		alpha = atan2(Y_target,X_target);
		r = sqrt(pow(X_target,2)+pow(Y_target,2));
		X_target_forgatott = r*sin(alpha - 2*PI/3);
		Y_target_forgatott = r*cos(alpha - 2*PI/3);

		also_arm_lenght_XZ = sqrt(pow(also_arm_lenght, 2) - pow((Y_target_forgatott), 2));
		d = sqrt(pow(motor_offset-(X_target+effektor_offset), 2) + pow(motor_height-Z_target, 2));
		l = (pow(upper_arm_lenght, 2) - pow(also_arm_lenght_XZ, 2) + pow(d, 2))/(2*d);
		h = sqrt(pow(upper_arm_lenght, 2) - pow(l, 2));

		Arm_joint_X = l*((X_target+effektor_offset) - motor_offset)/d + h*(Z_target - motor_height)/d + motor_offset;
		Arm_joint_Z = l*((Z_target - motor_height)/d + h*(X_target+effektor_offset) - motor_offset)/d + motor_height;

		Theta2 =40000 * atan2((Arm_joint_Z-motor_height),(Arm_joint_X-motor_offset)) /(2*PI);

	move (Theta0,Theta1,Theta2,tim1, Channel1, tim2, Channel2, tim3, Channel3);
}

void  Zero_XYZ(double X_target, double Y_target, double Z_target)
{
	double also_arm_lenght_XZ;
	double Theta0;
	double Theta1;
	double Theta2;

	double X_target_forgatott;
	double Y_target_forgatott;
	const double PI = 3.141592653589793;
	double alpha;
	double r;

	double d;
	double l;
	double h;
	double Arm_joint_X;
	double Arm_joint_Z;

	//-----------------------------Motor 0
	X_target_forgatott = X_target;
	Y_target_forgatott = Y_target;

	also_arm_lenght_XZ = sqrt(pow(also_arm_lenght, 2) - pow((Y_target_forgatott), 2));
	d = sqrt(pow(motor_offset-(X_target_forgatott+effektor_offset), 2) + pow(motor_height-Z_target, 2));
	l = (pow(upper_arm_lenght, 2) - pow(also_arm_lenght_XZ, 2) + pow(d, 2))/(2*d);
	h = sqrt(pow(upper_arm_lenght, 2) - pow(l, 2));

	Arm_joint_X = l*((X_target_forgatott+effektor_offset) - motor_offset)/d + h*(Z_target - motor_height)/d + motor_offset;
	Arm_joint_Z = l*((Z_target - motor_height)/d + h*(X_target_forgatott+effektor_offset) - motor_offset)/d + motor_height;

	Theta0 =40000 * atan2((Arm_joint_Z-motor_height),(Arm_joint_X-motor_offset)) /(2*PI);

	//-----------------------------Motor 1
	alpha = atan2(Y_target,X_target);
	r = sqrt(pow(X_target,2)+pow(Y_target,2));
	X_target_forgatott = r*sin(alpha + 2*PI/3);
	Y_target_forgatott = r*cos(alpha + 2*PI/3);

	also_arm_lenght_XZ = sqrt(pow(also_arm_lenght, 2) - pow((Y_target_forgatott), 2));
	d = sqrt(pow(motor_offset-(X_target+effektor_offset), 2) + pow(motor_height-Z_target, 2));
	l = (pow(upper_arm_lenght, 2) - pow(also_arm_lenght_XZ, 2) + pow(d, 2))/(2*d);
	h = sqrt(pow(upper_arm_lenght, 2) - pow(l, 2));

	Arm_joint_X = l*((X_target+effektor_offset) - motor_offset)/d + h*(Z_target - motor_height)/d + motor_offset;
	Arm_joint_Z = l*((Z_target - motor_height)/d + h*(X_target+effektor_offset) - motor_offset)/d + motor_height;

	Theta1 =40000 * atan2((Arm_joint_Z-motor_height),(Arm_joint_X-motor_offset)) /(2*PI);

	//-----------------------------Motor 2
		alpha = atan2(Y_target,X_target);
		r = sqrt(pow(X_target,2)+pow(Y_target,2));
		X_target_forgatott = r*sin(alpha - 2*PI/3);
		Y_target_forgatott = r*cos(alpha - 2*PI/3);

		also_arm_lenght_XZ = sqrt(pow(also_arm_lenght, 2) - pow((Y_target_forgatott), 2));
		d = sqrt(pow(motor_offset-(X_target+effektor_offset), 2) + pow(motor_height-Z_target, 2));
		l = (pow(upper_arm_lenght, 2) - pow(also_arm_lenght_XZ, 2) + pow(d, 2))/(2*d);
		h = sqrt(pow(upper_arm_lenght, 2) - pow(l, 2));

		Arm_joint_X = l*((X_target+effektor_offset) - motor_offset)/d + h*(Z_target - motor_height)/d + motor_offset;
		Arm_joint_Z = l*((Z_target - motor_height)/d + h*(X_target+effektor_offset) - motor_offset)/d + motor_height;

		Theta2 =40000 * atan2((Arm_joint_Z-motor_height),(Arm_joint_X-motor_offset)) /(2*PI);

	Set_M_Poz_0(Theta0);
	Set_M_Poz_1(Theta1);
	Set_M_Poz_2(Theta2);
}
