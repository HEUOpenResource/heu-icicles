#include <Arduino.h>

int led_pin[] = {8, 9, 10, 11, 12, 13};   // LED引脚
int led_cnt = 6;    // LED数量

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<led_cnt; i++){
    pinMode(led_pin[i], OUTPUT);    // 设置LED引脚为输出模式
    digitalWrite(led_pin[i], LOW);  // 设置输出低电平
  }
    
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<led_cnt; i++){
    digitalWrite(led_pin[i], HIGH);   // 设置输出高电平
    delay(200);                       // 延时200ms
    digitalWrite(led_pin[i], LOW);    // 设置输出低电平
  }
}