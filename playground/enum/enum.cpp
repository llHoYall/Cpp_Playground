/* Include Headers -----------------------------------------------------------*/
#include <iostream>

/* Enumeration ---------------------------------------------------------------*/
enum class Color {
	red, green, blue
};
enum class TrafficLight {
	red, yellow, green
};
enum Name {
	Kim, Lee, Park
};

/* Private Function Prototypes -----------------------------------------------*/
static TrafficLight& operator++(TrafficLight&);
template<typename T>
static std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type&, const T&);

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[enum.cpp]" << std::endl;

	Color c = Color::red;
	TrafficLight tl = TrafficLight::red;
	// int i = Color::green;		// Error!
	int i = Kim;

	std::cout << "Color: " << c << std::endl;
	std::cout << "TrafficLight: " << tl << std::endl;
	std::cout << "Name: " << i << std::endl;

	TrafficLight next = ++tl;

	std::cout << "TrafficLight: " << next << std::endl;

	return 0;
}

/* Private Functions ---------------------------------------------------------*/
static TrafficLight& operator++(TrafficLight& tl) {
	switch (tl) {
		case TrafficLight::red:
			return tl = TrafficLight::green;

		case TrafficLight::yellow:
			return tl = TrafficLight::red;

		case TrafficLight::green:
			return tl = TrafficLight::yellow;
	}
}

template<typename T>
static std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e)
{
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}
