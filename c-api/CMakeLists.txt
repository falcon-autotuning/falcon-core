cmake_minimum_required(VERSION 3.14)
project(FalconCoreCAPI LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(../include include ../vcpkg_installed/x64-linux/include)

link_directories(../build)

file(GLOB_RECURSE C_API_SOURCES "src/*.cpp")

add_library(falcon_core_c_api SHARED ${C_API_SOURCES})

target_link_libraries(falcon_core_c_api PRIVATE falcon_core_cpp)

set_target_properties(
  falcon_core_c_api
  PROPERTIES LIBRARY_OUTPUT_DIRECTORY
             "${CMAKE_CURRENT_SOURCE_DIR}/../dist/c_api"
             PREFIX ""
             SUFFIX ".so")
