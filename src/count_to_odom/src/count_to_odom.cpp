#include <ros/ros.h>
#include <ros/time.h>
#include <math.h>
#include <std_msgs/Empty.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>
#include <tf/transform_broadcaster.h>
#include <tf/tf.h>
#include <nav_msgs/Odometry.h>


/* For enconder*/

int count = 0;
int count4velocity = 0;
long int dt = 0;

int aState;
int aLastState;

unsigned long current_time;
unsigned long last_time;

unsigned long previousMillis = 0;

/* Info for wheels */
/* used to determine Odometry info */
/* Hypter parameters */
const double radius = 4.5 * 1E-3; // meter unit
const double spinNumber = 1.8; 
const int baseCount = 273;
const double slideVelocityConst = 1.5; // arbiterary number

double x = 0.0;
double y = 0.0;
double th = 0.0;

double delta_x = 0.0;
double delta_y = 0.0;
double delta_th = 0.0;

float vx = 0.1;
float vy = 0.0;
float vth = 0.1;

/*
*  Active time of the vehicle moving to a direction
*  It should be same as the legth of time that 
*  Planning node exepts this node to run for.
*/

bool up = false;
bool down = false;
bool right = false;
bool left = false;

/* ROS communication*/
/* -------------------------------------------------------- */

void subControlcallback( const std_msgs::Int32& Control_msg) {
	if(Control_msg.data == 1)
	{
		up = true;	
	}else if(Control_msg.data == 2)
	{
		down = true;	
	}else if(Control_msg.data == 3)
	{
		right = true;	
	}else if(Control_msg.data == 4)
	{
		left = true;	
	}
}

void subRotationcallback( const std_msgs::Int32& Rotation_msg) {
	count4velocity = Rotation_msg.data;
}
void subDTcallback( const std_msgs::Int32& dt_msg) {
	dt = dt_msg.data;
}

int main(int argc, char **argv){

	ros::init(argc, argv, "count_to_odom");

	ros::NodeHandle  nh;
	
	ros::Subscriber subControl = nh.subscribe("Control", 1 ,&subControlcallback);
	ros::Subscriber subRotation = nh.subscribe("rotation", 1 ,&subRotationcallback);
	ros::Subscriber subDt = nh.subscribe("dt", 1, &subDTcallback);

	//ros::Publisher odom_pub("odom",&odom_msg,1);
	ros::Publisher odom_pub = nh.advertise<nav_msgs::Odometry>("odom",1);

	tf::TransformBroadcaster odom_broadcaster;
    //odom_broadcaster.init(nh);

    //ros::Rate r(100);
	while(nh.ok())
	{
        nav_msgs::Odometry odom_msg;
		if(up)
		{
			/* moving forward
			*  
			*  1, actuate all 4 wheels to go forward
			*  2, setting odometry as go forward
			*
			*/  
			vx = 2 * M_PI * radius * spinNumber * count4velocity;
			vy = 0;
			delta_x = vx * dt;
			delta_y = 0; 
			up = !up;	// stop
		}
		else if(down)
		{
			/* moving backward 
			*  same as moving forward
			*/  

			vx = 2 * M_PI * radius * spinNumber * count4velocity;
			vy = 0;
			delta_x = - vx * dt;
			delta_y = 0; 		
			down = !down;
		}
		else if(right)
		{
			/* moving rightward
			*  velocity for this direction should be
			*  slideVelocityConst(some const) * spinNumber * count4velocity
			*/  
			vx = 0;
			vy = slideVelocityConst * spinNumber * count4velocity; // dependent on count4velocity
			delta_x = 0;
			delta_y = vy * dt; 
			right = !right;
		}
		else if(left)
		{
			/* moving leftward 
			*  opposite to moving rightward
			*/  
			vx = 0;
			vy = slideVelocityConst * spinNumber * count4velocity; // dependent on count4velocity
			delta_x = 0;
			delta_y = - vy * dt; 
			left = !left;
		}
		else
		{
			vx = 0;
			vy = 0;
			delta_x = 0;
			delta_y = 0;
			delta_th = 0;	
		}
		//Serial.print("position; ");
		//Serial.println(count);
		//Serial.println(count4velocity);

		delta_th = vth * dt;
		x += delta_x;
		y += delta_y;
		th += delta_th;

		//since all odometry is 6DOF we'll need a quaternion created from yaw
		//geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);

		//first, we'll publish the transform over tf
		geometry_msgs::TransformStamped odom_trans;
		odom_trans.header.stamp = ros::Time::now();

		//odom_trans.header.frame_id = "odom";
		//odom_trans.child_frame_id = "base_link";

		odom_trans.header.frame_id = "odom";
		odom_trans.child_frame_id = "base_link";


		odom_trans.transform.translation.x = x;
		odom_trans.transform.translation.y = y;
		odom_trans.transform.translation.z = 0.0;
		//odom_trans.transform.translation_length = 3;

		//odom_trans.transform.rotation = odom_quat;
		odom_trans.transform.rotation.x = 0.0;
		odom_trans.transform.rotation.y = 0.0;
		odom_trans.transform.rotation.z = 0.0;
		odom_trans.transform.rotation.w = 0.0;
		//odom_trans.transform.rotation_length = 4;
	

		//send the transform
		odom_broadcaster.sendTransform(odom_trans);

		//next, we'll publish the odometry message over ROS
		nav_msgs::Odometry odom;
		odom.header.stamp =  ros::Time::now();
		//odom.header.frame_id = "odom";
		odom.header.frame_id = "odom";

		//set the position
		odom.pose.pose.position.x = x;
		odom.pose.pose.position.y = y;
		odom.pose.pose.position.z = 0.0;
		//odom.pose.pose.position_length = 3;		
		//odom.pose.pose.orientation = odom_quat;
		odom.pose.pose.orientation.x = 0.0;
		odom.pose.pose.orientation.y = 0.0;
		odom.pose.pose.orientation.z = 0.0;
		//odom.pose.pose.orientation_length = 3;

		//set the velocity
		//odom.child_frame_id = "base_link";
		odom.child_frame_id = "base_link";

		odom.twist.twist.linear.x = vx;
		odom.twist.twist.linear.y = vy;
		odom.twist.twist.angular.z = vth;
		//odom.twist.twist.linear_length = 2;
		//odom.twist.twist.angular.z_length = 1;

		//publish the message
		odom_pub.publish(odom);
		ros::spinOnce();
	}
  return 0;
}
