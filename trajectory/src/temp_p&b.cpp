#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>

class Trajectory
{
public:
	nav_msgs::Path path;
	Trajectory()//construction
	{
		//Topic you want to publish
		pub_ = n_.advertise<nav_msgs::Path>("/published_topic", 1);
		//Topic you want to subscribe
		sub_ = n_.subscribe("odom",1000,&Trajectory::callback,this);
	}
	void callback(const nav_msgs::OdometryConstPtr& odom)
	{
		//your callback function
		pub_.publish(path);
	}
private:
	//defination of class members
	ros::NodeHandle n_; 
	ros::Publisher pub_;
	ros::Subscriber sub_;
};

int main(int argc, char** argv){
	ros::init(argc, argv, "trajectory_publisher");
	Trajectory trajectoryObject;//create an object
	ros::spin();
	return 0;
}

