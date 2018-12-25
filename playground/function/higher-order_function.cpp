/*******************************************************************************
 * @brief		Higher-order function in modern C++
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.24	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>

/* Main Routine --------------------------------------------------------------*/
auto HigherOrderFunction() -> int {
	// Higher-order Function: Map
	std::vector<int> v1;
	for (int i = 0; i < 5; ++i) {
		v1.push_back(i);
	}
	std::vector<int> v2;
	v2.resize(v1.size());
	std::transform(std::begin(v1), std::end(v1), std::begin(v2), [](int i) {
		return i * i;
	});
	std::cout << "v1 contains";
	for (auto v : v1) {
		std::cout << "  " << v;
	}
	std::cout << std::endl;
	std::cout << "v2 contains";
	for (auto v : v2) {
		std::cout << "  " << v;
	}
	std::cout << std::endl << std::endl;

	// Higher-order Function: Filter
	std::vector<int> numbers;
	for (int i = 0; i < 20; ++i) {
		numbers.push_back(i);
	}
	std::cout << "The original numbers" << std::endl;
	copy(std::begin(numbers), std::end(numbers), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::vector<int> primes;
	std::copy_if(std::begin(numbers), std::end(numbers), std::back_inserter(primes), [](int n) {
		if (n < 2) {
			return (n != 0) ? true : false;
		} else {
			for (int j = 2; j < n; ++j) {
				if (n % j == 0) {
					return false;
				}
			}
			return true;
		}
	});
	std::cout <<  "The primes numbers" << std::endl;
	copy(std::begin(primes), std::end(primes), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::vector<int> non_primes;
	std::remove_copy_if(numbers.begin(), numbers.end(), std::back_inserter(non_primes), [](int n) {
		if (n < 2) {
			return (n != 0) ? true : false;
		} else {
			for (int j = 2; j < n; ++j) {
				if (n % j == 0) {
					return false;
				}
			}
			return true;
		}
	});
	std::cout <<  "The non-primes numbers" << std::endl;
	copy(std::begin(non_primes), std::end(non_primes), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl << std::endl;

	// Higher-order Function: Fold
	numbers = {0, 1, 2, 3, 4};
	auto foldl = std::accumulate(std::begin(numbers), std::end(numbers), 0, std::plus<int>());
	auto foldr = std::accumulate(std::rbegin(numbers), std::rend(numbers), 0, std::plus<int>());
	std::cout << "fold left result = " << foldl << std::endl;
	std::cout << "fold right result = " << foldr << std::endl;
	std::cout << std::endl;

	return 0;
}
