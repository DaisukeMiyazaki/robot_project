/*
 * How to test encoder with Arduino
 * url: http://osoyoo.com/?p=30267
 */
 
#define speedPinRB 9   //Front Wheel PWM pin connect Right MODEL-X ENA 
#define RightMotorDirpin1B  22    //Rear Right Motor direction pin 1 to Right MODEL-X IN1  (K1)
#define RightMotorDirpin2B  24   //Rear Right Motor direction pin 2 to Right MODEL-X IN2   (K1)                                 
#define LeftMotorDirpin1B 46  // Rear Left Motor direction pin 1 to Right MODEL-X IN3 (K3)
#define LeftMotorDirpin2B 48   // Rear Left Motor direction pin 2 to Right MODEL-X IN4 (K3)
#define speedPinLB 10   //Front Wheel PWM pin connect Right MODEL-X ENB

#define SPEED  360     //both sides of the motor speed

const int turntime = 550;

class Wheel
{

  public:
  
    Wheel(byte pin1, byte pin2, byte pin3)
    {
      init(pin1, pin2, pin3);
    }

    void init(byte motorPowerpin1, byte motorPowerpin2, byte speedpin)
    {
      /*setup L298N pin mode*/
      pinMode(motorPowerpin1, OUTPUT); 
      pinMode(motorPowerpin2, OUTPUT); 
      pinMode(speedpin, OUTPUT);  
    }
  
   /*motor control*/
    void Stop(byte pin1, byte pin2);    // Stop
    void Forward(byte pin1, byte pin2);  // Wheel forwared turn
    void Backward(byte pin1, byte pin2);
    void set_Motorspeed(byte speedpin, int Speed);

};

/*motor control*/
void Wheel::Stop(byte pin1, byte pin2)
{
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  set_Motorspeed(0, 0);
}

void Wheel::Forward(byte pin1, byte pin2)
{
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW); 
}

void Wheel::Backward(byte pin1, byte pin2)
{
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
}
void Wheel::set_Motorspeed(byte speedpin, int _speed)
{
 analogWrite(speedpin,_speed); 
}


// Creating objects globally so that setup() and loop()
// can access to the objects

Wheel wheelRearR(RightMotorDirpin1B,RightMotorDirpin2B,speedPinRB);
Wheel wheelRearL(LeftMotorDirpin1B,LeftMotorDirpin2B,speedPinLB);

void setup() 
{   
  
} 
 void loop() 
 { 
     
   wheelRearL.Stop(LeftMotorDirpin1B,LeftMotorDirpin2B);
   //wheelRearR.Stop(RightMotorDirpin1B,RightMotorDirpin2B);

   wheelRearL.set_Motorspeed(speedPinLB,SPEED);
   //wheelRearR.set_Motorspeed(speedPinRB,SPEED);
   
   wheelRearL.Forward(LeftMotorDirpin1B,LeftMotorDirpin2B);
   //wheelRearR.Forward(RightMotorDirpin1B,RightMotorDirpin2B); 
   
   delay(turntime);
   
   //wheelRearR.Stop(RightMotorDirpin1B,RightMotorDirpin2B);
   wheelRearL.Stop(LeftMotorDirpin1B,LeftMotorDirpin2B);
 
   delay(turntime * 3);
 }
