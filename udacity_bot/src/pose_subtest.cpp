#include "ros/ros.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "fstream"
std::ofstream file_;

void initialposecallback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg) {
        // Write the pose data to the file
        if (file_.is_open()) {
            //file_ << "Timestamp: " << msg->header.stamp << "\n";
            file_ << "Position_x: "
                   << msg->pose.pose.position.x << " "
            //file_ << "Position_y: "
                   << msg->pose.pose.position.y << " "
            //file_ << "Position_z: "
                   << msg->pose.pose.position.z << " \n";
            //file_ << "Orientation: "
                   //<< msg->pose.pose.orientation.x << " "
                   //<< msg->pose.pose.orientation.y << " "
                   //<< msg->pose.pose.orientation.z << " "
                   //<< msg->pose.pose.orientation.w << "\n";
            //file_ << "Covariance: ";
            //for (const auto& cov : msg->pose.covariance) {
                //file_ << cov << " ";
            //}
            file_ << "\n\n";
        }
    }




int main(int argc, char **argv) {
    ros::init(argc, argv, "subtest");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/initialpose", 10, initialposecallback);
    ros::Rate looprate(10);

    file_.open("pose_data.txt", std::ios::out | std::ios::app);
        if (!file_.is_open()) {
            ROS_ERROR("Failed to open file for writing.");
        }
    

    ros::spin();
    file_.close();
    return 0;

}