cmake_minimum_required(VERSION 3.15)

project(
  lightning-diffusion
  VERSION 1.0
  DESCRIPTION "Simulating diffusion processes in complex networks"
  LANGUAGES CXX)

# graphlib
add_library(graphlib graphlib/graph.cpp graphlib/graph.hpp)

# lightning-diffusion

# Main app
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE graphlib)

# Tests
find_package(Catch2 3 REQUIRED)

add_executable(graphlib_tests tests/graphlib/test_graph.cpp)
target_link_libraries(graphlib_tests PRIVATE graphlib Catch2::Catch2WithMain)
