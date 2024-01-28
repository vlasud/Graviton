cmake_minimum_required(VERSION 3.9)

project(3d_shooter)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

add_executable(${PROJECT_NAME} WIN32 src/main.cpp)

include_directories(include)

# GLFW
add_subdirectory(third_party/glfw)
include_directories(third_party/glfw/include)
include_directories(third_party/glfw/deps)
target_link_libraries(${PROJECT_NAME} glfw)

# Render
add_subdirectory(src/render)
target_link_libraries(${PROJECT_NAME} 3d_shooter_render)