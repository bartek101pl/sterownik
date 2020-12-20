#ifndef MENUE
#define MENUE

#include <Arduino.h>
#include "../lcdController/lcdController.h"
#include "../printElement/printElement.h"

class menuElement
{
protected:
   
    String lable = "";
    bool isActive = false,isSelect = false;
    int max = 0, currentID = 0;
private:
    
public:
void setStatus(bool x);
String getLable();
bool getStatus();
virtual void nextEvent()=0;
virtual void backEvent()=0;
virtual void lessEvent()=0;
virtual void moreEvent()=0;
virtual void print(driver::lcdController * lcd) =0;
};
#endif