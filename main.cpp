/*
 * main.cpp
 *
 *  Created on: Mar 14, 2022
 *      Author: Yaakov Azat
 */

#include "main.h"
#include "core.hpp"
#include "i2c_scan.hpp"
#include "uart.hpp"
#include "usart.h"
#include "i2c.h"

void CppMain(){
	// this is our main for cpp part.
	 azt::I2C_Scan(&hi2c2, &huart3);
}


void setup(){
	// put your setup code here, to run once;
}


void loop(){
	// put your main code here, to run repeatedly;
}
