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
	uint8_t tx_buff[40]={"\r\n"};
	uint32_t poz0;
	uint32_t poz1;
	uint32_t poz2;

	uint8_t *Menu_Main[] = {
			"Set f MAX",
			"Set f MIN",
			"Set a",
			"Move to motor poz",
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
					sprintf(tx_buff, "\r\nf MAX was: %d\r\n",Get_f_MAX());
					UART_Out(huart, tx_buff);
					strcpy(tx_buff, "Input f MAX\r\n");
					UART_Out(huart, tx_buff);
					UART_In(huart, tx_buff, 20);
					Set_f_MAX(atoi(tx_buff));
					sprintf(tx_buff, "New f MAX is: %d\r\n",Get_f_MAX());
					UART_Out(huart, tx_buff);
					break;
				case '1':
					sprintf(tx_buff, "\r\nf MIN was: %d\r\n",Get_f_MIN());
					UART_Out(huart, tx_buff);
					strcpy(tx_buff, "Input f MIN\r\n");
					UART_Out(huart, tx_buff);
					UART_In(huart, tx_buff, 20);
					Set_f_MIN(atoi(tx_buff));
					sprintf(tx_buff, "New f MIN is: %d\r\n",Get_f_MIN());
					UART_Out(huart, tx_buff);
					break;
				case '2':
					sprintf(tx_buff, "\r\na MAX was: %d\r\n",Get_a_MAX());
					UART_Out(huart, tx_buff);
					strcpy(tx_buff, "Input a MAX\r\n");
					UART_Out(huart, tx_buff);
					UART_In(huart, tx_buff, 20);
					Set_a_MAX(atoi(tx_buff));
					sprintf(tx_buff, "New a MAX is: %d\r\n",Get_a_MAX());
					UART_Out(huart, tx_buff);
					break;
				case '3':
					sprintf(tx_buff, "\r\nMotor 0 poz was: %d\r\n",M_Poz_0());
					UART_Out(huart, tx_buff);
					strcpy(tx_buff, "Input motor 0 poz\r\n");
					UART_Out(huart, tx_buff);
					UART_In(huart, tx_buff, 20);
					poz0 = atoi(tx_buff);
					sprintf(tx_buff, "New motor 0 poz will be: %d\r\n",poz0);
					UART_Out(huart, tx_buff);

					sprintf(tx_buff, "\r\nMotor 1 poz was: %d\r\n",M_Poz_1());
					UART_Out(huart, tx_buff);
					strcpy(tx_buff, "Input motor 1 poz\r\n");
					UART_Out(huart, tx_buff);
					UART_In(huart, tx_buff, 20);
					poz1 = atoi(tx_buff);
					sprintf(tx_buff, "New motor 1 poz will be: %d\r\n",poz1);
					UART_Out(huart, tx_buff);

					sprintf(tx_buff, "\r\nMotor 2 poz was: %d\r\n",M_Poz_2());
					UART_Out(huart, tx_buff);
					strcpy(tx_buff, "Input motor 2 poz\r\n");
					UART_Out(huart, tx_buff);
					UART_In(huart, tx_buff, 20);
					poz2 = atoi(tx_buff);
					sprintf(tx_buff, "New motor 2 poz will be: %d\r\n",poz2);
					UART_Out(huart, tx_buff);

					move(poz0,poz1,poz2,M0_TIM, M0_CHANNEL, M1_TIM, M1_CHANNEL, M2_TIM, M2_CHANNEL);

					sprintf(tx_buff, "\r\nNew motor 0 poz: %d\r\n",M_Poz_0());
					UART_Out(huart, tx_buff);
					sprintf(tx_buff, "New motor 1 poz: %d\r\n",M_Poz_1());
					UART_Out(huart, tx_buff);
					sprintf(tx_buff, "New motor 2 poz: %d\r\n",M_Poz_2());
					UART_Out(huart, tx_buff);
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
	uint8_t tx_buff[40]={"\r\n"};

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
						sprintf(tx_buff, "\r\nHALL 0 angle: %f \r\n",360*(double)((double)(0x3FFF&Hall_Sensor_Read_Angle(&hspi1, Hall_SS0_PORT, Hall_SS0_PIN))/0x3FFF));
						UART_Out(huart, tx_buff);
						break;
					case '1':
						sprintf(tx_buff, "\r\nHALL 0 amplitude: %d \r\n", 0x3FFF&Hall_Sensor_Read_Magnitude(Hall_SPI, Hall_SS0_PORT, Hall_SS0_PIN));
						UART_Out(huart, tx_buff);
						break;
					case '2':
						sprintf(tx_buff, "\r\nHALL 1 angle: %f \r\n",360*(double)((double)(0x3FFF&Hall_Sensor_Read_Angle(Hall_SPI, Hall_SS1_PORT, Hall_SS1_PIN))/0x3FFF));
						UART_Out(huart, tx_buff);
						break;
					case '3':
						sprintf(tx_buff, "\r\nHALL 1 amplitude: %d \r\n", 0x3FFF&Hall_Sensor_Read_Magnitude(Hall_SPI, Hall_SS1_PORT, Hall_SS1_PIN));
						UART_Out(huart, tx_buff);
						break;
					case '4':
						sprintf(tx_buff, "\r\nHALL 2 angle: %f \r\n",360*(double)((double)(0x3FFF&Hall_Sensor_Read_Angle(&hspi1, Hall_SS2_PORT, Hall_SS2_PIN))/0x3FFF));
						UART_Out(huart, tx_buff);
						break;
					case '5':
						sprintf(tx_buff, "\r\nHALL 2 amplitude: %d \r\n", 0x3FFF&Hall_Sensor_Read_Magnitude(Hall_SPI, Hall_SS2_PORT, Hall_SS2_PIN));
						UART_Out(huart, tx_buff);
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
	uint8_t tx_buff[40]={"\r\n"};

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
						if(!Relay_0_Read()) strcpy(tx_buff, "\r\nRelay 0 was set\r\n");
						else strcpy(tx_buff, "\r\nRelay 0 was already set\r\n");
						UART_Out(huart, tx_buff);
						Relay_0_Set();
						break;
					case '1':
						if(!Relay_0_Read()) strcpy(tx_buff, "\r\nRelay 0 was already reset\r\n");
						else strcpy(tx_buff, "\r\nRelay 0 was reset\r\n");
						UART_Out(huart, tx_buff);
						Relay_0_Reset();
						break;
					case '2':
						if(!Relay_0_Read()) strcpy(tx_buff, "\r\nRelay 1 was set\r\n");
						else strcpy(tx_buff, "\r\nRelay 1 was already set\r\n");
						UART_Out(huart, tx_buff);
						Relay_1_Set();
						break;
					case '3':
						if(!Relay_0_Read()) strcpy(tx_buff, "\r\nRelay 1 was already reset\r\n");
						else strcpy(tx_buff, "\r\nRelay 1 was reset\r\n");
						UART_Out(huart, tx_buff);
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
	HAL_UART_Transmit(huart, tx_buff, 4, 1000);
	for(uint8_t i=0;i<size;i++)
	{
		sprintf(tx_buff, "   %d.  %s\r\n", i, p[i]);
		UART_Out(huart, tx_buff);
	}
}

void UART_Out(UART_HandleTypeDef *huart, uint8_t* p)
{
	for(uint8_t j=0;p[j];j++) HAL_UART_Transmit(huart, (p+j), 1, 1000);
}

void UART_In(UART_HandleTypeDef *huart, uint8_t* p, uint8_t len)
{
	uint8_t rx_buff =0;
	uint8_t tx_buff[10]={"\r\n"};
	uint8_t i=0;
	while(i<len)
	{
		while(1)
		{
			if(HAL_UART_Receive(huart, &rx_buff, 1, 1000)==HAL_OK) //if transfer is successful
			{
				break;
			} else {
				__NOP();
			}
		}
		if(rx_buff=='\r') break;
		*(p+i) = rx_buff;
		HAL_UART_Transmit(huart, &rx_buff, 1, 1000);
		i++;
	}
	*(p+i) = 0;
	HAL_UART_Transmit(huart, tx_buff, 4, 1000);
}

