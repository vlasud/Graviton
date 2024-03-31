cmake_minimum_required(VERSION 3.10)

project(3d_shooter)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

add_executable(${PROJECT_NAME} WIN32
	src/main.cpp

	third_party/glfw/deps/glad_gl.c "include/render/shaders.h")

include_directories(include)

# GLFW
add_subdirectory(third_party/glfw)
link_libraries(glfw)
include_directories(third_party/glfw/include)
include_directories(third_party/glfw/deps)

find_package(OpenGL REQUIRED)
link_libraries(OpenGL::GL)

# GLM
include_directories(third_party/glm)

# Render
add_subdirectory(src/render)
target_link_libraries(${PROJECT_NAME} PRIVATE 3d_shooter_render)

# Input
add_subdirectory(src/input)
target_link_libraries(${PROJECT_NAME} PRIVATE 3d_shooter_input)

# Core
add_subdirectory(src/core)
target_link_libraries(${PROJECT_NAME} PRIVATE 3d_shooter_core)