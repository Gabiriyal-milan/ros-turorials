#include "ros/ros.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "paramtest");
    ros::NodeHandle nh;

    nh.setParam("/robot_name", "trialamr");

    std::string robot_name;
    if(nh.getParam("/robot_name", robot_name)){
        ROS_INFO("Robot name is: %s",robot_name.c_str());

    }else{
        ROS_WARN("Robot name is not reterive");
    }
    ros::spinOnce();
    return 0;
}