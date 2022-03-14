/*
 * i2c.cpp
 *
 *  Created on: Mar 13, 2022
 *      Author: Azat
 */


#include "stmpp.hpp"
#include "i2c.hpp"

namespace azt{

	// base
	// a constructor should not have a return type.
	I2C::I2C(){
	}

	// begin
	status I2C::begin(I2C_HandleTypeDef *hi2c, uint8_t address){
		uint8_t ret;
		ret = HAL_I2C_IsDeviceReady(&*hi2c, (uint16_t)(address), 3, 5);
		 if (ret != HAL_OK) {
			 return error;
		} else {
			device_address = address;
			i2c_handler = *hi2c;
			return ok;
		}
	}

	// read
	status I2C::read(uint16_t address, uint8_t *data, uint16_t length){
		HAL_I2C_Mem_Read(&i2c_handler, device_address, address, length, &*data, 3, HAL_MAX_DELAY);
		return ok;
	}

	// write
	status I2C::write(uint16_t address, uint16_t addr_length, uint8_t *data, uint16_t data_length){
		HAL_I2C_Mem_Write(&i2c_handler, device_address, address, addr_length, &*data, data_length, HAL_MAX_DELAY);
		return ok;
	}

}
