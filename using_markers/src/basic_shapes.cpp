#include "ros/ros.h"
#include "visualization_msgs/Marker.h"

int main(int argc,char** argv)
{
    ros::init(argc,argv,"basic_shapes");
    ros::NodeHandle n;
    ros::Rate r(1);
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker",1);

    uint32_t shape = visualization_msgs::Marker::SPHERE;
    int num=0;
    float px,py;

    while(ros::ok())
    {
        visualization_msgs::Marker marker;
        marker.header.frame_id = "map";
        marker.header.stamp = ros::Time::now();
        marker.ns = "basic_shapes";
        marker.id = 0;
        marker.type = shape;
        marker.action = visualization_msgs::Marker::ADD;

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

	if(num==17)
	    num=0;
	else
	    num++;

        marker.text=num;

        marker.pose.position.x = px;
        marker.pose.position.y = py;
        marker.pose.position.z = 0;
        marker.pose.orientation.x = 0.0;
        marker.pose.orientation.y = 0.0;
        marker.pose.orientation.z = 0.0;
        marker.pose.orientation.w = 1.0;

        marker.scale.x = 1.0;
        marker.scale.y = 1.0;
        marker.scale.z = 2.0;

        marker.color.r = 0.0f;
        marker.color.g = 1.0f;
        marker.color.b = 0.0f;
        marker.color.a = 1;

        marker.lifetime = ros::Duration();

        while(marker_pub.getNumSubscribers() < 1)
        {
            if(!ros::ok())
            {
                return 0;
            }
            ROS_WARN_ONCE("Please create a subscriber to the marker");
            sleep(1);
        }
        marker_pub.publish(marker);

        /*switch(shape)
        {
            case visualization_msgs::Marker::CUBE:
                shape = visualization_msgs::Marker::SPHERE;
                break;
            case visualization_msgs::Marker::SPHERE:
                shape = visualization_msgs::Marker::ARROW;
                break;
            case visualization_msgs::Marker::ARROW:
                shape = visualization_msgs::Marker::CYLINDER;
                break;
            case visualization_msgs::Marker::CYLINDER:
                shape = visualization_msgs::Marker::CUBE;
                break;

        }*/
        r.sleep();
    }

}
