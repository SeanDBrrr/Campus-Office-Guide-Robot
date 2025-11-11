# Campus-Office-Guide-Robot
This project involves developing an autonomous guide robot for campus and office environments using ROS 2, IoT, and Edge AI technologies. The robot is designed to navigate, recognize objects, and interact with users, providing intelligent assistance and real-time guidance in indoor spaces.

# Package descriptions
## robi__core
Core C++ package that will hold “real” robot logic later. This package is your compiled code (fast, deployable).

## robi_bringup:
Bringup (Python) package: only for launch files & system startup. This package stays light and only orchestrates startup. For future implementation of multiple nodes (vision, control, voice bridge…), all launched together.

# Development 
Open the repo in VS Code → Reopen in Container → use tasks to build.
