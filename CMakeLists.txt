cmake_minimum_required(VERSION 3.15)

project(
  lightning-diffusion
  VERSION 0.1.0
  DESCRIPTION "Simulating diffusion processes in complex networks"
  LANGUAGES CXX)

# graphlib
add_library(graphlib graphlib/graph.cpp)

# lightning-diffusion
add_library(lightning-diffusion lightning-diffusion/utils/timer.cpp
                                lightning-diffusion/utils/rng.cpp)

# Main app
add_executable(main src/main.cpp src/cli/argument_parser.cpp)
target_link_libraries(main PRIVATE graphlib)
target_link_libraries(main PRIVATE lightning-diffusion)

# Tests
enable_testing()
find_package(Catch2 3 REQUIRED)

# graphlib
add_executable(graphlib_tests tests/graphlib/test_graph.cpp)
target_link_libraries(graphlib_tests PRIVATE graphlib Catch2::Catch2WithMain)
add_test(NAME graphlib_tests COMMAND $<TARGET_FILE:graphlib_tests>)

# lightning-diffusion
add_executable(ld_tests tests/lightning-diffusion/test_utils.cpp)
target_link_libraries(ld_tests PRIVATE lightning-diffusion
                                       Catch2::Catch2WithMain)
add_test(NAME ld_tests COMMAND $<TARGET_FILE:ld_tests>)
