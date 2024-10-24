#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "fstream"
#include "string"



int main(int argc, char **argv) {
ros::init(argc, argv, "publish");
ros::NodeHandle nh;

 //std::ofstream file("New pose_x.txt");
  //if(!file.is_open()) {

    //    ROS_ERROR("Could not open the file 'New pose_x.txt'");
      //  return 1;
   // }

ros::Publisher pub = nh.advertise<geometry_msgs::PoseWithCovarianceStamped>("/initialpose", 1);
ros::Rate looprate(10);

while (ros::ok()) {
    geometry_msgs::PoseWithCovarianceStamped msg;
    msg.pose.pose.position.x = 2.999;
    ROS_INFO("Bot initial pose_x:  %f", msg.pose.pose.position.x);
    pub.publish(msg);
    //file << "position: (" 
      //   <<  msg.pose.pose.position.x << " )";

    ros::spinOnce();
   looprate.sleep();
}

//file.close();

return 0;

}
