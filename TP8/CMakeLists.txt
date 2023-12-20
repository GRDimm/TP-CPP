cmake_minimum_required(VERSION 3.20)

project(td8)

set(CMAKE_CXX_STANDARD 11)


add_executable(exo11 1.1.h 1.1.cc 1.1.test.cc main_utils.h)
add_executable(exo12 1.2.h 1.2.cc 1.2.test.cc main_utils.h)
add_executable(exo133 1.3.h 1.3.cc 1.3.3.test.cc main_utils.h)
add_executable(exo14 1.4.h 1.4.cc 1.4.test.cc main_utils.h)
add_executable(exo15 1.4.h 1.4.cc 1.5.test.cc main_utils.h matrix_ops.h matrix_ops.cc)
add_executable(exo16 1.4.h 1.4.cc 1.6.test.cc main_utils.h matrix_ops.h matrix_ops.cc)
add_executable(exo17 1.4.h 1.4.cc 1.7.test.cc main_utils.h matrix_ops.h matrix_ops.cc)