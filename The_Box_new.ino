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

class Flicker
{
      int ledPin1;
      int ledPin2;
      int flick;
      long flickcount;

      unsigned long lastMillis;

  public:
  Flicker(int pin1, int pin2, long cycles)
  {
      ledPin1 = pin1;
      ledPin2 = pin2;
      pinMode(ledPin1, OUTPUT);
      pinMode(ledPin2, OUTPUT);

      flickcount = cycles;
      lastMillis = 0;
  }

  void Update()
  {
    unsigned long currentMillis = millis();
    if (currentMillis - lastMillis >= flick)
    {
      analogWrite(ledPin1, random(120)+135);
      analogWrite(ledPin2, random(120)+135);
    } 
  }

  void Run()
  {
    flick = random(120)+135;
    for(int i=0; i < flickcount ; i++)
    {
       self.Update();
    }
  }
}

class Flasher
{

      int ledPin;
      long OnTime;
      long OffTime;

      int ledState;
      unsigned long previousMillis;

  public:
  Flasher(int pin, long on, long off)
  {
      ledPin = pin;
      pinMode(ledPin, OUTPUT);

      OnTime = on;
      OffTime = off;

      ledState = LOW;
      previousMillis = 0;
  }

  void Update()
  {
    unsigned long currentMillis = millis();
    if((ledState = HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      ledState = LOW;
      previousMilis = currentMillis;
      digitalWrite(ledPin, ledState);
    }
    else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      ledState = HIGH;
      previousMillis = currentMillis;
      digitalWrite(ledPin, ledState);
    }
  }
}

Flasher led1(ledFlicker1_blue, 100, 400);
Flasher led2(ledFlicker1_white, 350, 350);

void setup()
{
}
 
void loop()
{
	led1.Update();
	led2.Update();
}

