cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
add_definitions(-D_GLIBCXX_USE_CXX14_ABI=0)

add_executable(untitled main.cpp DFA.cpp DFA.h)