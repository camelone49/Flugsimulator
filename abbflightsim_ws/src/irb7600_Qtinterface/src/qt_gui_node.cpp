#include <QApplication>
#include <QMainWindow>
#include <QTimer>

#include "rclcpp/rclcpp.hpp"

class MyMainWindow : public QMainWindow
{
  // your UI code here
public:
  MyMainWindow() {
    setWindowTitle("irb7600 Qt Interface");
    resize(600, 400);
  }
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  QApplication app(argc, argv);

  auto node = std::make_shared<rclcpp::Node>("qt_gui_node");

  MyMainWindow window;
  window.show();

  // Spin ROS in Qt event loop timer
  QTimer timer;
  QObject::connect(&timer, &QTimer::timeout, [&]() {
    rclcpp::spin_some(node);
  });
  timer.start(10);  // spin ROS every 10 ms
  
  int ret = app.exec();

  rclcpp::shutdown();
  return ret;
}
