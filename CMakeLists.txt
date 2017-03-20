cmake_minimum_required(VERSION 3.6)
project(Algorithms_Exercise)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp substring_searching_algorithms/substring_search_algorithms.h "substring_searching_algorithms/kmp_algorithm.cpp" "substring_searching_algorithms/naive_string_matching_algorithm.cpp" substring_searching_algorithms/rabin_karp_algorithm.cpp)
add_executable(Algorithms_Exercise ${SOURCE_FILES})