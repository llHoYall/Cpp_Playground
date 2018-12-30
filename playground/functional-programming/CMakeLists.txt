cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g")

project(functional-programming)

file (GLOB SRCS
	customer.cpp
	functional-programming.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
