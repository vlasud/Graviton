cmake_minimum_required(VERSION 3.10)

project(3d_shooter_core)

add_library(${PROJECT_NAME}
  engine.cpp  
  object.cpp
  scene.cpp
  filesystem.cpp)