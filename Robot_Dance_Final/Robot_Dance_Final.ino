
#include <Servo.h>                           // Include servo library

Servo servoLeft;                             // Declare left servo signal
Servo servoRight;                            // Declare right servo signal

int PIEZOPIN = 5;                            // Declare pin that the piezo is connected to.
// DECLARE LED PINS HERE

int red = 0;
int green = 13;

// One octave of notes between A4 and A5, for Piezo Greeting
//Notes in the var name
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
  //C
  tone(8, note_C5);
  forward();
  redLight();
  delay(400);
  //A#
  tone(8, note_As4);
  back();
  greenLight(); 
  delay(400);
  //rest robot for rest of notes
  noLight();
  wait();
  delay(400);
  //G#
  tone(8, note_Gs4);
  redLight();
  delay(200);
  //A#
  tone(8, note_As4);
  greenLight();
  delay(200);
}

//This plays and dances to In My Feelings by Drake
void song() {
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  
  firstMeasure();
  firstMeasure();
  firstMeasure();
  //this is the wiggle
  //C
  tone(8, note_C5);
  right();
  redLight();
  delay(200);
  //C#
  tone(8, note_Cs5);
  left();
  greenLight();
  delay(200);
  //C
  tone(8, note_C5);
  left();
  redLight();
  delay(200);
  //A#
  tone(8, note_As4);
  right();
  greenLight();
  delay(200);
  //A#
  tone(8, note_As4);
  wait();
  redLight();
  delay(400);
  //G#
  tone(8, note_Gs4);
  greenLight();
  delay(200);
  //A#
  tone(8, note_As4);
  redLight();
  delay(200);
  //____________
  firstMeasure();
  //this is the back, forward
  //G
  tone(8, note_G4);
  back();
  redLight();
  delay(400);
  //F
  tone(8, note_F4);
  forward();
  greenLight();
  delay(400);
  //rest
  noTone(8);
  noLight();
  delay(400);
  //G#
  tone(8, note_Gs4);
  circleRight();
  redLight();
  delay(200);
  //A#
  tone(8, note_As4);
  circleRight();
  greenLight();
  delay(200);
  //C
  tone(8, note_C5);
  circleRight();
  redLight();
  delay(400);
  //A#
  tone(8, note_As4);
  circleRight();
  greenLight();
  delay(400);
  //rest
  noTone(8);
  noLight();
  wait();
  delay(400);
  //end circle
  //G#
  tone(8, note_Gs4);
  circleRight();
  redLight();
  delay(200);
  //A#
  tone(8, note_As4);
  circleRight();
  greenLight();
  delay(200);
  //C#
  tone(8, note_Cs5);
  circleRight();
  redLight();
  delay(200);
  //C#
  tone(8, note_Cs5);
  circleRight();
  greenLight();
  delay(200);
  //C
  tone(8, note_C5);
  circleRight();
  redLight();
  delay(200);
  //A#
  tone(8, note_As4);
  circleRight();
  greenLight();
  delay(200);
  //G#
  tone(8, note_Gs4);
  circleRight();
  redLight();
  delay(400);
  //G
  tone(8, note_G4);
  circleRight();
  greenLight();
  delay(400);
  //----------this is the chord
  //G#
  flash();
  tone(8, note_Gs4);
  //C
  tone(8, note_C5);
  //D#
  tone(8, note_Ds5);
  //G#
  tone(8, note_Gs5);
  vibrate();
  wait();
  noTone(8);
  noLight();
  delay(3000);
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

void circleRight() {
  servoLeft.writeMicroseconds(1200);        
  servoRight.writeMicroseconds(100);
}

void vibrate() {
  for (int i = 0; i < 4; i++) {
    forward();
    delay(200);
    back();
    delay(200);
  }
}

void right() {
  servoLeft.writeMicroseconds(2500);        
  servoRight.writeMicroseconds(1500);
}

void left() {
    servoLeft.writeMicroseconds(1500);        
    servoRight.writeMicroseconds(500);
}

void wait() {
  servoLeft.writeMicroseconds(1500);        
  servoRight.writeMicroseconds(1500);
}

void forward() {
  servoLeft.writeMicroseconds(2500);        
  servoRight.writeMicroseconds(500);
}

void back() {
  servoLeft.writeMicroseconds(500);        
  servoRight.writeMicroseconds(2500);
}

void redLight() {
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
}

void greenLight() {
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
}
void noLight() {
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
}

void flash() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(green, HIGH);
    digitalWrite(red, HIGH);
    delay(100);
    noLight();
    delay(100);
   }
}

void loop()
{
  //green LED
  pinMode(green, OUTPUT);
  //red LED
  pinMode(red, OUTPUT);
  song();
  // Code for testing servos. 
  // Tinker with the numbers to see how they work!
  // For help, visit https://learn.parallax.com/tutorials/robot/shield-bot/robotics-board-education-shield-arduino/chapter-2-shield-lights-servo-4. 

}
