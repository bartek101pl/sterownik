#ifndef analogPWMD
#define analogPWMD

#include <Arduino.h>
#include "../dataController/dataController.h"

class analogPWM
{
private:
    bool * zab;
    bool * help;
    uint8_t pinCode;
    unsigned long time;
    float basTime;
    unsigned long currentTime;
    unsigned long oldTime;
    int last = 0;
    const int petB = 4;
    float lowTime;
    bool status = false;
    driver::function * data;
public:
    analogPWM(uint8_t pinCode,driver::function * data, bool * zab,bool * help);
    ~analogPWM();
    void update(float x,bool i);
    void update(float x ,  bool * hPinStatus);
    bool getStatus();
    void init();
};
#endif

