#include "./dataController.h"
using namespace driver;

    dataController::dataController(/* args */)
    {
    }
    
    dataController::~dataController()
    {
    }
    void dataController::init(){
        EEPROM.get(0,this->settings);
        if(this->settings.code != this->code)
        {
            pinMode(5,OUTPUT);
            long long time = 0;
            while (1)
            {
                
            }
            this->init();
            
            
        }
    }
    void dataController::factorySetting(){
        settings.a1.x1 = {0,100,33,50,0};
        settings.a1.x2 = {0,100,33,50,0};
        settings.a1.y1 = {0,100,33,50,0};
        settings.a1.y2 = {0,100,33,50,0};
        settings.a1.z1 = {0,100,33,50,0};
        settings.a1.z2 = {0,100,33,50,0};
        settings.a1.zabezpi = 0;
        settings.a1.zabezpi2 = 0;
        settings.a2.x1 = {0,100,33,50,0};
        settings.a2.x2 = {0,100,33,50,0};
        settings.a2.y1 = {0,100,33,50,0};
        settings.a2.y2 = {0,100,33,50,0};
        settings.a2.z1 = {0,100,33,50,0};
        settings.a2.z2 = {0,100,33,50,0};
        settings.a2.zabezpi = 0;
        settings.a2.zabezpi2 = 0;
        settings.a3.x1 = {0,100,33,50,0};
        settings.a3.x2 = {0,100,33,50,0};
        settings.a3.y1 = {0,100,33,50,0};
        settings.a3.y2 = {0,100,33,50,0};
        settings.a3.z1 = {0,100,33,50,0};
        settings.a3.z2 = {0,100,33,50,0};
        settings.a3.zabezpi = 2;
        settings.a3.zabezpi2 = 2;

        settings.code = this->code;
        this->save();
    }
    void dataController::save(){
        EEPROM.put(0,this->settings);
    }