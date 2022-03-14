/*
 * uart.cpp
 *
 *  Created on: Mar 13, 2022
 *      Author: Azat
 */


#include "uart.hpp"
#include <string>

namespace azt {
	/**
	 * sends message (std::string) to the UART.
	 */
	HAL_StatusTypeDef uart_tx(UART_HandleTypeDef *huart, std::string msg){
		HAL_UART_Transmit(&*huart, (uint8_t *)msg.c_str(), msg.size(), HAL_MAX_DELAY);
		return HAL_OK;
	}
}

