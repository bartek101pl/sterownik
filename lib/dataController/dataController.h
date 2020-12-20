#ifndef DATC
#define DATC

#include <Arduino.h>
#include <EEPROM.h>





namespace driver
{

    struct function
{
    uint8_t min;
    uint8_t max;
    uint8_t hz;
    uint8_t ramp;
    uint8_t help;
};
struct axisData
{
    driver::function x1;
    driver::function x2;
    driver::function y1;
    driver::function y2;
    driver::function z1;
    driver::function z2;
    uint8_t zabezpi;
    uint8_t zabezpi2;
};

struct saveData
{
    driver::axisData a1;
    driver::axisData a2;
    driver::axisData a3;
    uint8_t code = 18;
};
    class dataController
    {
    private:
       const uint8_t code = 12;
    public:
        driver::saveData settings;
        dataController(/* args */);
        void init();
        void save();
        void factorySetting();
        ~dataController();
    };
    

    
} // namespace driver

#endif