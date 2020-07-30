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
#include <std_msgs/Int16.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Int32.h>
#include <boost/bind.hpp>

/* For enconder*/

int count = 0;
int aState;
int aLastState;

unsigned long current_time;
unsigned long last_time;

unsigned long previousMillis = 0;

/*
*  Active time of the vehicle moving to a direction
*  It should be same as the legth of time that 
*  Planning node exepts this node to run for.
*/
unsigned int interval = 1000;  	

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
	
/* Control signal from Jetson, either of 4 directions*/

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
void subDurationcallback( const std_msgs::UInt16& Duration_msg){
	interval = Duration_msg.data; 
}

std_msgs::Int16 int_msg;
std_msgs::Int32 time_msg;

ros::Subscriber<std_msgs::Int16> subControl("Control", &subControlcallback);
ros::Subscriber<std_msgs::UInt16> subDuration("Duration", &subDurationcallback);

//ros::Publisher rotationCount_pub("rotation",&int_msg,1); //this fails 
ros::Publisher rotationCount_pub("rotation",&int_msg);
ros::Publisher dt_pub("dt",&time_msg);

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
	nh.subscribe(subControl);
	nh.subscribe(subDuration);
	nh.advertise(rotationCount_pub);
	nh.advertise(dt_pub);

    //int_msg.count(int*)malloc(sizeof(int))
	current_time = millis();
	last_time = millis();
	//ros::Rate r(1.0);

}
void loop()
{
	unsigned long currentMillis = millis();
    time_msg.data = (currentMillis - previousMillis) * 1000; // Convert milliseconds to seconds
	

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
			/*
			vx = 2 * M_PI * radius * spinNumber * count4velocity;
			vy = 0;
			delta_x = vx * dt;
			delta_y = 0; 
			*/
			up = !up;	// stop
		}
		else if(down)
		{
			/* moving backward 
			*  same as moving forward
			*/  
			moving_back(wlfrontR, wlfrontL, wlrearR, wlrearL, SPEEDF);
			/*vx = 2 * M_PI * radius * spinNumber * count4velocity;
			vy = 0;
			delta_x = - vx * dt;
			delta_y = 0; 		
			*/			
			down = !down;
  		}
		else if(right)
		{
			/* moving rightward
			*  velocity for this direction should be
			*  slideVelocityConst(some const) * spinNumber * count4velocity
			*/  
			side_way_right(wlfrontR, wlfrontL, wlrearR, wlrearL, SPEEDF);
			/*
			vx = 0;
			vy = slideVelocityConst * spinNumber * count4velocity; // dependent on count4velocity
			delta_x = 0;
			delta_y = vy * dt; 
			*/
			right = !right;
		}
		else if(left)
		{
			/* moving leftward 
			*  opposite to moving rightward
			*/  
			side_way_left(wlfrontR, wlfrontL, wlrearR, wlrearL, SPEEDF);
			/*vx = 0;
			vy = slideVelocityConst * spinNumber * count4velocity; // dependent on count4velocity
			delta_x = 0;
			delta_y = - vy * dt; 
			*/
			left = !left;
		}
		else
		{
			Four_wheels_stop(wlfrontR, wlfrontL, wlrearR, wlrearL);		
		}
		//Serial.print("position; ");
		//Serial.println(count);
		int_msg.data = count;
		count = 0;
		rotationCount_pub.publish(&int_msg);
		dt_pub.publish(&time_msg);
	}
	
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
  nh.spinOnce();
}
