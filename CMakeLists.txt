cmake_minimum_required(VERSION 3.20)
project(FalconCore LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# --- Dependencies ---
include(FetchContent)
function(cpp_tests)
  # This function is used to set up C++ tests. It is called at the end of the
  # CMakeLists.txt file.
  message(STATUS "Setting up C++ tests")
  enable_testing()

  add_executable(
    run_tests
    tests/test_unit.cpp tests/test_common_unit.cpp tests/test_song.cpp
    tests/test_device_structures.cpp tests/test_arrays.cpp
    tests/test_labelled_arrays.cpp)

  target_link_libraries(run_tests GTest::gtest_main falcon_core_cpp)

  include(GoogleTest)
  gtest_discover_tests(run_tests)
endfunction()

function(swig_modules)
  # This function is used to set up SWIG modules.

  set(SWIG_MODULE_NAME "falcon_core")

  # Set the output directory for Python package files
  set(PYTHON_PACKAGE_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/src/falcon_core_gen")
  set(TEMPLATE_I_FILE "${CMAKE_CURRENT_SOURCE_DIR}/swig/default.in")

  # Set the swig modules for disccovery/generation
  set(FIELD_NAMES SUBMODULE_NAME CLASS_NAME SWIG_INTERFACE HEADER
                  DIRECTORY_PATH)
  set(SWIG_MODULES
      song
      Song
      Song.i
      Song.hpp
      generic
      base_connection
      BaseConnection
      BaseConnection.i
      BaseConnection.hpp
      physics/device_structures
      gate
      Gate
      Gate.i
      Gate.hpp
      physics/device_structures
      screening_gate
      ScreeningGate
      ScreeningGate.i
      ScreeningGate.hpp
      physics/device_structures
      reservoir_gate
      ReservoirGate
      ReservoirGate.i
      ReservoirGate.hpp
      physics/device_structures)
  file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/swig/add_song_deserializers.i"
       DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/build/swig/")

  list(LENGTH FIELD_NAMES NUM_COLUMNS)
  list(LENGTH SWIG_MODULES num_entries)
  math(EXPR num "${num_entries} / ${NUM_COLUMNS}")
  math(EXPR max "${num} - 1")
  foreach(i RANGE 0 ${max})
    set(ROW_VALUES "")
    math(EXPR LAST_INDEX "${NUM_COLUMNS} - 1")
    foreach(j RANGE 0 ${LAST_INDEX})
      math(EXPR idx "${i} * ${NUM_COLUMNS} + ${j}")
      list(GET SWIG_MODULES ${idx} value)
      list(APPEND ROW_VALUES "${value}")
    endforeach()
    # Pass the 4 values directly
    falcon_process_swig_module(${ROW_VALUES})
  endforeach()
endfunction()

function(clean_directory_path DIRECTORY_PATH OUT_VAR)
  # This function makes sure that the directly path has a / after it
  # DIRECTORY_PATH: The path to clean (e.g., "physics/device_structures").
  # OUT_VAR: The variable to store the cleaned path
  if(DIRECTORY_PATH)
    set(CLEANED_DIR "${DIRECTORY_PATH}")
    # Remove trailing slashes
    string(REGEX REPLACE "/+$" "" CLEANED_DIR "${CLEANED_DIR}")
    # Remove leading slashes
    string(REGEX REPLACE "^/+" "" CLEANED_DIR "${CLEANED_DIR}")
    # Add trailing slash
    set(CLEANED_DIR "${CLEANED_DIR}/")
    set(${OUT_VAR}
        "${CLEANED_DIR}"
        PARENT_SCOPE)
  else()
    set(${OUT_VAR}
        "/"
        PARENT_SCOPE)
  endif()
endfunction()

function(assert_file_extension FILE EXT)
  string(REGEX MATCH "\\.${EXT}$" MATCHED "${FILE}")
  if(NOT MATCHED)
    message(FATAL_ERROR "${FILE} does not end with .${EXT}")
  endif()
endfunction()

function(remove_file_extension FILE_PATH OUT_VAR)
  # Removes the extension from FILE_PATH and stores the result in OUT_VAR.
  string(REGEX REPLACE "\\.[^.]*$" "" NO_EXT "${FILE_PATH}")
  set(${OUT_VAR}
      "${NO_EXT}"
      PARENT_SCOPE)
endfunction()

function(falcon_process_swig_module SUBMODULE_NAME CLASS_NAME SWIG_INTERFACE
         HEADER DIRECTORY_PATH)
  # This function processes a SWIG module for Python bindings. It generates the
  # necessary files and sets up the target. SUBMODULE_NAME: Name of the
  # submodule (e.g., "song", "base_connection"). CLASS_NAME: Name of the python
  # class (e.g., "Song", "BaseConnection"). SWIG_INTERFACE: Name of the the SWIG
  # interface file (e.g., "Song.i"). HEADER_PATH: Name of the header file (e.g.,
  # "Song.hpp"). DIRECTORY_PATH: Path to the nested directory for all files
  # (e.g., "physics/device_structures").
  assert_file_extension("${SWIG_INTERFACE}" "i")
  assert_file_extension("${HEADER}" "hpp")
  remove_file_extension("${HEADER}" HEADER_NO_EXT)
  clean_directory_path(${DIRECTORY_PATH} CLEANED_DIR)
  set(SUBMODULE_PATH "${CLEANED_DIR}${SUBMODULE_NAME}")
  set(PYTHON_PACKAGE_DIR "${PYTHON_PACKAGE_ROOT}/${SUBMODULE_PATH}")
  set(SWIG_MODULE_NAME "falcon_core_${SUBMODULE_NAME}")

  # SWIG interface file logic
  set(SWIG_SOURCE "swig/${CLEANED_DIR}${SWIG_INTERFACE}")
  set(BUILD_I_FILE "${CMAKE_CURRENT_SOURCE_DIR}/build/${SWIG_SOURCE}")
  cmake_path(GET BUILD_I_FILE PARENT_PATH BUILD_I_DIR)
  file(MAKE_DIRECTORY "${BUILD_I_DIR}")

  if(EXISTS "${SWIG_SOURCE}")
    message(STATUS "Using custom SWIG interface: ${SWIG_SOURCE}")
    file(COPY "${SWIG_SOURCE}" DESTINATION "${BUILD_I_DIR}")
  else()
    message(STATUS "Autogenerating SWIG interface for ${SUBMODULE_NAME}")
    set(HEADER_PATH_NO_EXT "falcon_core/${CLEANED_DIR}${HEADER_NO_EXT}")
    string(REPLACE "/" "::" CPP_CLASS "${HEADER_PATH_NO_EXT}")
    cmake_path(GET HEADER_PATH_NO_EXT PARENT_PATH PACKAGE_DIR)
    string(REPLACE "/" "." PACKAGE_TREE "${PACKAGE_DIR}")
    set(HEADER_PATH "${HEADER_PATH_NO_EXT}.hpp")
    configure_file("${TEMPLATE_I_FILE}" "${BUILD_I_FILE}" @ONLY)
  endif()

  # Create package directories and __init__.py files
  string(REPLACE "/" ";" SUBMODULE_PATH_LIST "${SUBMODULE_PATH}")
  set(PACKAGE_PATH "${PYTHON_PACKAGE_ROOT}")
  file(WRITE "${PACKAGE_PATH}/__init__.py" "")
  foreach(PART ${SUBMODULE_PATH_LIST})
    set(PACKAGE_PATH "${PACKAGE_PATH}/${PART}")
    file(MAKE_DIRECTORY "${PACKAGE_PATH}")
    file(WRITE "${PACKAGE_PATH}/__init__.py" "")
  endforeach()

  set(CMAKE_SWIG_OUTDIR ${PYTHON_PACKAGE_DIR})
  set_property(SOURCE ${BUILD_I_FILE} PROPERTY CPLUSPLUS ON)

  swig_add_library(
    ${SWIG_MODULE_NAME}
    LANGUAGE python
    SOURCES ${BUILD_I_FILE})

  set_target_properties(
    ${SWIG_MODULE_NAME}
    PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PYTHON_PACKAGE_DIR}
               PREFIX "_"
               SWIG_USE_TARGET_INCLUDE_DIRECTORIES TRUE
               LINKER_LANGUAGE CXX)

  target_include_directories(
    ${SWIG_MODULE_NAME}
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include"
            "${CMAKE_CURRENT_SOURCE_DIR}/build/swig" ${Python3_INCLUDE_DIRS}
            "${SWIG_LIB_DIR}/python" ${NUMPY_INCLUDE_DIR})

  target_link_libraries(${SWIG_MODULE_NAME} PRIVATE Python3::Python
                                                    falcon_core_cpp)
  message(STATUS "Finished processing ${SUBMODULE_NAME}")
endfunction()

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

swig_modules()
cpp_tests()
# --- Python Binding Tests ---
add_test(NAME python_bindings_test
         COMMAND ${Python3_EXECUTABLE}
                 ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_bindings.py)
set_tests_properties(python_bindings_test
                     PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
