# CMake generated Testfile for 
# Source directory: /home/yy/sight/pfa-nav/src/rmoss_core/rmoss_util/test
# Build directory: /home/yy/sight/pfa-nav/build/rmoss_util/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_url_resolve "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/yy/sight/pfa-nav/build/rmoss_util/test_results/rmoss_util/test_url_resolve.gtest.xml" "--package-name" "rmoss_util" "--output-file" "/home/yy/sight/pfa-nav/build/rmoss_util/ament_cmake_gtest/test_url_resolve.txt" "--command" "/home/yy/sight/pfa-nav/build/rmoss_util/test/test_url_resolve" "--gtest_output=xml:/home/yy/sight/pfa-nav/build/rmoss_util/test_results/rmoss_util/test_url_resolve.gtest.xml")
set_tests_properties(test_url_resolve PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/yy/sight/pfa-nav/build/rmoss_util/test/test_url_resolve" TIMEOUT "60" WORKING_DIRECTORY "/home/yy/sight/pfa-nav/build/rmoss_util/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/yy/sight/pfa-nav/src/rmoss_core/rmoss_util/test/CMakeLists.txt;3;ament_add_gtest;/home/yy/sight/pfa-nav/src/rmoss_core/rmoss_util/test/CMakeLists.txt;0;")
subdirs("../gtest")
