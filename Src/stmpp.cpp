/*
 * stmpp.cpp
 *
 *  Created on: Mar 14, 2022
 *      Author: Yaakov Azat
 */

#include "stmpp.hpp"

namespace azt{

	status digitalWrite(std::string pin, uint8_t val){
		GPIO_PinState PinState;
		switch(val){
		case HIGH:
			PinState = GPIO_PIN_SET;
			break;
		case LOW:
			PinState = GPIO_PIN_RESET;
			break;
		}
		std::string pin_bank = pin.substr(0, 2);
		int pin_num = std::stoi(pin.substr(pin.length() - 2));
		uint16_t GPIO_Pin = (uint16_t)pin_num;
		if(pin_bank=="PA"){
			HAL_GPIO_WritePin(GPIOA, GPIO_Pin, PinState);
		}
		else if(pin_bank=="PB"){
			HAL_GPIO_WritePin(GPIOB, GPIO_Pin, PinState);
		}

		else if(pin_bank =="PC"){
			HAL_GPIO_WritePin(GPIOC, GPIO_Pin, PinState);
		}

		else if(pin_bank=="PD"){
			HAL_GPIO_WritePin(GPIOD, GPIO_Pin, PinState);
		}

		else if(pin_bank=="PE"){
			HAL_GPIO_WritePin(GPIOE, GPIO_Pin, PinState);
		}

		else if(pin_bank=="PF"){
			HAL_GPIO_WritePin(GPIOF, GPIO_Pin, PinState);
		}

		else{
			return error;
		}
		return ok;
	}
}


