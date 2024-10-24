#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <fstream>

class PoseSubscriber {
public:
    PoseSubscriber() {
        // Subscribe to the pose topic
        subscriber_ = nh_.subscribe("/initialpose", 10, &PoseSubscriber::initialposeCallback, this);
        
        // Open the file to store pose data
        file_.open("pose_data.txt", std::ios::out | std::ios::app);
        if (!file_.is_open()) {
            ROS_ERROR("Failed to open file for writing.");
        }
    }

    ~PoseSubscriber() {
        if (file_.is_open()) {
            file_.close();
        }
    }

private:
    void initialposeCallback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg) {
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

    ros::NodeHandle nh_;
    ros::Subscriber subscriber_;
    std::ofstream file_;
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "pose_subscriber");
    PoseSubscriber pose_subscriber;
    ros::spin();
    return 0;
}
