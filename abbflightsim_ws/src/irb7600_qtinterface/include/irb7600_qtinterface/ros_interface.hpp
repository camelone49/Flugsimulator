#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include "control_msgs/msg/joint_trajectory_controller_state.hpp"
#include <QObject>
#include <iostream>
#include <string>
#include <QString>
#include <QColor>
#include <QTimer>
#include <QColor>
#include <iostream>
#include <functional>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>
#include "controller_manager_msgs/srv/list_controllers.hpp"

#include <trajectory_msgs/msg/joint_trajectory.hpp>


class RosInterface : public QObject, public rclcpp::Node
{
  Q_OBJECT

public:
  RosInterface();
  ~RosInterface();
    // For Qt to spin the node
  rclcpp::node_interfaces::NodeBaseInterface::SharedPtr get_node_base_interface() {
    return rclcpp::Node::get_node_base_interface();
  }

  //function to publish the desired joint positions
  void publish_joint_positions();
  //function to set the desired joint positions
  void setDesiredJointPositions(const std::array<double, 6> &positions);
  //function to update the controller status labels
  void update_controller_status_labels(int, int, int, int);
  //function to call some services
  void controllerStatusUpdate();
  //function to initialize timers

  int list_controllers_service_call();
  int controller_manager_check();
  int hw_interface_check();
  int trajectory_executing_check();
  bool is_node_running(rclcpp::Node::SharedPtr, const std::string&);


signals:

  //received messages for the joint positions and desired positions
  void receivedJoint1_Position(double val);
  void receivedJoint2_Position(double val);
  void receivedJoint3_Position(double val);
  void receivedJoint4_Position(double val);
  void receivedJoint5_Position(double val);
  void receivedJoint6_Position(double val);

  void receivedJoint1_Desired(double val);
  void receivedJoint2_Desired(double val);
  void receivedJoint3_Desired(double val);
  void receivedJoint4_Desired(double val);
  void receivedJoint5_Desired(double val);
  void receivedJoint6_Desired(double val);


  //signals for dissplaying the controller status labels  void controllerManagerStatus(QString, QColor color);
  void controllerManagerStatus(QString, QColor color);
  void controllerList(QString, QColor color);
  void hardwareInterfaceStatus(QString, QColor color);
  void trajectoryExecutionStatus(QString, QColor color);


public slots:
  //void sendMessage(const QString &msg);  // Slot to publish from UI

private:

    //initailzation of subscribers and service calls
  rclcpp::Subscription<control_msgs::msg::JointTrajectoryControllerState>::SharedPtr subscription_armcontroller;
  void armcontroller_topic_callback(const control_msgs::msg::JointTrajectoryControllerState::SharedPtr msg);

  //actual joint positions subscriber
  rclcpp::Publisher<trajectory_msgs::msg::JointTrajectory>::SharedPtr publisher_jointpositions;


  double epsilon = 0.0001;
    //all the metrics that can be displayed or fetched from the UI
  double joint_positions_[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  double desired_joint_positions_[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0}; // Example joint positions
  double target_coordinates_[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0}; // Example target coordinates

  //joint states to be published

  double user_desired_joint_positions_[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0}; // User desired joint positions

  //status label indicators
  std::string controller_manager_status[3] = {"ACTIVE", "INACTIVE", "No Status"}; // controller manager status
  std::string controller_list[4]= { "arm_controller: ACTIVE", 
                              "arm_controller: INACTIVE",
                              "joint_state_broadcaster: ACTIVE",
                              "joint_state_broadcaster: INACTIVE" }; // controller list
  std::string hw_interface_status[3] = {"GAZEBO", "INACTIVE", "No Status"}; // hardware interface status
  std::string trajectory_status[3] = {"EXECUTING", "READY", "No Status"}; // trajectory status

  bool bPassedTime_5sec = false;
  unsigned int uiPassedTimeCounter = 0;

  //Qt members
  QTimer* service_call_timer_;
};
