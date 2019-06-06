/* Include Headers -----------------------------------------------------------*/
#include <iostream>

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[iostream.cpp]" << std::endl;

	// decimal, hexadecimal, octal
	std::cout << 1234 << ", " << std::hex << 1234 << ", " << std::oct << 1234 << '\n';

	// double, scientific, hexfloat, fixed, defaultfloat
	constexpr double d = 123.456;
	std::cout << d << ", "
		<< std::scientific << d << ", "
		<< std::hexfloat << d << ", "
		<< std::fixed << d << ", "
		<< std::defaultfloat << d << '\n';

	// precision
	std::cout.precision(8);
	std::cout << 1234.56789 << ' ' << 1234.56789 << ' ' << 123456.0 << '\n';
	std::cout.precision(4);
	std::cout << 1234.56789 << ' ' << 1234.56789 << ' ' << 123456.0 << '\n';
	std::cout << 1234.56789 << '\n';

	return 0;
}
