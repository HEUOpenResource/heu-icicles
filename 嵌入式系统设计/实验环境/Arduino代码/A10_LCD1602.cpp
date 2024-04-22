#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>

// 初始化LCD控制引脚
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // 初始化LCD1602的行数和列数:
  lcd.begin(16, 2);
  // LCD显示Hello World
  lcd.print("hello, world!");
}

void loop() {
  // 设置要显示的位置为第二行第一列
  lcd.setCursor(0, 1);
  // 打印当前秒数
  lcd.print(millis() / 1000);
}
