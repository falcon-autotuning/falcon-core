cmake_minimum_required(VERSION 3.20)
project(FalconCore LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_Position_INDEPENDENT_CODE ON)
set(CPP_LIB_NAME
    "${CPP_TARGET}"
    CACHE STRING "ChangeMe")
if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

find_package(cereal CONFIG REQUIRED)
find_package(xtl CONFIG REQUIRED)
find_package(xtensor CONFIG REQUIRED)
find_package(xsimd CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)
find_package(hdf5 CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem system uuid)

file(GLOB_RECURSE FALCON_CORE_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
add_library(${CPP_LIB_NAME} SHARED ${FALCON_CORE_SOURCES})
target_include_directories(
  ${CPP_LIB_NAME}
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include>
         ${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-linux/include)
target_link_libraries(
  ${CPP_LIB_NAME}
  PRIVATE Boost::filesystem
          Boost::system
          Boost::uuid
          xtl
          xtensor
          xsimd
          yaml-cpp::yaml-cpp
          hdf5::hdf5-shared
          hdf5::hdf5_cpp-shared
          cereal::cereal)
target_link_libraries(${CPP_LIB_NAME} PUBLIC yaml-cpp::yaml-cpp)

# ---- Optional test build ----
option(BUILD_TESTS "Build and enable C++ tests" ON)

if(BUILD_TESTS)
  find_package(GTest CONFIG REQUIRED)
  message(STATUS "Setting up C++ tests")
  enable_testing()
  file(GLOB RUN_TESTS_SOURCES tests/test_*.cpp)
  add_executable(run_tests ${RUN_TESTS_SOURCES})
  set(HDF5_DEBUG_LIB
      "${CMAKE_CURRENT_SOURCE_DIR}/build/vcpkg_installed/x64-linux-dynamic/debug/lib"
  )
  set_target_properties(
    run_tests
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
               BUILD_RPATH "${HDF5_DEBUG_LIB}"
               INSTALL_RPATH "${HDF5_DEBUG_LIB}")
  target_link_libraries(run_tests GTest::gtest_main Boost::filesystem
                        Boost::system ${CPP_LIB_NAME})
  include(GoogleTest)
  gtest_discover_tests(run_tests)
endif()
