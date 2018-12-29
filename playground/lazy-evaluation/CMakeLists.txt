cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project(lazy-evaluation)

file (GLOB SRCS
	lazy-evaluation.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
