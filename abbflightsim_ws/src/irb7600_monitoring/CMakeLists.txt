cmake_minimum_required(VERSION 3.8)
project(irb7600_monitoring)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(control_msgs REQUIRED)
find_package(trajectory_msgs REQUIRED)

# If you actually need these packages, keep them, otherwise you can remove them:
find_package(controller_manager REQUIRED)
find_package(gripper_controllers REQUIRED)
find_package(ros2_control REQUIRED)
find_package(ros2_controllers REQUIRED)
find_package(xacro REQUIRED)

add_executable(monitor_jointpos src/monitor_jointpos.cpp)

ament_target_dependencies(monitor_jointpos
  rclcpp
  std_msgs
  control_msgs
  trajectory_msgs
  # add others here if you use them
)

install(TARGETS
  monitor_jointpos
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
