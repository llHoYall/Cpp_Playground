cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project(enum)

file (GLOB SRCS
	enum.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
