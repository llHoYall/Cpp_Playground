/*******************************************************************************
 * @brief		Template Meta programming: If-Else
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.29	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>

/* Private Functions ---------------------------------------------------------*/
static void TrueStatement(void) {
	std::cout << "  True Statement" << std::endl;
}

static void FalseStatement(void) {
	std::cout << "  False Statement" << std::endl;
}

/* Templates -----------------------------------------------------------------*/
template<bool predicate>
class IfElse {};

template<>
class IfElse<true> {
public:
	static inline void func(void) {
		TrueStatement();
	}
};

template<>
class IfElse<false> {
public:
	static inline void func(void) {
		FalseStatement();
	}
};

/* Main Routine --------------------------------------------------------------*/
auto Main_IfElse(void) -> int {
	std::cout << "> Template Meta Programming: If-Else" << std::endl;

	IfElse<(2 + 3 == 5)>::func();

	std::cout << std::endl;
	return 0;
}
