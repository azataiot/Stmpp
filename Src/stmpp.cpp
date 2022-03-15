/*
 * stmpp.cpp
 *
 *  Created on: Mar 14, 2022
 *      Author: Yaakov Azat
 */

#include <Stmpp.hpp>

namespace azt {

GPIO_PinState mapPinState(uint8_t val) {
	switch (val) {
	case HIGH:
		return GPIO_PIN_SET;
		break;
	case LOW:
		return GPIO_PIN_RESET;
		break;
	default:
		return GPIO_PIN_RESET;
	}
}

GPIO_TypeDef* mapPinBank(std::string pin_bank) {
	if (pin_bank == "PA") {
		return GPIOA;
	} else if (pin_bank == "PB") {
		return GPIOB;
	}

	else if (pin_bank == "PC") {
		return GPIOC;
	}

	else if (pin_bank == "PD") {
		return GPIOD;
	}

	else if (pin_bank == "PE") {
		return GPIOE;
	}

	else if (pin_bank == "PF") {
		return GPIOF;
	}

	else if (pin_bank == "PG") {
		return GPIOG;
	}
	// we should not never able to touch here.
	// but we also need to return something, otherwise c++ compiler will complain about
	// "warning: control reaches end of non-void function [-Wreturn-type]"
	return GPIOG;
}

uint16_t mapPinNumber(int pin_num) {
	switch (pin_num) {
	case 0:
		return GPIO_PIN_0;
		break;
	case 1:
		return GPIO_PIN_1;
		break;
	case 2:
		return GPIO_PIN_2;
		break;
	case 3:
		return GPIO_PIN_3;
		break;
	case 4:
		return GPIO_PIN_4;
		break;
	case 5:
		return GPIO_PIN_5;
		break;
	case 6:
		return GPIO_PIN_6;
		break;
	case 7:
		return GPIO_PIN_7;
		break;
	case 8:
		return GPIO_PIN_8;
		break;
	case 9:
		return GPIO_PIN_9;
		break;
	case 10:
		return GPIO_PIN_10;
		break;
	case 11:
		return GPIO_PIN_11;
		break;
	case 12:
		return GPIO_PIN_12;
		break;
	case 13:
		return GPIO_PIN_13;
		break;
	case 14:
		return GPIO_PIN_14;
		break;
	case 15:
		return GPIO_PIN_15;
		break;
	case 16:
		return GPIO_PIN_All;
		break;
	default:
		return GPIO_PIN_All;
	}
}

// Implementation of the Arduino digitalWrite() Function in STM32 CPP.
status digitalWrite(std::string pin, uint8_t val) {
	// PinState
	GPIO_PinState PinState = mapPinState(val);
	// std::string pin_bank = pin.substr(0, 2);
	// GPIO_Bank
	GPIO_TypeDef *GPIO_Bank = mapPinBank(pin.substr(0, 2));
	int pin_num = std::stoi(pin.substr(pin.length() - 2));
	// GPIO_Pin
	uint16_t GPIO_Pin = mapPinNumber(pin_num);
	HAL_GPIO_WritePin(GPIO_Bank, GPIO_Pin, PinState);
	return ok;
}

// Implementation of Arduino digitalRead() Function.
GPIO_PinState digitalRead(std::string pin) {
	// GPIO_Bank
	GPIO_TypeDef *GPIO_Bank = mapPinBank(pin.substr(0, 2));
	int pin_num = std::stoi(pin.substr(pin.length() - 2));
	// GPIO_Pin
	uint16_t GPIO_Pin = mapPinNumber(pin_num);
	return HAL_GPIO_ReadPin(GPIO_Bank, GPIO_Pin);
}
}

