# Exploration-Algrithm

## GFEexploration

### How to run this project?

1.Clone it into your working space and use compile it:
```Bash
cd ~/XX_ws
catkin_make
```
Ps: You might get some warning when you compile it, it's because some head files may hasn's been created in your package, in this case you can try to `compile it more than once` and it will skip some of those files and finish the whole compile process then creat those files automatically. In other word, if you keep compiling it more than once, it will be sucessful ultimately.

2.Then add it to the source:
```Bash
source ~/XX_ws/devel/setup.bash
```
3.After this, you can run the command bellow to see the simulation environment and the auto exploration program:
```Bash
roslaunch nearest_frontier_planner single_simulated_frontier.launch
```
4.In a new terminal, run:
```Bash
roslaunch explore_lite explore.launch
```
now you can see the robot is running and mapping;

5.In another new terminal, run:
```Bash
rostopic echo /route_topic
```
then You can see the total time and total path length at present in this terminal;

6.Open another new terminal, run:
```Bash
rosrun using_markers text
```
7.In rviz, add visualization by three topic: /trajectory, /Line and /PointMarker, in this case you'll see the trajectory and current goal as well as current scope of exploration.

### About some details

1.The "explore" package is about GFE exploration which is base on Greedy-frontier exploration strategy which according to this git: https://github.com/hrnr/m-explore

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
5.You can change the weight of frontier information(frontier size) and the weight of frontier distance by changing this in explore.launch:
```HTML
<param name="potential_scale" value="3.0"/><!--the weight of frontier distance-->
<param name="gain_scale" value="0.0"/><!--the weight of frontier information-->
```
6.Since the exploration goal is chosen according to our map, and the optimal exploration sequence is calculated by simulated annealing algorithm, you can change them in explore.cpp, and the variable ox, oy is the length and width of the exploration area:
```C++
double ox=0,oy=0;
case 0: px=-5.642+ox;py=5.1908+oy;break;
case 1: px=-2.2746+ox;py=4.8702+oy;break;
```
