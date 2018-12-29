/*******************************************************************************
 * @brief		Meta programming in modern C++
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.29	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include "type.h"
#include "if-else.h"
#include "switch.h"
#include "do-while.h"
#include "value.h"
#include "class.h"

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[meta-programming.cpp]" << std::endl << std::endl;

	Main_Type();
	Main_IfElse();
	Main_Switch();
	Main_DoWhile();
	Main_Value();
	Main_Class();

	return 0;
}
