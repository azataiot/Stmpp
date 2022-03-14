/*
 * uart.hpp
 *
 *  Created on: Mar 13, 2022
 *      Author: Azat
 */

#ifndef INC_AZT_UART_HPP_
#define INC_AZT_UART_HPP_

#include "main.h"
#include <string>


namespace azt {

	HAL_StatusTypeDef uart_tx(UART_HandleTypeDef *huart, std::string msg);
}


#endif /* INC_AZT_UART_HPP_ */
