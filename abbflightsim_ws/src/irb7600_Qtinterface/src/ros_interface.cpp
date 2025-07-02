#include "irb7600_qtinterface/ros_interface.hpp"


// Constructor
RosInterface::RosInterface()
: QObject(), rclcpp::Node("ros_interface_node")
{
    std::cout << "Constructing RosInterface" << std::endl;

    subscription_armcontroller = this->create_subscription<control_msgs::msg::JointTrajectoryControllerState>(
        "/arm_controller/controller_state",
        10,
        std::bind(&RosInterface::armcontroller_topic_callback, this, std::placeholders::_1));

    publisher_jointpositions = this->create_publisher<trajectory_msgs::msg::JointTrajectory>(
        "/arm_controller/joint_trajectory",
        10);

    service_call_timer_ = new QTimer(this);
    connect(service_call_timer_, &QTimer::timeout, this, [this](){
        this->controllerStatusUpdate();
    });
    service_call_timer_->start(500); //ms
}
RosInterface::~RosInterface() {
    //deconstructor
}

// Subscriber callback to the armcontroller
void RosInterface::armcontroller_topic_callback(const control_msgs::msg::JointTrajectoryControllerState::SharedPtr msg)
{
    if (msg->feedback.positions.size() < 6) return;  // safety check

    // Update internal joint positions
    for (size_t i = 0; i < 6; ++i) {
        joint_positions_[i] = msg->feedback.positions[i];
        desired_joint_positions_[i] = msg->reference.positions[i];
    }

    // Emit signals with correct indices
    emit receivedJoint1_Position(joint_positions_[0]);
    emit receivedJoint2_Position(joint_positions_[1]);
    emit receivedJoint3_Position(joint_positions_[2]);
    emit receivedJoint4_Position(joint_positions_[3]);
    emit receivedJoint5_Position(joint_positions_[4]);
    emit receivedJoint6_Position(joint_positions_[5]);

    emit receivedJoint1_Desired(desired_joint_positions_[0]);
    emit receivedJoint2_Desired(desired_joint_positions_[1]);
    emit receivedJoint3_Desired(desired_joint_positions_[2]);
    emit receivedJoint4_Desired(desired_joint_positions_[3]);
    emit receivedJoint5_Desired(desired_joint_positions_[4]);
    emit receivedJoint6_Desired(desired_joint_positions_[5]);
}

//Timer Callback function
void RosInterface::controllerStatusUpdate(){

    //update the passed time 
    uiPassedTimeCounter++; 
    if (uiPassedTimeCounter >= 10){
        bPassedTime_5sec = !bPassedTime_5sec;
        uiPassedTimeCounter = 0;
    }

    //hier kommt der Service call mit dem Timer, der vorgegeben ist
    int controller_list_indicator = RosInterface::list_controllers_service_call();
    int trajectory_indicator = RosInterface::trajectory_executing_check();
    int hw_status_indicator = RosInterface::hw_interface_check();
    int controller_manager_status = RosInterface::controller_manager_check();

    //call the update label function
    RosInterface::update_controller_status_labels(controller_manager_status,controller_list_indicator,hw_status_indicator,trajectory_indicator);
}
//A function that lists the active controllers
int RosInterface::list_controllers_service_call(){
    using ListControllers = controller_manager_msgs::srv::ListControllers;

    auto client = this->create_client<ListControllers>("/controller_manager/list_controllers");

    if (!client->wait_for_service(std::chrono::seconds(3))) {
        RCLCPP_ERROR(this->get_logger(), "Service not available");
        return 2;
    }

    auto request = std::make_shared<ListControllers::Request>();
    auto future = client->async_send_request(request);

    if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future) !=rclcpp::FutureReturnCode::SUCCESS) {
        RCLCPP_ERROR(this->get_logger(), "Failed to call service");
        return 4;
    }

    auto response = future.get();

    for (const auto &controller : response->controller) {
        if (!bPassedTime_5sec) {  // Check JBS when toggle is false
            if (controller.name == "joint_state_broadcaster") {
                if (controller.state == "active") {
                    return 2;
                }
                else {
                    return 3;
                }
            }
        }
        else {  // Check arm_controller when toggle is true
            if (controller.name == "arm_controller") {
                if (controller.state == "active") {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    }

    return 3;
}
//A function that returns if the controller manager is online
int RosInterface::controller_manager_check(){
    int controller_manager_status_flag = 0;
    auto node = rclcpp::Node::make_shared("node_checker");

    std::string target_node = "/controller_manager";

    if (RosInterface::is_node_running(node, target_node)){
        controller_manager_status_flag = 0;
    }
    else{
        controller_manager_status_flag = 1;
    }

    return controller_manager_status_flag;
}

bool RosInterface::is_node_running(rclcpp::Node::SharedPtr node, const std::string& node_name){
    // Get list of nodes currently in ROS graph
    std::vector<std::string> nodes = node->get_node_names();

    return std::find(nodes.begin(), nodes.end(), node_name) != nodes.end();
}

//implement this function if i also have other hw interfaces other than gazebo (e. g. prototype). For now check if gz_ros_control is running
int RosInterface::hw_interface_check(){
    int hw_interface_state = 0;
    auto node = rclcpp::Node::make_shared("node_checker");

    std::string target_node = "/gz_ros_control";

    if (RosInterface::is_node_running(node, target_node)){
        hw_interface_state = 0;
    }
    else{
        hw_interface_state = 1;
    }

    return hw_interface_state;
}

int RosInterface::trajectory_executing_check(){
    bool executing_trajectory_flag = false; 
    int trajectory_indicator = 1; //1 indicates normal function, 0 executing, 2 nothing
    
    for (int i = 0; i < 6; ++i){
        if (std::abs(desired_joint_positions_[i] - joint_positions_[i]) > epsilon){
            executing_trajectory_flag = true;
            trajectory_indicator = 0;
            break;
        }
    }
    return trajectory_indicator;
}

//Function that updates the controller status labels 
void RosInterface::update_controller_status_labels(int input_cm, int input_cl, int input_hw, int input_tra){

  QStringList controllerManagerStatusStrings; //convert variables to Qstringlist
  for (const auto &status : controller_manager_status) {
    controllerManagerStatusStrings << QString::fromStdString(status);
  }

  QStringList controllerStatusStrings;
  for (const auto &ctrl : controller_list) {
    controllerStatusStrings << QString::fromStdString(ctrl);
  }

  QStringList hwStatusStrings;
  for (const auto &status : hw_interface_status) {
    hwStatusStrings << QString::fromStdString(status);
  }

  QStringList trajectoryStatusStrings;
  for (const auto &status : trajectory_status) {
    trajectoryStatusStrings << QString::fromStdString(status);
  }

  switch (input_cm){//depending on the input of the function, emit the desired signal (that could be done in a much cleaner way!!)
    case 0:
        emit controllerManagerStatus(controllerManagerStatusStrings.value(0), QColor(Qt::darkGreen));
        break;
    case 1:
        emit controllerManagerStatus(controllerManagerStatusStrings.value(1), QColor(Qt::darkRed));
        break;
    default:
        emit controllerManagerStatus(controllerManagerStatusStrings.value(2), QColor(Qt::darkYellow));
        break;
  }

  switch (input_cl){
    case 0:
        emit controllerList(controllerStatusStrings.value(0), QColor(Qt::darkGreen));
        break;
    case 1:
        emit controllerList(controllerStatusStrings.value(1), QColor(Qt::darkRed));
        break;
    case 2:
        emit controllerList(controllerStatusStrings.value(2), QColor(Qt::darkGreen));
        break;
    case 3:
        emit controllerList(controllerStatusStrings.value(3), QColor(Qt::darkRed));
        break;
  }

  switch (input_hw){
    case 0:
        emit hardwareInterfaceStatus(hwStatusStrings.value(0), QColor(Qt::darkGreen));
        break;
    case 1:
        emit hardwareInterfaceStatus(hwStatusStrings.value(1), QColor(Qt::darkRed));
        break;
    default:
        emit hardwareInterfaceStatus(hwStatusStrings.value(2), QColor(Qt::darkYellow));
        break;
  }

  switch (input_tra){
    case 0:
        emit trajectoryExecutionStatus(trajectoryStatusStrings.value(0), QColor(Qt::darkRed));
        break;
    case 1:
        emit trajectoryExecutionStatus(trajectoryStatusStrings.value(1), QColor(Qt::darkGreen));
        break;
    default:
        emit trajectoryExecutionStatus(trajectoryStatusStrings.value(2), QColor(Qt::darkYellow));
        break;
  }
}

//Setpoints for the Robot
void RosInterface::setDesiredJointPositions(const std::array<double, 6> &positions) {
    for (size_t i = 0; i < 6; ++i)
        user_desired_joint_positions_[i] = positions[i];
}

//publish the joint positions
void RosInterface::publish_joint_positions()
{
    trajectory_msgs::msg::JointTrajectory joint_trajectory_msg;
    joint_trajectory_msg.joint_names = {"joint_1", "joint_2", "joint_3", "joint_4", "joint_5", "joint_6"};

    trajectory_msgs::msg::JointTrajectoryPoint point;
    point.positions = {
        user_desired_joint_positions_[0],
        user_desired_joint_positions_[1],
        user_desired_joint_positions_[2],
        user_desired_joint_positions_[3],
        user_desired_joint_positions_[4],
        user_desired_joint_positions_[5]
    };
    point.time_from_start.sec = 0;  // Example time from start
    point.time_from_start.nanosec = 5000;

    joint_trajectory_msg.points.push_back(point);


    publisher_jointpositions->publish(joint_trajectory_msg);
}

#include "ros_interface.moc"
// This line is necessary to ensure the MOC (Meta-Object Compiler) processes the signals and slots correctly