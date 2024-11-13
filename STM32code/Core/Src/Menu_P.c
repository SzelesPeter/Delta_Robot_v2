/*
 * Menu_P.c
 *
 *  Created on: Nov 13, 2024
 *      Author: win10
 */

#include "Menu_P.h"

uint8_t *Menu_main[] = {
		"Set f MAX",
		"Set f MIN",
		"Set a",
		"Set theta1, theta2, theta3"
};

uint8_t Banner[] = {"\r\n         :::::::::   ::::::::::  :::     :::::::::::  :::  \r\n        :+:    :+:  :+:         :+:         :+:    :+: :+: \r\n       +:+    +:+  +:+         +:+         +:+   +:+   +:+ \r\n      +#+    +:+  +#++:++#    +#+         +#+  +#++:++#++: \r\n     +#+    +#+  +#+         +#+         +#+  +#+     +#+  \r\n    #+#    #+#  #+#         #+#         #+#  #+#     #+#   \r\n   #########   ##########  ##########  ###  ###     ###    \r\n\r\n"};


void Menu_UART_Start(UART_HandleTypeDef *huart)
{
	for(uint32_t j=0;Banner[j];j++) HAL_UART_Transmit(huart, (Banner+j), 1, 1000);
	Menu_UART_Out(huart, Menu_main);

}

void Menu_UART_Out(UART_HandleTypeDef *huart, uint8_t** p)
{
	uint8_t tx_buff[40];
	for(uint8_t i=0;i<sizeof(Menu_main);i++)
	{
		sprintf(tx_buff, "   %d.  %s\r\n", i, p[i]);
		for(uint8_t j=0;tx_buff[j];j++) HAL_UART_Transmit(huart, (tx_buff+j), 1, 1000);
	}
}
