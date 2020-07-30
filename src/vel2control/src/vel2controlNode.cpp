/* Convert cmd_vel, geometry_msgs/Twist 
to Control, std_msgs/Int32 */

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Int32.h>
#include <math.h>

void cmd_velCallback(const geometry_msgs::Twist::ConstPtr& twist){
	twist->linear;
}

int main(int argc, char ** argv){

    ros::init(argc,argv, "vel2controlNode");

    ros::NodeHandle nh;
    ros::Publisher Control_pub = nh.advertise<std_msgs::Int32>("Control", 1);
    ros::Subscriber cmd_vel_sub = nh.subscribe<geometry_msgs::Twist>("cmd_vel", 1, cmd_velCallback);
    int control = 1;
    geometry_msgs::Twist twist_msg;
    std_msgs::Int32 control_msg;

    double x, y;
    x = twist_msg.linear.x;
    y = twist_msg.linear.y;
    
    while(ros::ok()){
        //float theta = 0;
        //theta = arcsin(x / (abs(sqrt( x ** 2 + y ** 2)));

        // deciding which direction to go
        if( x >= 0 && y >= 0 ){
            if( x >=  y){
                /* move rightward */ 
                y = 0;
                control = 2;
            }else{
                /* move forward */
                x = 0;
                control = 1;
            }
        }else if( x > 0 && y < 0 ){
            if( x >=  abs(y)){
                /* move rightward */ 
                y = 0;
                control = 2;
            }else{
                /* move downward */
                x = 0;
                control = 3;
            }
        }else if( x < 0 && y < 0){
            if( abs(x) >=  abs(y)){
                /* move leftward */ 
                y = 0;
                control = 4;
            }else{
                /* move downward */
                x = 0;
                control = 3;
            }
        }else if( x < 0 && y > 0 ){
            if( abs(x) >=  y){
                /* move leftward */ 
                y = 0;
                control = 4;
            }else{
                /* move forward */
                x = 0;
                control = 1;
            }
        }else{
            ROS_INFO("No sure which direction to go");
            return -1;
        }
        //const std_msgs::Int32::ConstPtr& control_msg_ptr;

        control_msg.data = control; 
        Control_pub.publish(control_msg);
        ros::spinOnce();
    }
    
    // save the memory 
    return 0;
}
