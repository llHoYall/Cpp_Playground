/*******************************************************************************
 * @brief		Concurrency: Mutex
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.30	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <thread>
#include <mutex>

/* APIs ----------------------------------------------------------------------*/
auto Main_Mutex(void) -> int {
	std::cout << "> mutex" << std::endl;

	std::mutex mtx;
	std::thread threads[5];
	int counter = 0;
	for (int i = 0; i < 5; ++i) {
		threads[i] = std::thread([&counter, &mtx]() {
			for (int i = 0; i < 10; ++i) {
				// Way 1: mtx.unlock()호출 이전에 exception이 발생할 경우 lock이 안풀릴 수 있다.
				// mtx.lock();
				// ++counter;
				// mtx.unlock();

				// Way 2: code block을 빠져나갈 때 자동으로 lock이 해제된다.
				{
					std::lock_guard<std::mutex> guard(mtx);
					++counter;
				}

				std::cout << "  Thread ID: " << std::this_thread::get_id() << ", Counter = " << counter << std::endl;
			}
		});
	}
	for (auto& thread : threads) {
		thread.join();
	}
	std::cout << "  Final counter = " << counter << std::endl;

	std::cout << std::endl;
	return 0;
}
