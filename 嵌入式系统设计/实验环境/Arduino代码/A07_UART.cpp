#include <Arduino.h>

String comdata = "";

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    while (Serial.available() > 0)  
    {
        comdata += char(Serial.read());
        delay(2);
    }
    if (comdata.length() > 0)
    {
        Serial.print("Received: ");
        Serial.println(comdata);
        comdata = "";
    }
}
