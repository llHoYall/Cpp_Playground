/*******************************************************************************
 * @brief		lambda expression
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.10.08	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "vehicle.h"

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[lambda.cpp]" << std::endl;

	// Lambda: Tiny function
	Vehicle car("car", 4);
	Vehicle motorcycle("motorcycle", 2);
	Vehicle bicycle("bicycle", 2);
	Vehicle bus("bus", 6);
	std::vector<Vehicle> vehicles = { car, motorcycle, bicycle, bus };

	std::cout << "All vehicles: " << std::endl;
	std::for_each (std::begin(vehicles), std::end(vehicles), [](const Vehicle &vehicle) {
		std::cout << vehicle.GetType() << std::endl;
	});

	// Lambda: Multiline function
	std::vector<int> vect;
	for (int i = 0; i < 10; ++i) {
		vect.push_back(i);
	}
	for_each(std::begin(vect), std::end(vect), [](int n) {
		std::cout << n << " is";
		if (n < 2) {
			if (0 == n) {
				std::cout << " not";
			}
		} else {
			for (int j = 2; j < n; ++j) {
				if (n % j == 0) {
					std::cout << " not";
					break;
				}
			}
		}
		std::cout << " prime number" << std::endl;
	});

	// Lambda: Returnung value
	std::vector<int> vect1;
	for (int i = 0; i < 10; ++i) {
		vect1.push_back(i);
	}

	std::cout << "Original Data: " << std::endl;
	for_each(std::begin(vect1), std::end(vect1), [](int n) {
		std::cout << n << " ";
	});
	std::cout << std::endl;

	std::vector<int> vect2;
	vect2.resize(vect1.size());
	std::transform(std::begin(vect1), std::end(vect1), std::begin(vect2), [](int n) {
		return n * n;
	});

	std::cout << "Squared Data: " << std::endl;
	for_each(std::begin(vect2), std::end(vect2), [](int n) {
		std::cout << n << " ";
	});
	std::cout << std::endl;

	std::vector<int> vect3;
	vect3.resize(vect1.size());
	std::transform(std::begin(vect2), std::end(vect2), std::begin(vect3), [](int n) -> double {
		return n / 2.0;
	});

	std::cout << "Divided Data: " << std::endl;
	for_each(std::begin(vect3), std::end(vect3), [](double d) {
		std::cout << d << " ";
	});
	std::cout << std::endl;

	// Lambda: Capturing by value
	vect.clear();
	for (int i = 0; i < 10; ++i) {
		vect.push_back(i);
	}

	std::cout << "Original Data: " << std::endl;
	for_each(std::begin(vect), std::end(vect), [](int n) {
		std::cout << n << " ";
	});
	std::cout << std::endl;

	int a = 2;
	int b = 8;
	std::cout << "Capturing 2 variables: " << std::endl;
	std::cout << a << " and " << b << " explicitly [a,b]: " << std::endl;
	for_each(std::begin(vect), std::end(vect), [a,b](int n) {
		if (n >= a && n <= b) {
			std::cout << n << " ";
		}
	});
	std::cout << std::endl;

	a = 3;
	b = 7;
	std::cout << "Capturing 2 variables: " << std::endl;
	std::cout << a << " and " << b << " implicitly [a,b]: " << std::endl;
	for_each(std::begin(vect), std::end(vect), [=](int n) {	// 암시적으로 모든 변수를 값으로 capturing
		if (n >= a && n <= b) {
			std::cout << n << " ";
		}
	});
	std::cout << std::endl;

	// Lambda 표현식 바깥의 변수를 직접 수정하지 않고 capture한 변수의 상태를 변경한다.
	for_each(std::begin(vect), std::end(vect), [=](int& x) mutable {	// mutable keyword 때문에 실제로 수정되지는 않는다.
		const int old = x;
		x *= 2;
		a = b;
		b = old;
	});

	std::cout << "Doubled Data: " << std::endl;
	for_each(std::begin(vect), std::end(vect), [](int n) {
		std::cout << n << " ";
	});
	std::cout << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	// Lambda: Capturing by reference
	vect.clear();
	for (int i = 0; i < 10; ++i) {
		vect.push_back(i);
	}

	std::cout << "Original Data: " << std::endl;
	for_each(std::begin(vect), std::end(vect), [](int n) {
		std::cout << n << " ";
	});
	std::cout << std::endl;

	a = 1;
	b = 1;
	for_each(std::begin(vect), std::end(vect), [&a, &b](int& x) {
		const int old = x;
		x *= 2;
		a = b;
		b = old;
	});

	std::cout << "Doubled Data: " << std::endl;
	for_each(std::begin(vect), std::end(vect), [](int n) {
		std::cout << n << " ";
	});
	std::cout << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	// Lambda: Initialization capture
	a = 5;
	std::cout << "Initial a = " << a << std::endl;
	auto myLambda = [&x = a]() {
		x += 2;
	};
	myLambda();
	std::cout << "New a = " << a << std::endl;

	// Lambda: Generic expression
	auto find_max = [](auto &x, auto &y) {
		return x > y ? x : y;
	};
	int i1 = 5;
	int i2 = 3;
	float f1 = 2.5f;
	float f2 = 2.05f;

	std::cout << "i1 = " << i1 << ", i2 = " << i2 << std::endl;
	std::cout << "Max: " << find_max(i1, i2) << std::endl;
	std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
	std::cout << "Max: " << find_max(f1, f2) << std::endl;

	return 0;
}
