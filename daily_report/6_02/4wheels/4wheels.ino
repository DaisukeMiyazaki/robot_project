/*
 * How to test encoder with Arduino
 * url: http://osoyoo.com/?p=30267
 */
#define outputA 6
#define outputB 7

#define speedPin 9   //  Front Wheel PWM pin connect Right MODEL-X ENA 
#define RightMotorDirPin1B  22    //Rear Right Motor direction pin 1 to Right MODEL-X IN1  (K1)
#define RightMotorDirPin2B  24   //Rear Right Motor direction pin 2 to Right MODEL-X IN2   (K1)                                 
#define LeftMotorDirPin1 23   // Rear Left Motor direction pin 1 to Right MODEL-X IN3 (K3)
#define LeftMotorDirPin2 25   // Rear Left Motor direction pin 2 to Right MODEL-X IN4 (K3)

#define SPEED  360     //both sides of the motor speed

 
int counter = 0; 
int aState;
int aLastState;  
const int turntime = 550;

/*motor control*/
void stop_Stop()    //Stop
{
  digitalWrite(RightMotorDirPin1B, LOW);
  digitalWrite(RightMotorDirPin2B,LOW);
  set_Motorspeed(0);
}

void FR_fwd()  //front-right wheel forward turn
{
  digitalWrite(RightMotorDirPin1B,HIGH);
  digitalWrite(RightMotorDirPin2B,LOW); 
}

/*set motor speed */
void set_Motorspeed(int rightFront)
{
 analogWrite(speedPin,rightFront); 
}

 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   pinMode (LED_BUILTIN, OUTPUT);

   /*setup L298N pin mode*/
   pinMode(RightMotorDirPin1B, OUTPUT); 
   pinMode(RightMotorDirPin2B, OUTPUT); 
   pinMode(speedPin, OUTPUT);  
    
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);   
 } 
 void loop() { 
   aState = digitalRead(outputA); // Reads the "current" state of the outputA
   stop_Stop();
   set_Motorspeed(SPEED);
   
   FR_fwd(); 
   delay(turntime);
   
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) {
       Serial.print(outputB);
       Serial.print(aState);
       //digitalWrite(LED_BUILTIN, HIGH);
       //delay(1);
       counter ++;
       //digitalWrite(LED_BUILTIN, LOW);
       //delay(1);
     } else {
       Serial.print(outputB);
       Serial.print(aState);
       //digitalWrite(LED_BUILTIN, HIGH);
       //delay(1);
       counter --;
       //digitalWrite(LED_BUILTIN, LOW);
       //delay(1);
     }
     Serial.print("Position: ");
     Serial.println(counter);
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state
   stop_Stop();
   delay(turntime * 3);
   
 }
