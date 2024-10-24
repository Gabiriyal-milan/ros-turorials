#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "fstream"
#include <sstream>
#include <string>
std::ifstream file_;

int main(int argc, char **argv){
ros::init(argc, argv, "test");
ros::NodeHandle nh;

// Open the file to read pose data
        file_.open("pose_data.txt");
        if (!file_.is_open()) {
            ROS_ERROR("Failed to open file for reading.");
        }


ros::Publisher pub = nh.advertise<geometry_msgs::PoseWithCovarianceStamped>("/initialpose", 1);
ros::Rate looprate(10);

while (ros::ok()){
    geometry_msgs::PoseWithCovarianceStamped msg;
    std::string line;
        if (std::getline(file_, line)) {
            geometry_msgs::PoseWithCovarianceStamped msg;

            // Parse the line to extract pose and covariance data
            std::istringstream iss(line);
            std::string timestamp;
            iss >> timestamp; // Skip the timestamp

            // Read position
            iss >> msg.pose.pose.position.x;
                //>> msg.pose.pose.position.y
                //>> msg.pose.pose.position.z

            // Read orientation
            //iss >> msg.pose.pose.orientation.x
               // >> msg.pose.pose.orientation.y
                //>> msg.pose.pose.orientation.z
                //>> msg.pose.pose.orientation.w;

            // Read covariance
            //for (double& cov : msg.pose.covariance) {
              //  iss >> cov;
            //}
        }
    ROS_INFO("Bot initial pose_x:  %f", msg.pose.pose.position.x);
    pub.publish(msg);
    ros::spinOnce();
    looprate.sleep();
        

}

return 0;


}