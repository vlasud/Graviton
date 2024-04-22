cmake_minimum_required(VERSION 3.10)

project(graviton_utils)

add_library(${PROJECT_NAME}
	stringUtils.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ../../include)

# OpenGL
target_include_directories(${PROJECT_NAME} PUBLIC ../../third_party/glfw/include)
target_include_directories(${PROJECT_NAME} PUBLIC ../../third_party/glfw/deps)

# GLM
target_include_directories(${PROJECT_NAME} PUBLIC ../../third_party/glm)