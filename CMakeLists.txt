cmake_minimum_required(VERSION 3.10)

project(3d_shooter)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

add_executable(${PROJECT_NAME} WIN32
	src/main.cpp
)

include_directories(include)

# SDL
add_subdirectory(third_party/SDL EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
include_directories(third_party/SDL/include)

# Render
add_subdirectory(src/render)
target_link_libraries(${PROJECT_NAME} PRIVATE 3d_shooter_render)