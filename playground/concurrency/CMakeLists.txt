cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project(concurrency)

file (GLOB SRCS
	single-thread.cpp
	multi-thread.cpp
	mutex.cpp
	deadlock.cpp
	concurrency.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
