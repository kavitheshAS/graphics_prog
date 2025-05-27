#minimum CMake version required for this project
cmake_minimum_required(VERSION 3.10)

#define the project name.This name will be used for your build target
project(GRAPHICS_PROG)

#set the c++ standard to c++17
set(CMAKE_CXX_STANDARD 17)

# Find required libraries
# These commands search for the installed libraries on your system.
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

#Adds OpenGL headers to include path
include_directories(${OPENGL_INCLUDE_DIRS})

file(GLOB SOURCES "src/*.cpp") #finds all .cpp files in src/
#you can also manually mention all the files in above line

#set(SOURCES
#   src/test_window.cpp
#   src/triangle.cpp
# )

#Defines binary target and its source(s)
# add_executable(OpenGLTriangle ${SOURCES})
#the above line builds multiple cpp files to one, that means it will fail if there are multiple main() functions

# Executable for black window
add_executable(test_window src/test_window.cpp)
target_link_libraries(test_window
    GLEW::GLEW
    glfw
    OpenGL::GL
)

# Executable for triangle renderer
add_executable(triangle src/triangle.cpp)
target_link_libraries(triangle
    GLEW::GLEW
    glfw
    OpenGL::GL
)


