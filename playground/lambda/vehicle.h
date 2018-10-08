/*******************************************************************************
 * @brief		vehicle module
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.10.08	Created.
 ******************************************************************************/

#ifndef __VEHICLE_H__
#define __VEHICLE_H__

/* Include Headers -----------------------------------------------------------*/
#include <string>

/* Class Declaration ---------------------------------------------------------*/
class Vehicle {
public:
	/* Constructor & Destructor */
	Vehicle();
	Vehicle(const std::string &type, int wheel);
	~Vehicle();

	/* APIs */
	std::string GetType() const {
		return m_vehicleType;
	}

	int GetNumOfWheel() const {
		return m_totalOfWheel;
	}

private:
	std::string m_vehicleType;
	int m_totalOfWheel;
};

#endif
