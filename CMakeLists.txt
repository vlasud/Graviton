cmake_minimum_required(VERSION 3.10)

project(graviton)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

add_library(${PROJECT_NAME} third_party/glfw/deps/glad_gl.c)

# GLFW
add_subdirectory(third_party/glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC OpenGL::GL)

# GLM
target_include_directories(${PROJECT_NAME} PUBLIC third_party/glm)

# Render
add_subdirectory(src/render)
target_link_libraries(${PROJECT_NAME} PUBLIC graviton_render)

# Input
add_subdirectory(src/input)
target_link_libraries(${PROJECT_NAME} PUBLIC graviton_input)

# Core
add_subdirectory(src/core)
target_link_libraries(${PROJECT_NAME} PUBLIC graviton_core)

# Utils
add_subdirectory(src/utils)
target_link_libraries(${PROJECT_NAME} PUBLIC graviton_utils)