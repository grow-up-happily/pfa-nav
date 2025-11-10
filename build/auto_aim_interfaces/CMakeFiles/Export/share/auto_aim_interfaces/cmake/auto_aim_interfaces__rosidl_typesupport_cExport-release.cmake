#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "auto_aim_interfaces::auto_aim_interfaces__rosidl_typesupport_c" for configuration "Release"
set_property(TARGET auto_aim_interfaces::auto_aim_interfaces__rosidl_typesupport_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(auto_aim_interfaces::auto_aim_interfaces__rosidl_typesupport_c PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "rosidl_runtime_c::rosidl_runtime_c;rosidl_typesupport_c::rosidl_typesupport_c"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libauto_aim_interfaces__rosidl_typesupport_c.so"
  IMPORTED_SONAME_RELEASE "libauto_aim_interfaces__rosidl_typesupport_c.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS auto_aim_interfaces::auto_aim_interfaces__rosidl_typesupport_c )
list(APPEND _IMPORT_CHECK_FILES_FOR_auto_aim_interfaces::auto_aim_interfaces__rosidl_typesupport_c "${_IMPORT_PREFIX}/lib/libauto_aim_interfaces__rosidl_typesupport_c.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
