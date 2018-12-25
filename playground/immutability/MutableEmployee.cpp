/*******************************************************************************
 * @brief		Mutable employee module
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.25	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include "MutableEmployee.h"

/* Class Functions -----------------------------------------------------------*/
MutableEmployee::MutableEmployee(void) : m_id(0), m_salary(0.0) {
}

MutableEmployee::MutableEmployee(const int& id, const std::string& first_name, const std::string& last_name, const double& salary) :
	m_id(id), m_first_name(first_name), m_last_name(last_name), m_salary(salary) {
}

void MutableEmployee::SetId(const int id) {
	m_id = id;
}

void MutableEmployee::SetFirstName(const std::string& first_name) {
	m_first_name = first_name;
}

void MutableEmployee::SetLastName(const std::string& last_name) {
	m_last_name = last_name;
}

void MutableEmployee::SetSalary(const double& salary) {
	m_salary = salary;
}
