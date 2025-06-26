import os
import launch
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription,SetEnvironmentVariable
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition, UnlessCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch.actions import TimerAction

import xacro

def generate_launch_description():
    package_name = 'abb_irb7600'
    xacro_relative_path = 'description/urdf/irb7600_150_350.urdf.xacro'
    ros2_control_relative_path = 'config/ros2_control.yaml'

    pkg_path = get_package_share_directory(package_name)
    xacro_model_path = os.path.join(pkg_path, xacro_relative_path)
    ros2_control_path = os.path.join(pkg_path, ros2_control_relative_path)

    # Generate robot description from XACRO
    robot_desc = xacro.process_file(xacro_model_path, mappings={'prefix': ''}).toxml()
    robot_description = {'robot_description': robot_desc}

    # Declare launch arguments
    declared_arguments = [
        DeclareLaunchArgument(name="gui", default_value="true", description="Flag to enable GUI"),
    ]

    gui = LaunchConfiguration("gui")

    # Launch Gazebo with GUI or headless
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('ros_gz_sim'), 'launch', 'gz_sim.launch.py'
        )]),
        launch_arguments={"gz_args": "-r -v 3 empty.sdf"}.items(),
        condition=IfCondition(gui)
    )

    gazebo_headless = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('ros_gz_sim'), 'launch', 'gz_sim.launch.py'
        )]),
        launch_arguments={"gz_args": "--headless-rendering -s -r -v 3 empty.sdf"}.items(),
        condition=UnlessCondition(gui)
    )

    # Gazebo-ROS bridge
    gazebo_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        name='ros_gz_bridge',
        output='screen',
        arguments=["/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock"]
    )

    # Spawn robot in simulation
    gz_spawn_entity = Node(
        package='ros_gz_sim',
        executable='create',
        output='screen',
        arguments=[
            "-topic", "/robot_description",
            "-name", "irb7600",
            "-z", "0.0",
            "--allow_renaming", "true"
        ]
    )

    # Robot state publisher
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[robot_description]
    )

    # Control node
    control_node = TimerAction(
        period=20.0,
        actions=[
            Node(
                package='controller_manager',
                executable='ros2_control_node',
                parameters=[robot_description, ros2_control_path],
                output='screen'
            )
        ]
    )

    joint_state_broadcaster_spawner = TimerAction(
        period=30.0,
        actions=[
            Node(
                package='controller_manager',
                executable='spawner',
                arguments=['joint_state_broadcaster'],
                output='screen'
            )
        ]
    )

    robot_controller_spawner = TimerAction(
        period=30.0,
        actions=[
            Node(
                package='controller_manager',
                executable='spawner',
                arguments=["forward_position_controller", "--param-file", ros2_control_path],
                output='screen'
            )
        ]
    )
    

    return LaunchDescription(declared_arguments + [
        robot_state_publisher,
        gazebo,
        gazebo_headless,
        gazebo_bridge,
        gz_spawn_entity,
        control_node,
        joint_state_broadcaster_spawner,
        robot_controller_spawner,
    ])
