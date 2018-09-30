/*******************************************************************************
 * @brief		decltype keyword
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.09.30	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>

/* Private Function Prototypes -----------------------------------------------*/
template<typename I, typename J>
auto add(I i, J j) -> decltype(i + j);

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[decltype.cpp]" << std::endl;

	auto d = add<int, double>(2, 2.5);
	std::cout << "result of 2 + 2.5: " << d << std::endl;

	return 0;
}

/* Private Functions ---------------------------------------------------------*/
template<typename I, typename J>
auto add(I i, J j) -> decltype(i + j) {
	return i + j;
}
