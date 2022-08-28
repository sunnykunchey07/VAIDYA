  #define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SPI.h>

char auth[] = "GX-KsrDrJH-dJH629IDFLMkJf-dw_slM";
char ssid[] = "Kunchey";
char pass[] = "Sunny78010";

#define IN_1   D1   // Right Connector motor
#define IN_2   D2
#define IN_3   D3   // Left Connector motor
#define IN_4   D4

#define En_A   D0
#define En_B   D5


void setup()
{
  // Debug console
  Serial.begin(9600);
  
  Blynk.begin(auth, ssid, pass);

  pinMode(IN_1,OUTPUT);
  pinMode(IN_2,OUTPUT);
  pinMode(IN_3,OUTPUT);
  pinMode(IN_4,OUTPUT);
  
  pinMode(En_A,OUTPUT);
  pinMode(En_B,OUTPUT);

  
  digitalWrite(IN_1,LOW);
  digitalWrite(IN_2,LOW);
  digitalWrite(IN_3,LOW);
  digitalWrite(IN_4,LOW);
}

BLYNK_WRITE(V0)
{
  int x = param[0].asInt();
  int y = param[1].asInt();
  
  Serial.print("x - "); 
  Serial.println(x);
  Serial.print("; y - "); 
  Serial.println(y);

  if((x ==512) && (y ==512)) //stop
  {
    Serial.print(" stop "); 
    stop();
  }
  if(y >=650 ) // forword
  {
    Serial.print(" forword "); 
    forword();
  }
  if(y <=400 ) // backword
  {
    Serial.print(" backword "); 
    backword();
  }
  if(x >=650 ) // right
  {
    Serial.print(" right "); 
    right();
  }
   if(x <=400 ) // left
  {
    Serial.print(" left "); 
    left();
  }
}

BLYNK_WRITE(V1) // speed varaiable
{
  int speed = param.asInt();
  analogWrite(En_A,speed);
  analogWrite(En_B,speed);

  Serial.print(" speed - "); 
  Serial.println(speed);

  if(speed <= 60 ) // speed stop
  {
    Serial.print(" stop "); 
    stop();
  }
}

  void forword(void)
  {
    digitalWrite(IN_1,LOW);   // Right Connector motor
    digitalWrite(IN_2,HIGH);
    digitalWrite(IN_3,LOW);   // left Connector motor
    digitalWrite(IN_4,HIGH);
    delay(20);
  }
  void backword(void)
  {
    digitalWrite(IN_1,HIGH);
    digitalWrite(IN_2,LOW);
    digitalWrite(IN_3,HIGH);
    digitalWrite(IN_4,LOW);
    delay(20);
  }
  void right(void)
  {
    digitalWrite(IN_1,HIGH);
    digitalWrite(IN_2,LOW);
    digitalWrite(IN_3,LOW);
    digitalWrite(IN_4,HIGH);
    delay(20);
  }
  void left(void)
  {
    digitalWrite(IN_1,LOW);
    digitalWrite(IN_2,HIGH);
    digitalWrite(IN_3,HIGH);
    digitalWrite(IN_4,LOW);
    delay(20);
  }
  void stop(void)
  {
    digitalWrite(IN_1,LOW);
    digitalWrite(IN_2,LOW);
    digitalWrite(IN_3,LOW);
    digitalWrite(IN_4,LOW);
    delay(20);
  }

void loop()
{
  Blynk.run();
}
