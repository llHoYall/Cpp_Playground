/*******************************************************************************
 * @brief		Mutable employee module
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.25	Created.
 ******************************************************************************/

#ifndef __MUTABLE_EMPLOYEE_H__
#define __MUTABLE_EMPLOYEE_H__

/* Include Headers -----------------------------------------------------------*/
#include <string>

/* Class Declarations --------------------------------------------------------*/
class MutableEmployee {
private:
	int m_id;
	std::string m_first_name;
	std::string m_last_name;
	double m_salary;

public:
	MutableEmployee(void);
	MutableEmployee(const int& id, const std::string& first_name, const std::string& last_name, const double& salary);

	void SetId(const int id);
	void SetFirstName(const std::string& first_name);
	void SetLastName(const std::string& last_name);
	void SetSalary(const double& salary);

	int GetId(void) const {
		return m_id;
	}

	std::string GetFirstName(void) const {
		return m_first_name;
	}

	std::string GetLastName(void) const {
		return m_last_name;
	}

	double GetSalary(void) const {
		return m_salary;
	}
};

#endif
