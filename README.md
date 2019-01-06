# Exploration-Algrithm

## How to run this project?

clone it into your working space and use compile it
```Bash
cd XX_ws
catkin_make
```
then add it to the source
```Bash
source ~/XX_ws/devel/setup.bash
```
after this, you can run the command bellow to see the simulation environment and the auto exploration process
```Bash
roslaunch nearest_frontier_planner single_simulated_frontier.launch
```
in a new terminal, run
```Bash
roslaunch explore_lite explore.launch
```
now you can see the robot is running and mapping

## 
