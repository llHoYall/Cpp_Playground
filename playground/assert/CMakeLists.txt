cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project(assert)

file (GLOB SRCS
	assert.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
