cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project(for_each)

file (GLOB SRCS
	for_each.cpp
	vehicle.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
