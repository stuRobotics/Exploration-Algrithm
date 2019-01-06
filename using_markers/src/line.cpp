#include <ros/ros.h> 
#include <visualization_msgs/Marker.h> 
#include <cmath> 
int main( int argc, char** argv ) 
{ 
	ros::init(argc, argv, "showline"); 
	ros::NodeHandle n; 
	ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 10); 
	visualization_msgs::Marker line_list; 
	ros::Rate r(60);  
	while (ros::ok()) 
	{ 
		line_list.header.frame_id = "map"; 
		line_list.header.stamp = ros::Time::now(); 
		line_list.ns = "lines"; 
		line_list.action = visualization_msgs::Marker::ADD; 
		line_list.pose.orientation.w = 1.0; 
		line_list.id = 2; 
		line_list.type = visualization_msgs::Marker::LINE_LIST; // LINE_STRIP/LINE_LIST markers use only the x component of scale, for the line width 	
		line_list.scale.x = 0.1; // Line list is red 
		line_list.color.r = 1.0; 
		line_list.color.a = 1.0; // Create the vertices for the points and lines 
		geometry_msgs::Point p; 
		p.x = 0; 
		p.y = 0; 
		p.z = 0; // The line list needs two points for each line 
		line_list.points.push_back(p); 
		p.x += 3.0; 
		line_list.points.push_back(p); 
		p.y += 3.0;
		line_list.points.push_back(p); 
		p.x -= 3.0; 
		line_list.points.push_back(p); 
		p.y -= 3.0;
		line_list.points.push_back(p); 
		marker_pub.publish(line_list); 
		r.sleep(); 
		//f += 1.0; 
	} 
}
