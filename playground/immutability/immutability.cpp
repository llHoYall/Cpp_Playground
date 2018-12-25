/*******************************************************************************
 * @brief		Immutability in modern C++
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.25	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include "MutableEmployee.h"
#include "ImmutableEmployee.h"

/* Class Declarations --------------------------------------------------------*/
class Value {
public:
	const int value;
	Value(int v) : value(v) {
	}
};

class Function {
public:
	const int x;
	const int y;

	Function(int _x, int _y) : x(_x), y(_y) {
	}

	Value Addition(void) const {
		return Value(x + y);
	}

	Value Subtraction(void) const {
		return Value(x - y);
	}

	Value Multiplication(void) const {
		return Value(x * y);
	}

	Value Division(void) const {
		return Value(x / y);
	}
};

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[immutability.cpp]" << std::endl;

	// Immutable Object
	int a = 100;
	int b = 10;
	std::cout << "Initial Value" << std::endl;
	std::cout << "  a = " << a << ", b = " << b << std::endl;
	Function func(a, b);
	auto CallableAdd = std::mem_fn(&Function::Addition);
	auto CallableSub = std::mem_fn(&Function::Subtraction);
	auto CallableMul = std::mem_fn(&Function::Multiplication);
	auto CallableDiv = std::mem_fn(&Function::Division);
	auto value1 = CallableAdd(func);
	auto value2 = CallableSub(func);
	auto value3 = CallableMul(func);
	auto value4 = CallableDiv(func);
	std::cout << "The result" << std::endl;
	std::cout << "  Addition = " << value1.value << std::endl;
	std::cout << "  Subtraction = " << value2.value << std::endl;
	std::cout << "  Multiplication = " << value3.value << std::endl;
	std::cout << "  Division = " << value4.value << std::endl;
	std::cout << std::endl;

	// Mutable Class
	std::string first = "Abraham";
	std::string last = "Lincoln";
	double d = 1500.0;
	MutableEmployee he(0, first, last, d);
	std::cout << "Content of MutableEmployee instance" << std::endl;
	std::cout << "  ID : " << he.GetId() << std::endl;
	std::cout << "  Name : " << he.GetFirstName() << " " << he.GetLastName() << std::endl;
	std::cout << "  Salary : " << he.GetSalary() << std::endl;
	he.SetId(1);
	he.SetFirstName("aaa");
	he.SetLastName("bbb");
	he.SetSalary(2100.0);
	std::cout << "Content of MutableEmployee instance" << std::endl;
	std::cout << "  ID : " << he.GetId() << std::endl;
	std::cout << "  Name : " << he.GetFirstName() << " " << he.GetLastName() << std::endl;
	std::cout << "  Salary : " << he.GetSalary() << std::endl;

	// Immutable Class
	first = "Barbara";
	last = "Palvin";
	d = 1500.0;
	ImmutableEmployee she(0, first, last, d);
	std::cout << "Content of ImmutableEmployee instance" << std::endl;
	std::cout << "  ID : " << she.GetId() << std::endl;
	std::cout << "  Name : " << she.GetFirstName() << " " << she.GetLastName() << std::endl;
	std::cout << "  Salary : " << she.GetSalary() << std::endl;
	ImmutableEmployee she2 = she.SetId(1);
	ImmutableEmployee she3 = she2.SetFirstName("xxx");
	ImmutableEmployee she4 = she3.SetLastName("yyy");
	ImmutableEmployee she5 = she4.SetSalary(2345.6);
	std::cout << "Content of ImmutableEmployee instance" << std::endl;
	std::cout << "  ID : " << she5.GetId() << std::endl;
	std::cout << "  Name : " << she5.GetFirstName() << " " << she5.GetLastName() << std::endl;
	std::cout << "  Salary : " << she5.GetSalary() << std::endl;

	return 0;
}
