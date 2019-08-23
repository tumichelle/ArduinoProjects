#include <Servo.h>                           // Include servo library

Servo servoRight;
Servo servoLeft;

void moveBack() {
  // Your Code Here
  servoLeft.writeMicroseconds(2500);        
  servoRight.writeMicroseconds(500);
}

void moveForward() {
  // Your Code Here
  servoLeft.writeMicroseconds(500);        
  servoRight.writeMicroseconds(2500);
}

void moveBackRight() {
  servoLeft.writeMicroseconds(1500);        
  servoRight.writeMicroseconds(500);
}

void moveBackLeft() {
  servoLeft.writeMicroseconds(2500);        
  servoRight.writeMicroseconds(1500);
}

void stopKitty() {
  // Your Code Here
  servoLeft.writeMicroseconds(1500);        
  servoRight.writeMicroseconds(1500);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(5, INPUT); // whisker 1
  pinMode(7, INPUT); // whisker 2
  servoLeft.attach(13);
  servoRight.attach(12); 
  Serial.begin(9600);
  Serial.println("setup completed");
  pinMode(2, INPUT); // button
  pinMode(3, OUTPUT); 
  digitalWrite(3, LOW);
  //Your Code Here
}

void loop() {
  // put your main code here, to run repeatedly:
  int rightValue = digitalRead(5);
  int leftValue = digitalRead(7);
  int buttonValue = digitalRead(2);
  
  if (buttonValue == 1) {
    digitalWrite(3, HIGH);
  }
  else {
    digitalWrite(3, LOW);
  }
  
  if(rightValue == 0 && leftValue == 0) {
    Serial.println("Both whiskers are touching");
    moveBack();
  }
  else if(rightValue == 1 && leftValue == 0) {
    Serial.println("Only the left whisker is touching");
    moveBackRight();
  }
  else if(rightValue == 0 && leftValue == 1) {
    Serial.println("Only the right whisker is touching");
    moveBackLeft();
  }
  else if(rightValue == 1 && leftValue == 1) {
    Serial.println("Neither whisker is touching");
    moveForward();
  }
  delay(50);
}
