#include <Stepper.h>

// left motor input pins 
#define IN_11  11        // L298N #1 in 1 motor  Left
#define IN_12  10        // L298N #1 in 2 motor  Left
#define IN_13  9         // L298N #1 in 3 motor  Left
#define IN_14  8         // L298N #1 in 4 motor  Left
//right motor input pins
#define IN_21  7        // L298N #2 in 1 motor Right
#define IN_22  6        // L298N #2 in 2 motor Right
#define IN_23  5        // L298N #2 in 3 motor Right
#define IN_24  4        // L298N #2 in 4 motor Right
  
//String to store app command state.
int command;
//Stepper Consts
const float STEPS_PER_REV = 32; 
const float GEAR_RED = 64;
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;

//declare steps required
int StepsRequired;

Stepper steppermotorL(STEPS_PER_REV, 8, 9, 10, 11);
Stepper steppermotorR(STEPS_PER_REV, 4, 5, 6, 7);

void setup() {  
  Serial.begin(9600); 
  pinMode(2, OUTPUT);
  pinMode(IN_11, OUTPUT);
  pinMode(IN_12, OUTPUT);
  pinMode(IN_13, OUTPUT);
  pinMode(IN_14, OUTPUT);
  pinMode(IN_21, OUTPUT);
  pinMode(IN_22, OUTPUT);
  pinMode(IN_23, OUTPUT);
  pinMode(IN_24, OUTPUT);
} 
void off(){
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, LOW);
  digitalWrite(IN_13, LOW);
  digitalWrite(IN_14, LOW);
  digitalWrite(IN_21, LOW);
  digitalWrite(IN_22, LOW);
  digitalWrite(IN_23, LOW);
  digitalWrite(IN_24, LOW);
}
void goAhead(){ 
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotorL.setSpeed(100);   
  steppermotorR.setSpeed(100);   
  steppermotorR.step(-StepsRequired);
  steppermotorL.step(StepsRequired);
  delay(1000);
  off();
}
void goBack(){ 
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotorL.setSpeed(100);   
  steppermotorL.step(-StepsRequired);
  steppermotorR.setSpeed(100);   
  steppermotorR.step(StepsRequired);
  delay(1000);
  off();
}
void goLeft(){
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotorL.setSpeed(100);   
  steppermotorL.step(-StepsRequired);
  steppermotorR.setSpeed(100);   
  steppermotorR.step(-StepsRequired);
  delay(1000);
  off();
}
void goRight(){ 
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotorL.setSpeed(100);   
  steppermotorL.step(StepsRequired);
  steppermotorR.setSpeed(100);   
  steppermotorR.step(StepsRequired);
  delay(1000);
  off();
}
void goAheadLeft(){
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotorL.setSpeed(0);   
  steppermotorR.setSpeed(100);   
  steppermotorR.step(-StepsRequired);
  delay(1000);
  off();
}
void goAheadRight(){
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotorL.setSpeed(100);   
  steppermotorL.step(StepsRequired);
  steppermotorR.setSpeed(0);   
  delay(1000);
  off();
}
void goBackLeft(){ 
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotorL.setSpeed(100);   
  steppermotorL.step(StepsRequired);
  steppermotorR.setSpeed(100);   
  steppermotorR.step(-StepsRequired);
  delay(1000);
  off();
}
void goBackRight(){ 
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotorL.setSpeed(0);   
  steppermotorR.setSpeed(100);   
  steppermotorR.step(StepsRequired);
  delay(1000);
  off();
}
void stopRobot(){  
  off();
  delay(1000);
}
  
void loop(){  
  if (Serial.available() > 0) {
    command = Serial.read();
    
    switch (command) {
      case '1' :goAhead();break;
      case '2' :goBack();break;
      case '3' :goLeft();break;
      case '4' :goRight();break;
      case '5' :goAheadLeft();break;
      case '6' :goAheadRight();break;
      case '7' :goBackLeft();break;
      case '8' :goBackRight();break;
      case '9' :stopRobot();break;
        //default:digitalWrite(2,HIGH);break;      
    }
  }
}
