/*******************************************************************************
 * @brief		tuple in modern C++
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.23	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <tuple>

/* Private Functions ---------------------------------------------------------*/
std::tuple<int, std::string, bool> GetData(int data_id) {
	if (1 == data_id) {
		return std::make_tuple(0, "Aran", false);
	} else if (2 == data_id) {
		return std::make_tuple(1, "brian", true);
	} else {
		return std::make_tuple(2, "Chris", false);
	}
}

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[tuple.cpp]" << std::endl;

	std::tuple<int, std::string, bool> t1(1, "Elsa", true);
	auto t2 = std::make_tuple(2, "Anna", false);
	std::cout << "t1 elements: " << std::endl;
	std::cout << "  " << std::get<0>(t1) << std::endl;
	std::cout << "  " << std::get<1>(t1) << std::endl;
	std::cout << "  " << (std::get<2>(t1) == true ? "Old" : "Young") << std::endl;
	std::cout << "t2 elements: " << std::endl;
	std::cout << "  " << std::get<0>(t2) << std::endl;
	std::cout << "  " << std::get<1>(t2) << std::endl;
	std::cout << "  " << (std::get<2>(t2) == true ? "Old" : "Young") << std::endl << std::endl;

	int i;
	std::string s;
	bool b;
	std::tie(i, s, b) = t1;
	std::cout << "tie t1" << std::endl;
	std::cout << "  i = " << i << std::endl;
	std::cout << "  s = " << s << std::endl;
	std::cout << "  b = " << std::boolalpha << b << std::endl;
	std::tie(std::ignore, s, std::ignore) = t2;
	std::cout << "tie t2" << std::endl;
	std::cout << "  i = " << i << std::endl;
	std::cout << "  s = " << s << std::endl;
	std::cout << "  b = " << std::boolalpha << b << std::endl << std::endl;

	auto name = GetData(1);
	std::cout << "GetData(1)" << std::endl;
	std::cout << "  " << "ID = " << std::get<0>(name) << std::endl;
	std::cout << "  " << "Name = " << std::get<1>(name) << std::endl;
	std::cout << "  " << "Old = " << (std::get<2>(name) == true ? "Yes" : "No") << std::endl;
	tie(i, s, b) = GetData(2);
	std::cout << "GetData(2)" << std::endl;
	std::cout << "  " << "ID = " << i << std::endl;
	std::cout << "  " << "Name = " << s << std::endl;
	std::cout << "  " << "Old = " << (b == true ? "Yes" : "No") << std::endl;

	return 0;
}
