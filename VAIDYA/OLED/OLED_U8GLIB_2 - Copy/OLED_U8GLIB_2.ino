#include "U8glib.h"

// Change this constructor to match your display.WE USE 1.3 INCH OLED SH1106
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI 

int yPos = 0;

void setup() {  
  
  u8g.setFont(u8g_font_unifont);
  //u8g.setColorIndex(1); // Instructs the display to draw with a pixel on. 
}

void loop() {  
  u8g.firstPage();
  do {  
    draw();
  } while( u8g.nextPage() );
  
  // add a delay if it is fast ,increment y by a greater number if it's slow
  if(yPos < 83){
    yPos++;  }
  else{
    // When the yPos is off the screen, reset to 0.
    yPos = 0;
  }  
}  
void draw(){
  u8g.drawStr( 0, yPos, "Hello World");    
}
