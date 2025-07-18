#include<IRremote.h>

IRrecv irrecv_A0(A4);
decode_results results_A0;
long ir_item;

void go(){
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
}

void left(){
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW)；
}

void right(){
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
}

void stop(){
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}

void setup(){
    Serial.begin(9600);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    irrecv_A0.enableIRIn();
    // pinMode(4, INPUT);
    // pinMode(5, INPUT);
}

void loop(){
    if(irrecv_A0.decode(&results_A0)){
        ir_item=results_A0.value;
        String type="UNKNOWN";
        String typelist[14]={"UNKNOWN", "NEC", "SONY", "RC5", "RC6", "DISH", "SHARP", "PANASONIC", "JVC", "SANYO", "MITSUISHI", "SAMSUNG", "LG", "MHYNTER"};
        if(results_A0.decode_type>=1&&results_A0.decode_type<=13){
            type=typelist[results_A0.decode_type];
        }
        Serial.print("IR TYPE:" + type + "   ");
        Serial.println(ir_item,HEX);
        irrecv_A0.resume();
    } else {
        if (ir_item == 0XFF18E7){
        go();

        }

    }

    if(digitalRead(5) == 0 && digitalRead(4) == 0){
        stop();
    }else if(digitalRead(5) == 1 && digitalRead(4) == 0){
        right();
    }else if(digitalRead(5) == 0 && digitalRead(4) == 1){
        left();
    }else if(digitalRead(4) == 1 && digitalRead(5) == 1){
        go();
    }
}