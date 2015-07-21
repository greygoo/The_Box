#include <Servo.h>
#include <TrueRandom.h>

const int ledFlicker2_blue = 5;
const int ledFlicker2_white = 6;
const int ledFlicker1_blue = 9;
const int ledFlicker1_white = 10;
const int ledBacklight_yellow = 11;
const int ledMain_green = 8;
const int ledMain_yellow = 12;
const int ledMain_red = 13;
const int ledFlask1_green = A5;
const int ledFlask1_red = A4;
const int ledFlask2_green = A3;
const int ledFlask2_red = A2;
const int ledFlask3_green = A1;
const int ledFlask3_red = A0;
int pos = 0;

Servo boxServo;

void setup() {
  pinMode(ledFlask1_red, OUTPUT);
  pinMode(ledFlask2_red, OUTPUT);
  pinMode(ledFlask3_red, OUTPUT);
  pinMode(ledFlask1_green, OUTPUT);
  pinMode(ledFlask2_green, OUTPUT);
  pinMode(ledFlask3_green, OUTPUT);
  pinMode(ledBacklight_yellow, OUTPUT);
  pinMode(ledFlicker1_blue, OUTPUT);
  pinMode(ledFlicker2_blue, OUTPUT);
  pinMode(ledFlicker1_white, OUTPUT);
  pinMode(ledFlicker2_white, OUTPUT);
  pinMode(ledMain_green, OUTPUT);
  pinMode(ledMain_yellow, OUTPUT);
  pinMode(ledMain_red, OUTPUT);
  
  boxServo.attach(3);
  Serial.begin(9600);
}

int jitter() {
  return random(0,10) - 5;
}

void dance_servo() {
      for(pos = 0; pos < 180; pos += 1)
      {
       // if (pos >= 180) { pos = 179; };
        boxServo.write(pos);
        // delay(15 + jitter());
        delay(5);
      }
      for(pos = 180; pos>=1; pos-= 1)
      {
       // if (pos <= 0) { pos = 1; };
        boxServo.write(pos);
        // delay(15 + jitter());
        delay(5);
      }
}

void flask_light(int release) {
      if (release == 1) {
        digitalWrite(ledFlask1_red, LOW);
        digitalWrite(ledFlask2_red, LOW);
        digitalWrite(ledFlask3_red, LOW);
        digitalWrite(ledFlask1_green, HIGH);
        digitalWrite(ledFlask2_green, HIGH);
        digitalWrite(ledFlask3_green, HIGH);
      } else if (release == 0) {
        digitalWrite(ledFlask1_red, HIGH);
        digitalWrite(ledFlask2_red, HIGH);
        digitalWrite(ledFlask3_red, HIGH);
        digitalWrite(ledFlask1_green, LOW);
        digitalWrite(ledFlask2_green, LOW);
        digitalWrite(ledFlask3_green, LOW);
      } else {
        digitalWrite(ledFlask1_red, HIGH);
        digitalWrite(ledFlask2_red, HIGH);
        digitalWrite(ledFlask3_red, HIGH);
        digitalWrite(ledFlask1_green, HIGH);
        digitalWrite(ledFlask2_green, HIGH);
        digitalWrite(ledFlask3_green, HIGH);
      }       
}

void flicker() {
      for(int i=0; i < 300 ; i++)
      {
        analogWrite(ledFlicker1_white, TrueRandom.random(0,155));
        analogWrite(ledFlicker1_blue, TrueRandom.random(0,155));
        analogWrite(ledFlicker2_white, TrueRandom.random(0,155));
        analogWrite(ledFlicker2_blue, TrueRandom.random(0,155));
        delay(TrueRandom.random(10,40));
      }
      digitalWrite(ledFlicker1_white, LOW);
      digitalWrite(ledFlicker1_blue, LOW);
      digitalWrite(ledFlicker2_white, LOW);
      digitalWrite(ledFlicker2_blue, LOW);
}


void loop() {
  if (Serial.available() > 0) {          
    char in = (char)Serial.read();
    if (in == 'A') {
      dance_servo();
      flask_light(1);
      flicker();
    }
    if (in == 'O') {
      dance_servo();
      flask_light(0);
      flicker();
    }
  }
}
