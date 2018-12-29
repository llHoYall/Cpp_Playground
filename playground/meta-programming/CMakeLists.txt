cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project(meta-programming)

file (GLOB SRCS
	type.cpp
	if-else.cpp
	switch.cpp
	do-while.cpp
	value.cpp
	class.cpp
	meta-programming.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
