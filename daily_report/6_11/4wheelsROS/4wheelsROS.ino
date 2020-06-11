#include <ros.h>
#include <std_msgs/String.h>

#define speedPinR 9   //Front Wheel PWM pin connect Right MODEL-X ENA 
#define pin1R  22    //Front Right Motor direction pin 1 to Right MODEL-X IN1  (K1)
#define pin2R  24   //Front Right Motor direction pin 2 to Right MODEL-X IN2   (K1)                                 

#define SPEED 160  // 600 is too fast and doesnt run fast neccesarily
#define BUTTON 8

const int turntime = 1500;

ros::NodeHandle node_handle;
std_msgs::String button_msg;

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
      init(_pin1,_pin2,_pin3);    
    }
    void init(int _pin1, int _pin2, int _pin3)
    {
      pin1 = _pin1;
      pin2 = _pin2;
      pin3 = _pin3;
    }
   /*motor control*/
    void Stop()    // Stop
    {
       set_Motorspeed(0);
       digitalWrite(pin1,LOW);
       digitalWrite(pin2,LOW);
     }
    void Forward(int Speed)  // Wheel forwared turn
    {
       set_Motorspeed(Speed);
       digitalWrite(pin1,HIGH);
       digitalWrite(pin2,LOW);
     }

    void Backward(int Speed)
    {
      set_Motorspeed(Speed);
       digitalWrite(pin1,LOW);
       digitalWrite(pin2,HIGH);
    }
    void set_Motorspeed(int Speed)
    {
       digitalWrite(pin3,Speed);
     }
};

// Creating objects globally so that setup() and loop()
// can access to the objects
// init


Wheel wlfrontR(pin1R,pin2R,speedPinR);
ros::Publisher button_publisher("button_press", &button_msg);

void setup() 
{   
   node_handle.initNode();
   node_handle.advertise(button_publisher);
} 
 void loop() 
 { 
    wlfrontR.Forward(SPEED);
    if (digitalRead(speedPinR) == LOW)
    {
        button_msg.data = "Pressed";
       
    }else{
        button_msg.data = "NOT pressed";
    }
    button_publisher.publish( &button_msg );
    node_handle.spinOnce();
  }
