#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 100

//motor signals
#define ENA_m1 5        // Enable/speed motor Front Right 
#define ENA_m2 6        // Enable/speed motor Back Right

//motor1 
#define IN_11  11        // L298N #1 in 1 motor Right
#define IN_12  10        // L298N #1 in 2 motor Right
#define IN_13  9         // L298N #1 in 3 motor Right
#define IN_14  8        // L298N #1 in 4 motor Right

//motor2
#define IN_21  7        // L298N #2 in 1 motor Left
#define IN_22  6        // L298N #2 in 2 motor Left
#define IN_23  5        // L298N #2 in 3 motor Left
#define IN_24  4       // L298N #2 in 4 motor Left
  
Stepper stepper1(STEPS, 8, 9, 10, 11);
Stepper stepper2(STEPS, 4, 5, 6, 7);

int command;            //Int to store app command state.
int speedCar = 100;     // 50 - 255.
int speed_Coeff = 4;

void setup() {  
       
  pinMode(ENA_m1, OUTPUT);
  pinMode(ENA_m2, OUTPUT);
  pinMode(IN_11, OUTPUT);
  pinMode(IN_12, OUTPUT);
  pinMode(IN_13, OUTPUT);
  pinMode(IN_14, OUTPUT);
  pinMode(IN_21, OUTPUT);
  pinMode(IN_22, OUTPUT);
  pinMode(IN_23, OUTPUT);
  pinMode(IN_24, OUTPUT);


  stepper1.setSpeed(30);
  stepper2.setSpeed(30);
} 

void goAhead(){ 
  digitalWrite(IN_11, HIGH);
  digitalWrite(IN_12, LOW);
  analogWrite(ENA_m1, speedCar);
  digitalWrite(IN_21, LOW);
  digitalWrite(IN_22, HIGH);
  analogWrite(ENA_m2, speedCar);
}

void goBack(){ 
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, HIGH);
  analogWrite(ENA_m1, speedCar);
  digitalWrite(IN_21, HIGH);
  digitalWrite(IN_22, LOW);
  analogWrite(ENA_m2, speedCar);
}

void goRight(){ 
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, HIGH);
  analogWrite(ENA_m1, speedCar);
  digitalWrite(IN_21, LOW);
  digitalWrite(IN_22, HIGH);
  analogWrite(ENA_m2, speedCar);
}

void goLeft(){
  digitalWrite(IN_11, HIGH);
  digitalWrite(IN_12, LOW);
  analogWrite(ENA_m1, speedCar);
  digitalWrite(IN_21, HIGH);
  digitalWrite(IN_22, LOW);
  analogWrite(ENA_m2, speedCar);
}

void goAheadRight(){
  digitalWrite(IN_11, HIGH);
  digitalWrite(IN_12, LOW);
  analogWrite(ENA_m1, speedCar/speed_Coeff);
  digitalWrite(IN_21, LOW);
  digitalWrite(IN_22, HIGH);
  analogWrite(ENA_m2, speedCar);
}

void goAheadLeft(){
  digitalWrite(IN_11, HIGH);
  digitalWrite(IN_12, LOW);
  analogWrite(ENA_m1, speedCar);
  digitalWrite(IN_21, LOW);
  digitalWrite(IN_22, HIGH);
  analogWrite(ENA_m2, speedCar/speed_Coeff);
}

void goBackRight(){ 
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, HIGH);
  analogWrite(ENA_m1, speedCar/speed_Coeff);
  digitalWrite(IN_21, HIGH);
  digitalWrite(IN_22, LOW);
  analogWrite(ENA_m2, speedCar);
}

void goBackLeft(){ 
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, HIGH);
  analogWrite(ENA_m1, speedCar);
  digitalWrite(IN_21, HIGH);
  digitalWrite(IN_22, LOW);
  analogWrite(ENA_m2, speedCar/speed_Coeff);
}

void stopRobot(){  
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, LOW);
  analogWrite(ENA_m1, speedCar);
  digitalWrite(IN_13, LOW);
  digitalWrite(IN_14, LOW);
  analogWrite(ENA_m2, speedCar);
}
  
void loop(){  
  if (Serial.available() > 0) {
    command = Serial.read();
    switch (command) {
      case '()':goAhead();break;
      case 'B':goBack();break;
      case 'L':goLeft();break;
      case 'R':goRight();break;
      case 'I':goAheadRight();break;
      case 'G':goAheadLeft();break;
      case 'J':goBackRight();break;
      case 'H':goBackLeft();break;
      case '1010':stopRobot();break;      
    }
  }
}
