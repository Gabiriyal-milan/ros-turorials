#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "fstream"
#include "string"
#include "std_msgs/Float64.h"

std::ofstream outfile;
void initialposecallback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg){

    if(!outfile.is_open()) {

        ROS_ERROR("Could not open the file 'x_pose.txt'");
        //return 1;
    } 
   
}

int main(int argc, char **argv) {
ros::init(argc, argv, "pose_sub");
ros::NodeHandle nh;
geometry_msgs::PoseWithCovarianceStamped msg;
//outfile.open("x_pose.txt", std::ios::out | std::ios::app);
   //if(outfile.is_open()){
  //      outfile << msg.pose.pose.position.x << std::endl;
    //} 
outfile << "position: (" 
       <<  msg.pose.pose.position.x << " )";

ros::Subscriber sub = nh.subscribe("initialpose", 1, initialposecallback);
ros::spinOnce();

    

outfile.close();
return 0;


} 