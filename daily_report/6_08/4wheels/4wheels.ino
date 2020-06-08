/*
 * How to test encoder with Arduino
 * url: http://osoyoo.com/?p=30267
 */
 
#define speedPinRB 9   //Front Wheel PWM pin connect Right MODEL-X ENA 
#define MtrDirpin1RB  22    //Rear Right Motor direction pin 1 to Right MODEL-X IN1  (K1)
#define MtrDirpin2RB  24   //Rear Right Motor direction pin 2 to Right MODEL-X IN2   (K1)                                 
#define MtrDirpin1LB 46  // Rear Left Motor direction pin 1 to Right MODEL-X IN3 (K3)
#define MtrDirpin2LB 48   // Rear Left Motor direction pin 2 to Right MODEL-X IN4 (K3)
#define speedPinLB 10   //Front Wheel PWM pin connect Right MODEL-X ENB

#define speedPinRF 6   //Front Wheel PWM pin connect Right MODEL-X ENA 
#define MtrDirpin1RF  28    //Rear Right Motor direction pin 1 to Right MODEL-X IN1  (K1)
#define MtrDirpin2RF  30   //Rear Right Motor direction pin 2 to Right MODEL-X IN2   (K1)                                 
#define MtrDirpin1LF 40  // Rear Left Motor direction pin 1 to Right MODEL-X IN3 (K3)
#define MtrDirpin2LF 42   // Rear Left Motor direction pin 2 to Right MODEL-X IN4 (K3)
#define speedPinLF 7   //Front Wheel PWM pin connect Right MODEL-X ENB


#define SPEEDL 6000    //both sides of the motor speed
#define SPEEDR 6000

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

Wheel wlRearR(MtrDirpin1RB,MtrDirpin2RB,speedPinRB);
Wheel wlRearL(MtrDirpin1LB,MtrDirpin2LB,speedPinLB);

Wheel wlFRONTR(MtrDirpin1RF,MtrDirpin2RF,speedPinRF);
Wheel wlFRONTL(MtrDirpin1LF,MtrDirpin2LF,speedPinLF);


void setup() 
{   
  
} 
 void loop() 
 { 
     
   //wlRearL.Stop(MtrDirpin1LB,MtrDirpin2LB);
   //wlRearR.Stop(MtrDirpin1RB,MtrDirpin2RB);

   wlFRONTL.Stop(MtrDirpin1LF,MtrDirpin2LF);
   wlFRONTR.Stop(MtrDirpin1RF,MtrDirpin2RF);

   wlRearL.set_Motorspeed(speedPinLB,SPEEDL);
   wlRearR.set_Motorspeed(speedPinRB,SPEEDL);

   wlFRONTL.set_Motorspeed(speedPinLF,SPEEDL);
   wlFRONTR.set_Motorspeed(speedPinRF,SPEEDL);
   
   wlRearL.Forward(MtrDirpin1LB,MtrDirpin2LB);
   wlRearR.Forward(MtrDirpin1RB,MtrDirpin2RB);

   wlFRONTL.Forward(MtrDirpin1LF,MtrDirpin2LF);
   wlFRONTR.Forward(MtrDirpin1RF,MtrDirpin2RF);
   
   delay(turntime);
   delay(turntime);
   
   wlRearR.Stop(MtrDirpin1RB,MtrDirpin2RB);
   wlRearL.Stop(MtrDirpin1LB,MtrDirpin2LB);

   wlFRONTR.Stop(MtrDirpin1RF,MtrDirpin2RF);
   wlFRONTL.Stop(MtrDirpin1LF,MtrDirpin2LF);
 
   delay(turntime * 3);
 }
