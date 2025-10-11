cmake_minimum_required(VERSION 3.20)
project(FalconCorePybind LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_Position_INDEPENDENT_CODE ON)
if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

find_package(pybind11 CONFIG REQUIRED)
find_package(
  Python3
  COMPONENTS Development
  REQUIRED)

# Adjust these paths as needed
include_directories(../include ../vcpkg_installed/x64-linux/include
                    ${Python3_INCLUDE_DIRS})

link_directories(../build # Path to where falcon_core_cpp is built
)

set(PYBIND_MODULES
    song,Song,pybind_song.cpp,generic
    # list,List,List.i,generic # farray,FArray,FArray.i,generic
    # map,Map,Map.i,generic
    connection,Connection,pybind_connection.cpp,physics/device_structures
    # connections,Connections,Connections.i,physics/device_structures #
    # ohmic,Ohmic,Ohmic.i,physics/device_structures
    # impedance,Impedance,Impedance.i,physics/device_structures #
    # impedances,Impedances,Impedances.i,physics/device_structures #
    # gate_relations,GateRelations,GateRelations.i,physics/device_structures #
    # prefix,Prefix,Prefix.i,physics/units unit,Unit,Unit.i,physics/units #
    # symbol_unit,SymbolUnit,SymbolUnit.i,physics/units #
    # instrument_port,InstrumentPort,InstrumentPort.i,instrument_interfaces/names
    # # ports,Ports,Ports.i,instrument_interfaces/names #
    # quantity,Quantity,Quantity.i,math #
    # control_array,ControlArray,ControlArray.i,math/arrays #
    # control_array_1D,ControlArray1D,ControlArray1D.i,math/arrays #
    # increasing_alignment,IncreasingAlignment,IncreasingAlignment.i,math/arrays
    # # measured_array,MeasuredArray,MeasuredArray.i,math/arrays)
)

# --- Pre-pass: Create directories and __init__.py files ---
set(PYTHON_PACKAGE_ROOT
    "${CMAKE_CURRENT_SOURCE_DIR}/../dist/python/src/falcon_core")
set(UNIQUE_SUBMODULE_PATHS "")
foreach(MODULE_STRING IN LISTS PYBIND_MODULES)
  string(REPLACE "," ";" MODULE_VALUES "${MODULE_STRING}")
  list(GET MODULE_VALUES 3 SUBMODULE_PATH)
  list(FIND UNIQUE_SUBMODULE_PATHS "${SUBMODULE_PATH}" FOUND_INDEX)
  if(FOUND_INDEX EQUAL -1)
    list(APPEND UNIQUE_SUBMODULE_PATHS "${SUBMODULE_PATH}")
  endif()
endforeach()

if(NOT EXISTS "${PYTHON_PACKAGE_ROOT}/__init__.py")
  file(WRITE "${PYTHON_PACKAGE_ROOT}/__init__.py" "")
  message(STATUS "Created __init__.py in: ${PYTHON_PACKAGE_ROOT}")
endif()
foreach(SUBMODULE_PATH IN LISTS UNIQUE_SUBMODULE_PATHS)
  string(REPLACE "/" ";" SUBMODULE_LIST "${SUBMODULE_PATH}")
  set(PACKAGE_PATH "${PYTHON_PACKAGE_ROOT}")
  foreach(PART ${SUBMODULE_LIST})
    set(PACKAGE_PATH "${PACKAGE_PATH}/${PART}")
    if(NOT EXISTS "${PACKAGE_PATH}")
      file(MAKE_DIRECTORY "${PACKAGE_PATH}")
      message(STATUS "Created directory: ${PACKAGE_PATH}")
    endif()
    if(NOT EXISTS "${PACKAGE_PATH}/__init__.py")
      file(WRITE "${PACKAGE_PATH}/__init__.py" "")
      message(STATUS "Created __init__.py in: ${PACKAGE_PATH}")
    endif()
  endforeach()
endforeach()

# --- Build pass: Build pybind11 modules ---
foreach(MODULE_STRING IN LISTS PYBIND_MODULES)
  string(REPLACE "," ";" MODULE_VALUES "${MODULE_STRING}")
  list(GET MODULE_VALUES 0 MOD_NAME)
  list(GET MODULE_VALUES 2 CPP_FILE)
  list(GET MODULE_VALUES 3 SUBMODULE_PATH)
  set(SRC_PATH "${CMAKE_CURRENT_SOURCE_DIR}/${SUBMODULE_PATH}/${CPP_FILE}")
  set(PACKAGE_PATH "${PYTHON_PACKAGE_ROOT}/${SUBMODULE_PATH}")
  message(
    STATUS
      "Building pybind11 module: ${MOD_NAME} from ${SRC_PATH} to ${PACKAGE_PATH}"
  )
  add_library(${MOD_NAME} MODULE ${SRC_PATH})
  target_link_libraries(${MOD_NAME} PRIVATE pybind11::module Python3::Python
                                            falcon_core_cpp)
  target_include_directories(
    ${MOD_NAME} PRIVATE ${Python3_INCLUDE_DIRS} ../include
                        ../vcpkg_installed/x64-linux/include)
  set_target_properties(
    ${MOD_NAME}
    PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PACKAGE_PATH}"
               PREFIX ""
               SUFFIX ".so")
endforeach()
