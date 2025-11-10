#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rmoss_util::rmoss_util" for configuration "Release"
set_property(TARGET rmoss_util::rmoss_util APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rmoss_util::rmoss_util PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/librmoss_util.so"
  IMPORTED_SONAME_RELEASE "librmoss_util.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS rmoss_util::rmoss_util )
list(APPEND _IMPORT_CHECK_FILES_FOR_rmoss_util::rmoss_util "${_IMPORT_PREFIX}/lib/librmoss_util.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
