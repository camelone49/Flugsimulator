cmake_minimum_required(VERSION 3.8)
project(irb7600_Qtinterface)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# Find Qt5 packages
find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)  # Enable automatic Qt MOC
set(CMAKE_AUTOUIC ON)  # Enable automatic Qt UIC (if using .ui files)
set(CMAKE_AUTORCC ON)  # Enable automatic Qt RCC (if using resource files)

add_executable(qt_gui_node src/qt_gui_node.cpp)

target_link_libraries(qt_gui_node Qt5::Widgets)
ament_target_dependencies(qt_gui_node rclcpp)

install(TARGETS qt_gui_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
