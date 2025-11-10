# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_wp_map_tools_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED wp_map_tools_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(wp_map_tools_FOUND FALSE)
  elseif(NOT wp_map_tools_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(wp_map_tools_FOUND FALSE)
  endif()
  return()
endif()
set(_wp_map_tools_CONFIG_INCLUDED TRUE)

# output package information
if(NOT wp_map_tools_FIND_QUIETLY)
  message(STATUS "Found wp_map_tools: 1.0.0 (${wp_map_tools_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'wp_map_tools' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${wp_map_tools_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(wp_map_tools_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_dependencies-extras.cmake;rosidl_cmake-extras.cmake;ament_cmake_export_include_directories-extras.cmake;ament_cmake_export_libraries-extras.cmake;ament_cmake_export_targets-extras.cmake;rosidl_cmake_export_typesupport_targets-extras.cmake;rosidl_cmake_export_typesupport_libraries-extras.cmake")
foreach(_extra ${_extras})
  include("${wp_map_tools_DIR}/${_extra}")
endforeach()
