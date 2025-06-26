#include <memory>
#include <sstream>

#include "rclcpp/rclcpp.hpp"
#include "control_msgs/msg/joint_trajectory_controller_state.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

class PositionMonitor : public rclcpp::Node
{
public:
  PositionMonitor(): Node("joint_pos_monitoring")
  {
    using control_msgs::msg::JointTrajectoryControllerState;

    auto armcontroller_topic_callback = [this](JointTrajectoryControllerState::UniquePtr msg) {
      std::ostringstream log_stream;

      log_stream << "\n[Joint State Update from the Arm Controller]\n";
      for (size_t i = 0; i < msg->joint_names.size(); ++i) {
        const auto &name = msg->joint_names[i];
        double desired = msg->reference.positions[i];
        double actual  = msg->feedback.positions[i];
        double error   = msg->error.positions[i];
        log_stream << "  " << name
                   << " | Desired: " << desired
                   << " | Actual: "  << actual
                   << " | Error: "   << error << "\n";
      }

      //log_stream << "Speed Scaling Factor: " << msg->speed_scaling_factor;

      RCLCPP_INFO(this->get_logger(), "%s", log_stream.str().c_str());
    };


    auto jointstate_topic_callback = [this](sensor_msgs::msg::JointState::UniquePtr msg) {
      std::ostringstream log_stream;

      log_stream << "\n[Joint State Update from the JSP]\n";
      for (size_t i = 0; i < msg->name.size(); ++i) {
        const auto &name = msg->name[i];
        double position = msg->position[i];
        log_stream << "  " << name << " | Position: " << position << "\n";
      }

      RCLCPP_INFO(this->get_logger(), "%s", log_stream.str().c_str());
    };


    subscription_armcontroller = this->create_subscription<JointTrajectoryControllerState>("/arm_controller/controller_state", 10,armcontroller_topic_callback);
    subscription_jointstatepub = this->create_subscription<sensor_msgs::msg::JointState>("/joint_states", 10, jointstate_topic_callback);
  }

private:
  rclcpp::Subscription<control_msgs::msg::JointTrajectoryControllerState>::SharedPtr subscription_armcontroller;
  rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription_jointstatepub;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PositionMonitor>());
  rclcpp::shutdown();
  return 0;
}
