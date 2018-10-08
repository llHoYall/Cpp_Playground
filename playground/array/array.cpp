/*******************************************************************************
 * @brief		array container
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.10.08	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <array>

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[array.cpp]" << std::endl;

	std::array<int, 10> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::cout << "Original Data: ";
	for (auto a: arr) {
		std::cout << a << " ";
	}
	std::cout << std::endl;

	arr[1] = 9;
	arr[3] = 7;

	std::cout << "Manipulated Data: ";
	for (auto a: arr) {
		std::cout << a << " ";
	}
	std::cout << std::endl;

	return 0;
}
