#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

SemaphoreHandle_t interruptSemaphore; // 声明一个二值信号量

void TaskLed(void *pvParameters);
void interruptHandler();

void setup() {

  pinMode(2, INPUT_PULLUP);

  xTaskCreate(TaskLed, 
              "Led", 
              128,  
              NULL, 
              0, 
              NULL );

  
  interruptSemaphore = xSemaphoreCreateBinary();
  if (interruptSemaphore != NULL) {
    // 配置中断
    attachInterrupt(digitalPinToInterrupt(2), interruptHandler, LOW);
  }

  
}

void loop() {}


void interruptHandler() {
  // 释放信号量
  xSemaphoreGiveFromISR(interruptSemaphore, NULL);
}


void TaskLed(void *pvParameters)
{
  (void) pvParameters;

  pinMode(LED_BUILTIN, OUTPUT);

  for (;;) {
    
    // 获取信号量
    if (xSemaphoreTake(interruptSemaphore, portMAX_DELAY) == pdPASS) {
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    }
  }
}
