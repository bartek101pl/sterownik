#include "./eventLisner.h"

using namespace driver;

    eventLisner::eventLisner(menuController * menu)
    {
        this->menu = menu;
    }
    
    eventLisner::~eventLisner()
    {
        delete this->menu;
    }
    void eventLisner::init(){
        pinMode(back,INPUT);
        pinMode(next,INPUT);
        pinMode(less,INPUT);
        pinMode(more,INPUT);
        pinMode(connect,INPUT);
        this->lastTime = millis();
    }
    void eventLisner::update(){
        if(digitalRead(connect) == HIGH){
            if(!isConnect&&!isConnect2){
                isConnect2 = true;
                isConnect = true;
                this->lastTime = millis();
            }
            if(isConnect2 && millis()-this->lastTime > this->delayTime2){
                this->isConnect2 = false;
                this->menu->connect();
            }
        }
        else
        {
            this->isConnect = false;
            this->isConnect2 = false;
        }

        if(isConnect){
        //back Event
        if(digitalRead(this->back) == HIGH && millis()-this->lastTime > this->delayTime){
            this->lastTime = millis();
            this->menu->back();
        }
        //next Event
        if(digitalRead(this->next) == HIGH && millis()-this->lastTime > this->delayTime){
            this->lastTime = millis();
            this->menu->next();
        }
        //less Event
        if(digitalRead(this->less) == HIGH && millis()-this->lastTime > this->delayTime){
            this->lastTime = millis();
            this->menu->less();
        }
        //more Event
        if(digitalRead(this->more) == HIGH && millis()-this->lastTime > this->delayTime){
            this->lastTime = millis();
            this->menu->more();
        }
    }

    

    }