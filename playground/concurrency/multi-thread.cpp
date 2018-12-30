/*******************************************************************************
 * @brief		Concurrency: Multi thread
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
}

/* APIs ----------------------------------------------------------------------*/
auto Main_MultiThread(void) -> int {
	std::cout << "> multi thread" << std::endl;

	std::thread threads[5];
	// Way 1
	for (int i = 0; i < 5; ++i) {
		threads[i] = std::thread(ThreadProc);
	}
	// Way 2: Lambda
	// for (int i = 0; i < 5; ++i) {
	// 	threads[i] = std::thread([]() {
	// 		std::cout << "  Thread ID: " << std::this_thread::get_id() << std::endl;
	// 	});
	// }
	for (auto& thread : threads) {
		thread.join();
	}

	std::cout << std::endl;
	return 0;
}
