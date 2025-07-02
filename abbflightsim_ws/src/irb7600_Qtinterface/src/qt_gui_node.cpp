#include <QApplication>
#include <QMainWindow>
#include <QTimer>
#include <QColor>
#include "irb7600_qtinterface/ui_irb7600_widget.hpp"  // Include your generated UI header

#include "rclcpp/rclcpp.hpp"
#include "irb7600_qtinterface/ros_interface.hpp"  // Include your ROS interface header
#include <random>

void connectUiSignals(Ui_FlightSimControl_MainWindow &ui, RosInterface &ros_interface, QObject* parent)
{
  QObject::connect(&ros_interface, &RosInterface::receivedJoint1_Position, parent, [&](double val) {
    ui.joint1_actual_label->setText(QString::number(val, 'f', 3));
  });
  QObject::connect(&ros_interface, &RosInterface::receivedJoint2_Position, parent, [&](double val) {
    ui.joint2_actual_label->setText(QString::number(val, 'f', 3));
  });
  QObject::connect(&ros_interface, &RosInterface::receivedJoint3_Position, parent, [&](double val) {
    ui.joint3_actual_label->setText(QString::number(val, 'f', 3));
  });
  QObject::connect(&ros_interface, &RosInterface::receivedJoint4_Position, parent, [&](double val) {
    ui.joint4_actual_label->setText(QString::number(val, 'f', 3));
  });
  QObject::connect(&ros_interface, &RosInterface::receivedJoint5_Position, parent, [&](double val) {
    ui.joint5_actual_label->setText(QString::number(val, 'f', 3));
  });
  QObject::connect(&ros_interface, &RosInterface::receivedJoint6_Position, parent, [&](double val) {
    ui.joint6_acutal_label->setText(QString::number(val, 'f', 3));  // fixed typo
  });

  QObject::connect(&ros_interface, &RosInterface::receivedJoint1_Desired, parent, [&](double val) {
    ui.joint1_desired_label->setText(QString::number(val, 'f', 3));
  });
  QObject::connect(&ros_interface, &RosInterface::receivedJoint2_Desired, parent, [&](double val) {
    ui.joint2_desired_label->setText(QString::number(val, 'f', 3));
  });
  QObject::connect(&ros_interface, &RosInterface::receivedJoint3_Desired, parent, [&](double val) {
    ui.joint3_desired_label->setText(QString::number(val, 'f', 3));
  });
  QObject::connect(&ros_interface, &RosInterface::receivedJoint4_Desired, parent, [&](double val) {
    ui.joint4_desired_label->setText(QString::number(val, 'f', 3));
  });
  QObject::connect(&ros_interface, &RosInterface::receivedJoint5_Desired, parent, [&](double val) {
    ui.joint5_desired_label->setText(QString::number(val, 'f', 3));
  });
  QObject::connect(&ros_interface, &RosInterface::receivedJoint6_Desired, parent, [&](double val) {
    ui.joint6_desired_label->setText(QString::number(val, 'f', 3));
  });

  // Status labels
  QObject::connect(&ros_interface, &RosInterface::controllerManagerStatus, parent, [&](QString status, QColor color) {
    ui.controller_manager_status->setText(status);
    QPalette palette = ui.controller_manager_status->palette();
    palette.setColor(QPalette::WindowText, color);
    ui.controller_manager_status->setPalette(palette);
  });

  QObject::connect(&ros_interface, &RosInterface::controllerList, parent, [&](QString status, QColor color) {
    ui.controller_list_status->setText(status);
    QPalette palette = ui.controller_list_status->palette();
    palette.setColor(QPalette::WindowText, color);
    ui.controller_list_status->setPalette(palette);
  });

  QObject::connect(&ros_interface, &RosInterface::hardwareInterfaceStatus, parent, [&](QString status, QColor color) {
    ui.hwinterface_status->setText(status);
    QPalette palette = ui.hwinterface_status->palette();
    palette.setColor(QPalette::WindowText, color);
    ui.hwinterface_status->setPalette(palette);
  });

  QObject::connect(&ros_interface, &RosInterface::trajectoryExecutionStatus, parent, [&](QString status, QColor color) {
    ui.trajectory_status->setText(status);
    QPalette palette = ui.trajectory_status->palette();
    palette.setColor(QPalette::WindowText, color);
    ui.trajectory_status->setPalette(palette);
  });

  // Button clicks - no changes here, looks fine
  QObject::connect(ui.publishradpos, &QPushButton::clicked, [&]() {
    double val1 = ui.joint1_rad->text().toDouble();
    double val2 = ui.joint2_rad->text().toDouble();
    double val3 = ui.joint3_rad->text().toDouble();
    double val4 = ui.joint4_rad->text().toDouble();
    double val5 = ui.joint5_rad->text().toDouble();
    double val6 = ui.joint6_rad->text().toDouble();

    ros_interface.setDesiredJointPositions({val1, val2, val3, val4, val5, val6});
    ros_interface.publish_joint_positions();
  });

  QObject::connect(ui.centerpos_pushbutton, &QPushButton::clicked, [&]() {
    ros_interface.setDesiredJointPositions({0,0,0,0,0,0});
    ros_interface.publish_joint_positions();
  });

  QObject::connect(ui.randompos_pushbutton, &QPushButton::clicked, [&]() {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_real_distribution<> dis1(-1.57, 1.57);
    std::uniform_real_distribution<> dis2(-1.047, 1.4835);
    std::uniform_real_distribution<> dis3(-1.57, 1.047);
    std::uniform_real_distribution<> dis4(-5.236, 5.236);
    std::uniform_real_distribution<> dis5(-1.745, 1.745);
    std::uniform_real_distribution<> dis6(-3.141, 3.141);

    std::array<double, 6> random_positions = {dis1(gen), dis2(gen), dis3(gen), dis4(gen), dis5(gen), dis6(gen)};
    ros_interface.setDesiredJointPositions(random_positions);
    ros_interface.publish_joint_positions();
  });
}



//main function that spins the node
int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  QApplication app(argc, argv);

  // Qt main window
  QMainWindow window;
  Ui_FlightSimControl_MainWindow ui;
  ui.setupUi(&window);

  // Instantiate your ROS interface
  RosInterface ros_interface;

  // Connect ROS signal to update GUI label
  connectUiSignals(ui, ros_interface, &window);


  // Spin ROS inside Qt
  QTimer ros_timer;
  QObject::connect(&ros_timer, &QTimer::timeout, [&]() {
    rclcpp::spin_some(ros_interface.get_node_base_interface());
  });
  ros_timer.start(10);  // ms

  window.show();
  int ret = app.exec();
  rclcpp::shutdown();
  return ret;
}