/*******************************************************************************
 * @brief		Concurrency: Deadlock
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.30	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <thread>
#include <mutex>

/* Structures ----------------------------------------------------------------*/
struct Math {
	std::recursive_mutex mtx;
	int m_content;

	Math(void) : m_content(1) {}

	void Multiplexer(int n) {
		std::lock_guard<std::recursive_mutex> lock(mtx);
		m_content *= n;
		std::cout << "  Multiplexer: Content = " << m_content << std::endl;
	}

	void Divisor(int n) {
		std::lock_guard<std::recursive_mutex> lock(mtx);
		m_content /= n;
		std::cout << "  Multiplexer: Content = " << m_content << std::endl;
	}

	void RunAll(int n) {
		std::lock_guard<std::recursive_mutex> lock(mtx);
		Multiplexer(n);
		Divisor(n);
	}
};

/* APIs ----------------------------------------------------------------------*/
auto Main_Deadlock(void) -> int {
	std::cout << "> deadlock" << std::endl;

	Math math;
	math.RunAll(10);

	std::cout << std::endl;
	return 0;
}
