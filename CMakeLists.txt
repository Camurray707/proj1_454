cmake_minimum_required(VERSION 3.17)
project(problem1)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lgmp")

#include_directories(./gmp)

add_executable(problem1 problem1.cpp DFA.cpp DFA.h)

target_link_libraries(problem1 gmp gmpxx)
