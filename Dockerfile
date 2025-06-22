FROM osrf/ros:jazzy-desktop-full

RUN apt-get update && apt-get install -y \
    python3-pip \
    python3-rosdep \
    python3-vcstool \
    python3-colcon-common-extensions \
    python3-argcomplete \
    python3-pytest 


#install gazebo 
RUN apt-get update && apt-get install -y \
    curl lsb-release gnupg

RUN curl https://packages.osrfoundation.org/gazebo.gpg --output /usr/share/keyrings/pkgs-osrf-archive-keyring.gpg
RUN echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/pkgs-osrf-archive-keyring.gpg] http://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/gazebo-stable.list > /dev/null
RUN apt-get update
RUN apt-get install -y gz-harmonic
RUN apt install -y ros-jazzy-urdf-tutorial

#do all the rest
RUN rm -rf /var/lib/apt/lists/*

RUN apt-get install -y git

RUN mkdir -p /catkin_ws/src && cd /catkin_ws/src

RUN git clone https://github.com/MOGI-ROS/Week-1-2-Introduction-to-ROS2.git



RUN echo "ALL DONE"

#to build the image, run: docker build -t "insert_your_image_name" .
#to run the image, run:docker run -it "insert_your_image_name" bash

#flags for docker run:
#-it: interactive terminal
#--rm: remove the container after it exits
#-v "${PWD}:/catkin_ws" : mount a volume (e.g., your local catkin workspace) to the container
#--name "insert_your_container_name": name the container
#--network=host: use the host's network stack
#-e DISPLAY=host.docker.internal:0.0: set the DISPLAY environment variable for GUI applications
#--gpus all: use all available GPUs (if applicable)
#-p 8888:8888: map port 8888 from the container to the host (if needed)
#