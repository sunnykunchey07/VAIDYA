

#include"SD.h"                //declare SD library for SD cards
#define SD_ChipSelectPin   //select sd chip select pin 10
#include"TMRpcm.h"            //library to play audio from sd card by arduino
#include"SPI.h"              //create Serial peripheral Interface Communication
TMRpcm tmrpcm;              //name tmrpcm


int in1= ;               //declare Infrared sensor pins
int in2= ;
int in3= ;

void setup() 
{

 tmrpcm.speakerPin= 4;   //Speaker pin 9,audio out pin is 9
 
 Serial.begin(9600);    //initialize Serial communication
 
 if(!SD.begin(SD_ChipSelectPin))   //this runs until SD is connected
 {
  Serial.println("SD FAIL");
  return; 
 }

}

void loop() 
{
  if(!(digitalRead(in3)))          //Chest sensor is low- Say "Hi there.."
  {
   tmrpcm.play("welcome.wav");     //Playing audio saved as 'welcome.wav'
           //hand up- saying HI
    delay(2000);
          //hand comes to handshake position
    
    delay(9000);
    
  }
 
  if(!(digitalRead(in1)))       //Sensor on eye gets low play audio -"dont touch my eye"
  {
    tmrpcm.play("dont.wav");     //play file saved as "dont.wav" - dont touch my eye 
    delay(3000);
  }
 
  if(!(digitalRead(in2)))     //Sensor on eye gets low play audio -"dont touch my eye"
  {
    tmrpcm.play("dont.wav");
 
    delay(3000);
  }
}
