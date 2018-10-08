/*******************************************************************************
 * @brief		for_each algorithm in modern C++
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.09.30	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "vehicle.h"

/* Private Function Prototypes -----------------------------------------------*/
static void PrintOut(const Vehicle &vehicle);

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[for_each.cpp]" << std::endl;

	Vehicle car("car", 4);
	Vehicle motorcycle("motorcycle", 2);
	Vehicle bicycle("bicycle", 2);
	Vehicle bus("bus", 6);
	std::vector<Vehicle> vehicles = { car, motorcycle, bicycle, bus };

	std::cout << "All vehicles: " << std::endl;
	std::for_each (std::begin(vehicles), std::end(vehicles), PrintOut);

	return 0;
}

/* Private Functions ---------------------------------------------------------*/
static void PrintOut(const Vehicle &vehicle) {
	std::cout << vehicle.GetType() << std::endl;
}
