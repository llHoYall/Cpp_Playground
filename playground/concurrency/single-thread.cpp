/*******************************************************************************
 * @brief		Concurrency: Single thread
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.30	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <thread>

/* Private Functions ---------------------------------------------------------*/
static void ThreadProc(void) {
	std::cout << "  Thread ID: " << std::this_thread::get_id() << std::endl;
	for (int i = 0; i < 5; ++i) {
		std::cout << "  Thread Current i = " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
	}
}

/* APIs ----------------------------------------------------------------------*/
auto Main_SingleThread(void) -> int {
	std::cout << "> single thread" << std::endl;

	std::thread thread1(ThreadProc);
	for (int i = 0; i < 5; ++i) {
		std::cout << "  Main Current i = " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
	thread1.join();

	std::cout << std::endl;
	return 0;
}
