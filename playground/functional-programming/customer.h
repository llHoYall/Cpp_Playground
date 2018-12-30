/*******************************************************************************
 * @brief		customer module
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.30	Created.
 ******************************************************************************/

#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

/* Include Headers -----------------------------------------------------------*/
#include <string>
#include <vector>
#include <memory>

/* Class Declarations --------------------------------------------------------*/
class Customer {
private:
	template<typename T, typename U>
	class BaseClass {
	public:
		virtual U InvokeFunction(const std::shared_ptr<T>&) = 0;
	};

	class CustomerName: public BaseClass<Customer, std::string> {
	public:
		virtual std::string InvokeFunction(const std::shared_ptr<Customer>& customer) {
			return customer->name;
		}
	};

	class CustomerAddress: public BaseClass<Customer, std::string> {
	public:
		virtual std::string InvokeFunction(const std::shared_ptr<Customer>& customer) {
			return customer->address;
		}
	};

	class CustomerPhone: public BaseClass<Customer, std::string> {
	public:
		virtual std::string InvokeFunction(const std::shared_ptr<Customer>& customer) {
			return customer->phone;
		}
	};

	class CustomerEmail: public BaseClass<Customer, std::string> {
	public:
		virtual std::string InvokeFunction(const std::shared_ptr<Customer>& customer) {
			return customer->email;
		}
	};

public:
	static std::vector<Customer> registeredCustomers;
	int id = 0;
	std::string name;
	std::string address;
	std::string phone;
	std::string email;
	bool isActive = true;

	static std::vector<std::string> GetActiveCustomerNames(std::vector<Customer> customers);
	static std::vector<std::string> GetActiveCustomerAddresses(std::vector<Customer> customers);
	static std::vector<std::string> GetActiveCustomerPhones(std::vector<Customer> customers);
	static std::vector<std::string> GetActiveCustomerEmails(std::vector<Customer> customers);

	static int CountActiveCustomers(std::vector<Customer> customers);

	template<typename T>
	static std::vector<T> GetActiveCustomerByFunctionField(
		std::vector<Customer> customer, const std::shared_ptr<BaseClass<Customer, T>>& classField
	);
};

#endif
