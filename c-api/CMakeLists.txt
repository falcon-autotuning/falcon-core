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

find_package(cereal CONFIG REQUIRED)
find_package(xtl CONFIG REQUIRED)
find_package(xtensor CONFIG REQUIRED)
find_package(xsimd CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)
find_package(hdf5 CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem system uuid)


file(GLOB_RECURSE C_API_SOURCES "src/*.cpp")

add_library(${C_API_LIB_NAME} SHARED ${C_API_SOURCES})

target_include_directories(${C_API_LIB_NAME}
  PUBLIC $<BUILD_INTERFACE:${CORE_ROOT}/include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include>)

message(STATUS "CORE_ROOT is: ${CORE_ROOT}")
get_filename_component(CORE_BUILD_ABS "${CORE_ROOT}/build" ABSOLUTE)
message(STATUS "CORE_BUILD_ABS: ${CORE_BUILD_ABS}")
target_link_libraries(${C_API_LIB_NAME}
  PRIVATE ${CORE_BUILD_ABS}/libfalcon_core_cpp.so
          cereal::cereal
          xtl
          xtensor
          xsimd
          yaml-cpp::yaml-cpp
          hdf5::hdf5-shared
          hdf5::hdf5_cpp-shared
          Boost::filesystem
          Boost::system
          Boost::uuid)

set_target_properties(
  ${C_API_LIB_NAME}
  PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
             PREFIX "lib"
             SUFFIX ".so")

# ---- Optional test build ----
option(BUILD_TESTS "Build and enable C++ tests" ON)

if(BUILD_TESTS)
  enable_testing()
  file(GLOB RUN_TESTS_SOURCES tests/test_*.cpp)
  add_executable(run_tests ${RUN_TESTS_SOURCES})
  target_link_directories(run_tests PRIVATE ${CORE_BUILD_ABS})
  set_target_properties(
    run_tests
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
               BUILD_RPATH "${CMAKE_CURRENT_SOURCE_DIR}/build;${CORE_BUILD_ABS}"
               INSTALL_RPATH
               "${CMAKE_CURRENT_SOURCE_DIR}/build;${CORE_BUILD_ABS}")
  find_package(GTest REQUIRED)
  target_link_libraries(
    run_tests PRIVATE GTest::gtest_main Boost::filesystem Boost::system
                      yaml-cpp::yaml-cpp ${C_API_LIB_NAME})
  include(GoogleTest)
  gtest_discover_tests(run_tests)
endif()
