#!/bin/bash
set -e

# Source the ROS 2 setup script
source /opt/ros/jazzy/setup.bash

# Source workspace if built
if [ -f "/app/install/setup.bash" ]; then
    source /app/install/setup.bash
fi

# Execute the passed command (default is 'bash' from Dockerfile CMD)
exec "$@"
