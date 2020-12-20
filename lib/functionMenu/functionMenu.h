#ifndef FUNCE
#define FUNCE
 #include <Arduino.h>
 #include "../menuElement/menuElement.h"

 class functionMenu : public menuElement
 {
 private:
    
     uint8_t * data;
     int counter =1, min,max;
     String unit = "";
     
 public:
    void nextEvent(); 
    void backEvent(); 
    void moreEvent(); 
    void lessEvent();
    void print(driver::lcdController * lcd);
    void setStatus(bool x);

     functionMenu(String lable,uint8_t * data, String units,int min,int max);
     ~functionMenu();
 };
 #endif