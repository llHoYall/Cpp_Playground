/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

/* APIs ----------------------------------------------------------------------*/
auto Time_ChronoTime(void) -> void {
	std::cout << "> Time: Chrono Time" << std::endl;

	auto t0 = std::chrono::high_resolution_clock::now();
	// for (volatile int i = 0; i < 1000000; i++);
	std::this_thread::sleep_for(std::chrono::milliseconds(10) + 15ms);
	auto t1 = std::chrono::high_resolution_clock::now();
	std::cout << ">> Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count() << "msec\n";
}
