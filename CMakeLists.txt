cmake_minimum_required(VERSION 3.16)
project(FalconCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Dependencies ---
include(FetchContent)

# nlohmann/json
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(json)

# GoogleTest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# xtl (dependency for xtensor)
FetchContent_Declare(
  xtl
  GIT_REPOSITORY https://github.com/xtensor-stack/xtl.git
  GIT_TAG 0.7.5
)
FetchContent_MakeAvailable(xtl)

# xtensor
FetchContent_Declare(
  xtensor
  GIT_REPOSITORY https://github.com/xtensor-stack/xtensor.git
  GIT_TAG 0.24.0
)
FetchContent_MakeAvailable(xtensor)

# pybind11 (dependency for xtensor-python)
FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG v2.10.4
)
FetchContent_MakeAvailable(pybind11)

# xtensor-python
FetchContent_Declare(
  xtensor-python
  GIT_REPOSITORY https://github.com/xtensor-stack/xtensor-python.git
  GIT_TAG 0.26.1
)
FetchContent_MakeAvailable(xtensor-python)

# --- SWIG and Python ---
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
include_directories(${Python3_INCLUDE_DIRS})

# --- C++ Library Target ---
add_library(falcon_core_cpp src/Time.cpp src/Jsonable.cpp)
target_include_directories(falcon_core_cpp PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    ${json_SOURCE_DIR}/include
    ${xtl_SOURCE_DIR}/include
    ${xtensor_SOURCE_DIR}/include
    ${xtensor-python_SOURCE_DIR}/include
)
target_link_libraries(falcon_core_cpp PRIVATE nlohmann_json::nlohmann_json)


# --- SWIG Python Bindings ---
set(SWIG_MODULE_NAME falcon_core)
set(CMAKE_SWIG_FLAGS -c++)
set_source_files_properties(swig/${SWIG_MODULE_NAME}.i PROPERTIES CPLUSPLUS ON)
swig_add_library(${SWIG_MODULE_NAME}
    LANGUAGE python
    SOURCES swig/${SWIG_MODULE_NAME}.i
)
swig_link_libraries(${SWIG_MODULE_NAME}
    Python3::Python
    falcon_core_cpp
)

# --- C++ Tests ---
enable_testing()
add_executable(run_tests
    tests/test_time.cpp
    tests/test_jsonable.cpp
)
target_link_libraries(run_tests
    GTest::gtest_main
    falcon_core_cpp
)

include(GoogleTest)
gtest_discover_tests(run_tests)

# --- Python Binding Tests ---
# This configures ctest to run the python test script from the build directory,
# so that it can correctly import the generated falcon_core module.
add_test(
    NAME python_bindings_test
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_bindings.py
)
set_tests_properties(python_bindings_test PROPERTIES
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
