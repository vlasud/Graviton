cmake_minimum_required(VERSION 3.10)

project(graviton_core)

add_library(${PROJECT_NAME}
  engine.cpp  
  object.cpp
  scene.cpp
  filesystem.cpp)


  target_include_directories(${PROJECT_NAME} PUBLIC ../../include)

  # OpenGL
  target_include_directories(${PROJECT_NAME} PUBLIC ../../third_party/glfw/include)
  target_include_directories(${PROJECT_NAME} PUBLIC ../../third_party/glfw/deps)
  
  # GLM
  target_include_directories(${PROJECT_NAME} PUBLIC ../../third_party/glm)