#ifndef MENUC
#define MENUC

#include <Arduino.h>
#include "../lcdController/lcdController.h"
#include "../menuElement/menuElement.h"
#include "../analogMenu/analogMenu.h"
#include "../axisMenu/axisMenu.h"
#include "../dataController/dataController.h"
namespace driver{

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
  bool b1;
  bool b2;
  bool b3;
  bool b4;
  bool b5; 
  bool b6;
  uint8_t code = 18;
};

    class menuController
    {
    private:
        dataController * _dataController;
        lcdController * lcd;
        saveData * data;
        menuElement *elements[3];
        int max = 2;
        int curretID = 0;
        bool isSelect = false;
        senddata dc;
    public:
        menuController(lcdController * lcd, dataController * data);
        menuController()=default;
        ~menuController();
        void next();
        void back();
        void less();
        void more();
        void refer();
        void connect();
        void NRF_status(bool x);
        void setData(senddata dc);
    };
        
}
#endif