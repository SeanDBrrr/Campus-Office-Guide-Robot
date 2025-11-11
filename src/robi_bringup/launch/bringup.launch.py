from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='robi_core',
            executable='heartbeat',
            name='robi_heartbeat',
            output='screen'
        )
    ])
