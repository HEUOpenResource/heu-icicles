#include <Arduino.h>

volatile byte state = LOW;
void led_on();

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(INT0, led_on, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, state);
}

void led_on() {
  state = !state;
}