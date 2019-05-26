cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project(const)

file (GLOB SRCS
	const.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
