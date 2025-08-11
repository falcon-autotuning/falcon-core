cmake_minimum_required(VERSION 3.20)
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

# Get SWIG's library directory for standard .i files
execute_process(COMMAND ${SWIG_EXECUTABLE} -swiglib
  OUTPUT_VARIABLE SWIG_LIB_DIR
  OUTPUT_STRIP_TRAILING_WHITESPACE)

# --- Debugging ---
message(STATUS "--- SWIG PATH DIAGNOSTICS ---")
message(STATUS "SWIG Executable: ${SWIG_EXECUTABLE}")
message(STATUS "SWIG Library Directory (SWIG_LIB_DIR): ${SWIG_LIB_DIR}")
message(STATUS "Project Include Directory: ${CMAKE_CURRENT_SOURCE_DIR}/include")
message(STATUS "-----------------------------")

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
include_directories(${Python3_INCLUDE_DIRS})


# --- C++ Library Target ---
add_library(falcon_core_cpp
    src/Time.cpp
    src/Jsonable.cpp
    src/Dimension.cpp
    src/Prefix.cpp
    src/Unit.cpp
    src/SymbolUnit.cpp
)
target_include_directories(falcon_core_cpp PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    ${json_SOURCE_DIR}/include
    ${xtl_SOURCE_DIR}/include
    ${xtensor_SOURCE_DIR}/include
    ${xtensor-python_SOURCE_DIR}/include
)
target_link_libraries(falcon_core_cpp PRIVATE nlohmann_json::nlohmann_json)


# --- SWIG Python Bindings (Manual Custom Command) ---
set(SWIG_MODULE_NAME "falcon_core")
set(SWIG_I_FILE "${CMAKE_CURRENT_SOURCE_DIR}/swig/${SWIG_MODULE_NAME}.i")
set(SWIG_WRAP_CXX "${CMAKE_CURRENT_BINARY_DIR}/${SWIG_MODULE_NAME}_wrap.cxx")

# Define all files that, if changed, should trigger a re-run of SWIG.
file(GLOB SWIG_DEPENDENCIES
    "${CMAKE_CURRENT_SOURCE_DIR}/include/falcon_core/*.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/swig/*.i"
)

# Manually define the command to run SWIG. This bypasses the failing
# swig_add_library function and gives us explicit control over the command line.
add_custom_command(
    OUTPUT ${SWIG_WRAP_CXX}
    COMMAND ${SWIG_EXECUTABLE} -python -c++
        -I"${SWIG_LIB_DIR}"
        -I"${CMAKE_CURRENT_SOURCE_DIR}/include"
        -I"${CMAKE_CURRENT_SOURCE_DIR}/swig"
        -cpperraswarn
        -o ${SWIG_WRAP_CXX}
        -outdir "${CMAKE_CURRENT_BINARY_DIR}"
        ${SWIG_I_FILE}
    DEPENDS ${SWIG_DEPENDENCIES}
    COMMENT "Generating Python wrapper for ${SWIG_MODULE_NAME} via custom command"
    VERBATIM
)

# Create a custom target that depends on the generated wrapper file.
# This ensures the SWIG command is executed during the build.
add_custom_target(swig_wrapper DEPENDS ${SWIG_WRAP_CXX})

# Create the Python module from the generated C++ wrapper file.
add_library(${SWIG_MODULE_NAME} SHARED ${SWIG_WRAP_CXX})

# The C++ compiler needs to find our project's headers.
target_include_directories(${SWIG_MODULE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    ${Python3_INCLUDE_DIRS}
)

# Link the Python module against Python and our core C++ library.
target_link_libraries(${SWIG_MODULE_NAME} PRIVATE
    Python3::Python
    falcon_core_cpp
)

# Ensure the C++ library is built before this module.
add_dependencies(${SWIG_MODULE_NAME} falcon_core_cpp swig_wrapper)

# Set the output name to be `_falcon_core.so` so python can import it.
set_target_properties(${SWIG_MODULE_NAME} PROPERTIES
    PREFIX "_"
    OUTPUT_NAME "${SWIG_MODULE_NAME}"
)

# --- C++ Tests ---
enable_testing()
add_executable(run_tests
    tests/test_time.cpp
    tests/test_jsonable.cpp
    tests/test_dimension.cpp
    tests/test_unit.cpp
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
