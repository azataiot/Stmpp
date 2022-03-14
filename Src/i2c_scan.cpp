/*
 * i2c_scan.cpp
 *
 *  Created on: Mar 13, 2022
 *      Author: Azat
 */


#include "i2c_scan.hpp"
#include "uart.hpp"
#include <string>
#include <cstring> // because we want to use the strcpy function.
#include <cstdio> // because we need sprintf
#include <sstream>
// i2c scan
uint8_t var = 0, ret;
std::stringstream s;
std::string s_buff;
uint8_t Buffer[20];
uint8_t Space[] = " - \r\n";
uint8_t StartMSG[] = "Starting I2C Scanning: \r\n";
uint8_t EndMSG[] = "Done! \r\n\r\n";

namespace azt {
	// i2c scan
	HAL_StatusTypeDef I2C_Scan(I2C_HandleTypeDef *hi2c, UART_HandleTypeDef *huart){
		  /*-[ I2C Bus Scanning ]-*/
		for (var = 1; var < 128; ++var) {
			  ret = HAL_I2C_IsDeviceReady(&*hi2c, (uint16_t)(var<<1), 3, 5);
			  if (ret != HAL_OK) {
			} else {
				// apply formatting
				s << std::hex << var;
				azt::uart_tx(huart, s.str());
			}
		}

		return HAL_OK;
			  /*--[ Scanning Done ]--*/
	}
}


