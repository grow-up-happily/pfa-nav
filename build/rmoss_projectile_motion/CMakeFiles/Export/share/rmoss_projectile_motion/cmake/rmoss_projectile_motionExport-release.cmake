#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rmoss_projectile_motion::rmoss_projectile_motion" for configuration "Release"
set_property(TARGET rmoss_projectile_motion::rmoss_projectile_motion APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rmoss_projectile_motion::rmoss_projectile_motion PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/librmoss_projectile_motion.so"
  IMPORTED_SONAME_RELEASE "librmoss_projectile_motion.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS rmoss_projectile_motion::rmoss_projectile_motion )
list(APPEND _IMPORT_CHECK_FILES_FOR_rmoss_projectile_motion::rmoss_projectile_motion "${_IMPORT_PREFIX}/lib/librmoss_projectile_motion.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
