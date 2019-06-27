cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)

project(time)

file (GLOB SRCS
	time_chrono.cpp
	time.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
