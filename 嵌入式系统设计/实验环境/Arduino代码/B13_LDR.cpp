#include <Arduino.h>
const int LDR_PIN = A0;
float var;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  var = analogRead(LDR_PIN);
  Serial.println(var);
}