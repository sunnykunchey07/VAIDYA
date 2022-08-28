#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

#include <Servo.h>

char auth[] = "GExHht65phuNcY7_MSbPRufg_DFz-i-V";

char ssid[] = "Kunchey";

char pass[] = "Sunny78010";

Servo servo;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;


BLYNK_WRITE(V0) {

servo.write(param.asInt());

}

BLYNK_WRITE(V1) {

servo1.write(param.asInt());

}

BLYNK_WRITE(V2) {

servo2.write(param.asInt());

}

BLYNK_WRITE(V3) {

servo3.write(param.asInt());

}

BLYNK_WRITE(V4) {

servo4.write(param.asInt());

}

BLYNK_WRITE(V5) {

servo5.write(param.asInt());

}

BLYNK_WRITE(V6) {

servo6.write(param.asInt());

}


void setup() {


Blynk.begin(auth, ssid, pass);



servo.attach(16); 
servo1.attach(5); 
servo2.attach(4); 
servo3.attach(0); 
servo4.attach(2); 
servo5.attach(14); 
servo6.attach(12); 

}

void loop()

{

Blynk.run();

}
