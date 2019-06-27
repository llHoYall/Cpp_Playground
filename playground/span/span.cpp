/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <span>

/* Private Function Prototypes -----------------------------------------------*/
static void InitArray(int* p, int n);
static void InitArrayEnhanced(std::span<int> p);

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[gsl::span.cpp]" << std::endl;

	int a[100];
	InitArray(a, 100);
	// InitArray(a, 1000);				// Error!
	// InitArray(a + 10, 100);		// Error!

	InitArrayEnhanced(a);								// OK, create implicitly span<int>{a, 100}
	InitArrayEnhanced(a, 1000);					// Error!
	InitArrayEnhanced({a + 10, 100});		// Error!

	return 0;
}

/* Private Functions ---------------------------------------------------------*/
static void InitArray(int* p, int n) {
	for (int i = 0; i < n; ++i) {
		p[i] = 0;
	}
}

static void InitArrayEnhanced(std::span<int> p) {
	for (int x: p) {
		x = 0;
	}
}
