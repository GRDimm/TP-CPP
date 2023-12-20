cmake_minimum_required(VERSION 3.20)
project(td4)

set(CMAKE_CXX_STANDARD 11)

add_library(student student.h student.cc)
add_library(class class.h class.cc)
add_library(io io.h io.cc)

add_executable(main main.cc)
target_link_libraries(main PRIVATE io class student)

