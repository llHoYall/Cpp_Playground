/*******************************************************************************
 * @brief		Recursion in modern C++
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.26	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <unistd.h>

/* Private Variables ---------------------------------------------------------*/
const int rows = 8;
const int cols = 8;

/* Private Functions ---------------------------------------------------------*/
static int Factorial_Iteration(int n) {
	int result = 1;

	// do-while
	// int i = 1;
	// do {
	// 	result *= i;
	// } while (++i <= n);

	// for
	for (int i = 1; i <= n; ++i) {
		result *= i;
	}

	return result;
}

static int Factorial_Recursion(int n) {
	if (n == 0) {
		return 1;
	} else {
		return n * Factorial_Recursion(n - 1);
	}
}

static int Factorial_TailRecursion(int n, int i) {
	if (n == 0) {
		return i;
	}
	return Factorial_TailRecursion(n - 1, n * i);
}

static int Fibonacci_Iteration(int n) {
	if (n == 0) {
		return 0;
	}

	int previous = 0;
	int current = 1;
	for (int i = 1; i < n; ++i) {
		int next = previous + current;
		previous = current;
		current = next;
	}
	return current;
}

static int Fibonacci_Recursion(int n) {
	if (n <= 1) {
		return n;
	}
	return Fibonacci_Recursion(n - 1) + Fibonacci_Recursion(n - 2);
}

static int Power(int base, int exp) {
	if (exp == 0) {
		return 1;
	} else {
		return base * Power(base, exp - 1);
	}
}

static void DoPermute(const std::string& chosen, const std::string& remaining) {
	if (remaining == "") {
		std::cout << "  " << chosen << std::endl;
	} else {
		for (uint32_t u = 0; u < remaining.length(); ++u) {
			DoPermute(chosen + remaining[u], remaining.substr(0, u) + remaining.substr(u + 1));
		}
	}
}

static void Permute(const std::string& s) {
	DoPermute("", s);
}

static std::vector<std::vector<char>> CreateLabyrinth(void) {
	std::vector<std::vector<char>> labyrinth = {
		{ '#', '#', '#', '#', '#', '#', '#', '#' },
		{ '#', 'S', ' ', ' ', ' ', ' ', ' ', '#' },
		{ '#', '#', '#', ' ', '#', '#', '#', '#' },
		{ '#', ' ', '#', ' ', '#', '#', '#', '#' },
		{ '#', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
		{ '#', ' ', '#', '#', '#', '#', '#', '#' },
		{ '#', ' ', ' ', ' ', ' ', ' ', 'F', '#' },
		{ '#', '#', '#', '#', '#', '#', '#', '#' }
	};
	return labyrinth;
}

static void DisplayLabyrinth(std::vector<std::vector<char>> labyrinth) {
	std::cout << "====================" << std::endl;
	std::cout << "The Labyrinth" << std::endl;
	std::cout << "====================" << std::endl;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			std::cout << " " << labyrinth[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << "====================" << std::endl << std::endl;
}

static bool Navigate(std::vector<std::vector<char>> labyrinth, int row, int col) {
	DisplayLabyrinth(labyrinth);
	std::cout << "Checking cell (" << row << ", " << col << ")" << std::endl;
	sleep(1);

	if (labyrinth[row][col] == 'F') {
		std::cout << "Congratulations!" << std::endl;
		std::cout << "  Point (" << row << ", " << col << ")" << std::endl;
		return true;
	} else if (labyrinth[row][col] == '#' || labyrinth[row][col] == '*') {
		return false;
	} else if (labyrinth[row][col] == ' ') {
		labyrinth[row][col] = '*';
	}

	if ((row + 1 < rows) && Navigate(labyrinth, row + 1, col)) {
		return true;
	}
	if ((col + 1 < cols) && Navigate(labyrinth, row, col + 1)) {
		return true;
	}
	if ((row - 1 >= 0) && Navigate(labyrinth, row - 1, col)) {
		return true;
	}
	if ((col - 1 >= 0) && Navigate(labyrinth, row, col - 1)) {
		return true;
	}

	return false;
}

static bool IsLabyrinthSolvable(std::vector<std::vector<char>> labyrinth) {
	int start_row = -1;
	int start_col = -1;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (labyrinth[i][j] == 'S') {
				start_row = i;
				start_col = j;
				break;
			}
		}
	}

	if (start_row == -1 || start_col == -1) {
		std::cerr << "No valid starting point found!" << std::endl;
		return false;
	}

	std::cout << "Starting point at (" << start_row << ", " << start_col << ")" << std::endl;

	return Navigate(labyrinth, start_row, start_col);
}

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[recursion.cpp]" << std::endl << std::endl;

	// Iteration: Factorial
	for (int i = 1; i < 10; ++i) {
		std::cout << i << "! = " << Factorial_Iteration(i) << std::endl;
	}
	std::cout << std::endl;

	// Recursion: Factorial
	for (int i = 1; i < 10; ++i) {
		std::cout << i << "! = " << Factorial_Recursion(i) << std::endl;
	}
	std::cout << std::endl;

	// Tail Recursion: Factorial
	for (int i = 1; i < 10; ++i) {
		std::cout << i << "! = " << Factorial_TailRecursion(i, 1) << std::endl;
	}
	std::cout << std::endl;

	// Iteration: Fibonacci
	for (int i = 0; i < 10; ++i) {
		std::cout << Fibonacci_Iteration(i) << " ";
	}
	std::cout << std::endl << std::endl;

	// Recursion: Fibonacci
	for (int i = 0; i < 10; ++i) {
		std::cout << Fibonacci_Recursion(i) << " ";
	}
	std::cout << std::endl << std::endl;

	// Functional Recursion
	for (int i = 0; i <= 5; ++i) {
		std::cout << "Power (2, " << i << ") = " << Power(2, i) << std::endl;
	}
	std::cout << std::endl;

	// Procedural Recursion
	std::string str;
	std::cout << "Permutation of a string" << std::endl;
	std::cout << "Enter a string: ";
	getline(std::cin, str);
	std::cout << "The possibility permutation of " << str << std::endl;
	Permute(str);
	std::cout << std::endl;

	// Back Tracking Recursion
	std::vector<std::vector<char>> labyrinth = CreateLabyrinth();
	DisplayLabyrinth(labyrinth);
	std::cout << "Press enter to continue..." << std::endl;
	std::string line;
	getline(std::cin, line);
	if (IsLabyrinthSolvable(labyrinth)) {
		std::cout << "  Labyrinth is solved!" << std::endl;
	} else {
		std::cout << "  Labyrinth could not be solved!" << std::endl;
	}

	return 0;
}
