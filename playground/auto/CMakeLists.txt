cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project(auto)

file (GLOB SRCS
	auto.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
