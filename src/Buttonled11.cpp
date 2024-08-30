
#include <Arduino.h>

const int buttonPin = 2;
const int Lampe1 = 9;
const int Lampe2 = 11;

int Count = 0;
int buttonState = 0; // variable for reading the pushbutton status
int loopCount = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(Lampe1, OUTPUT);
  pinMode(Lampe2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  analogWrite(Lampe1, 255);
  analogWrite(Lampe2, 0);

  int i = 10;
  char s[80];
  sprintf(s, "Hi %d", i);
  Serial.println(s);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW)
  {
    // Serial.println(buttonState);
    analogWrite(Lampe1, 0);
    analogWrite(Lampe2, 255);
    delay(4000);
    analogWrite(Lampe1, 0);
    analogWrite(Lampe1, 255);
    analogWrite(Lampe2, 0);
    ++Count;
    Serial.println(Count);
  }
  //Serial.print(loopCount);
  ++loopCount;
  delay(100);
}
