#!/bin/bash
set -e


apt-get update && apt-get install -y ros-jazzy-moveit ros-jazzy-rviz-visual-tools

# Source ROS 2 setup
source /opt/ros/jazzy/setup.bash

# Source workspace if built
if [ -f "/abbflightsim_ws/install/setup.bash" ]; then
    source /abbflightsim_ws/install/setup.bash
fi

echo "Welcome to the ABB IRB7600 Environment!"

# Execute the container's main command (or default to bash)
exec "$@"
