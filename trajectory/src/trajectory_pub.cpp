#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <nav_msgs/Path.h>
#include <geometry_msgs/PoseStamped.h>
/*nav_msgs/Path :
	std_msgs/Header header :
		uint32 seq
		time stamp  --start_time
		string frame_id
	geometry_msgs/PoseStamped[] poses
*/
class Trajectory
{
public:
	unsigned int seq;
	nav_msgs::Path path;
	Trajectory()
	{
		seq=0;
		//Topic you want to subscribe
		sub_ = n_.subscribe("odom",1000,&Trajectory::callback,this);
		//Topic you want to publish
		pub_ = n_.advertise<nav_msgs::Path>("trajectory",1, true);
	}
	void callback(const nav_msgs::OdometryConstPtr& odom)
	{
		if(seq%333==0)
		{
			geometry_msgs::PoseStamped this_pose_stamped;
			path.header=odom->header;
			path.header.seq=seq;
			this_pose_stamped.header=odom->header;
			this_pose_stamped.header.seq=seq;
			this_pose_stamped.pose=odom->pose.pose;
			path.poses.push_back(this_pose_stamped);
			pub_.publish(path);
		}
		seq++;
	}
private:
	ros::NodeHandle n_; 
	ros::Publisher pub_;
	ros::Subscriber sub_;
	//int init_flag=0;
};

int main(int argc, char** argv){
	ros::init(argc, argv, "trajectory_publisher");
	Trajectory trajectoryObject;
	ros::spin();
	return 0;
}


//ROS_INFO("\nodom info:\nHead:\n\tseq:[%d]\n\tstamp:[%f]\n\tframe_id:[%s]\nPose:\n\tx:[%f]\n\ty:[%f]\n\tz:[%f]",(unsigned int)odom->header.seq,(double)odom->header.stamp.toSec(),odom->header.frame_id.c_str(),(double)odom->pose.pose.position.x,(double)odom->pose.pose.position.y,(double)odom->pose.pose.position.z);//odom->twist.twist.linear.x);
