#include "ros/ros.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include <fstream>
#include <sstream>
#include <string>
#include "std_msgs/Float64.h"

std::ifstream file_;

int main(int argc, char **argv) {
    ros::init(argc, argv, "test");
    ros::NodeHandle nh;

    // Open the file to read pose data
    file_.open("pose_data.txt");
    if (!file_.is_open()) {
        ROS_ERROR("Failed to open file for reading.");
        return -1;  // Exit if the file can't be opened
    }

    ros::Publisher pub = nh.advertise<geometry_msgs::PoseWithCovarianceStamped>("/initialpose", 10);
    ros::Rate looprate(50);

    while (ros::ok()) {
        std::string line;
        if (std::getline(file_, line)) {
            geometry_msgs::PoseWithCovarianceStamped msg;

            // Parse the line to extract pose and covariance data
            std::istringstream iss(line);
            std::string timestamp;
            iss >> timestamp; // Skip the timestamp

            // Read position
            iss >> msg.pose.pose.position.x
                >> msg.pose.pose.position.y
                >> msg.pose.pose.position.z;

            // Read orientation
            //iss >> msg.pose.pose.orientation.x
                //>> msg.pose.pose.orientation.y
                //>> msg.pose.pose.orientation.z
                //>> msg.pose.pose.orientation.w;

            // Read covariance
            //for (double& cov : msg.pose.covariance) {
                //iss >> cov;
            //}

            // Set the header
            //msg.header.stamp = ros::Time::now();
            //msg.header.frame_id = "base_link";  // Change as needed

            // Log the pose information
             ROS_INFO("Bot initial pose_x:  %f, Bot initial pose_y: %f, Bot initial pose_z: %f", msg.pose.pose.position.x, msg.pose.pose.position.y, msg.pose.pose.position.z);
            // Publish the message
            pub.publish(msg);

        } else {
            // If the end of the file is reached, you can reset or break
            ROS_WARN("End of file reached or no more lines to read.");
            file_.clear(); // Clear EOF flag
            file_.seekg(5); // Rewind the file if you want to loop through it
            // Optionally, you can break if you don't want to loop
            //break;
        }

        ros::spinOnce();
        looprate.sleep();
    }

    file_.close(); // Close the file before exiting
    return 0;
}
