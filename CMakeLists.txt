cmake_minimum_required(VERSION 3.5)
project(6771_tut_week7_part2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

set(SOURCE_FILES extraSmart.cpp)
add_executable(6771_tut_week7_part2 ${SOURCE_FILES})