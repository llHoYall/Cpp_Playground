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

	return 0;
}
