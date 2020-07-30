/* Convert cmd_vel, geometry_msgs/Twist 
to Control, std_msgs/Int32 */

#include <ros.h>
#include <geometry_msgs/Twist>
#include <std_msgs/Int32>

void cmd_velCallback(const geometry_msgs::Twist::ConstPtr& twist){
    twist->twist_msgs;
}


int main(int argc, char **argv){

    ros::init(argc,argv, "vel2control_client");
    ros::NodeHandle nh;
    ros::Subscriber cmd_vel_sub = nh.subscribe<geometry_msgs/Twist>("cmd_vel", 1, cmd_velCallback);

    ros::spin();
    return 0;
}