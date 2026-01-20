cmake_minimum_required(VERSION 3.20)
project(FalconCore LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CPP_TARGET "falcon_core_cpp")
set(CPP_LIB_NAME "${CPP_TARGET}" CACHE STRING "ChangeMe")

option(FALCON_CORE_DEV "Dev mode generates coverage and testing" OFF)
option(USE_VCPKG "Use vcpkg for dependencies" ON)

if(FALCON_CORE_DEV)
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

# ---- CMake policy: Boost FindBoost removal ----
if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

# ---- Dependencies ----
find_package(cereal CONFIG REQUIRED)
find_package(xtl CONFIG REQUIRED)
find_package(xtensor CONFIG REQUIRED)
find_package(xsimd CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)

# HDF5 (vcpkg target names differ for static vs shared triplets)
find_package(hdf5 CONFIG REQUIRED)

set(HDF5_TARGET "")
set(HDF5_CPP_TARGET "")

if(TARGET hdf5::hdf5-shared)
  set(HDF5_TARGET hdf5::hdf5-shared)
elseif(TARGET hdf5::hdf5-static)
  set(HDF5_TARGET hdf5::hdf5-static)
elseif(TARGET hdf5::hdf5)
  set(HDF5_TARGET hdf5::hdf5)
else()
  message(FATAL_ERROR "No HDF5 CMake target found (expected hdf5::hdf5-static or hdf5::hdf5-shared).")
endif()

if(TARGET hdf5::hdf5_cpp-shared)
  set(HDF5_CPP_TARGET hdf5::hdf5_cpp-shared)
elseif(TARGET hdf5::hdf5_cpp-static)
  set(HDF5_CPP_TARGET hdf5::hdf5_cpp-static)
elseif(TARGET hdf5::hdf5_cpp)
  set(HDF5_CPP_TARGET hdf5::hdf5_cpp)
else()
  # If you don't actually need HDF5 C++ API, you can omit linking it.
  message(STATUS "No HDF5 C++ target found; proceeding without HDF5 C++ link target.")
endif()

# Boost (vcpkg provides BoostConfig.cmake)
find_package(Boost REQUIRED COMPONENTS filesystem)

# ---- Library ----
file(GLOB_RECURSE FALCON_CORE_SOURCES CONFIGURE_DEPENDS "src/*.cpp")

if(WIN32)
  add_library(${CPP_LIB_NAME} STATIC ${FALCON_CORE_SOURCES})
else()
  add_library(${CPP_LIB_NAME} SHARED ${FALCON_CORE_SOURCES})
endif()


# Handle large object files on MinGW or using MSVC
if(MINGW)
  target_compile_options(${CPP_LIB_NAME} PRIVATE -Wa,-mbig-obj)
endif()

if (MSVC)
  set_source_files_properties(
    src/math/AnalyticFunction.cpp
    PROPERTIES COMPILE_OPTIONS "/bigobj"
  )
  add_compile_options(/Zc:__cplusplus)
endif()

target_include_directories(
  ${CPP_LIB_NAME}
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include>)

target_link_libraries(
  ${CPP_LIB_NAME}
  PUBLIC Boost::filesystem
         xtl
         xtensor
         xsimd
         yaml-cpp::yaml-cpp
         ${HDF5_TARGET}
         cereal::cereal)

if(HDF5_CPP_TARGET)
  target_link_libraries(${CPP_LIB_NAME} PUBLIC ${HDF5_CPP_TARGET})
endif()

# Optional extra Boost components you were using under USE_VCPKG
# (Keep if actually needed by your code)
if(USE_VCPKG)
  find_package(Boost REQUIRED COMPONENTS system uuid)
  target_link_libraries(${CPP_LIB_NAME} PUBLIC Boost::system Boost::uuid)
endif()

# ---- Optional tests ----
if(FALCON_CORE_DEV)
  find_package(GTest CONFIG REQUIRED)
  enable_testing()

  file(GLOB RUN_TESTS_SOURCES tests/test_*.cpp)
  add_executable(falcon_core_cpp_run_tests ${RUN_TESTS_SOURCES})
  target_link_libraries(falcon_core_cpp_run_tests PRIVATE GTest::gtest_main ${CPP_LIB_NAME})

  if(WIN32)
    add_test(NAME falcon_core_cpp_run_tests COMMAND falcon_core_cpp_run_tests)
  else()
    include(GoogleTest)
    gtest_discover_tests(falcon_core_cpp_run_tests)
  endif()
endif()
