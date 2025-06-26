from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    gz_sim_path = get_package_share_directory('ros_gz_sim')
    launch_file = os.path.join(gz_sim_path, 'launch', 'gz_sim.launch.py')

    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(launch_file),
            launch_arguments={'gz_args': '-r empty.sdf'}.items()  # -r = run immediately
        )
    ])
