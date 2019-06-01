/* Include Headers -----------------------------------------------------------*/
#include <iostream>

/* Private Variable Definitions ----------------------------------------------*/
constexpr double c = 299792.458;

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[assert.cpp]" << std::endl;

	constexpr double v = 160.0 / (60 * 60);

	static_assert(v < c, "Error 1");
	// static_assert(v > c, "Error 2");		// Error
	// static_assert(4 > sizeof(int));		// Default error message

	return 0;
}
