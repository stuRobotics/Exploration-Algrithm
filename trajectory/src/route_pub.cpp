#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/Pose.h>
#include <trajectory/Time_route.h>
class Route
{
public:
	int flag;
	ros::Duration run_time;
	std_msgs::Float64 route;
	
	ros::Time time_last;
	geometry_msgs::Pose pose_last;
	
	trajectory::Time_route tr_msgs;
	Route()//construction
	{
		flag = 0;
		route.data = 0;
		run_time = ros::Duration(0);		
		//Topic you want to publish
		pub_ = n_.advertise<trajectory::Time_route>("/route_topic", 10);
		//Topic you want to subscribe
		sub_ = n_.subscribe("odom",1000,&Route::callback,this);
	}
	void callback(const nav_msgs::OdometryConstPtr& odom)
	{
		
		if(flag)
		{
			
			double dx,dy,ds;
			geometry_msgs::Pose pose_now;
			pose_now = odom->pose.pose;
			dx=pose_now.position.x-pose_last.position.x;
			dy=pose_now.position.y-pose_last.position.y;
			ds=sqrt(dx*dx+dy*dy);
			ds=ds>0.00001?ds:0;
			route.data = route.data + ds;

			ros::Time time_now;
			time_now = odom->header.stamp;
			run_time = run_time + (time_now-time_last); 				
		}
		else
			flag = 1;
		pose_last = odom->pose.pose;
		time_last = odom->header.stamp;
		
		tr_msgs.run_time=run_time;
		tr_msgs.route=route.data;
		pub_.publish(tr_msgs);
		ROS_INFO("length:%f",(double)route.data);
	}
private:
	//defination of class members
	ros::NodeHandle n_; 
	ros::Publisher pub_;
	ros::Subscriber sub_;
};

int main(int argc, char** argv){
	ros::init(argc, argv, "route_publisher");
	Route RouteObject;//create an object
	ros::spin();
	return 0;
}

