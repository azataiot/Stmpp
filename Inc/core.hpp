/*
 * core.hpp
 *
 *  Created on: Mar 13, 2022
 *      Author: Azat Yaakov
 */

#ifndef INC_AZT_CORE_HPP_
#define INC_AZT_CORE_HPP_

namespace azt {

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
