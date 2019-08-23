
#include <Servo.h>                           // Include servo library

Servo servoLeft;                             // Declare left servo signal
Servo servoRight;                            // Declare right servo signal

int PIEZOPIN = 5;                            // Declare pin that the piezo is connected to.
// DECLARE LED PINS HERE

// One octave of notes between A4 and A5, for Piezo Greeting
int note_F4 = 349.23;
int note_G4 = 392;
int note_Gs4 = 415.3;
int note_A4 = 440;
int note_As4 = 466; int note_Bb4 = note_As4;
int note_B4 = 494;
int note_C5 = 523;
int note_Cs5 = 554; int note_Db5 = note_Cs5;
int note_D5 = 587;
int note_Ds5 = 622; int note_Eb5 = note_Ds5;
int note_E5 = 659;
int note_F5 = 698;
int note_Fs5 = 740; int note_Gb5 = note_Fs5;
int note_G5 = 784;
int note_Gs5 = 830; int note_Ab5 = note_Gs5;

void firstMeasure() {
  tone(8, note_C5);
  servoLeft.writeMicroseconds(2500);        
  servoRight.writeMicroseconds(500);
  delay(400);
  tone(8, note_As4);
  servoLeft.writeMicroseconds(500);        
  servoRight.writeMicroseconds(2500);
  delay(400);
  servoLeft.writeMicroseconds(1500);        
  servoRight.writeMicroseconds(1500);
  delay(400);
  tone(8, note_Gs4);
  delay(200);
  tone(8, note_As4);
  delay(200);
}

void song() {
  firstMeasure();
  firstMeasure();
  firstMeasure();
  //this is the wiggle
  tone(8, note_C5);
  servoLeft.writeMicroseconds(2500);        
  servoRight.writeMicroseconds(1500);
  delay(200);
  tone(8, note_Cs5);
  servoLeft.writeMicroseconds(1500);        
  servoRight.writeMicroseconds(500);
  delay(200);
  tone(8, note_C5);
  servoLeft.writeMicroseconds(1500);        
  servoRight.writeMicroseconds(500);
  delay(200);
  tone(8, note_As4);
  servoLeft.writeMicroseconds(2500);        
  servoRight.writeMicroseconds(1500);
  delay(200);
  tone(8, note_As4);
  servoLeft.writeMicroseconds(1500);        
  servoRight.writeMicroseconds(1500);
  delay(400);
  tone(8, note_Gs4);
  delay(200);
  tone(8, note_As4);
  delay(200);
  //____________
  firstMeasure();
  //this is the back, forward
  tone(8, note_G4);
  servoLeft.writeMicroseconds(500);        
  servoRight.writeMicroseconds(2500);
  delay(400);
  tone(8, note_F4);
  servoLeft.writeMicroseconds(2500);        
  servoRight.writeMicroseconds(500);
  delay(400);
  noTone(8);
  delay(400);
  tone(8, note_Gs4);
  circleRight();
  delay(200);
  tone(8, note_As4);
  circleRight();
  delay(200);
  tone(8, note_C5);
  circleRight();
  delay(400);
  tone(8, note_As4);
  circleRight();
  delay(400);
  noTone(8);
  servoLeft.writeMicroseconds(1500);        
  servoRight.writeMicroseconds(1500);
  delay(400);
  //--------------
  tone(8, note_Gs4);
  circleRight();
  delay(200);
  tone(8, note_As4);
  circleRight();
  delay(200);
  tone(8, note_Cs5);
  circleRight();
  delay(200);
  tone(8, note_Cs5);
  circleRight();
  delay(200);
  tone(8, note_C5);
  circleRight();
  delay(200);
  tone(8, note_As4);
  circleRight();
  delay(200);
  tone(8, note_Gs4);
  circleRight();
  delay(400);
  tone(8, note_G4);
  circleRight();
  delay(400);
  //----------this is the chord
  tone(8, note_Gs4);
  tone(8, note_C5);
  tone(8, note_Ds5);
  tone(8, note_Gs5);
  vibrate();
  vibrate();
  vibrate();
  vibrate();
}

void setup()
{
  pinMode(PIEZOPIN, OUTPUT);                 // Attach piezo to pin 5. 
  servoLeft.attach(13);                      // Attach left signal to pin 13
  servoRight.attach(12);                     // Attach right signal to pin 12
  servoLeft.writeMicroseconds(1500);        // Calibrate left servo
  servoRight.writeMicroseconds(1500);       // Calibrate right servo
  // Attach LED pins here.
  
}  

void frontBack() {
  servoLeft.writeMicroseconds(2500);        
  servoRight.writeMicroseconds(500);
  delay(400);
  servoLeft.writeMicroseconds(500);        
  servoRight.writeMicroseconds(2500);
  delay(400);
}
void turnRight() {
  servoLeft.writeMicroseconds(2500);        
  servoRight.writeMicroseconds(1500);
  delay(400);
  servoLeft.writeMicroseconds(1500);        
  servoRight.writeMicroseconds(500);
  delay(400);
}

void turnLeft() {
  servoLeft.writeMicroseconds(1500);        
  servoRight.writeMicroseconds(500);
  delay(400);
  servoLeft.writeMicroseconds(2500);        
  servoRight.writeMicroseconds(1500);
  delay(400);
}

void circleRight() {
  servoLeft.writeMicroseconds(1200);        
  servoRight.writeMicroseconds(100);
}

void dance() {
  frontBack();
  delay(800);
  frontBack();
  delay(800);
  turnRight();
  turnLeft();
}

void vibrate() {
  servoLeft.writeMicroseconds(2500);        
  servoRight.writeMicroseconds(500);
  delay(200);
  servoLeft.writeMicroseconds(500);        
  servoRight.writeMicroseconds(2500);
  delay(200);
}

void loop()
{
  song();
  // Code for testing servos. 
  // Tinker with the numbers to see how they work!
  // For help, visit https://learn.parallax.com/tutorials/robot/shield-bot/robotics-board-education-shield-arduino/chapter-2-shield-lights-servo-4. 

}
