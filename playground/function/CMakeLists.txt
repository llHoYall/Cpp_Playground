cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project(function)

file (GLOB SRCS
	first-class_function.cpp
	higher-order_function.cpp
	pure_function.cpp
	currying.cpp
	function.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
