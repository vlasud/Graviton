cmake_minimum_required(VERSION 3.9)

project(3d_shooter_render)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

add_library(${PROJECT_NAME} SHARED
	render.cpp
)