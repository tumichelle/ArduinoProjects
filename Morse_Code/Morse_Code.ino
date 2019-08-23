void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
}
// dash and dot function definitions
void dash(){
    digitalWrite(6, HIGH);
    delay(1500);
    digitalWrite(6, LOW);
    delay(500);
  }
void dot() {
    digitalWrite(6, HIGH);
    delay(500);
    digitalWrite(6, LOW);
    delay(500);
  }

void one() {
  dot();
  dash();
  dash();
  dash();
  dash();
}

void two() {
  dot();
  dot();
  dash();
  dash();
  dash();
}

void three() {
  dot();
  dot();
  dot();
  dash();
  dash();
}

void four() {
  dot();
  dot();
  dot();
  dot();
  dash();
}

void five() {
  dot();
  dot();
  dot();
  dot();
  dot();
}

void loop() {
  // put your main code here, to run repeatedly:
  //GWMC (Girls Who Morse Code) in morse code:
  dash();
  dash();
  dot();
  delay(1500);
  //^this is G
  dot();
  dash();
  dash();
  delay(1500);
  //^this is W
  dash();
  dash();
  delay(1500);
  //^this is M
  dash();
  dot();
  dash();
  dot();
  delay(3000);
  //^this is C and a long delay
}
