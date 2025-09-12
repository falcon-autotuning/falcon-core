#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "hdf5::hdf5-static" for configuration "Debug"
set_property(TARGET hdf5::hdf5-static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(hdf5::hdf5-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/lib/libhdf5_debug.a"
  )

list(APPEND _cmake_import_check_targets hdf5::hdf5-static )
list(APPEND _cmake_import_check_files_for_hdf5::hdf5-static "${_IMPORT_PREFIX}/debug/lib/libhdf5_debug.a" )

# Import target "hdf5::hdf5_hl-static" for configuration "Debug"
set_property(TARGET hdf5::hdf5_hl-static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(hdf5::hdf5_hl-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/lib/libhdf5_hl_debug.a"
  )

list(APPEND _cmake_import_check_targets hdf5::hdf5_hl-static )
list(APPEND _cmake_import_check_files_for_hdf5::hdf5_hl-static "${_IMPORT_PREFIX}/debug/lib/libhdf5_hl_debug.a" )

# Import target "hdf5::hdf5_cpp-static" for configuration "Debug"
set_property(TARGET hdf5::hdf5_cpp-static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(hdf5::hdf5_cpp-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/lib/libhdf5_cpp_debug.a"
  )

list(APPEND _cmake_import_check_targets hdf5::hdf5_cpp-static )
list(APPEND _cmake_import_check_files_for_hdf5::hdf5_cpp-static "${_IMPORT_PREFIX}/debug/lib/libhdf5_cpp_debug.a" )

# Import target "hdf5::hdf5_hl_cpp-static" for configuration "Debug"
set_property(TARGET hdf5::hdf5_hl_cpp-static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(hdf5::hdf5_hl_cpp-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/lib/libhdf5_hl_cpp_debug.a"
  )

list(APPEND _cmake_import_check_targets hdf5::hdf5_hl_cpp-static )
list(APPEND _cmake_import_check_files_for_hdf5::hdf5_hl_cpp-static "${_IMPORT_PREFIX}/debug/lib/libhdf5_hl_cpp_debug.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
