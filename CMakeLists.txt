cmake_minimum_required(VERSION 3.20)
project(FalconCore LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_Position_INDEPENDENT_CODE ON)

# --- Dependencies via vcpkg ---
find_package(cereal CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(xtl CONFIG REQUIRED)
find_package(xtensor CONFIG REQUIRED)
find_package(xsimd CONFIG REQUIRED)
find_package(xtensor-blas CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)
find_package(hdf5 CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem system)

function(cpp_tests)
  # This function is used to set up C++ tests. It is called at the end of the
  # CMakeLists.txt file.
  message(STATUS "Setting up C++ tests")
  enable_testing()

  if(FALCON_CORE_TESTS)
    set(RUN_TESTS_SOURCES ${FALCON_CORE_TESTS})
  else()
    # Default: include all test files
    set(RUN_TESTS_SOURCES
    tests/test_unit.cpp
    tests/test_common_unit.cpp
    tests/test_song.cpp
    tests/test_device_structures.cpp
    tests/test_arrays.cpp
    tests/test_labelled_arrays.cpp
    tests/test_quantity.cpp
    tests/test_instrument_interfaces_names.cpp
    tests/test_config.cpp
    tests/test_domains.cpp
    tests/test_discretizers.cpp
    tests/test_spaces.cpp
    tests/test_discrete_spaces.cpp
    tests/test_vector.cpp
    tests/test_analytic_function.cpp
    tests/test_port_transforms.cpp
    tests/test_waveforms.cpp
    tests/test_device_voltage_states.cpp
    tests/test_messages.cpp
    tests/test_farray.cpp
  )
  endif()

  add_executable(run_tests ${RUN_TESTS_SOURCES})

  target_link_libraries(run_tests GTest::gtest_main falcon_core_cpp)

  include(GoogleTest)
  gtest_discover_tests(run_tests)
endfunction()

function(generate_swig_modules SWIG_MODULES_LIST)
  # This function is used to set up SWIG modules. SWIG_MODULES_LIST: A list of
  # SWIG modules to process. Each entry in the list should contain the following
  # fields: FIELD_NAMES
  set(MODULE_LIST ${${SWIG_MODULES_LIST}}) # Dereference to get the list

  set(SWIG_MODULE_NAME "falcon_core")

  # Set the output directory for Python package files
  set(PYTHON_PACKAGE_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/src/falcon_core")
  set(TEMPLATE_I_FILE "${CMAKE_CURRENT_SOURCE_DIR}/swig/default.in")

  # Set the swig modules for disccovery/generation
  set(FIELD_NAMES SUBMODULE_NAME CLASS_NAME SWIG_INTERFACE DIRECTORY_PATH)

  list(LENGTH MODULE_LIST num_entries)
  message(DEBUG "Generating SWIG modules for ${num_entries} entries")
  foreach(module_string IN LISTS MODULE_LIST)
    string(REPLACE "," ";" ROW_VALUES "${module_string}")
    # Pass the 4 values directly
    message(DEBUG "The values for the row are ${ROW_VALUES}")
    falcon_process_swig_module(${ROW_VALUES})
  endforeach()
endfunction()

function(generate_song_deserializers OUT_DIR)
  # This function generates the add_song_deserializers.i file.
  file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/swig/add_song_deserializers.i"
       DESTINATION "${OUT_DIR}")
endfunction()

function(generate_swig_header_interface HEADER_LIST_VAR OUTPUT_FILE MODULE_NAME)
  # HEADER_LIST_VAR: name of the variable holding the header list (e.g.,
  # falcon_headers) OUTPUT_FILE: path to write the .i file MODULE_NAME: SWIG
  # module name

  # Get the list from the variable name
  set(headers "${${HEADER_LIST_VAR}}")

  # Write the module declaration
  file(WRITE "${OUTPUT_FILE}" "%module ${MODULE_NAME}\n\n")

  # Write the %{ ... %} block
  file(APPEND "${OUTPUT_FILE}" "%{\n")
  foreach(header ${headers})
    if(header MATCHES "\\.hpp$")
      file(APPEND "${OUTPUT_FILE}" "#include \"${header}\"\n")
    endif()
  endforeach()
  file(APPEND "${OUTPUT_FILE}" "%}\n\n")

  # Include std types
  file(APPEND "${OUTPUT_FILE}" "%include <std_string.i>\n")
  file(APPEND "${OUTPUT_FILE}" "%include <std_wstring.i>\n")
  file(APPEND "${OUTPUT_FILE}" "%include <std_vector.i>\n")
  file(APPEND "${OUTPUT_FILE}" "%include <std_map.i>\n")
  # file(APPEND "${OUTPUT_FILE}" "%include <std_pair.i>\n")
  file(APPEND "${OUTPUT_FILE}" "%include <std_except.i>\n")
  file(APPEND "${OUTPUT_FILE}" "%include <std_shared_ptr.i>\n")
  file(APPEND "${OUTPUT_FILE}" "%include <std_unique_ptr.i>\n")
  # Write the %include lines
  foreach(header ${headers})
    if(header MATCHES "\\.hpp$")
      file(APPEND "${OUTPUT_FILE}" "%include \"${header}\"\n")
    else()
      # Remove problematic characters for unique_name
      string(REGEX REPLACE "[:<>, ]" "_" unique_name "${header}")
      file(APPEND "${OUTPUT_FILE}" "%template(${unique_name}) ${header};\n")
    endif()
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
         DIRECTORY_PATH)
  # This function processes a SWIG module for Python bindings. It generates the
  # necessary files and sets up the target. SUBMODULE_NAME: Name of the
  # submodule (e.g., "song", "base_connection"). CLASS_NAME: Name of the python
  # class (e.g., "Song", "BaseConnection"). SWIG_INTERFACE: Name of the the SWIG
  # interface file (e.g., "Song.i"). DIRECTORY_PATH: Path to the nested
  # directory for all files (e.g., "physics/device_structures").
  assert_file_extension("${SWIG_INTERFACE}" "i")
  remove_file_extension("${SWIG_INTERFACE}" C_FILENAME_NO_EXT)
  clean_directory_path(${DIRECTORY_PATH} CLEANED_DIR)
  set(PYTHON_PACKAGE_DIR "${PYTHON_PACKAGE_ROOT}/${DIRECTORY_PATH}")
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
    set(FILE_PATH_NO_EXT "falcon_core/${CLEANED_DIR}${C_FILENAME_NO_EXT}")
    string(REPLACE "/" "::" CPP_CLASS
                   "falcon_core/${CLEANED_DIR}${C_FILENAME_NO_EXT}")
    cmake_path(GET FILE_PATH_NO_EXT PARENT_PATH PACKAGE_DIR)
    string(REPLACE "/" "." PACKAGE_TREE "${PACKAGE_DIR}")
    configure_file("${TEMPLATE_I_FILE}" "${BUILD_I_FILE}" @ONLY)
  endif()

  # Create package directories and __init__.py files
  string(REPLACE "/" ";" SUBMODULE_PATH_LIST "${CLEANED_DIR}")
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
  message(STATUS "Finished processing ${SWIG_MODULE_NAME}")
endfunction()

# --- SWIG and Python ---
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
find_package(
  Python3
  COMPONENTS Interpreter Development
  REQUIRED)

# Find NumPy include directory
# execute_process(
#   COMMAND ${Python3_EXECUTABLE} -c "import numpy; print(numpy.get_include())"
#   OUTPUT_VARIABLE NUMPY_INCLUDE_DIR
#   OUTPUT_STRIP_TRAILING_WHITESPACE)
# if(NOT NUMPY_INCLUDE_DIR)
#   message(FATAL_ERROR "NumPy include directory not found. Is NumPy installed?")
# endif()

# Get SWIG's library directory for standard .i files
execute_process(
  COMMAND ${SWIG_EXECUTABLE} -swiglib
  OUTPUT_VARIABLE SWIG_LIB_DIR
  OUTPUT_STRIP_TRAILING_WHITESPACE)

# --- C++ Library Target ---
if(FALCON_CORE_DIRS)
  set(FALCON_CORE_SOURCES "")
  foreach(dir_or_file ${FALCON_CORE_DIRS})
    if(IS_DIRECTORY ${dir_or_file})
      file(GLOB_RECURSE DIR_SOURCES CONFIGURE_DEPENDS "${dir_or_file}/*.cpp")
      list(APPEND FALCON_CORE_SOURCES ${DIR_SOURCES})
    elseif(EXISTS ${dir_or_file})
      list(APPEND FALCON_CORE_SOURCES ${dir_or_file})
    endif()
  endforeach()
else()
  file(GLOB_RECURSE FALCON_CORE_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
endif()

add_library(falcon_core_cpp ${FALCON_CORE_SOURCES})

target_include_directories(
     falcon_core_cpp
     PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
   )

target_link_libraries(falcon_core_cpp
    PRIVATE
    Boost::filesystem
    Boost::system
    xtl
    xtensor
    xsimd
    xtensor-blas
    yaml-cpp:yaml-cpp
    hdf5::hdf5-static
    hdf5::hdf5_cpp-static
    cereal::cereal
)

target_link_libraries(falcon_core_cpp PUBLIC yaml-cpp)

if(NOT FALCON_CORE_DIRS)
  set(FALCON_HEADERS
    falcon_core/generic/Song.hpp
    falcon_core/Constants.hpp
    falcon_core/physics/device_structures/BaseConnection.hpp
    falcon_core/physics/device_structures/BarrierGate.hpp
    falcon_core/physics/device_structures/ScreeningGate.hpp
    falcon_core/physics/device_structures/ReservoirGate.hpp
    falcon_core/physics/device_structures/PlungerGate.hpp
    falcon_core/physics/device_structures/Ohmic.hpp
    falcon_core/physics/device_structures/Impedance.hpp
    falcon_core/physics/device_structures/BaseConnections.hpp
    falcon_core/physics/device_structures/BarrierGates.hpp
    falcon_core/physics/device_structures/ScreeningGates.hpp
    falcon_core/physics/device_structures/ReservoirGates.hpp
    falcon_core/physics/device_structures/PlungerGates.hpp
    falcon_core/physics/device_structures/Ohmics.hpp
    falcon_core/physics/device_structures/Impedances.hpp
    falcon_core/physics/device_structures/GateRelations.hpp
    falcon_core/physics/units/TotalDimensions.hpp
    falcon_core/physics/units/Prefix.hpp
    falcon_core/physics/units/Unit.hpp
    falcon_core/physics/units/CommonUnits.hpp
    falcon_core/physics/units/SymbolUnit.hpp
    falcon_core/physics/units/Units.hpp
    falcon_core/instrument_interfaces/Instrument.hpp
    falcon_core/instrument_interfaces/names/InstrumentPort.hpp
    falcon_core/instrument_interfaces/names/Ports.hpp
    falcon_core::instrument_interfaces::names::Ports<falcon_core::instrument_interfaces::names::Knob>
    falcon_core::instrument_interfaces::names::Ports<falcon_core::instrument_interfaces::names::Meter>
    falcon_core/instrument_interfaces/names/Knob.hpp
    falcon_core/instrument_interfaces/names/Knobs.hpp
    falcon_core/instrument_interfaces/names/Meter.hpp
    falcon_core/instrument_interfaces/names/Meters.hpp
    # falcon_core/math/Axes.hpp
    # std::map<falcon_core::physics::device_structures::BaseConnection,double>
    # falcon_core/math/Point.hpp
    falcon_core/math/Quantity.hpp
    # falcon_core/math/Sign.hpp
    falcon_core/math/arrays/BaseArray.hpp
    falcon_core::math::arrays::BaseArray<double>
    falcon_core/math/arrays/ControlArray.hpp
    falcon_core::math::arrays::ControlArray<double>
    falcon_core/math/arrays/ControlArray1D.hpp
    falcon_core/math/arrays/IncreasingAlignment.hpp
    falcon_core/math/arrays/MeasuredArray.hpp
    # falcon_core/math/labelled_arrays/BaseLabelledArray.hpp
    # falcon_core/math/labelled_arrays/BaseLabelledArrays.hpp
    # falcon_core/math/labelled_arrays/IsLabelled1D.hpp
    # falcon_core::math::labelled_arrays::BaseLabelledArray<falcon_core::math::arrays::ControlArray1D,falcon_core::instrument_interfaces::names::InstrumentPort<falcon_core::physics::device_structures::Gate>>
    # falcon_core::math::labelled_arrays::IsLabelled1D<falcon_core::math::labelled_arrays::LabelledControlArray1D>
    # falcon_core/math/labelled_arrays/LabelledControlArray1D.hpp
)
  set(SWIG_MODULES
    song,Song,Song.i,generic
    base_connection,BaseConnection,BaseConnection.i,physics/device_structures
    ohmic,Ohmic,Ohmic.i,physics/device_structures
    barrier_gate,BarrierGate,BarrierGate.i,physics/device_structures
    plunger_gate,PlungerGate,PlungerGate.i,physics/device_structures
    screening_gate,ScreeningGate,ScreeningGate.i,physics/device_structures
    reservoir_gate,ReservoirGate,ReservoirGate.i,physics/device_structures
    ohmics,Ohmics,Ohmics.i,physics/device_structures
    barrier_gates,BarrierGates,BarrierGates.i,physics/device_structures
    plunger_gates,PlungerGates,PlungerGates.i,physics/device_structures
    reservoir_gates,ReservoirGates,ReservoirGates.i,physics/device_structures
    screening_gates,ScreeningGates,ScreeningGates.i,physics/device_structures
    impedance,Impedance,Impedance.i,physics/device_structures
    impedances,Impedances,Impedances.i,physics/device_structures
    gate_relations,GateRelations,GateRelations.i,physics/device_structures
    prefix,Prefix,Prefix.i,physics/units
    unit,Unit,Unit.i,physics/units
    symbol_unit,SymbolUnit,SymbolUnit.i,physics/units
    units,Units,Units.i,physics/units
    instrument_port,InstrumentPort,InstrumentPort.i,instrument_interfaces/names
    knob,Knob,Knob.i,instrument_interfaces/names
    meter,Meter,Meter.i,instrument_interfaces/names
    ports,Ports,Ports.i,instrument_interfaces/names
    knobs,Knobs,Knobs.i,instrument_interfaces/names
    meters,Meters,Meters.i,instrument_interfaces/names
    quantity,Quantity,Quantity.i,math
    base_array,BaseArray,BaseArray.i,math/arrays
    control_array,ControlArray,ControlArray.i,math/arrays
    control_array_1D,ControlArray1D,ControlArray1D.i,math/arrays
    increasing_alignment,IncreasingAlignment,IncreasingAlignment.i,math/arrays
    measured_array,MeasuredArray,MeasuredArray.i,math/arrays
)
  generate_swig_header_interface(
  FALCON_HEADERS "${CMAKE_CURRENT_BINARY_DIR}/swig/falcon_core_all.i"
  "falcon_core_all")
  generate_song_deserializers("${CMAKE_CURRENT_BINARY_DIR}/swig/")
  generate_swig_modules(SWIG_MODULES)
  # --- Python Binding Tests ---
  add_test(NAME python_bindings_test
         COMMAND ${Python3_EXECUTABLE}
                 ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_bindings.py)
  set_tests_properties(python_bindings_test
                     PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endif()
cpp_tests()
