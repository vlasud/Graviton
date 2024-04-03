cmake_minimum_required(VERSION 3.10)

project(3d_shooter_render)

add_library(${PROJECT_NAME}
	render.cpp
	shaders.cpp
	mesh.cpp)