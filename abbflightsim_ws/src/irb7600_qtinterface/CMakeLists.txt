cmake_minimum_required(VERSION 3.8)
project(irb7600_qtinterface)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(control_msgs REQUIRED)
find_package(controller_manager_msgs REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Source and header files
set(SOURCES
  src/ros_interface.cpp
  src/qt_gui_node.cpp
)

set(HEADERS
  include/irb7600_qtinterface/ros_interface.hpp
  include/irb7600_qtinterface/ui_irb7600_widget.hpp
)

# Add executable
add_executable(qt_gui_node ${SOURCES} ${HEADERS})

# Include directories (prefer target_include_directories)
target_include_directories(qt_gui_node PRIVATE include)

# Link libraries
target_link_libraries(qt_gui_node Qt5::Widgets Qt5::Core Qt5::Gui)


# Declare dependencies
ament_target_dependencies(qt_gui_node
  rclcpp
  std_msgs
  control_msgs
  controller_manager_msgs
)

# Install binary and headers
install(TARGETS qt_gui_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include/
)

ament_package()
