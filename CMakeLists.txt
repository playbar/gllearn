cmake_minimum_required(VERSION 3.4.1)
project(glfwassimp LANGUAGES CXX C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fexceptions")

add_subdirectory(opencv)
add_subdirectory(assimp)
add_subdirectory(glfw)
add_subdirectory(assimpmodel)


