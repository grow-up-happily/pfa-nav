#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rmoss_cam::rmoss_cam" for configuration "Release"
set_property(TARGET rmoss_cam::rmoss_cam APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rmoss_cam::rmoss_cam PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/librmoss_cam.so"
  IMPORTED_SONAME_RELEASE "librmoss_cam.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS rmoss_cam::rmoss_cam )
list(APPEND _IMPORT_CHECK_FILES_FOR_rmoss_cam::rmoss_cam "${_IMPORT_PREFIX}/lib/librmoss_cam.so" )

# Import target "rmoss_cam::usb_cam_component" for configuration "Release"
set_property(TARGET rmoss_cam::usb_cam_component APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rmoss_cam::usb_cam_component PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libusb_cam_component.so"
  IMPORTED_SONAME_RELEASE "libusb_cam_component.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS rmoss_cam::usb_cam_component )
list(APPEND _IMPORT_CHECK_FILES_FOR_rmoss_cam::usb_cam_component "${_IMPORT_PREFIX}/lib/libusb_cam_component.so" )

# Import target "rmoss_cam::virtual_cam_component" for configuration "Release"
set_property(TARGET rmoss_cam::virtual_cam_component APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rmoss_cam::virtual_cam_component PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libvirtual_cam_component.so"
  IMPORTED_SONAME_RELEASE "libvirtual_cam_component.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS rmoss_cam::virtual_cam_component )
list(APPEND _IMPORT_CHECK_FILES_FOR_rmoss_cam::virtual_cam_component "${_IMPORT_PREFIX}/lib/libvirtual_cam_component.so" )

# Import target "rmoss_cam::image_task_demo_component" for configuration "Release"
set_property(TARGET rmoss_cam::image_task_demo_component APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rmoss_cam::image_task_demo_component PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libimage_task_demo_component.so"
  IMPORTED_SONAME_RELEASE "libimage_task_demo_component.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS rmoss_cam::image_task_demo_component )
list(APPEND _IMPORT_CHECK_FILES_FOR_rmoss_cam::image_task_demo_component "${_IMPORT_PREFIX}/lib/libimage_task_demo_component.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
