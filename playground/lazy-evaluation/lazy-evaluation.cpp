/*******************************************************************************
 * @brief		Lazy evaluation in modern C++
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.27	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <functional>
#include <cmath>
#include "lazy-evaluation.h"

/* Private Functions ---------------------------------------------------------*/
static int OuterFormula(int x, int y, int z, std::function<int(int, int)> yzFunc) {
	std::cout << "Calculate " << x << " + InnerFormula(" << y << ", " << z << ")" << std::endl;
	return x + yzFunc(y, z);
}

static int InnerFormula(int y, int z) {
	std::cout << "Calculate " << y << " * " << z << std::endl;
	return y * z;
}

static Row<void*> PrimeCheck(int i) {
	if ((i % 2) == 0) {
		if (i == 2) {
			return Row<void*>(nullptr);
		} else {
			return Row<void*>();
		}
	}

	int sqr = sqrt(i);
	for (int t = 3; t <= sqr; t += 2) {
		if (i % t == 0) {
			return Row<void*>();
		}
	}

	if (i == 1) {
		return Row<void*>();
	} else {
		return Row<void*>(nullptr);
	}
}

static Row<int> GenerateInfiniteIntRow(int initial_number) {
	return Row<int>([initial_number]() {
		return Chunk<int>(initial_number, GenerateInfiniteIntRow(initial_number + 1));
	});
}

template<class T, class U>
static auto MappingRow(Row<T> row, U fn) -> Row<decltype(fn(row.Fetch()))> {
	using V = decltype(fn(row.Fetch()));
	if (row.IsEmpty()) {
		return Row<V>();
	}
	return Row<V>([row, fn]() {
		return Chunk<V>(fn(row.Fetch()), MappingRow(row.ShiftLastToFirst(), fn));
	});
}

template<class T, class U> static auto MappingRowByValue(Row<T> row, U fn) -> Row<decltype(fn())> {
	using v = decltype(fn());
	if (row.IsEmpty()) {
		return Row<v>();
	}

	return Row<v>([row, fn]() {
		return Chunk<v>(fn(), MappingRowByValue(row.ShiftLastToFirst(), fn));
	});
}

template<class T> static Row<T> ConvertChunkToRow(T value) {
	return Row<T>([value]() {
		return Chunk<T>(value);
	});
}

template<class T> static Row<T> JoiningAllRows(Row<Row<T>> row_of_rows) {
	while (!row_of_rows.IsEmpty() && row_of_rows.Fetch().IsEmpty()) {
		row_of_rows = row_of_rows.ShiftLastToFirst();
	}

	if (row_of_rows.IsEmpty()) {
		return Row<T>();
	}
	return Row<T>([row_of_rows]() {
		Row<T> row = row_of_rows.Fetch();
		return Chunk<T>(row.Fetch(), ConcatenateRows(row.ShiftLastToFirst(), JoiningAllRows(row_of_rows.ShiftLastToFirst())));
	});
}

template<class T, class U> static Row<T> Binding(Row<T> row, U fn) {
	return JoiningAllRows(MappingRow(row, fn));
}

template<class T, class U> static auto JoiningPrimeNumber(Row<T> row, U fn) -> decltype(fn()) {
	return JoiningAllRows(MappingRowByValue(row, fn));
}

static Row<int> GenerateInfinitePrimeRow(void) {
	return Binding(GenerateInfiniteIntRow(1), [](int i) {
		return JoiningPrimeNumber(PrimeCheck(i), [i]() {
			return ConvertChunkToRow(i);
		});
	});
}

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[lazy-evaluation.cpp]" << std::endl;

	// Lazy Evaluation
	int x = 4;
	int y = 3;
	int z = 2;
	std::cout << "Calculate " << x << " + " << "(" << y << " * " << z << ")" << std::endl;
	int result = OuterFormula(x, y, z, InnerFormula);
	std::cout << x << " + " << "(" << y << " * " << z << ") = " << result << std::endl;
	std::cout << std::endl;

	// 처리 흐름 늦추기
	int a = 10;
	int b = 5;
	std::cout << "Constructing Delay<> named multiply" << std::endl;
	Delay<int> multiply_delay([a, b]() {
		std::cout << "Delay<> named multiply is constructed." << std::endl;
		return a * b;
	});
	std::cout << "Constructing Delay<> named division" << std::endl;
	Delay<int> division_delay([a, b]() {
		std::cout << "Delay<> named division is constructed." << std::endl;
		return a / b;
	});
	std::cout << "Invoking Fetch() method in multiply instance." << std::endl;
	int c = multiply_delay.Fetch();
	std::cout << "Invoking Fetch() method in division instance." << std::endl;
	int d = division_delay.Fetch();
	std::cout << "The result of a * b = " << c << std::endl;
	std::cout << "The result of a / b = " << d << std::endl;
	std::cout << std::endl;

	// Memoization으로 값 caching
	a = 10;
	b = 5;
	int multiplier = 0;
	Memoization<int> multiply_memoization([&]() {
		return multiplier * a * b;
	});
	for (int i = 0; i < 5; ++i) {
		++multiplier;
		std::cout << "Multiplier = " << multiplier << std::endl;
		std::cout << "a * b = " << multiply_memoization.Fetch() << std::endl;
	}
	std::cout << std::endl;

	// 지연 평가 code 만들기
	int n = 0;
	std::cout << "List of the first 100 prime numbers" << std::endl;
	Row<int> r = GenerateInfinitePrimeRow();
	Row<int> first_100_prime_numbers = r.Pick(100);
	ForEach(std::move(first_100_prime_numbers), [](int const& i) {
		std::cout << "  " << i;
	});

	return 0;
}
