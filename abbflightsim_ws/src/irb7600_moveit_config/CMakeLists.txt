cmake_minimum_required(VERSION 3.8)
project(irb7600_moveit_config)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(moveit_ros_move_group REQUIRED)
find_package(moveit_kinematics REQUIRED)
find_package(moveit_ros_visualization REQUIRED)
find_package(rviz2 REQUIRED)
find_package(rviz_visual_tools REQUIRED)

# -------------------------
# Executable
# -------------------------
add_executable(hello_moveit src/hello_moveit.cpp)
add_executable(drive_2221 src/drive_2221.cpp)

ament_target_dependencies(hello_moveit
  rclcpp
  geometry_msgs
  moveit_ros_planning_interface
)

ament_target_dependencies(drive_2221
  rclcpp
  geometry_msgs
  moveit_ros_planning_interface
)

# Install the executable so "ros2 run" can find it
install(TARGETS 
  hello_moveit
  drive_2221
  DESTINATION lib/${PROJECT_NAME}
)

# -------------------------
# Install config/launch/etc
# -------------------------
install(
  DIRECTORY config launch rviz src
  DESTINATION share/${PROJECT_NAME}
)

install(
  FILES .setup_assistant
  DESTINATION share/${PROJECT_NAME}
)

# -------------------------
# Testing
# -------------------------
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
