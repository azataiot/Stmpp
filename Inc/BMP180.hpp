/*
 * BMP180.hpp
 *
 *  Created on: Mar 13, 2022
 *      Author: Azat
 */

#ifndef INC_AZT_BMP180_HPP_
#define INC_AZT_BMP180_HPP_


#include "main.h"
#include "stmpp.hpp"

namespace azt {

	class BMP180{
	public:
		bool RTOS = false;
		BMP180();//base type
		status begin(UseRTOS::No);
		float temperature();
		float pressure();
		float altitute();
	private:
		uint16_t getUT();
		uint16_t getUP();
	};
}

#endif /* INC_AZT_BMP180_HPP_ */
