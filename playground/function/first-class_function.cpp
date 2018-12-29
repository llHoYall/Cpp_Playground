/*******************************************************************************
 * @brief		First class function in modern C++
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.23	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <functional>
#include <vector>
#include <cmath>
#include <algorithm>

/* Definitions ---------------------------------------------------------------*/
typedef std::function<int(int, int)> FuncType;
typedef std::function<double(double)> HyperbolicFn;

/* Private Variables ---------------------------------------------------------*/
// Way 1
// std::vector<HyperbolicFn> hb_fns = {
// 	std::sinhl, std::coshl, std::tanhl, [](double x) {
// 		return x * x;
// 	}
// };
// std::vector<HyperbolicFn> inv_fns = {
// 	std::asinhl, std::acoshl, std::atanhl, [](double x) {
// 		return exp(log(x) / 2);
// 	}
// };

// Way 2
// using Hyper = double(*)(double);
// std::vector<HyperbolicFn> hb_fns = {
// 	static_cast<Hyper>(std::sinh),
// 	static_cast<Hyper>(std::cosh),
// 	static_cast<Hyper>(std::tanh),
// 	[](double x) {
// 		return x * x;
// 	}
// };
// std::vector<HyperbolicFn> inv_fns = {
// 	static_cast<Hyper>(std::asinh),
// 	static_cast<Hyper>(std::acosh),
// 	static_cast<Hyper>(std::atanh),
// 	[](double x) {
// 		return exp(log(x) / 2);
// 	}
// };

// Way 3
std::vector<HyperbolicFn> hb_fns = {
	[](double x) { return std::sinh(x); },
	[](double x) { return std::cosh(x); },
	[](double x) { return std::tanh(x); },
	[](double x) { return x * x;        }
};
std::vector<HyperbolicFn> inv_fns = {
	[](double x) { return std::asinh(x);   },
	[](double x) { return std::acosh(x);   },
	[](double x) { return std::atanh(x);   },
	[](double x) { return exp(log(x) / 2); }
};

/* Private Functions ---------------------------------------------------------*/
template <typename A, typename B, typename C>
std::function<C(A)> compose(std::function<C(B)> f, std::function<B(A)> g) {
	return [f, g](A x) {
		return f(g(x));
	};
}

static int Addition(int x, int y) {
	return x + y;
}

static int Subtraction(int x, int y) {
	return x - y;
}

static int Multiplication(int x, int y) {
	return x * y;
}

static int Division(int x, int y) {
	return x / y;
}

static void PassingFunc(FuncType fn, int x, int y) {
	std::cout << "Result = " << fn(x, y) << std::endl;
}

/* Main Routine --------------------------------------------------------------*/
auto FirstClassFunction() -> int {
	std::cout << "[First-Class Function.cpp]" << std::endl;

	int i;
	int a;
	int b;
	FuncType fn;
	std::cout << "Menu " << std::endl;
	std::cout << "1. Addition" << std::endl;
	std::cout << "2. Subtraction" << std::endl;
	std::cout << "3. Multiplication" << std::endl;
	std::cout << "4. Division" << std::endl;
	std::cout << "Select: ";
	std::cin >> i;
	if (i < 1 || i > 4) {
		std::cout << "Please select available menu!";
		return 1;
	}
	std::cout << "a: ";
	std::cin >> a;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "You can only enter numbers.\n";
		std::cout << "Enter a number for variable a -> ";
		std::cin >> a;
	}
	std::cout << "b: ";
	std::cin >> b;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "You can only enter numbers.\n";
		std::cout << "Enter a number for variable b -> ";
		std::cin >> b;
	}

	// 매개변수로 함수 전달
	// switch (i) {
	// 	case 1: PassingFunc(Addition, a, b); break;
	// 	case 2: PassingFunc(Subtraction, a, b); break;
	// 	case 3: PassingFunc(Multiplication, a, b); break;
	// 	case 4: PassingFunc(Division, a, b); break;
	// }

	// 변수에 함수 대입
	// switch (i) {
	// 	case 1: fn = Addition; break;
	// 	case 2: fn = Subtraction; break;
	// 	case 3: fn = Multiplication; break;
	// 	case 4: fn = Division; break;
	// }
	// std::cout << "Result = " << fn(a, b) << std::endl;

	// Conntainer에 함수 저장
	std::vector<FuncType> fns;
	fns.push_back(Addition);
	fns.push_back(Subtraction);
	fns.push_back(Multiplication);
	fns.push_back(Division);
	std::cout << "Result = " << fns.at(i - 1)(a, b) << std::endl;

	// Runtime에 새로운 함수 생성
	std::vector<HyperbolicFn> composed_fns;
	std::vector<double> nums;
	for (int i = 1; i <= 5; ++i) {
		nums.push_back(i * 0.2);
	}
	std::transform(std::begin(inv_fns), std::end(inv_fns), std::begin(hb_fns), std::back_inserter(composed_fns), compose<double, double, double>);
	for (auto num : nums) {
		for (auto cfn : composed_fns) {
			std::cout << "f(g(" << num << ")) = " << cfn(num) << std::endl;
		}
		std::cout << "----------" << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
