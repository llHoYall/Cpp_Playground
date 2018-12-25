/*******************************************************************************
 * @brief		Immutable employee module
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.25	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include "ImmutableEmployee.h"

/* Class Functions -----------------------------------------------------------*/
ImmutableEmployee::ImmutableEmployee(void) : m_id(0), m_salary(0.0) {
}

ImmutableEmployee::ImmutableEmployee(const int& id, const std::string& first_name, const std::string& last_name, const double& salary) :
	m_id(id), m_first_name(first_name), m_last_name(last_name), m_salary(salary) {
}
