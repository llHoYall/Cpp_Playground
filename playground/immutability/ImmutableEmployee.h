/*******************************************************************************
 * @brief		Immutable employee module
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.25	Created.
 ******************************************************************************/

#ifndef __IMMUTABLE_EMPLOYEE_H__
#define __IMMUTABLE_EMPLOYEE_H__

/* Include Headers -----------------------------------------------------------*/
#include <string>

/* Class Declarations --------------------------------------------------------*/
class ImmutableEmployee {
private:
	const int m_id;
	const std::string m_first_name;
	const std::string m_last_name;
	const double m_salary;

public:
	ImmutableEmployee(void);
	ImmutableEmployee(const int& id, const std::string& first_name, const std::string& last_name, const double& salary);
	~ImmutableEmployee(void) {};

	const int& GetId(void) const {
		return m_id;
	}

	const std::string& GetFirstName(void) const {
		return m_first_name;
	}

	const std::string& GetLastName(void) const {
		return m_last_name;
	}

	const double& GetSalary(void) const {
		return m_salary;
	}

	const ImmutableEmployee SetId(const int& id) const {
		return ImmutableEmployee(id, m_first_name, m_last_name, m_salary);
	}

	const ImmutableEmployee SetFirstName(const std::string& first_name) const {
		return ImmutableEmployee(m_id, first_name, m_last_name, m_salary);
	}

	const ImmutableEmployee SetLastName(const std::string& last_name) const {
		return ImmutableEmployee(m_id, m_first_name, last_name, m_salary);
	}

	const ImmutableEmployee SetSalary(const double& salary) const {
		return ImmutableEmployee(m_id, m_first_name, m_last_name, salary);
	}
};

#endif
