/*******************************************************************************
 * @brief		Pure function in modern C++
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.24	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>

/* Private Functions ---------------------------------------------------------*/
static float CircleArea(float r) {
	return 3.14 * r * r;
}

/* Main Routine --------------------------------------------------------------*/
auto PureFunction() -> int {
	float f = 2.5f;
	for (int i = 1; i <= 5; ++i) {
		std::cout << "Invocation " << i << " -> ";
		std::cout << "Result of CircleArea(" << f << ") = ";
		std::cout << CircleArea(f) << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
