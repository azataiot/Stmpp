/*
 * Serial.cpp
 *
 *  Created on: Mar 15, 2022
 *      Author: Yaakov Azat
 */

#include <Serial.hpp>
#include <Stmpp.hpp>

namespace azt {
// base
// a constructor should not have a return type.
	Serial::Serial() {
	}

	status Serial::begin(UART_HandleTypeDef* huart){
		uart_handler = huart;
		return ok;
	}

	status Serial::print(std::string message){
		HAL_UART_Transmit(uart_handler, (uint8_t *)message.c_str(), message.size(), HAL_MAX_DELAY);
		return ok;
	}

	status Serial::println(std::string message){
		message += '\n';
		print(message);
		return ok;
	}

	status Serial::write(byte *data, uint16_t length){
		HAL_UART_Transmit(uart_handler, (uint8_t *)data, length, HAL_MAX_DELAY);
		return ok;
	}

	status Serial::read(byte *data, uint16_t length){
		HAL_UART_Receive(uart_handler, (uint8_t *)data, length, HAL_MAX_DELAY);
		return ok;
	}

}

