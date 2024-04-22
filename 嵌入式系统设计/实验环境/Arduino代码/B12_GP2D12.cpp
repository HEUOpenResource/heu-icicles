#include <Arduino.h>
int GP2D12_PIN = 0;
int val;
float distance;

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(500);
  val = analogRead(GP2D12_PIN);
  distance = 2547.8/((float)val*0.49-10.41)-0.42;
  if ( distance > 80 || distance < 10 ) {
    Serial.println("ERROR: Over Range!");
  }
  distance = int(distance * 10)/10.0;
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println("cm");
}