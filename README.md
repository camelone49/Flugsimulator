# Hishams Flight Simulator Model 
<p align="center">
  <img src="https://github.com/user-attachments/assets/01778c11-7b39-4e70-bb66-18073ae26a80" alt="image" width="400"/>
</p>
(Image from: https://images.squarespace-cdn.com/content/v1/58e3af9f8419c208174bbb4b/536c152f-ecec-45a6-9d9c-927765902610/robotic+motion+simulators+flight+simulation+becrobotics+kuka+6dof+-+1.png)
Is only for visualization!!

## Idea
The idea is to mount a cockpit on to a 6DOF robot and then control the joints such that you feel like you are in your own airplane!
Kind of like this: https://www.youtube.com/watch?v=KW-ONbO5NYU

Here you can find the things I am doing to realize this project. I am starting with a simulation:

## Running Instructions (Currently only for Windows, For Ubuntu change the Docker commands below - Just ask ChatGPT)
I am trying to program this application such that it can be accessed from any computer using a Docker container.
To run the current example (Windows Instructions):

1. Clone the repository
2. Install the Docker Engine https://www.youtube.com/watch?v=JBEUKrjbWqg
3. Install the Windows XLaunch app from https://sourceforge.net/projects/vcxsrv/ and run it, put "0" into the first input where you select the screen. Anything else can stay as it is.
4. Navigate into the folder root and run the following command (It's okay if it takes time):
   ``` bash
   docker build -t hisham_flightsim_image .
   ```
5. Then, you can start the Container by typing:
   ```bash
   docker run -it --rm -v ${PWD}/abbflightsim_ws:/abbflightsim_ws --name first_flightsim_container --network=host -e DISPLAY=host.docker.internal:0.0 --gpus all hisham_flightsim_image
   ```
   Notice how the abbflightsim_ws folder is mounted onto the Container as develop folder.
6. in the Docker Container (for every container shell):
   ```bash
   source /opt/ros/jazzy/setup.bash
   ```
 7. Navigate to the flightsim workspace and build it:
    ``` bash
    cd abbflightsim_ws
    colcon build
    source install/setup.bash
    ```

  8. If you want a basic visualization, continue with this step and you are done! Else (Gazebo Simulation), continue with 9
     ```bash
     ros2 launch irb7600_description robot_state_publisher.py
     ```
   You should now see the Rviz window and the joint state publisher!

9. Now its time to start the Gazebo simulation! run the coming commands in two different shells respectively (Don't forget to source your workspaces from 6. and 7.):
      ```bash
     ros2 launch irb7600_gazebo irb7600.gazebo.launch
     ```
      and
   
      ```bash
     ros2 run irb7600_qtinterface qt_gui_node
     ```

The latter runs the Qt interface that allows you to control the joints of the robot by setting desired joint positions. Also, you will be able to see information about the controller status:

<p align="center">
  <img src="https://github.com/user-attachments/assets/fb401ccc-105f-4dbe-a75e-6bf2febe06b9" alt="dof_qt_interface" width="400"/>
</p>



10. Experiment with the robot! As you might see, the practical joint limits are still not implemented and the controller is a little wild. This is still something to do, just like the inverse kinematics :) You should see the following output:

<p align="center">
  <img src="https://github.com/user-attachments/assets/47c91807-94ef-4d69-b3ce-12a9b844f54f" alt="gif" width="400"/>
</p>

## TODO: 

1. Add the Joint limits
2. Implement the inverse kinematics functionality - more on that and why it is needed and how it is going to enable the operation soon!
3. Customize the controller


    
   

