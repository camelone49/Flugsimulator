from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    rviz_config = os.path.join(
        get_package_share_directory("irb7600_rviz_visualization"),
        "rviz",
        "irb7600_visual.rviz"
    )

    return LaunchDescription([
        Node(
            package="irb7600_rviz_visualization",
            executable="visualize_stuff",
            name="visualize_stuff",
            output="screen",
        ),
        Node(
            package="rviz2",
            executable="rviz2",
            name="rviz2",
            arguments=["-d", rviz_config],
            output="screen",
        )
    ])
