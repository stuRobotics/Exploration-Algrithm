#include "ros/ros.h"	//包含了使用ROS节点的必要文件
#include "std_msgs/String.h"	//包含了使用的数据类型
#include <sstream>
int main(int argc, char **argv)
{
	ros::init(argc, argv, "goal_pub");	//初始化ROS，节点名命名为node_a，节点名必须保持唯一
	ros::NodeHandle n;	//实例化节点, 节点进程句柄
	ros::Publisher pub = n.advertise<std_msgs::String>("/mobe_base/goal", 3);//告诉系统要发布话题了，话题名为“str_message”，类型为std_msgs::String，缓冲队列为1000。
	ros::Rate loop_rate(20);	//设置发送数据的频率为10Hz
	//ros::ok()返回false会停止运行，进程终止。
	while(ros::ok())
	{
		std_msgs::String msg;
		std::stringstream ss;
		ss<<"Hello World";
		msg.data = ss.str();
		ROS_INFO("node_a is publishing %s", msg.data.c_str());
		pub.publish(msg);	//向话题“str_message”发布消息
		ros::spinOnce();	//不是必须，若程序中订阅话题则必须，否则回掉函数不起作用。
		loop_rate.sleep();	//按前面设置的10Hz频率将程序挂起
	}
 
	return 0;
}
