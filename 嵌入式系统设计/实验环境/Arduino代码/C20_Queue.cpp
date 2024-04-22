#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <queue.h>

struct pinRead {
  int pin;
  int value;
};

QueueHandle_t structQueue;

TaskHandle_t serial_handler;
TaskHandle_t adc0_handler;
TaskHandle_t adc1_handler;
TaskHandle_t blink_handler;

void TaskSerial(void* pvParameters);
void TaskADCPin0(void* pvParameters);
void TaskADCPin1(void* pvParameters);
void TaskBlink(void* pvParameters);

void setup() {
  structQueue = xQueueCreate(10, sizeof(struct pinRead));
  
  if (structQueue != NULL) {
    
    xTaskCreate(TaskSerial,
                "Serial",
                128,
                NULL, 
                2,
                &serial_handler);

    xTaskCreate(TaskADCPin0,
                "ADCPin0",
                128,
                NULL, 
                1,
                &adc0_handler);

    xTaskCreate(TaskADCPin1,
                "ADCPin1",
                128,
                NULL, 
                1,
                &adc1_handler);
    
  }


  xTaskCreate(TaskBlink,
              "Blink",
              128,
              NULL, 
              0,
              &blink_handler);

}

void loop() {}

void TaskADCPin0(void *pvParameters)
{
  struct pinRead currentPinRead;
  for (;;)
  {
    currentPinRead.pin = 0;
    currentPinRead.value = analogRead(A0);

    xQueueSend(structQueue, &currentPinRead, portMAX_DELAY);

    vTaskDelay(50 / portTICK_PERIOD_MS);
  }
}

void TaskADCPin1(void *pvParameters)
{
  struct pinRead currentPinRead;
  for (;;)
  {
    currentPinRead.pin = 1;
    currentPinRead.value = analogRead(A1);

    xQueueSend(structQueue, &currentPinRead, portMAX_DELAY);

    vTaskDelay(50 / portTICK_PERIOD_MS);
  }
}

void TaskSerial(void * pvParameters) {

  Serial.begin(9600);
  struct pinRead currentPinRead;

  for (;;) 
  {
    if (xQueueReceive(structQueue, &currentPinRead, portMAX_DELAY) == pdPASS) {
      Serial.print("Pin: ");
      Serial.print(currentPinRead.pin);
      Serial.print(" Value: ");
      Serial.println(currentPinRead.value);
    }
  }
}

void TaskBlink(void *pvParameters)
{
  pinMode(LED_BUILTIN, OUTPUT);

  for (;;)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay( 250 / portTICK_PERIOD_MS );
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay( 250 / portTICK_PERIOD_MS );
  }
}
