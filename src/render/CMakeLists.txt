cmake_minimum_required(VERSION 3.10)

project(graviton_render)

add_library(${PROJECT_NAME}
	renderer.cpp
	shader.cpp
	mesh.cpp
	objFile.cpp)


target_include_directories(${PROJECT_NAME} PUBLIC ../../include)

# OpenGL
target_include_directories(${PROJECT_NAME} PUBLIC ../../third_party/glfw/include)
target_include_directories(${PROJECT_NAME} PUBLIC ../../third_party/glfw/deps)

# GLM
target_include_directories(${PROJECT_NAME} PUBLIC ../../third_party/glm)