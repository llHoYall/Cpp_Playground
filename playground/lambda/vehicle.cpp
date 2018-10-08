/*******************************************************************************
 * @brief		vehicle module
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.10.08	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include "vehicle.h"

/* Class Declarations --------------------------------------------------------*/
/* Constructor & Destructor */
Vehicle::Vehicle() : m_totalOfWheel(0) {
}

Vehicle::Vehicle(const std::string &type, int wheel) : m_vehicleType(type), m_totalOfWheel(wheel) {
}

Vehicle::~Vehicle() {
}
