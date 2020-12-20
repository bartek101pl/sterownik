//
// Created by bartek on 14.09.2020.
//

#ifndef STEROWNIK_ONOFFMODE_H
#define STEROWNIK_ONOFFMODE_H
#include <Arduino.h>

class OnOffMode {
private:
    uint8_t pinCode;
    bool * zab;
public:
    OnOffMode(uint8_t pinCode , bool * zab);
    void update(bool x);
    void init();
    virtual ~OnOffMode();

};


#endif //STEROWNIK_ONOFFMODE_H
