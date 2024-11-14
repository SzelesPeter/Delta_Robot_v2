/*
 * Menu_P.c
 *
 *  Created on: Nov 13, 2024
 *      Author: win10
 */

#include "Menu_P.h"


void (*Menu_State)(UART_HandleTypeDef *huart) = Menu_UART_Main;

void Menu_UART_Start(UART_HandleTypeDef *huart)
{
	uint8_t Banner[] = {"\r\n         :::::::::   ::::::::::  :::     :::::::::::  :::  \r\n        :+:    :+:  :+:         :+:         :+:    :+: :+: \r\n       +:+    +:+  +:+         +:+         +:+   +:+   +:+ \r\n      +#+    +:+  +#++:++#    +#+         +#+  +#++:++#++: \r\n     +#+    +#+  +#+         +#+         +#+  +#+     +#+  \r\n    #+#    #+#  #+#         #+#         #+#  #+#     #+#   \r\n   #########   ##########  ##########  ###  ###     ###    \r\n\r\n"};
	for(uint32_t j=0;Banner[j];j++) HAL_UART_Transmit(huart, (Banner+j), 1, 1000);
	Menu_UART_Update(huart);
}

void Menu_UART_Update(UART_HandleTypeDef *huart)
{
	(*Menu_State)(huart);
}
//----------------------------------------------------------Menu_UART_Main------------------------------------------------------------------------
void Menu_UART_Main(UART_HandleTypeDef *huart)
{
	uint8_t *Menu_Main[] = {
			"Set f MAX",
			"Set f MIN",
			"Set a",
			"Set theta1, theta2, theta3",
			"Set/Reset Relay",
			"Read sensors"
	};
	Menu_UART_Out(huart, Menu_Main, 6);

	uint8_t rx_buff[2] = {0};
	while(1)
	{
		if(HAL_UART_Receive(huart, rx_buff, 1, 1000)==HAL_OK) //if transfer is successful
		{
			switch (rx_buff[0])
			{
				case '0':
					break;
				case '1':
					break;
				case '2':
					break;
				case '3':
					break;
				case '4':
					Menu_State = Menu_UART_Relay;
					break;
				case '5':
					Menu_State = Menu_UART_Sensors;
					break;
			}
			break;
		} else {
			__NOP();
		}
	}
}
//--------------------------------------------------------------------------------Menu_UART_Sensors-----------------------------------------------------------
void Menu_UART_Sensors(UART_HandleTypeDef *huart)
{

	uint8_t *Menu_Sensor[] = {
			"HALL 0 Angle",
			"HALL 1 Amplitude",
			"HALL 1 Angle",
			"HALL 1 Amplitude",
			"HALL 2 Angle",
			"HALL 2 Amplitude",
			"Exit"
	};
	Menu_UART_Out(huart, Menu_Sensor, 7);

	uint8_t rx_buff[2] = {0};
		while(1)
		{
			if(HAL_UART_Receive(huart, rx_buff, 1, 1000)==HAL_OK) //if transfer is successful
			{
				switch (rx_buff[0])
				{
					case '0':
						break;
					case '1':
						break;
					case '2':
						break;
					case '3':
						break;
					case '4':
						break;
					case '5':
						break;
					case '6':
						Menu_State = Menu_UART_Main;
						break;
				}
				break;
			} else {
				__NOP();
			}
		}
}

//--------------------------------------------------------------------------------Menu_UART_Relay-----------------------------------------------------------
void Menu_UART_Relay(UART_HandleTypeDef *huart)
{

	uint8_t *Menu_Relay[] = {
			"Set Relay 0",
			"Reset Relay 0",
			"Set Relay 1",
			"Reset Relay 1",
			"Exit"
	};
	Menu_UART_Out(huart, Menu_Relay, 5);

	uint8_t rx_buff[2] = {0};
		while(1)
		{
			if(HAL_UART_Receive(huart, rx_buff, 1, 1000)==HAL_OK) //if transfer is successful
			{
				switch (rx_buff[0])
				{
					case '0':
						Relay_0_Set();
						break;
					case '1':
						Relay_0_Reset();
						break;
					case '2':
						Relay_1_Set();
						break;
					case '3':
						Relay_1_Reset();
						break;
					case '4':
						Menu_State = Menu_UART_Main;
						break;
				}
				break;
			} else {
				__NOP();
			}
		}
}

void Menu_UART_Out(UART_HandleTypeDef *huart, uint8_t** p, uint32_t size)
{
	uint8_t tx_buff[40]={"\r\n"};
	HAL_UART_Transmit(huart, tx_buff, 4, 1000);
	for(uint8_t i=0;i<size;i++)
	{
		sprintf(tx_buff, "   %d.  %s\r\n", i, p[i]);
		for(uint8_t j=0;tx_buff[j];j++) HAL_UART_Transmit(huart, (tx_buff+j), 1, 1000);
	}
}

