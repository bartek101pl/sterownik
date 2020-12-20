#ifndef AXI
#define AXI

#include <Arduino.h>
#include "../menuElement/menuElement.h"
#include "../lcdController/lcdController.h"
#include "../functionMenu/functionMenu.h"
#include "../dataController/dataController.h"


class axisMenu: public menuElement
{
private:
   functionMenu *elements[5];
    driver::function * data;
    bool isSelect = false;
public:
    axisMenu(String lable,driver::function * data);
    ~axisMenu();
    virtual void nextEvent(); 
    virtual void backEvent(); 
    virtual void moreEvent(); 
    virtual void lessEvent();
    virtual void print(driver::lcdController * lcd);
};

#endif
