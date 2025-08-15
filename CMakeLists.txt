cmake_minimum_required(VERSION 3.20)
project(FalconCore LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# --- Dependencies ---
include(FetchContent)

# cereal
FetchContent_Declare(
  cereal
  GIT_REPOSITORY https://github.com/USCiLab/cereal.git
  GIT_TAG v1.3.2 # or latest release
)
FetchContent_Populate(cereal)

# GoogleTest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1)
FetchContent_MakeAvailable(googletest)

# eigen
FetchContent_Declare(
  eigen
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
  GIT_TAG 3.4.0)
# Eigen is header-only, so we don't need to build its tests. This prevents its
# test configuration from running, which cleans up CMake output and ensures our
# project's C++ standard is used.
set(EIGEN_BUILD_TESTING
    OFF
    CACHE BOOL "Disable Eigen tests" FORCE)
FetchContent_MakeAvailable(eigen)
set_property(DIRECTORY ${eigen_SOURCE_DIR} PROPERTY EXCLUDE_FROM_ALL TRUE)

# --- SWIG and Python ---
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
find_package(
  Python3
  COMPONENTS Interpreter Development
  REQUIRED)

# Find NumPy include directory
execute_process(
  COMMAND ${Python3_EXECUTABLE} -c "import numpy; print(numpy.get_include())"
  OUTPUT_VARIABLE NUMPY_INCLUDE_DIR
  OUTPUT_STRIP_TRAILING_WHITESPACE)
if(NOT NUMPY_INCLUDE_DIR)
  message(FATAL_ERROR "NumPy include directory not found. Is NumPy installed?")
endif()

# Get SWIG's library directory for standard .i files
execute_process(
  COMMAND ${SWIG_EXECUTABLE} -swiglib
  OUTPUT_VARIABLE SWIG_LIB_DIR
  OUTPUT_STRIP_TRAILING_WHITESPACE)

# --- C++ Library Target ---
file(GLOB_RECURSE FALCON_CORE_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
add_library(falcon_core_cpp ${FALCON_CORE_SOURCES})
target_include_directories(
  falcon_core_cpp
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include> ${eigen_SOURCE_DIR}
         ${cereal_SOURCE_DIR}/include)

# --- SWIG Module ---
set(SWIG_MODULE_NAME "falcon_core")

# Set the output directory for Python package files
set(PYTHON_PACKAGE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/falcon_core)
file(MAKE_DIRECTORY ${PYTHON_PACKAGE_DIR}) # Ensure the directory exists

# Set output for the python wrapper file (falcon_core.py)
set(CMAKE_SWIG_OUTDIR ${PYTHON_PACKAGE_DIR})

set_property(SOURCE swig/${SWIG_MODULE_NAME}.i PROPERTY CPLUSPLUS ON)

swig_add_library(
  ${SWIG_MODULE_NAME}
  LANGUAGE python
  SOURCES swig/${SWIG_MODULE_NAME}.i)

set_target_properties(
  ${SWIG_MODULE_NAME}
  PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PYTHON_PACKAGE_DIR}
             PREFIX "_"
             SWIG_USE_TARGET_INCLUDE_DIRECTORIES TRUE
             LINKER_LANGUAGE CXX)

target_include_directories(
  ${SWIG_MODULE_NAME}
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include"
          "${CMAKE_CURRENT_SOURCE_DIR}/swig" ${Python3_INCLUDE_DIRS}
          "${SWIG_LIB_DIR}/python" ${NUMPY_INCLUDE_DIR})

target_link_libraries(${SWIG_MODULE_NAME} PRIVATE Python3::Python
                                                  falcon_core_cpp)

# --- C++ Tests ---
enable_testing()

add_executable(run_tests tests/test_common_unit.cpp tests/test_unit.cpp tests/test_song.cpp tests/test_math.cpp)

target_link_libraries(run_tests GTest::gtest_main falcon_core_cpp)

include(GoogleTest)
gtest_discover_tests(run_tests)

# --- Python Binding Tests ---
add_test(NAME python_bindings_test
         COMMAND ${Python3_EXECUTABLE}
                 ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_bindings.py)
set_tests_properties(python_bindings_test
                     PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
