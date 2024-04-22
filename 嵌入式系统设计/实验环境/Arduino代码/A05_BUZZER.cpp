#include <Arduino.h>
int buzzer_pin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<=255; i++){
    analogWrite(9, i);
    delay(50);
  }
}