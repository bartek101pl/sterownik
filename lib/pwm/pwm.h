#ifndef PWM
#define PWM

#include <Arduino.h>

class pwm
{
private:
    
    uint8_t pinCode;
    unsigned long time;
    float basTime;
    unsigned long currentTime;
    float lowTime;
    unsigned long oldTime;
    bool status = false;
    
public:
    pwm(uint8_t pinCode,int Hz);
    void update(float x);
    bool getStatus();
    void init();
    ~pwm();
};




#endif