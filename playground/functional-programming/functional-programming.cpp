/*******************************************************************************
 * @brief		Functional programming in modern C++
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.30	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include "customer.h"
#include "memoization.h"

/* Private Functions ---------------------------------------------------------*/
static std::vector<Customer> RegisterCustomers() {
	int id = 0;
	bool b = false;

	std::vector<std::string> nameList = {
		"Aden",
		"Baron",
		"Chrono",
		"Dresden",
		"Epic",
		"Faker"
	};

	std::vector<Customer> ret;
	for (auto name : nameList) {
		Customer c;
		c.id = ++id;
		c.name = name;
		c.address = "somewhere";
		c.phone = "010";
		c.email = name + "@xyz.com";
		c.isActive = b;

		b = !b;

		ret.push_back(c);
	}
	return ret;
}

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[functional-programming.cpp]" << std::endl << std::endl;

	auto start = std::chrono::high_resolution_clock::now();

	Customer customer;
	std::cout << "> Total active customers" << std::endl;
	std::cout << "    " << customer.CountActiveCustomers(RegisterCustomers()) << std::endl;
	Memoization<std::vector<std::string>> customerMemo([customer]() {
		return customer.GetActiveCustomerNames(RegisterCustomers());
	});

	std::cout << "> List of active customer names" << std::endl;
	std::vector<std::string> activeCustomerNames = customerMemo.Fetch();
	for (auto name : activeCustomerNames) {
		std:: cout << "    " << name << std::endl;
	}

	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed = finish - start;
	std::cout << "> Total consuming time = " << elapsed.count() << " milliseconds" << std::endl;

	return 0;
}
