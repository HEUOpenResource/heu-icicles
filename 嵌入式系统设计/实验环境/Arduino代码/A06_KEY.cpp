#include <Arduino.h>
int key_pin = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(key_pin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int key_up = 1;   // 按键松开标志
  if(key_up && digitalRead(key_pin)==0){
    delay(10);      // 消除抖动
    key_up = 0;
    if(digitalRead(key_pin)==0){
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else if(digitalRead(key_pin)==1){
      digitalWrite(LED_BUILTIN, LOW);
      key_up = 1;
    }
  }
}