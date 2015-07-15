#include <Servo.h>

const int ledRed = 7;
const int ledGreen = 8;
String incoming = "";
Servo boxServo;

int pos = 0;

void setup() {
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  
  boxServo.attach(9);
  Serial.begin(9600);
}

void dance_servo() {
      for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees
      {                                  // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
      for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees
      {
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);
      }
}

void loop() {
  if (Serial.available() > 0) {          
    char in = (char)Serial.read();
    if (in == 'A') {
      digitalWrite(ledRed, LOW);
      digitalWrite(ledGreen, HIGH);
      dance_servo();
    }
    if (in == 'O') {
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledGreen, LOW);
      dance_servo();
    }
  }
}
