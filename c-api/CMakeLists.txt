cmake_minimum_required(VERSION 3.14)
project(FalconCoreCAPI LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(C_API_LIB_NAME
    "${C_API_TARGET}"
    CACHE STRING "ChangeMe")

include_directories(../include include ../vcpkg_installed/x64-linux/include)

link_directories(../build)

file(GLOB_RECURSE C_API_SOURCES "src/*.cpp")

add_library(${C_API_LIB_NAME} SHARED ${C_API_SOURCES})

target_link_libraries(${C_API_LIB_NAME} PRIVATE falcon_core_cpp)

set_target_properties(
  ${C_API_LIB_NAME}
  PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
             PREFIX "lib"
             SUFFIX ".so")

message(STATUS "Setting up C++ tests")
enable_testing()
file(GLOB RUN_TESTS_SOURCES tests/test_*.cpp)
add_executable(run_tests ${RUN_TESTS_SOURCES})
set_target_properties(
  run_tests
  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
             BUILD_RPATH "${CMAKE_CURRENT_SOURCE_DIR}/build"
             INSTALL_RPATH "${CMAKE_CURRENT_SOURCE_DIR}/build")
find_package(GTest REQUIRED)
target_link_libraries(run_tests GTest::gtest_main ${C_API_LIB_NAME})
include(GoogleTest)
gtest_discover_tests(run_tests)
