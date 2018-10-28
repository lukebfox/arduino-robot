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
String command;
//Stepper Consts
const float STEPS_PER_REV = 32; 
const float GEAR_RED = 64;
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;

//declare steps required
int StepsRequired;

Stepper stepperL(STEPS_PER_REV, 8, 9, 10, 11);
Stepper stepperR(STEPS_PER_REV, 4, 5, 6, 7);

void setup() {  
  Serial.begin(9600) 
  pinMode(IN_11, OUTPUT);
  pinMode(IN_12, OUTPUT);
  pinMode(IN_13, OUTPUT);
  pinMode(IN_14, OUTPUT);
  pinMode(IN_21, OUTPUT);
  pinMode(IN_22, OUTPUT);
  pinMode(IN_23, OUTPUT);
  pinMode(IN_24, OUTPUT);
} 

//done
void goAhead(){ 
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotorL.setSpeed(100);   
  steppermotorL.step(StepsRequired);
  steppermotorR.setSpeed(100);   
  steppermotorR.step(-StepsRequired);
  delay(1000);
}
//done
void goBack(){ 
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotorL.setSpeed(100);   
  steppermotorL.step(-StepsRequired);
  steppermotorR.setSpeed(100);   
  steppermotorR.step(StepsRequired);
  delay(1000);
}
//done
void goLeft(){
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotorL.setSpeed(100);   
  steppermotorL.step(-StepsRequired);
  steppermotorR.setSpeed(100);   
  steppermotorR.step(-StepsRequired);
  delay(1000);
}
//done
void goRight(){ 
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotorL.setSpeed(100);   
  steppermotorL.step(StepsRequired);
  steppermotorR.setSpeed(100);   
  steppermotorR.step(StepsRequired);
  delay(1000);
}
//done
void goAheadLeft(){
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotorL.setSpeed(0);   
  steppermotorR.setSpeed(100);   
  steppermotorR.step(-StepsRequired);
  delay(1000);
}
//done
void goAheadRight(){
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotorL.setSpeed(100);   
  steppermotorL.step(StepsRequired);
  steppermotorR.setSpeed(0);   
  delay(1000);
}
//done
void goBackLeft(){ 
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotor1.setSpeed(100);   
  steppermotor1.step(StepsRequired);
  steppermotor2.setSpeed(100);   
  steppermotor2.step(-StepsRequired);
  delay(1000);
}
//done
void goBackRight(){ 
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotorL.setSpeed(0);   
  steppermotorR.setSpeed(100);   
  steppermotorR.step(StepsRequired);
  delay(1000);
}
//done
void stopRobot(){  
  steppermotor1.setSpeed(0);   
  steppermotor2.setSpeed(0);   
  delay(1000);
}
  
void loop(){  
  if (Serial.available() > 0) {
    command = Serial.read();
    switch (command) {
      case '33':goAhead();break;
      case '11':goBack();break;
      case '13':goLeft();break;
      case '31':goRight();break;
      case '23':goAheadLeft();break;
      case '32':goAheadRight();break;
      case '12':goBackLeft();break;
      case '21':goBackRight();break;
      case '22':stopRobot();break;      
    }
  }
}
