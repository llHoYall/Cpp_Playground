/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <regex>

/* Private Function Prototypes -----------------------------------------------*/
static void IteratorTest(void);

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[regex.cpp]" << std::endl;

	// Search
	std::ifstream inf("./test.txt");
	if (!inf) {
		std::cerr << "File not found\n";
	}

	std::regex pat {R"(\w{2}\s*\d{5}(-\d{4})*)"};

	int lineno = 0;
	for (std::string line; getline(inf, line); ) {
		++lineno;
		std::smatch matches;
		if (regex_search(line, matches, pat)) {
			std::cout << lineno << ": " << matches[0] << '\n';
			if (1 < matches.size() && matches[1].matched) {
				std::cout << "\t: " << matches[1] << '\n';
			}
		}
	}

	IteratorTest();

	return 0;
}

/* Private Functions ---------------------------------------------------------*/
static void IteratorTest(void) {
	std::string input = "aa as; asd ++e^asdf asdfg";
	std::regex pat {R"(\s+(\w+))"};
	for (std::sregex_iterator p(input.begin(), input.end(), pat); p != std::sregex_iterator{}; ++p) {
		std::cout << (*p)[1] << '\n';
	}
}
