#include "irb7600_rviz_visualization/visualize_stuff.hpp"

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<VisualizeStuff>();

  // initialize MoveItVisualTools now
  node->init();

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
