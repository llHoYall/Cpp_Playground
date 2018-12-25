/*******************************************************************************
 * @brief		Currying in modern C++
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.24	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <functional>

/* Private Functions ---------------------------------------------------------*/
template<typename Fn, typename... Args>
auto curry(Fn fn, Args... args) {
	return [=](auto... last_param) {
		return fn(args..., last_param...);
	};
}

static int AreaOfRectangle(int length, int width) {
	return length * width;
}

static int VolumeOfRectangle(int length, int width, int height) {
	return length * width * height;
}

/* Main Routine --------------------------------------------------------------*/
auto Currying() -> int {
	auto Length5 = curry(AreaOfRectangle, 5);
	std::cout << "Curried  with specific data: Length = 5" << std::endl;
	for (int i = 0; i <= 5; ++i) {
		std::cout << "  Length5(" << i << ") = ";
		std::cout << Length5(i) << std::endl;
	}

	auto Length5_Width4 = curry(VolumeOfRectangle, 5, 4);
	std::cout << "Curried with specific data: Length = 5, Width = 4" << std::endl;
	for (int i = 0; i <= 5; ++i) {
		std::cout << "  Length5_Width4(" << i << ") = ";
		std::cout << Length5_Width4(i) << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
