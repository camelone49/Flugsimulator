#include "irb7600_rviz_visualization/visualize_stuff.hpp"

VisualizeStuff::VisualizeStuff() : Node("visualize_stuff")
{
  RCLCPP_INFO(this->get_logger(), "VisualizeStuff node created, call init() to setup visual tools");
}

void VisualizeStuff::init(){
  // Now it's safe to call shared_from_this()



  moveit_visual_tools_ = std::make_shared<moveit_visual_tools::MoveItVisualTools>(
      shared_from_this(),  // safe here because node is managed by shared_ptr
      "base_link",
      rviz_visual_tools::RVIZ_MARKER_TOPIC);

  moveit_visual_tools_->deleteAllMarkers();
  moveit_visual_tools_->loadRemoteControl();

  RCLCPP_INFO(this->get_logger(), "MoveItVisualTools initialized");

    marker_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>(rviz_visual_tools::RVIZ_MARKER_TOPIC, 10);

  // Timer to publish example markers every 2 seconds
  timer_ = this->create_wall_timer(
      std::chrono::seconds(45),
      std::bind(&VisualizeStuff::publishMarkers, this));

  timer_orientation = this->create_wall_timer(
      std::chrono::seconds(60),
      std::bind(&VisualizeStuff::visualizeOrientationMarkers, this));
}


void VisualizeStuff::visualizeOrientationMarkers(){

    visualization_msgs::msg::Marker marker;

    marker.header.frame_id = "base_link";
    marker.header.stamp = this->get_clock()->now();   //ROS2 time
    marker.ns = "orientation_spheres";
    marker.id = 0;
    marker.type = visualization_msgs::msg::Marker::SPHERE_LIST;
    marker.action = visualization_msgs::msg::Marker::ADD;

    // Sphere size
    marker.scale.x = 0.1;
    marker.scale.y = 0.1;
    marker.scale.z = 0.1;

    marker.lifetime = rclcpp::Duration::from_seconds(0.0); 

    // Define the points: concentric circles, every 0.5m, every 30°
    const double radius_step = 0.5;
    const double angle_step = M_PI / 6.0; // 30 degrees
    const double max_radius = 6.0;

    for (double radius = radius_step; radius <= max_radius; radius += radius_step) {
        for (double angle = 0.0; angle < 2 * M_PI; angle += angle_step) {
            geometry_msgs::msg::Point p;
            p.x = radius * cos(angle);
            p.y = radius * sin(angle);
            p.z = 0.0;
            marker.points.push_back(p);

            // Per-point color
            std_msgs::msg::ColorRGBA color;
            double hue = angle / (2 * M_PI); // hue from 0–1 around circle
            color.a = 1.0;
            color.r = std::abs(std::sin(M_PI * hue));
            color.g = std::abs(std::sin(M_PI * hue + 2.0 * M_PI / 3.0));
            color.b = std::abs(std::sin(M_PI * hue + 4.0 * M_PI / 3.0));
            marker.colors.push_back(color);
        }
    }

    RCLCPP_INFO(this->get_logger(), "Publishing orientation spheres");

    visualization_msgs::msg::MarkerArray marker_array;
    marker_array.markers.push_back(marker);

    marker_pub_->publish(marker_array);


    //place a text label at every meter in the positive x y plane
    Eigen::Isometry3d text_pose = Eigen::Isometry3d::Identity();
    double num_texts = (max_radius / radius_step);


    for (double i = 0.0; i <= num_texts; i++){
        text_pose.translation() = Eigen::Vector3d(i, 0.15, 0.1);
        moveit_visual_tools_->publishText(text_pose, std::to_string(i) + "m",
                                        rviz_visual_tools::WHITE,
                                        rviz_visual_tools::XXLARGE,
                                        false);

        text_pose.translation() = Eigen::Vector3d(0.15, i, 0.1);
        moveit_visual_tools_->publishText(text_pose, std::to_string(i) + "m",
                                        rviz_visual_tools::WHITE,
                                        rviz_visual_tools::XXLARGE,
                                        false);

        text_pose.translation() = Eigen::Vector3d(-i, -0.15, 0.1);
        moveit_visual_tools_->publishText(text_pose, "-" + std::to_string(i) + "m",
                                        rviz_visual_tools::WHITE,
                                        rviz_visual_tools::XXLARGE,
                                        false);

        text_pose.translation() = Eigen::Vector3d(-0.15, -i, 0.1);
        moveit_visual_tools_->publishText(text_pose, "-" + std::to_string(i) + "m",
                                        rviz_visual_tools::WHITE,
                                        rviz_visual_tools::XXLARGE,
                                        false);
    }
    moveit_visual_tools_->trigger();
}

void VisualizeStuff::publishMarkers()
{
  Eigen::Isometry3d text_pose = Eigen::Isometry3d::Identity();
  text_pose.translation() = Eigen::Vector3d(3.0, 0.0, 1.0);
  //moveit_visual_tools_->publishText(text_pose, "Hello IRB7600!", rviz_visual_tools::YELLOW, rviz_visual_tools::XXLARGE);

  Eigen::Isometry3d axis_pose = Eigen::Isometry3d::Identity();
  axis_pose.translation() = Eigen::Vector3d(0.5, 0.5, 0.5);
  //moveit_visual_tools_->publishAxis(axis_pose, 0.3, 0.03);

  //moveit_visual_tools_->trigger();
}

