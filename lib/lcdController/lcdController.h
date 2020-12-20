#ifndef LCDC
#define LCDC

#include <Arduino.h>
#include <LiquidCrystal_PCF8574.h>
#include "../printElement/printElement.h"
#include "../pwm/pwm.h"
namespace driver{

class lcdController
{
private:
    bool backLight = true;
    bool _NRF_Status=false;
    LiquidCrystal_PCF8574 lcd{0x27};
    printElement * content{};
    pwm * wd;
public:
    lcdController(/* args */);
    void init();
    void setContent(printElement * content);
    void setBackLight(bool x);
    bool getBackLightStatus();
    void NRF_Status(bool x);
    void setWD(pwm * wd);
    ~lcdController();
};
}
#endif