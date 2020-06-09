/*
 * How to test encoder with Arduino
 * url: http://osoyoo.com/?p=30267
 */
 
#define speedPinR 9   //Front Wheel PWM pin connect Right MODEL-X ENA 
#define pin1R  22    //Front Right Motor direction pin 1 to Right MODEL-X IN1  (K1)
#define pin2R  24   //Front Right Motor direction pin 2 to Right MODEL-X IN2   (K1)                                 

#define pin1L 26  // Front Left Motor direction pin 1 to Right MODEL-X IN3 (K3)
#define pin2L 28   // Front Left Motor direction pin 2 to Right MODEL-X IN4 (K3)
#define speedPinL 10   //Front Wheel PWM pin connect Right MODEL-X ENB

#define speedPinRBack 11   //Rear Wheel PWM pin connect Right MODEL-X ENA 
#define pin1RBack  5    //Rear Right Motor direction pin 1 to Right MODEL-X IN1  (K1)
#define pin2RBack  6   //Rear Right Motor direction pin 2 to Right MODEL-X IN2   (K1)                                 

#define pin1LBack 7  // Rear Left Motor direction pin 1 to Right MODEL-X IN3 (K3)
#define pin2LBack 8   // Rear Left Motor direction pin 2 to Right MODEL-X IN4 (K3)
#define speedPinLBack 12   //Rear Wheel PWM pin connect Right MODEL-X ENB


#define SPEEDL 140    //both sides of the motor speed
#define SPEEDR 160  // 600 is too fast and doesnt run fast neccesarily

const int turntime = 1500;

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

void straight_ahead(Wheel wlfR, Wheel wlfL, Wheel wlrR, Wheel wlrL, int Speed)
{
  wlfR.Forward(Speed);
  wlfL.Forward(Speed);
  wlrR.Forward(Speed);
  wlrL.Forward(Speed);
}

void side_way(Wheel wlfR, Wheel wlfL, Wheel wlrR, Wheel wlrL, int Speed)
{
  wlfR.Backward(Speed);
  wlfL.Forward(Speed);
  wlrR.Forward(Speed);
  wlrL.Backward(Speed);
}

void diagnal(Wheel wlfR, Wheel wlfL, Wheel wlrR, Wheel wlrL, int Speed)
{
  //wlfL.Forward(Speed); // leaving other 2 wheels command result in inacting them.
  //wlrR.Forward(Speed); // not sure why it happened so far, but the solution is to send commands for 4 wheels.

  wlfR.Backward(0);
  wlfL.Forward(Speed);
  wlrR.Forward(Speed);
  wlrL.Backward(0);
}

void cornering(Wheel wlfR, Wheel wlfL, Wheel wlrR, Wheel wlrL, int Speed)
{
  //wlfL.Forward(Speed);
  //wlrL.Forward(Speed);

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
  //wlrR.Forward(Speed);
  //wlrL.Forward(Speed);
}

void Four_wheels_stop(Wheel wlfR, Wheel wlfL, Wheel wlrR, Wheel wlrL)
{
  wlfR.Stop();
  wlfL.Stop();
  wlrR.Stop();
  wlrL.Stop();
}

void Light_count(int count)
{
   // for loop did not work for this ! 
   // instead incrementing i 
   int i = 0;
   while(i < count)
   {
      digitalWrite(LED_BUILTIN, HIGH);   
      delay(500);                      
      digitalWrite(LED_BUILTIN, LOW);   
      delay(500); 
      i++;
   } 
}

// init

Wheel wlfrontR(pin1R,pin2R,speedPinR);
Wheel wlfrontL(pin1L,pin2L,speedPinL);
Wheel wlrearR(pin1RBack,pin2RBack,speedPinRBack);
Wheel wlrearL(pin1LBack,pin2LBack,speedPinLBack);

void setup() 
{   
   pinMode(LED_BUILTIN, OUTPUT);
} 
 void loop() 
 { 
   Light_count(1);

   straight_ahead(wlfrontR,wlfrontL,wlrearR,wlrearL,SPEEDL);
   delay(turntime);

   Four_wheels_stop(wlfrontR,wlfrontL,wlrearR,wlrearL);
   delay(turntime);

   Light_count(2);

   side_way(wlfrontR,wlfrontL,wlrearR,wlrearL,SPEEDL);
   delay(turntime);

   Four_wheels_stop(wlfrontR,wlfrontL,wlrearR,wlrearL);
   delay(turntime);

   Light_count(3);
   
   diagnal(wlfrontR,wlfrontL,wlrearR,wlrearL,SPEEDL);
   delay(turntime);

   Four_wheels_stop(wlfrontR,wlfrontL,wlrearR,wlrearL);
   delay(turntime);

   Light_count(4);
   
   cornering(wlfrontR,wlfrontL,wlrearR,wlrearL,SPEEDL);
   delay(turntime);

   Four_wheels_stop(wlfrontR,wlfrontL,wlrearR,wlrearL);
   delay(turntime);

   Light_count(5);

   turn_around(wlfrontR,wlfrontL,wlrearR,wlrearL,SPEEDL);
   delay(turntime);

   Four_wheels_stop(wlfrontR,wlfrontL,wlrearR,wlrearL);
   delay(turntime);

   Light_count(6);

   turn_of_rear_axis(wlfrontR,wlfrontL,wlrearR,wlrearL,SPEEDL);
   delay(turntime);

   Four_wheels_stop(wlfrontR,wlfrontL,wlrearR,wlrearL);
   delay(turntime);
   
 }
