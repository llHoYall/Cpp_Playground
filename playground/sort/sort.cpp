/*******************************************************************************
 * @brief		sort algorithm
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.10.08	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>

/* Private Function Prototypes -----------------------------------------------*/
static bool comparer(int a, int b);

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[sort.cpp]" << std::endl;

	std::vector<int> vect = { 20, 43, 11, 78, 5, 96 };
	std::cout << "Original Data: ";
	for (auto v: vect) {
		std::cout << v << " ";
	}
	std::cout << std::endl;

	std::sort(std::begin(vect), std::end(vect));

	std::cout << "Ascending Sorted: ";
	for (auto v: vect) {
		std::cout << v << " ";
	}
	std::cout << std::endl;

	std::sort(std::begin(vect), std::end(vect), comparer);

	std::cout << "Descending Sorted: ";
	for (auto v: vect) {
		std::cout << v << " ";
	}
	std::cout << std::endl;

	return 0;
}

/* Private Functions ---------------------------------------------------------*/
static bool comparer(int a, int b) {
	return (a > b);
}
