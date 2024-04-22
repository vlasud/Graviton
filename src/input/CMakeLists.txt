cmake_minimum_required(VERSION 3.10)

project(graviton_input)

add_library(${PROJECT_NAME}
	input.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ../../include)

# OpenGL
target_include_directories(${PROJECT_NAME} PUBLIC ../../third_party/glfw/include)
target_include_directories(${PROJECT_NAME} PUBLIC ../../third_party/glfw/deps)

# GLM
target_include_directories(${PROJECT_NAME} PUBLIC ../../third_party/glm)