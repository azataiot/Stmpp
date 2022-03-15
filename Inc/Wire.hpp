/*
 * i2c.hpp
 *
 *  Created on: Mar 13, 2022
 *      Author: Azat
 */

#ifndef INC_AZT_I2C_HPP_
#define INC_AZT_I2C_HPP_

#include "main.h"
#include "Stmpp.hpp"

namespace azt{

	class Wire {
	public:
		Wire(); // base type.

		/** @brief Check the i2c line, and init the i2c device.
		 * @param *hi2c: I2C handler to use. (which i2c to use)
		 * @param address: device address (7bit).
		 * @note which i2c line to use, and init the device id.
		 * This function can also be used to check whether the device is ready
		 *  or exists on the i2c bus.
		 */
		status begin(I2C_HandleTypeDef *hi2c, uint8_t address);

		/** @brief Read an array of bytes from device memory.
		* @param address: starting register (memory) address to read.
		* @param *data: external array to hold data.
		* @param length: length of the data to be read.
		* @retval status.
		*/
		status read(uint16_t address,  uint16_t length, uint8_t *data);

		/** @brief Write an array of bytes to the device memory.
		 * @param address: start address of the memory to write.
		 * @param addr_length: length of the address to be written.
		 * @param *data: external array to hold the data to write.
		 * @param length: length of the data to write.
		 * @retval status.
		 */
		status write(uint16_t address, uint16_t addr_length, uint8_t *data, uint16_t data_length);
	private:
		I2C_HandleTypeDef i2c_handler;
		uint16_t device_address;
	};
}


#endif /* INC_AZT_I2C_HPP_ */
