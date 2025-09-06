#pragma once

#include <rclcpp/rclcpp.hpp>
#include <moveit_visual_tools/moveit_visual_tools.h>
#include <rviz_visual_tools/rviz_visual_tools.hpp>
#include <Eigen/Geometry>
#include <geometry_msgs/msg/pose.hpp>

#include <visualization_msgs/msg/marker.hpp>
#include <visualization_msgs/msg/marker_array.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <std_msgs/msg/color_rgba.hpp>

class VisualizeStuff : public rclcpp::Node
{
public:
  VisualizeStuff();

  // Initialize MoveItVisualTools after node is shared_ptr-managed
  void init();

  void visualizeOrientationMarkers();

private:
  void publishMarkers();

  moveit_visual_tools::MoveItVisualToolsPtr moveit_visual_tools_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::TimerBase::SharedPtr timer_orientation;

  rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr marker_pub_;
};