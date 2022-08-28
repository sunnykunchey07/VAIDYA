#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET); /* Object of class Adafruit_SSD1306 */



void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
 // u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(0, 20); 
  // call procedure from base class, http://arduino.cc/en/Serial/Print
  u8g.print("Hello World!");
}

void setup(void) {
  // flip screen, if required
  // u8g.setRot180();
}

void loop(void) {
  // picture loop
//  u8g.firstPage();  
  do {
    draw();
//  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(500);
}
