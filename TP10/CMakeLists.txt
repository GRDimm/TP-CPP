cmake_minimum_required(VERSION 3.20)

project(td10)

set(CMAKE_CXX_STANDARD 11)

add_compile_definitions(_USE_MATH_DEFINES)

add_executable(exo11 1.1.h 1.1.cc 1.1.test.cc main_utils.h)
add_executable(exo12 1.2.h 1.2.cc 1.2.test.cc main_utils.h)
add_executable(exo13 1.3.h 1.3.cc 1.3.test.cc main_utils.h)


add_executable(exo21 2.1.h 2.1.cc 2.1.test.cc main_utils.h)
add_executable(exo22 2.2.h 2.2.cc 2.2.test.cc main_utils.h)
add_executable(exo23 2.3.h 2.3.cc 2.3.test.cc main_utils.h)