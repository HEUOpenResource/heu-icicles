#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

int LED0_PIN = 2;
int LED1_PIN = 3;

TaskHandle_t StartTask_Handler;
TaskHandle_t LED0Task_Handler;
TaskHandle_t LED1Task_Handler;

void start_task(void* pvParameters);
void led0_task(void* pvParameters);
void led1_task(void* pvParameters);

void setup() {
  pinMode(LED0_PIN, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  digitalWrite(LED0_PIN, LOW);
  digitalWrite(LED1_PIN, LOW);
  Serial.begin(9600);
  xTaskCreate(              // 创建开始任务
    start_task,
    "start_task",
    128,
    NULL,
    1,
    &StartTask_Handler);
  vTaskStartScheduler();    // 开启任务调度
}

void loop() {
  // 空，程序放在任务中执行。
}

void start_task(void* pvParameters) {
  taskENTER_CRITICAL();   // 进入临界区
  xTaskCreate(            // 创建LED0任务
    led0_task,
    "led0_task",
    128,
    NULL,
    2,
    &LED0Task_Handler);
  xTaskCreate(            // 创建LED1任务
    led1_task,
    "led1_task",
    128,
    NULL,
    3,
    &LED1Task_Handler);
  vTaskDelete(StartTask_Handler);
  taskEXIT_CRITICAL();    // 退出临界区
}

void led0_task(void* pvParameters) {
  int led0_num = 0;
  for(;;) {
    led0_num++;
    Serial.print("Task led0: ");
    Serial.println(led0_num);
    if(led0_num == 5) {
      vTaskDelete(LED1Task_Handler);  // 删除LED1任务
    }
    digitalWrite(LED0_PIN, HIGH);
    vTaskDelay(50);
    digitalWrite(LED0_PIN, LOW);
    vTaskDelay(50);
  }
}

void led1_task(void* pvParameters) {
  int led1_num = 0;
  for(;;) {
    led1_num++;
    Serial.print("Task led1: ");
    Serial.println(led1_num);
    digitalWrite(LED1_PIN, HIGH);
    vTaskDelay(50);
    digitalWrite(LED1_PIN, LOW);
    vTaskDelay(50);
  }
}