/*******************************************************************************
 * @brief		for loop in modern C++
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.09.30	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[for-loop.cpp]" << std::endl;

	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// Previous C++
	std::cout << "Displaying array element using conventional for-loop" << std::endl;
	for (unsigned int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	// Modern C++ : Non-member function
	std::cout << "Displaying array element using non-member begin() and end()" << std::endl;
	for (auto i = std::begin(arr); i != std::end(arr); ++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	// Modern C++ : Range-based for loop
	std::cout << "Displaying array element using range-based for loop" << std::endl;
	for (auto a: arr) {
		std::cout << a << " ";
	}
	std::cout << std::endl;

	return 0;
}
