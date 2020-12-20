#ifndef EVLI
#define EVLI

#include <Arduino.h>
#include "../menuController/menuController.h"

namespace driver{
    class eventLisner
    {
    private:
        const int back = A2,next = A3,less = A4,more = A5,connect = A1;
        long long lastTime = 0;
        const int delayTime = 300;
        const int delayTime2 = 500;
        menuController * menu;
        bool isConnect = false;
        bool isConnect2 = false;

    public:
        void init();
        void update();
        eventLisner(menuController * menu);
        ~eventLisner();
        
    };
    

    
}
#endif