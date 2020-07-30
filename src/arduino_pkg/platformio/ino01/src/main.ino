#define pin1R  22    //Front Right Motor direction pin 1 to Right MODEL-X IN1  (K1)
#define pin2R  24   //Front Right Motor direction pin 2 to Right MODEL-X IN2   (K1) 
#define speedPinR 9   //Front Wheel PWM pin connect Right MODEL-X ENA 

#define pin1L 26  // Front Left Motor direction pin 1 to Right MODEL-X IN3 (K3)
#define pin2L 28   // Front Left Motor direction pin 2 to Right MODEL-X IN4 (K3)
#define speedPinL 10   //Front Wheel PWM pin connect Right MODEL-X ENB

#define pin1RBack  5    //Rear Right Motor direction pin 1 to Left MODEL-X IN1  (K1)
#define pin2RBack  6   //Rear Right Motor direction pin 2 to Left MODEL-X IN2   (K1) 
#define speedPinRBack 11   //Rear Wheel PWM pin connect Left MODEL-X ENA 

#define pin1LBack 8  // Rear Left Motor direction pin 1 to Left MODEL-X IN3 (K3)
#define pin2LBack 7   // Rear Left Motor direction pin 2 to Left MODEL-X IN4 (K3)
#define speedPinLBack 12   //Rear Wheel PWM pin connect Left MODEL-X ENB
#define SPEEDF 140    // 600 is too fast and doesnt run fast neccesarily

#define outputA 3
#define outputB 2

#include <ros.h>
#include <ros/time.h>
#include <math.h>
#include <std_msgs/Empty.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
#include <tf/transform_broadcaster.h>
#include <tf/tf.h>
#include <nav_msgs/Odometry.h>


/* For enconder*/

int count = 0;
int count4velocity = 0;

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
double x[] = {0.0};
double y[] = {0.0};
double th[] = {0.0};

double delta_x[] = {0.0};
double delta_y[] = {0.0};
double delta_th[] = {0.0};

double vx[] = {0.1};
double vy[] = {0.0};
double vth[] = {0.1};

*/ 
unsigned char ODOM[4] = "odom";
unsigned char base_link[9] = "base_link";

/*
class OdomArray
{
	Header header;
	int odom_length;
	Odom * odoms;
 

}
*/

/*
*  Active time of the vehicle moving to a direction
*  It should be same as the legth of time that 
*  Planning node exepts this node to run for.
*/
const long interval = 1000;  	

bool up = false;
bool down = false;
bool right = false;
bool left = false;

ros::NodeHandle  nh;

class Wheel
{
	private:
		int pin1;
		int pin2;
		int pin3;

	public:

    Wheel(int _pin1, int _pin2, int _pin3)
    {
		/*setup L298N pin mode*/
		pinMode(_pin1, OUTPUT);
		pinMode(_pin2, OUTPUT);
		pinMode(_pin3, OUTPUT);
		// initialize
		init(_pin1, _pin2, _pin3);
    }
    void init(int _pin1, int _pin2, int _pin3)
    {
		pin1 = _pin1;
		pin2 = _pin2;
		pin3 = _pin3;
    }
    /*motor control*/
    void Stop()
    {
		set_Motorspeed(0);
		digitalWrite(pin1, LOW);
		digitalWrite(pin2, LOW);
    }
    void Forward(int Speed)
    {
		set_Motorspeed(Speed);
		digitalWrite(pin1, HIGH);
		digitalWrite(pin2, LOW);
    }

    void Backward(int Speed)
    {
		set_Motorspeed(Speed);
		digitalWrite(pin1, LOW);
		digitalWrite(pin2, HIGH);
    }
    void set_Motorspeed(int Speed)
    {
    	digitalWrite(pin3, Speed);
    }
};

/* Motor instance member functions */
/* ----------------------------------------------------------------------*/

void straight_ahead(Wheel wlfR, Wheel wlfL, Wheel wlrR, Wheel wlrL, int Speed)
{
	wlfR.Forward(Speed);
	wlfL.Forward(Speed);
	wlrR.Forward(Speed);
	wlrL.Forward(Speed);
}

void moving_back(Wheel wlfR, Wheel wlfL, Wheel wlrR, Wheel wlrL, int Speed)
{
	wlfR.Backward(Speed);
	wlfL.Backward(Speed);
	wlrR.Backward(Speed);
	wlrL.Backward(Speed);
}

void side_way_right(Wheel wlfR, Wheel wlfL, Wheel wlrR, Wheel wlrL, int Speed)
{
	wlfR.Backward(Speed);
	wlfL.Forward(Speed);
	wlrR.Forward(Speed);
	wlrL.Backward(Speed);
}

void side_way_left(Wheel wlfR, Wheel wlfL, Wheel wlrR, Wheel wlrL, int Speed)
{
	wlfR.Forward(Speed);
	wlfL.Backward(Speed);
	wlrR.Backward(Speed);
	wlrL.Forward(Speed);
}

void diagnal(Wheel wlfR, Wheel wlfL, Wheel wlrR, Wheel wlrL, int Speed)
{
  
	wlfR.Backward(0);
	wlfL.Forward(Speed);
	wlrR.Forward(Speed);
	wlrL.Backward(0);
}

void cornering(Wheel wlfR, Wheel wlfL, Wheel wlrR, Wheel wlrL, int Speed)
{
  wlfR.Backward(0);
	wlfL.Forward(Speed);
	wlrR.Forward(0);
	wlrL.Backward(Speed);
}

void turn_around(Wheel wlfR, Wheel wlfL, Wheel wlrR, Wheel wlrL, int Speed)
{
	wlfR.Backward(Speed);
	wlfL.Forward(Speed);
	wlrR.Backward(Speed);
	wlrL.Forward(Speed);
}

void turn_of_rear_axis(Wheel wlfR, Wheel wlfL, Wheel wlrR, Wheel wlrL, int Speed)
{
	wlfR.Backward(Speed);
	wlfL.Forward(Speed);
}

void Four_wheels_stop(Wheel wlfR, Wheel wlfL, Wheel wlrR, Wheel wlrL)
{
	wlfR.Stop();
	wlfL.Stop();
	wlrR.Stop();
	wlrL.Stop();
}

/* ROS communication*/
/* -------------------------------------------------------- */

void subControlcallback( const std_msgs::Int16& Control_msg) {
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

//std_msgs::String str_msg;
nav_msgs::Odometry odom_msg;

//ros::Publisher chatter("Response", &str_msg);
ros::Subscriber<std_msgs::Int16> sub("Control", &subControlcallback);


//ros::Publisher odom_pub = nh.advertise<nav_msgs::Odometry>("odom", 50);
//ros::Publisher odom_pub("odom",&odom_msg,50);
//ros::Publisher odom_pub("odom",&odom_msg,1);
ros::Publisher odom_pub("odom",&odom_msg);

tf::TransformBroadcaster odom_broadcaster;

Wheel wlfrontR(pin1R, pin2R, speedPinR);
Wheel wlfrontL(pin1L, pin2L, speedPinL);
Wheel wlrearR(pin1RBack, pin2RBack, speedPinRBack);
Wheel wlrearL(pin1LBack, pin2LBack, speedPinLBack);


void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);

	/* Counting via hall sensor*/
	pinMode(outputA,INPUT);
	pinMode(outputB,INPUT);
	//Serial.begin(57600);

	aLastState = digitalRead(outputA);  

	nh.initNode();
    odom_broadcaster.init(nh);

	nh.subscribe(sub);
	//nh.advertise(chatter);
	nh.advertise(odom_pub);

    //int count4velocity = 0;

	//ros::Time current_time, last_time;
	current_time = millis();
	last_time = millis();
	//ros::Rate r(1.0);

}
void loop()
{
	//Light_count(1);
	unsigned long currentMillis = millis();
    unsigned long dt = (currentMillis - previousMillis) * 1000; // Convert milliseconds to seconds

	//Serial.print("current time is; ");
	//Serial.println(currentMillis);

	if(currentMillis - previousMillis >= interval)
	{
		// save the last time 
		previousMillis = millis();
	
		//Serial.println("activation");
		//Serial.println(currentMillis);
	
  		if(up)
		{
			/* moving forward
			*  
			*  1, actuate all 4 wheels to go forward
			*  2, setting odometry as go forward
			*
			*/  
			straight_ahead(wlfrontR, wlfrontL, wlrearR, wlrearL, SPEEDF);
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
			moving_back(wlfrontR, wlfrontL, wlrearR, wlrearL, SPEEDF);
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
			side_way_right(wlfrontR, wlfrontL, wlrearR, wlrearL, SPEEDF);
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
			side_way_left(wlfrontR, wlfrontL, wlrearR, wlrearL, SPEEDF);
			vx = 0;
			vy = slideVelocityConst * spinNumber * count4velocity; // dependent on count4velocity
			delta_x = 0;
			delta_y = - vy * dt; 
			left = !left;
		}
		else
		{
			Four_wheels_stop(wlfrontR, wlfrontL, wlrearR, wlrearL);		
		}
		//Serial.print("position; ");
		//Serial.println(count);
		count4velocity = count;
		count = 0;

		//Serial.println(count4velocity);

		delta_th = vth * dt;
		x += delta_x;
		y += delta_y;
		th += delta_th;

		//since all odometry is 6DOF we'll need a quaternion created from yaw
		//geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);

		//first, we'll publish the transform over tf
		geometry_msgs::TransformStamped odom_trans;
		odom_trans.header.stamp = nh.now();

		//odom_trans.header.frame_id = "odom";
		//odom_trans.child_frame_id = "base_link";

		odom_trans.header.frame_id = ODOM;
		odom_trans.child_frame_id = base_link;


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
		odom.header.stamp = nh.now();
		//odom.header.frame_id = "odom";
		odom.header.frame_id = ODOM;

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
		odom.child_frame_id = base_link;

		odom.twist.twist.linear.x = vx;
		odom.twist.twist.linear.y = vy;
		odom.twist.twist.angular.z = vth;
		//odom.twist.twist.linear_length = 2;
		//odom.twist.twist.angular.z_length = 1;

		//publish the message
		odom_pub.publish(&odom);


	}
	//chatter.publish(&str_msg);
	
	aState = digitalRead(outputA);
	if(aState != aLastState)
	{
		if(digitalRead(outputB) != aState)
		{
			count ++;
		}
		else{
			count --;
		}
		aLastState = aState;
	}

  // publish the message
  //odom_pub.publish(&odom_msg);
  //last_time = current_time;

  //delay(turntime);

  nh.spinOnce();
}
