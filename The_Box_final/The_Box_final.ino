#include <Servo.h>
#include <LED_Switch.h>
#include <Arduino.h>
#include <TrueRandom.h>
#include <Servo_Jump.h>
#include <Flicker.h>

const int ledFlicker2_blue = 9;
const int ledFlicker2_white = 10;
const int ledFlicker1_blue = 5;
const int ledFlicker1_white = 6;
const int ledBacklight_yellow = 11;
const int ledMain_green = 8;
const int ledMain_yellow = 12;
const int ledMain_red = 13;
int flickerDuration = 8000;
int GaugeDuration = 10000;
int LED_timeout = 9000;

Flicker Flicker1(ledFlicker1_blue, 10, 40, 0, 255,  flickerDuration);
Flicker Flicker2(ledFlicker1_white, 10, 40, 0, 255, flickerDuration);
Flicker Flicker3(ledFlicker2_blue, 1, 10, 0, 255, flickerDuration);
Flicker Flicker4(ledFlicker2_white, 1, 10, 0, 255, flickerDuration);

Servo_Jump Gauge(200, 0, 180, GaugeDuration);

LED_Switch LED_red(1, 8000);
LED_Switch LED_green(0, 8000);

void setup() {
  pinMode(ledBacklight_yellow, OUTPUT);
  pinMode(ledFlicker1_blue, OUTPUT);
  pinMode(ledFlicker2_blue, OUTPUT);
  pinMode(ledFlicker1_white, OUTPUT);
  pinMode(ledFlicker2_white, OUTPUT);
  pinMode(ledMain_green, OUTPUT);
  pinMode(ledMain_yellow, OUTPUT);
  pinMode(ledMain_red, OUTPUT);
  
  digitalWrite(ledBacklight_yellow, HIGH);

  Gauge.Attach(3);
  Serial.begin(9600);
}

void dance_servo() {
  Gauge.Enable();
}

void test(){
  Serial.print("Hello World\n");
}  

void flicker() {
  Flicker1.Enable();
  Flicker2.Enable();
  Flicker3.Enable();
  Flicker4.Enable();
}

void update_all() {
  Flicker1.Update();
  Flicker2.Update();
  Flicker3.Update();
  Flicker4.Update();

  Gauge.Update();
  
  LED_green.Update();
  LED_red.Update();
}

void loop() {
  update_all();
  if (Serial.available() > 0) {          
    char in = (char)Serial.read();
    if (in == 'A') {
      flicker();
      dance_servo();
      Gauge.JumpTo(0);
      LED_red.Enable();
    }
    if (in == 'O') {
      flicker();
      dance_servo();
      Gauge.JumpTo(180);
      LED_green.Enable();
    }
  }
}
