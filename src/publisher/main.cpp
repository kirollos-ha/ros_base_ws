#include<iostream>
#include<sstream>

#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char** argv) {
    ros::init(argc, argv, "publisher");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::String>("topic", 1000);
    ros::Rate eepy(10);
    int i = 0;

    while(ros::ok()) {
	std_msgs::String msg;
	std::stringstream ss;
	ss << "ma che oooooooh " <<i++<<'\n';
	msg.data = ss.str();
	ROS_INFO("inviato %s", msg.data.c_str());
	pub.publish(msg);
        ros::spinOnce();
	eepy.sleep();
    }

    return 0;
}
