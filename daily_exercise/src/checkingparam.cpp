#include "ros/ros.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "checkparam");
    ros::NodeHandle nh;

    if(nh.hasParam("/robot_name")){
        ROS_INFO("Robot name is found");
    }else{
        ROS_WARN("Robot name is not found");
    }
    ros::spinOnce();
    return 0;

}