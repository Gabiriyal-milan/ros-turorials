
#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"

int main(int argc, char **argv) {
    
    ros::init(argc, argv, "pose_publisher");
    ros::NodeHandle nh;

    
    double initial_pose_x;
    if (!nh.getParam("/amcl/initial_pose_x", initial_pose_x)){
        ROS_ERROR("Failed to get param 'robot/initial_pose/x'");
        return 1;
    }

    
    ros::Publisher pub = nh.advertise<geometry_msgs::PoseWithCovarianceStamped>("/amcl/initial_pose_x", 1);
    geometry_msgs::PoseWithCovarianceStamped msg;
    msg.pose.pose.position.x = initial_pose_x;
    ros::Rate loopRate(5);

    
    ros::Rate rate(1); 
   while (ros::ok()) {
        pub.publish(msg);
        ROS_INFO("Published initial pose x: %f", msg.pose.pose.position.x);
        ros::spinOnce();
        loopRate.sleep();
    }

    return 0;
}
