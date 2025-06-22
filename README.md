# Hishams Flight Simulator Model 
![image](https://github.com/user-attachments/assets/01778c11-7b39-4e70-bb66-18073ae26a80)
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
   docker run -it --rm -v ${PWD}/flightsim_ws:/flightsim_ws --name first_flightsim_container --network=host -e DISPLAY=host.docker.internal:0.0 --gpus all hisham_flightsim_image
   ```
   Notice how the flightsim_ws folder is mounted onto the Container as develop folder.
6. in the Docker Container (for every container shell):
   ```bash
   source /opt/ros/jazzy/setup.bash
   ```
 7. Navigate to the flightsim workspace and build it:
    ``` bash
    cd flightsim_ws
    colcon build --packages-select urdf_tutorial
    source install/setup.bash
    ros2 launch urdf_tutorial launch_everything.py
    ```

  8. As of right now, you should see an Rviz2 window popping up with an R2D2 floating around. This is where my further TODO begins :)
  ![image](https://github.com/user-attachments/assets/67084307-46e9-47b5-b557-3484c5cf9b60)

