#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include<visualization_msgs/MarkerArray.h>
#include<iostream>
#include "std_msgs/String.h"
#include <stdlib.h>
#include <cmath> 
using namespace std;

class Point
{
public:
	//visualization_msgs::MarkerArray markerArray;
	Point()
	{
		pub=n.advertise<visualization_msgs::Marker>("PointMarker", 10);
		line=n.advertise<visualization_msgs::Marker>("Line", 10);
		sub=n.subscribe("/explore/str_message", 10, &Point::callback,this);
	}
	void callback(const std_msgs::String::ConstPtr& msg)
	{
		//ros::Rate r(60);
		//visualization_msgs::MarkerArray markerArray;
		stringstream stream;
		int k=0,num;
		stream << msg->data;
		stream >>num;
		stream.clear();
	       	float px,py,hx=22,hy=25,res=0.1;
		visualization_msgs::Marker marker,line_list; 
		marker.header.frame_id="map";
		marker.header.stamp = ros::Time::now();
		marker.ns = "basic_shapes";
		marker.action = visualization_msgs::Marker::ADD;
		marker.pose.orientation.w = 1.0;
		marker.id =0;
		marker.type = visualization_msgs::Marker::TEXT_VIEW_FACING;

		marker.scale.z = 0.6;
		marker.color.b = 255;
		marker.color.g = 255;
		marker.color.r = 255;
		marker.color.a = 1;

	  	switch(num)
		{
		    case 0: px=-5.642;py=5.1908;break;
		    case 1: px=-2.2746;py=4.8702;break;
		    case 2: px=1.5299;py=4.5038;break;
		    case 3: px=0.5909;py=0.0763;break;
		    case 4: px=2.5336;py=0.3969;break;
		    case 5: px=3.4078;py=0;break;
		    case 6: px=3.8611;py=-5.1602;break;
		    case 7: px=0.4452;py=-5.0381;break;
		    case 8: px=-2.5498;py=-5.0381;break;
		    case 9: px=-5.4801;py=-5.0381;break;
		    case 10: px=-4.0554;py=-4.5038;break;
		    case 11: px=-5.6420;py=-1.8320;break;
		    case 12: px=-4.4440;py=-1.8320;break;
		    case 13: px=-2.5660;py=0.6107;break;
		    case 14: px=-1.3032;py=4.5038;break;
		    case 15: px=-1.2870;py=4.5038;break;
		    case 16: px=-3.7154;py=4.5038;break;
		    case 17: px=-5.6420;py=5.1908;break;
		    default : ROS_ERROR("num is wrong\n");
		}

		//if(num<17)
		//    num++;
		//else
		//    num=0;

		geometry_msgs::Pose pose;
		pose.position.x =px;
		pose.position.y =py;
		pose.position.z =0;
		ostringstream str;
		str<<num;
		marker.text=str.str();
		marker.pose=pose;

		//cout<<"k="<<k<<endl;
		//markerArray.markers.push_back(marker);
		//cout<<"markerArray.markers.size()"<<markerArray.markers.size()<<endl;
		pub.publish(marker);

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
		
		p.x = px-(hx/2*res); 
		p.y = py-(hy/2*res); //A
		p.z = 0; // The line list needs two points for each line 
		line_list.points.push_back(p); 
		p.x = px+(hx*res); //B
		line_list.points.push_back(p); 
		
		p.x = px+(hx*res); 
		line_list.points.push_back(p); 
		p.y = py+(hy*res);//C
		line_list.points.push_back(p); 

		p.y = py+(hy*res);
		line_list.points.push_back(p); 
		p.x = px-(hx*res); //D
		line_list.points.push_back(p); 

		p.x = px-(hx*res); 
		line_list.points.push_back(p);
		p.y = py-(hy/2*res); 
		line_list.points.push_back(p);

		p.y = py-(hy/2*res); 
		line_list.points.push_back(p);
		p.x = px-(hx/2*res); 
		//p.y = py-(hy/2*res);
		line_list.points.push_back(p); 
		//p.x += 3.0;
		//p.x = px-(hx/2*res); 
		//p.y = py-(hy/2*res); 
		//line_list.points.push_back(p); 
		line.publish(line_list); 		

		//r.sleep();
		k++;
	}
private:
	ros::NodeHandle n;
	ros::Publisher pub;
	ros::Publisher line;
	ros::Subscriber sub;
};

int main( int argc, char** argv )
{
    ros::init(argc, argv, "showline");
    Point pointObject;
    ros::spin();
    
    return 0;
}
