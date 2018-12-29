/*******************************************************************************
 * @brief		Template Meta programming: Create class in compile time
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.29	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>

/* Templates -----------------------------------------------------------------*/
template<int lastNumber, int nextToLastNumber>
class IsPrime {
public:
	enum {
		primeNumber = (
			(lastNumber % nextToLastNumber) && IsPrime<lastNumber, nextToLastNumber - 1>::primeNumber
		)
	};
};

template<int number>
class IsPrime<number, 1> {
public:
	enum {
		primeNumber = 1
	};
};

template<int number>
class PrimeNumberPrinter {
public:
	PrimeNumberPrinter<number - 1> printer;

	enum {
		primeNumber = IsPrime<number, number - 1>::primeNumber
	};

	void func(void) {
		printer.func();
		if (primeNumber) {
			std::cout << "  " << number;
		}
	}
};

template<>
class PrimeNumberPrinter<1> {
public:
	enum {
		primeNumber = 0
	};

	void func(void) {}
};

/* APIs ----------------------------------------------------------------------*/
auto Main_Class(void) -> int {
	std::cout << "> Template Meta Programming: Class" << std::endl;

	PrimeNumberPrinter<500> printer;
	printer.func();
	std::cout << std::endl;

	std::cout << std::endl;
	return 0;
}
