cmake_minimum_required(VERSION 3.17)
project(CS_454)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lgmp")

include_directories(usr/include)

add_executable(CS_454 main.cpp DFA.cpp DFA.h State.cpp State.h)

target_link_libraries(CS_454 gmp gmpxx)
