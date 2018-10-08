/*******************************************************************************
 * @brief		sort algorithm
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

/* Private Function Prototypes -----------------------------------------------*/
static bool IsTwoWheeled(const Vehicle &vehicle);

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[find.cpp]" << std::endl;

	Vehicle car("car", 4);
	Vehicle motorcycle("motorcycle", 2);
	Vehicle bicycle("bicycle", 2);
	Vehicle bus("bus", 6);
	std::vector<Vehicle> vehicles = { car, motorcycle, bicycle, bus };

	std::cout << "All vehicles: " << std::endl;
	for (auto v: vehicles) {
		std::cout << v.GetType() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Two-wheeled vehicle(s): " << std::endl;
	auto tw = std::find_if(std::begin(vehicles), std::end(vehicles), IsTwoWheeled);
	while (tw != std::end(vehicles)) {
		std::cout << tw->GetType() << std::endl;
		tw = std::find_if(++tw, std::end(vehicles), IsTwoWheeled);
	}
	std::cout << std::endl;

	std::cout << "Not the two-wheeled vehicle(s): " << std::endl;
	auto ntw = std::find_if_not(std::begin(vehicles), std::end(vehicles), IsTwoWheeled);
	while (ntw != std::end(vehicles)) {
		std::cout << ntw->GetType() << std::endl;
		ntw = std::find_if_not(++ntw, std::end(vehicles), IsTwoWheeled);
	}

	return 0;
}

/* Private Functions ---------------------------------------------------------*/
static bool IsTwoWheeled(const Vehicle &vehicle) {
	return vehicle.GetNumOfWheel() == 2 ? true : false;
}
