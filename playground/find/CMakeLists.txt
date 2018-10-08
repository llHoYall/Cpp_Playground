cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project(find)

file (GLOB SRCS
	find.cpp
	vehicle.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
