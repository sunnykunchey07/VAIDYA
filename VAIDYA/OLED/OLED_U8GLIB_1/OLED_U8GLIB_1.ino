#include "U8glib.h"            // U8glib library for the OLED you download below
#include <Wire.h>              // Set Wire library for I2C communication

U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE); //set i2C Interface

void draw(void) 
{
  u8g.setFont(u8g_font_profont15);        // Set display font 1
  u8g.drawStr(5, 20, "ALSELECTRO.COM"); 
  u8g.setFont(u8g_font_profont29);        // Set display font 2
  u8g.setPrintPos(1, 45);                 // set print position 1, 45
  u8g.println("1.3 OLED");         
  
}

void setup(void) 
{
    
}

void loop(void) 
{
  u8g.firstPage();  
  do 
    {
     draw();      
    }
  while( u8g.nextPage() );
  
  delay(1000);  //Set delay 1 second
}
