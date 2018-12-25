cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project(immutability)

file (GLOB SRCS
	MutableEmployee.cpp
	ImmutableEmployee.cpp
	immutability.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
