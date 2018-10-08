/*******************************************************************************
 * @brief		vector container
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.10.08	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <vector>

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[vector.cpp]" << std::endl;

	std::vector<int> vect = { 0, 1, 2 };
	std::cout << "Original Data: ";
	for (auto v: vect) {
		std::cout << v << " ";
	}
	std::cout << std::endl;

	vect.push_back(3);
	vect.push_back(4);

	std::cout << "New Data Added: ";
	for (auto v: vect) {
		std::cout << v << " ";
	}
	std::cout << std::endl;

	vect.at(2) = 5;
	vect.at(4) = 6;

	std::cout << "Manipulated Data: ";
	for (auto v: vect) {
		std::cout << v << " ";
	}
	std::cout << std::endl;

	return 0;
}
