# Exploration-Algrithm

## GFEexploration

### How to run this project?

clone it into your working space and use compile it
```Bash
cd ~/XX_ws
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

### About some details

1.The GFE exploration is base on Greedy-frontier exploration strategy which according to this git: https://github.com/hrnr/m-explore

2.You can change the robot's initial position by changing this in single_simulated_frontier.launch:
```HTML
<arg name="init_pose" value="-x -3.0 -y 3.0 -z 0.0"/>
```
3.You can change the exploration map/environment by changing this in single_simulated_frontier.launch:
```HTML
<arg name="world_name" value="$(find nearest_frontier_planner)/launch/includes/worlds/map1.world"/>
```
4.You can change the range of the sensor by changing this in single_simulated_frontier.launch:
```XML
<range>
  <min>0.1</min>
  <max>6</max><!--this is what you're gona change-->
  <resolution>0.01</resolution>
</range>
```

# `To be continue ...`
