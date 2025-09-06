cmake_minimum_required(VERSION 3.8)
project(irb7600_rviz_visualization)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)


find_package(moveit_ros_visualization REQUIRED)
find_package(rviz2 REQUIRED)
find_package(rviz_visual_tools REQUIRED)
find_package(moveit_visual_tools REQUIRED)

#headers and source files
set(SOURCES
    src/visualize_stuff.cpp
    src/main_visualize_stuff.cpp
)

set(HEADERS
    include/irb7600_rviz_visualization/visualize_stuff.hpp
)


# -------------------------
# Executable
# -------------------------
add_executable(visualize_stuff ${SOURCES} ${HEADERS})

ament_target_dependencies(visualize_stuff
  rclcpp
  moveit_ros_visualization
  rviz2
  rviz_visual_tools
  moveit_visual_tools
)

target_include_directories(visualize_stuff PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# Install the executable so "ros2 run" can find it
install(TARGETS
    visualize_stuff
  DESTINATION lib/${PROJECT_NAME}
)

# -------------------------
# Install config/launch/etc
# -------------------------
install(
  DIRECTORY rviz include launch
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
