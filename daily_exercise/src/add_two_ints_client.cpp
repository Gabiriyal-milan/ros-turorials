#include "ros/ros.h"
#include "daily_exercise/AddTwoInts.h"


int main(int argc, char **argv)
{
    ros::init(argc, argv, "addtwointsclient");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<daily_exercise::AddTwoInts>("add_two_ints");
    daily_exercise::AddTwoInts srv;

    srv.request.a = 5;
    srv.request.b = 2;

    if(client.call(srv)){
        ROS_INFO("sum: %ld", (long int)srv.response.sum);
    }
    else{
        ROS_ERROR("Failed to sum the two ints");
    }
    return 0;
}