/*******************************************************************************
 * @brief		customer module
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.30	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <algorithm>
#include "customer.h"

/* Class Declarations --------------------------------------------------------*/
std::vector<std::string> Customer::GetActiveCustomerNames(std::vector<Customer> customers) {
	return Customer::GetActiveCustomerByFunctionField<std::string>(
		customers, std::make_shared<CustomerName>()
	);
}

std::vector<std::string> Customer::GetActiveCustomerAddresses(std::vector<Customer> customers) {
	return Customer::GetActiveCustomerByFunctionField<std::string>(
		customers, std::make_shared<CustomerAddress>()
	);
}

std::vector<std::string> Customer::GetActiveCustomerPhones(std::vector<Customer> customers) {
	return Customer::GetActiveCustomerByFunctionField<std::string>(
		customers, std::make_shared<CustomerPhone>()
	);
}

std::vector<std::string> Customer::GetActiveCustomerEmails(std::vector<Customer> customers) {
	return Customer::GetActiveCustomerByFunctionField<std::string>(
		customers, std::make_shared<CustomerEmail>()
	);
}

int Customer::CountActiveCustomers(std::vector<Customer> customers) {
	if (customers.empty()) {
		return 0;
	} else {
		int add = customers.front().isActive ? 1 : 0;
		customers.erase(customers.begin());
		return add + CountActiveCustomers(customers);
	}
}

template<typename T>
std::vector<T> Customer::GetActiveCustomerByFunctionField(
	std::vector<Customer> customers, const std::shared_ptr<BaseClass<Customer, T>>& classField
) {
	std::vector<Customer> activeCustomers;
	std::vector<T> list;
	std::copy_if(customers.begin(), customers.end(), std::back_inserter(activeCustomers),
		[](Customer customer) {
		if (customer.isActive) {
			return true;
		} else {
			return false;
		}
	});
	for_each (activeCustomers.begin(), activeCustomers.end(), [&list, &classField](Customer customer) {
		list.push_back(classField->InvokeFunction(std::make_shared<Customer>(customer)));
	});
	return list;
}
