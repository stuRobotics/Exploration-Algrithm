cmake_minimum_required(VERSION 2.8.3)
project(trajectory)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  message_generation
  std_msgs
  nav_msgs
  tf
)

add_message_files(FILES Time_route.msg)

generate_messages(DEPENDENCIES std_msgs)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES trajectory
CATKIN_DEPENDS message_runtime nav_msgs roscpp rospy std_msgs tf
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/trajectory.cpp
# )

# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(odom_pub_node src/odom_pub.cpp)
target_link_libraries(odom_pub_node ${catkin_LIBRARIES})
add_executable(trajectory_pub_node src/trajectory_pub.cpp)
target_link_libraries(trajectory_pub_node ${catkin_LIBRARIES})
add_executable(route_pub_node src/route_pub.cpp)
target_link_libraries(route_pub_node ${catkin_LIBRARIES})

# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
# target_link_libraries(${PROJECT_NAME}_node
#   ${catkin_LIBRARIES}
# )


