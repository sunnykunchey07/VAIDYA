#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET); /* Object of class Adafruit_SSD1306 */

void setup() {
  display.begin(SH1106_SWITCHCAPVCC, 0x3C); /* Initialize display with address 0x3C */
  display.clearDisplay(); /* Clear display */
  display.setTextColor(WHITE);
  display.setTextSize(2); /* Select font size of text. Increases with size of argument. */
  // DISPLAY NUMBERS
  display.setCursor(0,14);
  display.println(123456789);
  display.display();
  delay(5000);
  display.clearDisplay();
  display.setCursor(0,14);
  display.println(1.23456,2);
  display.display();
  delay(5000);
  display.clearDisplay();
  //specify Base for numbers
  
  display.setCursor(0,2);
  display.print(0xFF, HEX); 
  display.setCursor(0,18);
  display.print(0xFF, DEC);
  display.display();
  delay(5000);
  display.clearDisplay();
  //display ASCII characters
  display.setCursor(15,10);
  display.write(36);  // $ symbol
  display.setCursor(40,10);
  display.write(248);  //  degree symbol
  display.setCursor(70,10);
  display.write(61);  //  =  symbol
  display.display();
 
}

void loop() {
  
  
}
