#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "wp_map_tools::wp_map_plugins" for configuration "Release"
set_property(TARGET wp_map_tools::wp_map_plugins APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(wp_map_tools::wp_map_plugins PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libwp_map_plugins.so"
  IMPORTED_SONAME_RELEASE "libwp_map_plugins.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS wp_map_tools::wp_map_plugins )
list(APPEND _IMPORT_CHECK_FILES_FOR_wp_map_tools::wp_map_plugins "${_IMPORT_PREFIX}/lib/libwp_map_plugins.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
