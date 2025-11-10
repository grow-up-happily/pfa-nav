#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rmoss_gz_base::rmoss_gz_base" for configuration "Release"
set_property(TARGET rmoss_gz_base::rmoss_gz_base APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rmoss_gz_base::rmoss_gz_base PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/librmoss_gz_base.so"
  IMPORTED_SONAME_RELEASE "librmoss_gz_base.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS rmoss_gz_base::rmoss_gz_base )
list(APPEND _IMPORT_CHECK_FILES_FOR_rmoss_gz_base::rmoss_gz_base "${_IMPORT_PREFIX}/lib/librmoss_gz_base.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
