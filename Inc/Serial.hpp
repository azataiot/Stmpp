/*
 * Serial.hpp
 *
 *  Created on: Mar 15, 2022
 *      Author: Yaakov Azat
 */

#ifndef SERIAL_HPP_
#define SERIAL_HPP_

#include "main.h"
#include "Stmpp.hpp"

namespace azt {

class Serial {
public:
	Serial(); // base type.

	status begin(UART_HandleTypeDef *huart);

	status print(std::string message);

	status println(std::string message);

	// HAL_UART_Transmit(&hlpuart1, pData, Size, Timeout)
	status write(byte *data, uint16_t length);

	// HAL_UART_Receive(&hlpuart1, pData, Size, Timeout)
	status read(byte *data, uint16_t length);

private:
	UART_HandleTypeDef *uart_handler;
};

}

#endif /* SERIAL_HPP_ */
