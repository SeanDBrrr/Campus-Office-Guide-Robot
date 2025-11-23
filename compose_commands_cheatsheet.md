# Docker Compose Workflow Cheatsheet
This cheatsheet lists the most common commands for managing the ROS2 and Code-Server containers defined in the [docker compose file](docker-compose.yml).


## 1. Full Environment Control (Start/Stop)
**Location: (Nano Terminal)**  
**Start the Full Development Stack:**
```bash
docker compose --profile ros2,nano up -d
```
Starts all three containers: ros2_nano (ROS2 background service), ros2_shell (ROS shell), and code (VS Code Server) for remote development.

**Start ONLY the ROS2 Background Service:**
```bash 
docker compose up -d ros2_nano
```
Starts the ros2_nano container, which keeps the ROS environment running in the background for drivers and launch files. 

**Start ONLY the Code Server:**
```bash
docker compose --profile nano up -d code
```
Starts the code-server container for remote editing, freeing up resources used by the ROS background service.

**Stop & Remove All Services:**
```bash
docker compose down
```
Stops all containers, removes them, and destroys the related network. Use for a full cleanup when you are done.

**Stop ONLY the Code Server:**
```bash
docker compose stop code
```
Stops the code container to instantly free up RAM/CPU, but keeps the ros2_nano service running.

## 2. Secure Remote Coding Workflow
 **Location: (Nano Terminal)**    
**Start Code-Server:**
```bash
docker compose --profile nano up -d code
```
Ensures the VS Code Server is running and listening on 127.0.0.1:8080.

**Location: (PC Terminal)**  
**Create Tunnel:**
```url
ssh -L 8080:localhost:8080 robi@192.168.0.213 
```
Ensures the VS Code Server is running and listening.

**Location: (Web Browser URL search bar)**  
**Access VSCode:**
```powershell
http://localhost:8080
```
Browse to this address (not the Nano's IP). The SSH tunnel transparently routes the connection to the secure server on 127.0.0.1:8080.

## 3. ROS2 Testing & Shells
**Location: (Nano Terminal)**  

**Open a New Interactive ROS Shell:**
```bash
docker compose run --rm ros2_shell
```
Starts the ros2_shell helper, automatically sources your ROS 2 workspace, and drops you into a shell. The --rm flag ensures the container is cleaned up when you type exit. Repeat this command for multiple terminals.

**Attach to the Running Background Service:**
```bash
docker compose exec ros2_nano bash
```
Opens a new shell inside the long-running ros2_nano container. Use this to quickly build, run a node, or monitor data while leaving the main service active.

**View Live ROS Logs:**
```bash
docker compose logs -f ros2_nano
```
Streams the real-time output (logs) from your main ros2_nano background service. Useful for monitoring errors or launch file output.