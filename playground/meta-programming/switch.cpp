/*******************************************************************************
 * @brief		Template Meta programming: Switch
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.29	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>

/* Private Functions ---------------------------------------------------------*/
static int Square(int a) {
	return a * a;
}

/* Templates -----------------------------------------------------------------*/
template<int value>
class Switch {
public:
	static inline int func(void) {
		return Square(0);
	}
};

template<>
class Switch<1> {
public:
	static inline int func(void) {
		return Square(1);
	}
};

template<>
class Switch<2> {
public:
	static inline int func(void) {
		return Square(2);
	}
};

/* APIs ----------------------------------------------------------------------*/
auto Main_Switch(void) -> int {
	std::cout << "> Template Meta Programming: Switch" << std::endl;

	const int i = 2;
	int output = Switch<i>::func();
	std::cout << "  The result is " << output << std::endl;

	std::cout << std::endl;
	return 0;
}
