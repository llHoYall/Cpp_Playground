/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <cmath>
#include <vector>

/* Private Function Prototypes -----------------------------------------------*/
static double sum(const std::vector<double>&);
constexpr static double square(double);

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[const.cpp]" << std::endl;

	int var = 17;
	const double var_b1 = sqrt(var);
	constexpr int var_a1 = 17;

	std::cout << "var_a: " << var_a1 << std::endl;
	std::cout << "var_b: " << var_b1 << std::endl;

	// double sum(const vector<double>&);
	std::vector<double> vd { 1.2, 3.4, 4.5 };
	const double var_a2 = sum(vd);		// Evaluate in run-time
	// constexpr double var_b2 = sum(vd);		// Error!

	std::cout << "var_a: " << var_a2 << std::endl;

	const double var_a3 = 1.4 * square(var);
	// constexpr double var_b3 = 1.4 * square(17);		// Error?
	// constexpr double var_b3 = 1.4 * square(var);		// Error!

	std::cout << "var_a: " << var_a3 << std::endl;

	return 0;
}

static double sum(const std::vector<double>& vd) {
	double result = 0;
	for (auto x : vd) {
		result += x;
	}
	return result;
}

constexpr static double square(double x) {
	return x * x;
}
