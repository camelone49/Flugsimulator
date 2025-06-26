from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch.substitutions import Command, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # Get package directories
    irb7600_pkg = FindPackageShare('abb_irb7600')
    ros_gz_sim_pkg_path = get_package_share_directory('ros_gz_sim')

    # Paths
    xacro_file = PathJoinSubstitution([
        irb7600_pkg,
        'description',
        'urdf',
        'irb7600_150_350.urdf.xacro'
    ])
    gz_launch_file = PathJoinSubstitution([
        ros_gz_sim_pkg_path,
        'launch',
        'gz_sim.launch.py'
    ])

    # Generate the launch description
    return LaunchDescription([
        # Launch Gazebo with empty world
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(gz_launch_file),
            launch_arguments={'gz_args': '-r empty.sdf'}.items()
        ),

        # Publish the robot description using xacro
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{
                'robot_description': Command(['xacro ', xacro_file])
            }]
        )
    ])
