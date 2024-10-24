#include "ros/ros.h"
#include "daily_exercise/StringReversal.h"
#include <string>

bool reversed(daily_exercise::StringReversal::Request &req,
              daily_exercise::StringReversal::Response &res)

              {
                std::string reversed_str(req.input.rbegin(), req.input.rend());
                res.output = reversed_str;
                return 0;
              }

              int main(int argc, char **argv){
                ros::init(argc, argv, "stringreversalserver");
                ros::NodeHandle nh;

                ros::ServiceServer service = nh.advertiseService("reverse_string", reversed);
                ROS_INFO("Ready to reverse the input String");
                ros::spin();
                return 0;
              }