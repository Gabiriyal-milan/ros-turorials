#include "ros/ros.h"
#include "daily_exercise/AddTwoInts.h"

bool add(daily_exercise::AddTwoInts::Request &req,
     daily_exercise::AddTwoInts::Response &res)
     {
        res.sum =req.a + req.b ;
        return true;
     }

int main(int argc, char **argv) {
    ros::init(argc, argv, "addtwointserver");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("add_two_ints", add);
    ROS_INFO("Ready to add the ints");

    ros::spin();
    return 0;

}