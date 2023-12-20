cmake_minimum_required(VERSION 3.20)
project(td5)


set(CMAKE_CXX_STANDARD 11)


add_executable(exo2_1
  2.1.h
  2.1.cc
  2.1.main.cc
)

add_library(exo2_2
  2.2.h
  2.2.cc
)

add_executable(exo2_2_main
  2.2.main.cc)

target_link_libraries(exo2_2_main
  exo2_2)

add_executable(exo2_3
  2.3.h
  2.3.cc
  2.3.main.cc
)

target_link_libraries(exo2_3
  exo2_2
)

add_executable(exo3_1
  3.1.h
  3.1.cc
  3.1.main.cc
)

add_executable(exo3_2
  3.1.h
  3.1.cc
  3.2.main.cc
)

add_executable(exo3_3
  3.1.h
  3.1.cc
  3.3.main.cc
)