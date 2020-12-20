#ifndef NRFLIB
#define NRFLIB

#include <Arduino.h>
struct senddata{
    int16_t a1x;
    int16_t a1y;
    int16_t a1z;
    int16_t a2x;
    int16_t a2y;
    int16_t a2z;
    int16_t a3x;
    int16_t a3y;
    int16_t a3z;
    bool bg = false;
    bool by = false;
    bool br = false;
    bool w1 = false;
    bool w2 = false;
    bool AWD = false;
    bool onoffL = false;
    bool onoffR = false;
    uint8_t code = 18;
};

class nrflib
{
private:

public:
nrflib() = default;
~nrflib() = default;



};





#endif