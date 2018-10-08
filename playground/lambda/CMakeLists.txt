cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project(lambda)

file (GLOB SRCS
	lambda.cpp
	vehicle.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
