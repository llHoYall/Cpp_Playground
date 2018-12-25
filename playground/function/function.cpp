/*******************************************************************************
 * @brief		Function in modern C++
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.23	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include "first-class_function.h"
#include "higher-order_function.h"
#include "pure_function.h"
#include "currying.h"

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	FirstClassFunction();
	HigherOrderFunction();
	PureFunction();
	Currying();

	return 0;
}
