/*******************************************************************************
 * @brief		Concurrency in modern C++
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.30	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include "single-thread.h"
#include "multi-thread.h"
#include "mutex.h"
#include "deadlock.h"

/* Main Routine --------------------------------------------------------------*/
auto main(void) -> int {
	std::cout << "[concurrency.cpp]" << std::endl;

	Main_SingleThread();
	Main_MultiThread();
	Main_Mutex();
	Main_Deadlock();

	return 0;
}
