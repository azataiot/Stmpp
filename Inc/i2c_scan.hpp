/*
 * i2c_scan.hpp
 *
 *  Created on: Mar 13, 2022
 *      Author: Azat
 */

#ifndef INC_I2C_SCAN_HPP_
#define INC_I2C_SCAN_HPP_

#include "main.h"

namespace azt {

	/**
	 * Scans the I2C devices on the *hi2c and prints out the results to the *huart (in the blocking way)
	 */
	HAL_StatusTypeDef I2C_Scan(I2C_HandleTypeDef *hi2c, UART_HandleTypeDef *huart);
}


#endif /* INC_I2C_SCAN_HPP_ */
