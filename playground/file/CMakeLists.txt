cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project(file)

file (GLOB SRCS
	file.cpp
	fstream.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
