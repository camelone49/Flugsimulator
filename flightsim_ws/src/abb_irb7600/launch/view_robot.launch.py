from launch import LaunchDescription
from launch_ros.actions import Node
import os

from ament_index_python.packages import get_package_share_directory
import xacro

def generate_launch_description():
    pkg_path = get_package_share_directory('abb_irb7600')
    xacro_path = os.path.join(pkg_path, 'description', 'urdf', 'irb7600_150_350.urdf.xacro')
    
    # Process Xacro
    robot_description_config = xacro.process_file(xacro_path).toxml()

    return LaunchDescription([
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            parameters=[{'robot_description': robot_description_config}],
            output='screen'
        ),      
        
        Node(
            package="joint_state_publisher_gui",
            executable="joint_state_publisher_gui",
            name="joint_state_publisher_gui",
        ), 
        
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', os.path.join(pkg_path, 'config', 'view.rviz')],
            output='screen'
        )
    ])
