#ifndef ANAM
#define ANAM

#include <Arduino.h>
#include "../menuElement/menuElement.h"
#include "../axisMenu/axisMenu.h"

class analogMenu: public menuElement
{
private:
    menuElement *elements[6];
   
    bool isSelect = false;
public:
    virtual void nextEvent(); 
    virtual void backEvent(); 
    virtual void moreEvent(); 
    virtual void lessEvent(); 
    virtual void print(driver::lcdController * lcd);
    analogMenu(String lable,driver::axisData * data);
    ~analogMenu();
};
#endif

