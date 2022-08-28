 #include "U8glib.h"
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI 

int p;

void page1();     
void page2(); 
void page3();   
void page4();      

void (*pages[])() = { page1, page2, page3, page4 } ;

void setup() {  
  u8g.setFont(u8g_font_unifont);
  u8g.setColorIndex(1);
  p = 0;
  
}

void loop() {  
  u8g.firstPage();
  do {  
    (*pages[p])();
  } while( u8g.nextPage() );
  delay(1000); 
  p = p+1;
  if (p == 4)
    p=0;
}
  


void page1() {
  u8g.drawStr( 0, 15, "First Page");
  
}
void page2(){
  u8g.drawStr( 0, 15, "2nd Page"); 
  
}
void page3() {
 
  u8g.drawStr( 0, 15, "Third Page"); 
  
}
void page4(){
 
  u8g.drawStr( 0, 15, "Fourth Page"); 
 
}
