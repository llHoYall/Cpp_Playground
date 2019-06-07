/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <fstream>

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[fstream.cpp]" << std::endl;

	std::ofstream ofs {"fname"};
	if (!ofs) {
		std::cerr << "Can't open file for output mode: fname\n";
	}

	std::ifstream ifs {"fname"};
	if (!ifs) {
		std::cerr << "Can't open file for input mode: fname\n";
	}

	return 0;
}
