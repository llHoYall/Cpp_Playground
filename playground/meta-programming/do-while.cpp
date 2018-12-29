/*******************************************************************************
 * @brief		Template Meta programming: Do-While
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.29	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>

/* Private Functions ---------------------------------------------------------*/
static void PrintNumber(int n) {
	std::cout << "  " << n;
}

/* Templates -----------------------------------------------------------------*/
template<int limit>
class DoWhile {
public:
	static inline void func(void) {
		PrintNumber(limit);
		DoWhile<run == true ? (limit - 1) : 0>::func();
	}

private:
	enum {
		run = (limit - 1) != 0
	};
};

template<>
class DoWhile<0> {
public:
	static inline void func(void) {}
};

/* APIs ----------------------------------------------------------------------*/
auto Main_DoWhile(void) -> int {
	std::cout << "> Template Meta Programming: Do-While" << std::endl;

	const int i = 10;
	DoWhile<i>::func();
	std::cout << std::endl;

	std::cout << std::endl;
	return 0;
}
