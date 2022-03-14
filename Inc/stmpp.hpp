/*
 * core.hpp
 *
 *  Created on: Mar 13, 2022
 *      Author: Azat Yaakov
 */

#ifndef INC_AZT_CORE_HPP_
#define INC_AZT_CORE_HPP_

// includes
#include <stdint.h>
#include "string"
#include "gpio.h"
// high low logic value
#define HIGH 0x1
#define LOW  0x0

// common math constants
#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define sq(x) ((x)*(x))

#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))

typedef bool boolean;
typedef uint8_t byte;

// pin selection





namespace azt {

	byte * gpio(std::string gpio_name);

	void digitalWrite(uint8_t pin, uint8_t val);

	enum status
	{
	   ok = 0,
	   error = 1,
	};

	enum class UseRTOS
		{
		   Yes = 0,
		   No = 1,
		};
}

#endif /* INC_AZT_CORE_HPP_ */
