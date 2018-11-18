/*******************************************************************************
 * @brief		Calculator example
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.10.08	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include "calculator.h"

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	int a = 6;
	int b = 3;

	std::cout << "Add: " << Add(a, b) << std::endl;
	std::cout << "Subtract: " << Sub(a, b) << std::endl;
	std::cout << "Multiplication: " << Mul(a, b) << std::endl;
	std::cout << "Division: " << Div(a, b) << std::endl;

	return 0;
}
