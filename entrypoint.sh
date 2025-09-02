#!/bin/bash
set -e

# Install additional dependencies (only runs when building)
apt-get update && apt-get install -y ros-jazzy-moveit ros-jazzy-rviz-visual-tools ros-jazzy-moveit-visual-tools

# Add ROS and workspace sources to bashrc so every terminal is preloaded
echo "source /opt/ros/jazzy/setup.bash" >> /root/.bashrc
if [ -f "/abbflightsim_ws/install/setup.bash" ]; then
    echo "source /abbflightsim_ws/install/setup.bash" >> /root/.bashrc
fi

# Source immediately for the current shell
source /opt/ros/jazzy/setup.bash
if [ -f "/abbflightsim_ws/install/setup.bash" ]; then
    source /abbflightsim_ws/install/setup.bash
fi

echo "Welcome to the ABB IRB7600 Environment!"

# Execute CMD or bash by default
exec "$@"
