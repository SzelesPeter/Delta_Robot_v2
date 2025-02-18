/*
 * UART.c
 *
 *  Created on: Feb 18, 2025
 *      Author: win10
 */


#include "UART.h"

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
