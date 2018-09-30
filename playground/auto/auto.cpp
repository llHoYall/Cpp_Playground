/*******************************************************************************
 * @brief		auto keyword
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.09.30	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <typeinfo>

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[auto.cpp]" << std::endl;

	auto a = 1;
	auto b = 1.0;
	auto c = a + b;
	auto d = { b, c };

	std::cout << "type of a: " << typeid(a).name() << std::endl;
	std::cout << "type of b: " << typeid(b).name() << std::endl;
	std::cout << "type of c: " << typeid(c).name() << std::endl;
	std::cout << "type of d: " << typeid(d).name() << std::endl;

	return 0;
}
