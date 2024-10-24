#include "ros/ros.h"
#include "daily_exercise/StringReversal.h"
#include <string>

int main(int argc, char **argv) {
    ros::init(argc, argv, "stringreversalclient");
    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<daily_exercise::StringReversal>("reverse_string");
    daily_exercise::StringReversal srv;

    srv.request.input = "hello, ros!";  // Ensure this matches your service definition

    if (client.call(srv)) {
        ROS_INFO("Reversed: %s", srv.response.output.c_str());
    } 
    else 
    {
        ROS_ERROR("Failed to reverse the input string");
    }

    return 0;
}
