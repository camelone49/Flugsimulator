from launch import LaunchDescription
from launch.actions import ExecuteProcess, RegisterEventHandler
from launch.event_handlers import OnProcessExit

def generate_launch_description():
    # Start joint state broadcaster
    start_joint_state_broadcaster_cmd = ExecuteProcess(
        cmd=['ros2', 'control', 'load_controller', '--set-state', 'active', 'joint_state_broadcaster'],
        output='screen'
    )

    # Start arm controller (after joint state broadcaster finishes loading)
    start_arm_controller_cmd = ExecuteProcess(
        cmd=['ros2', 'control', 'load_controller', '--set-state', 'active', 'arm_controller'],
        output='screen'
    )

    # Event handler to launch arm controller after joint state broadcaster is done
    load_arm_controller_after_jsb = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=start_joint_state_broadcaster_cmd,
            on_exit=[start_arm_controller_cmd]
        )
    )

    ld = LaunchDescription()
    ld.add_action(start_joint_state_broadcaster_cmd)
    ld.add_action(load_arm_controller_after_jsb)

    return ld
