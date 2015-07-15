#include <Servo.h>

const int ledWhite1 = 3;
const int ledWhite2 = 4;
const int ledPurple1 = 5;
const int ledPurple2 = 6;
const int ledBlue1 = 7;
const int ledBlue2 = 8;
const int ledRed1 = 9;
const int ledRed2 = 10;
const int ledGreen1 = 11;
const int ledGreen2 = 12;
int pos = 0;

Servo boxServo;

void setup() {
  pinMode(ledGreen1, OUTPUT);
  pinMode(ledGreen2, OUTPUT);
  pinMode(ledRed1, OUTPUT);
  pinMode(ledRed2, OUTPUT);
  pinMode(ledPurple1, OUTPUT);
  pinMode(ledPurple2, OUTPUT);
  pinMode(ledWhite1, OUTPUT);
  pinMode(ledWhite2, OUTPUT);
  pinMode(ledBlue1, OUTPUT);
  pinMode(ledBlue2, OUTPUT);
  
  boxServo.attach(13);
  Serial.begin(9600);
}

int jitter() {
  return random(0,10) - 5;
}

void dance_servo() {
      for(pos = 0; pos < 180; pos += 1)
      {
        boxServo.write(pos + jitter());
        delay(15 + jitter());
      }
      for(pos = 180; pos>=1; pos-=1)
      {
        boxServo.write(pos + jitter());
        delay(15 + jitter());
      }
}

void loop() {
  if (Serial.available() > 0) {          
    char in = (char)Serial.read();
    if (in == 'A') {
      digitalWrite(ledRed1, LOW);
      digitalWrite(ledGreen1, HIGH);
      dance_servo();
    }
    if (in == 'O') {
      digitalWrite(ledRed1, HIGH);
      digitalWrite(ledGreen1, LOW);
      dance_servo();
    }
  }
}
