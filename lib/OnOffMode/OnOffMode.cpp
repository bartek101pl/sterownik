//
// Created by bartek on 14.09.2020.
//

#include "OnOffMode.h"

OnOffMode::OnOffMode(uint8_t pinCode , bool * zab) {
    this->pinCode = pinCode;
    this->zab = zab;
}

OnOffMode::~OnOffMode() {
    delete this->zab;
}

void OnOffMode::update(bool x) {
    if(x)
        *this->zab = (*this->zab || x);

    digitalWrite(this->pinCode,x);
}

void OnOffMode::init() {
pinMode(this->pinCode,OUTPUT);
}
