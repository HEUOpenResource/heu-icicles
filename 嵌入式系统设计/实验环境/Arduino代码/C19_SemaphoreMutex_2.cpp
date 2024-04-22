#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

TaskHandle_t start_handler;
TaskHandle_t low_handler;
TaskHandle_t middle_handler;
TaskHandle_t high_handler;

SemaphoreHandle_t MutexSemphr;

void start_task(void *pvParameters);
void low_task(void *pvParameters);
void middle_task(void *pvParameters);
void high_task(void *pvParameters);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xTaskCreate(start_task,
    "start_task",
    128,
    NULL,
    1,
    &start_handler
  );
  vTaskStartScheduler();
}

void loop() { }

void start_task(void *pvParameters) {
  taskENTER_CRITICAL();
  // 创建二值信号量需要一次释放，若为互斥信号量不需要释放
  MutexSemphr = xSemaphoreCreateMutex();
  // 创建任务
  xTaskCreate(high_task,
    "high_task",
    192,
    NULL,
    4,
    &high_handler
  );
  xTaskCreate(middle_task,
    "middle_task",
    192,
    NULL,
    3,
    &middle_handler
  );
  xTaskCreate(low_task,
    "low_task",
    192,
    NULL,
    2,
    &low_handler
  );
  vTaskDelete(start_handler);
  taskEXIT_CRITICAL();
}

void high_task(void *pvParameters) {
  for(;;) {
    vTaskDelay(500/portTICK_PERIOD_MS);
    Serial.println("high task Pend Semaphore...");
    xSemaphoreTake(MutexSemphr, portMAX_DELAY);
    Serial.println("high task Running!");
    xSemaphoreGive(MutexSemphr);
    vTaskDelay(500/portTICK_PERIOD_MS);
  }
}

void middle_task(void *pvParameters) {
  for(;;) {
    Serial.println("middle task Running!");
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void low_task(void *pvParameters) {
  static uint32_t times;
  for(;;) {
    xSemaphoreTake(MutexSemphr, portMAX_DELAY);
    Serial.println("low task Running!");
    // 模拟低优先级任务占用信号量
    for(times=0; times<2000000; times++) {
      taskYIELD();    // 发起任务调度
    }
    xSemaphoreGive(MutexSemphr);
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}