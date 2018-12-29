/*******************************************************************************
 * @brief		Template Meta programming: Get const value in compile time
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.29	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>

/* Templates -----------------------------------------------------------------*/
template<int number>
struct Fibonacci {
	enum {
		value = Fibonacci<number - 1>::value + Fibonacci<number - 2>::value
	};
};

template<>
struct Fibonacci<1> {
	enum {
		value = 1
	};
};

template<>
struct Fibonacci<0> {
	enum {
		value = 0
	};
};

/* APIs ----------------------------------------------------------------------*/
auto Main_Value(void) -> int {
	std::cout << "> Template Meta Programming: Value" << std::endl;

	std::cout << "  Fibonacci(25) = " << Fibonacci<25>::value << std::endl;

	std::cout << std::endl;
	return 0;
}
