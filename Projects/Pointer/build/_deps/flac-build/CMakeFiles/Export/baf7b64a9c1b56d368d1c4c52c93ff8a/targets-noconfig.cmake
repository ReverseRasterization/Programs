#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "FLAC::FLAC" for configuration ""
set_property(TARGET FLAC::FLAC APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(FLAC::FLAC PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "C;RC"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libFLAC.a"
  )

list(APPEND _cmake_import_check_targets FLAC::FLAC )
list(APPEND _cmake_import_check_files_for_FLAC::FLAC "${_IMPORT_PREFIX}/lib/libFLAC.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
