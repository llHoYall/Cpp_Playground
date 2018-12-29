/*******************************************************************************
 * @brief		Template Meta programming: Get type in compile time
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.29	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>

/* Templates -----------------------------------------------------------------*/
template<typename T>
struct datatype {
	using type = T;
};

/* APIs ----------------------------------------------------------------------*/
auto Main_Type(void) -> int {
	std::cout << "> Template Meta Programming: Type" << std::endl;

	using t = typename datatype<int>::type;
	t var = 123;
	std::cout << "  var = " << var << std::endl;

	std::cout << std::endl;
	return 0;
}
