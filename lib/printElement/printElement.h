#ifndef PREL
#define PREL

#include <Arduino.h>
#include <LiquidCrystal_PCF8574.h>
#include "../pwm/pwm.h"
class printElement
{
private:
    const char brakeChar = '&'; 
    String line1,line2;
    bool isCenter1=false,isCenter2 = false;
public:
    printElement(const String text,bool center1,bool center2);
    printElement(const String text,bool center1);
    printElement(const String text);
    ~printElement();
    void print(LiquidCrystal_PCF8574 * root , pwm * wd);
};




#endif