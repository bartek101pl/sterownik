/*
- A0--Status led
- A1--Status led
*/

#include <Arduino.h>
#include "../lib/lcdController/lcdController.h"
#include "../lib/eventLisner/eventLisner.h"
#include "../lib/pwm/pwm.h"
#include "../lib/analogPWM/analogPWM.h"
#include "../lib/nrfLib/nrflib.h"
#include "../lib/OnOffMode/OnOffMode.h"

#define StatusPin 2
//#define OBDStatusPin 9 //Not using
#define timeout 500
driver::dataController data{};
driver::lcdController lcd{};
driver::menuController menu{&lcd,&data};
driver::eventLisner event{&menu};
bool zab[3] = {false,false,false};
bool helpD[3] = {false,false,false};
uint8_t zabList[3] = {A11,A12,A13};

bool help = false;

analogPWM a1x1{13,&data.settings.a1.x1,&zab[0],&help};
analogPWM a1x2{12,&data.settings.a1.x2,&zab[0],&help};
analogPWM a1y1{11,&data.settings.a1.y1,&zab[0],&help};
analogPWM a1y2{10,&data.settings.a1.y2,&zab[0],&help};
//analogPWM a1z1{31,&data.settings.a1.z1,&zab[1]};//ok p2-5 //Not using
//analogPWM a1z2{33,&data.settings.a1.z2,&zab[1]};//ok p2-6 //Not using
analogPWM a2x1{8,&data.settings.a2.x1,&zab[0],&help};
analogPWM a2x2{7,&data.settings.a2.x2,&zab[0],&help};
analogPWM a2y1{6,&data.settings.a2.y1,&zab[0],&help};
analogPWM a2y2{4,&data.settings.a2.y2,&zab[0],&help};
analogPWM a2z1{23,&data.settings.a2.z1,&zab[1],&help};
analogPWM a2z2{25,&data.settings.a2.z2,&zab[1],&help};
analogPWM a3x1{27,&data.settings.a3.x1,&zab[1],&help};
analogPWM a3x2{29,&data.settings.a3.x2,&zab[1],&help};
//analogPWM a3y1{27,&data.settings.a3.y1,&zab[1]};//ok p2-3 //Not using
//analogPWM a3y2{29,&data.settings.a3.y2,&zab[1]};//ok p2-4 //Not using
analogPWM a3z1{31,&data.settings.a3.z1,&zab[1],&help};
analogPWM a3z2{33,&data.settings.a3.z2,&zab[1],&help};

pwm wad{26,100};

OnOffMode bg{49,&zab[2]};
// OnOffMode by{51,&zab[2]}; //Not using
OnOffMode br{53,&zab[2]};

OnOffMode windaUp{45,&zab[2]};
OnOffMode windaDown{47,&zab[2]};

OnOffMode helpOut{35,&zab[1]};
OnOffMode kolano{39,&zab[2]};
OnOffMode napend{37,&zab[1]};
OnOffMode os{43,&zab[2]};
OnOffMode stop{41,&zab[2]};
OnOffMode pomoc_os_1{51,&zab[2]};


senddata dc;
senddata dc_old;
uint8_t counterD = 0;
bool is_start = false;
unsigned long time;

void setup() {
    wad.init();
    lcd.setWD(&wad);
    Serial.begin(9600);
    Serial1.begin(9600);
    time = millis();
    pinMode(A0,OUTPUT);
    pinMode(A1,INPUT);
    pinMode(StatusPin,INPUT);
    event.init();
    data.init();
    menu.refer();

    a1x1.init();
    a1x2.init();
    a1y1.init();
    a1y2.init();
//    a1z1.init(); //Not using
//    a1z2.init(); //Not using

    a2x1.init();
    a2x2.init();
    a2y1.init();
    a2y2.init();
    a2z1.init();
    a2z2.init();

    a3x1.init();
    a3x2.init();
//    a3y1.init(); //Not using
//    a3y2.init(); //Not using
    a3z1.init();
    a3z2.init();



    bg.init();
    // by.init(); //Not using
    br.init();

    windaDown.init();
    windaUp.init();

    helpOut.init();
    kolano.init();
    napend.init();
    os.init();
    stop.init();

    pinMode(zabList[0],OUTPUT);
    pinMode(zabList[1],OUTPUT);
    pinMode(zabList[2],OUTPUT);

    stop.update(false);

    digitalWrite(zabList[0],LOW);
    digitalWrite(zabList[1],LOW);
    digitalWrite(zabList[2],LOW);
    digitalWrite(StatusPin, HIGH);
}

void loop() {

    wad.update(50);

    if(Serial1.available()>=sizeof(senddata)){
        Serial1.readBytes((char *) &dc,sizeof(senddata));

        if(dc.code == 31){
            time = millis();
            menu.NRF_status(true);
        }

    }else
    {

    }
    wad.update(50);
    if( dc.code!=31 ||millis()-time > timeout) {
        if (dc.code!=31 || millis()-time > timeout){
            is_start = false;
            dc.a1x = 0;
            dc.a2x = 0;
            dc.a3x = 0;
            dc.a1y = 0;
            dc.a2y = 0;
            dc.a3y = 0;
            dc.a1z = 0;
            dc.a2z = 0;
            dc.a3z = 0;
            dc.AWD = false;
            dc.bg = false;
            dc.br = false;
            dc.by = false;
            dc.onoffL = false;
            dc.onoffR = false;
            dc.w1 = false;
            dc.w2 = false;
            menu.NRF_status(false);

            a1x1.update(0, true);
            a1x2.update(0, true);
            a1y1.update(0, true);
            a1y2.update(0, true);
//            a1z1.update(0, true); //Not using
//            a1z2.update(0, true); //Not using

            a2x1.update(0, true);
            a2x2.update(0, true);
            a2y1.update(0, true);
            a2y2.update(0, true);
            a2z1.update(0, true);
            a2z2.update(0, true);

            a3x1.update(0, true);
            a3x2.update(0, true);
//            a3y1.update(0, true); //Not using
//            a3y2.update(0, true); //Not using
            a3z1.update(0, true);
            a3z2.update(0, true);


            bg.update(false);
            // by.update(false); //Not using
            br.update(false);

            windaDown.update(false);
            windaUp.update(false);

            helpOut.update(false);
            kolano.update(false);
            napend.update(false);
            os.update(false);

            stop.update(!is_start);
            if(dc.code !=31){
                digitalWrite(StatusPin,LOW);
                while (Serial1.available())
                {
                    Serial1.read();
                }

                digitalWrite(StatusPin,HIGH);
                dc.code = 31;
            }
        }else
        {
            while (Serial1.available())
            {
                Serial1.read();
            }
            counterD++;
            dc = dc_old;
        }


    }else
    {
        is_start = true;
        counterD = 0;
    }

    wad.update(50);

    event.update();

    wad.update(50);

    zab[0] = false;
    zab[1] = false;
    zab[2] = false;

    helpD[0] = false;
    helpD[1] = false;
    helpD[2] = false;

    help = false;

    a1x1.update((float)(dc.a1x<0?-dc.a1x:0),&helpD[0]);
    a1x2.update((float)(dc.a1x>0?dc.a1x:0),&helpD[0]);

    if(dc.onoffR)
    {
        kolano.update(helpD[0]);
    }
    else
    {
        kolano.update(false);
    }

    wad.update(50);
    a1y1.update((float)(dc.a1y<0?-dc.a1y:0),false);
    a1y2.update((float)(dc.a1y>0?dc.a1y:0),false);
//    a1z1.update((float)(dc.a1z<0?-dc.a1z:0)); //Not using
//    a1z2.update((float)(dc.a1z>0?dc.a1z:0)); //Not using

    wad.update(50);

    a2x1.update((float)(dc.a2x<0?-dc.a2x:0),false);
    wad.update(50);
    a2x2.update((float)(dc.a2x>0?dc.a2x:0),false);
    wad.update(50);
    a2y1.update((float)(dc.a2y<0?-dc.a2y:0),false);
    wad.update(50);
    a2y2.update((float)(dc.a2y>0?dc.a2y:0),false);
    wad.update(50);
    a2z1.update((float)(dc.a2z<0?-dc.a2z:0),false);
    wad.update(50);
    a2z2.update((float)(dc.a2z>0?dc.a2z:0),false);
    wad.update(50);

    wad.update(50);

    a3x1.update((float)(dc.a3x<0?-dc.a3x:0),&helpD[1]);
    a3x2.update((float)(dc.a3x>0?dc.a3x:0),&helpD[1]);

    if(dc.AWD)
    {
        napend.update(helpD[1]);
    }
    else
    {
        napend.update(false);
    }
//    a3y1.update((float)(dc.a3y<0?-dc.a3y:0)); //Not using
//    a3y2.update((float)(dc.a3y>0?dc.a3y:0)); //Not using
    a3z1.update((float)(dc.a3z<0?-dc.a3z:0),&helpD[2]);
    a3z2.update((float)(dc.a3z>0?dc.a3z:0),&helpD[2]);
    wad.update(50);
    pomoc_os_1.update(helpD[2]);
    if(!dc.onoffL)
    {
        os.update(helpD[2]);
    }
    else
    {
        os.update(false);
    }

    wad.update(50);

    helpOut.update(help);

    windaUp.update((!dc.w2?dc.w1: false));
    windaDown.update((!dc.w1?dc.w2: false));

    bg.update(dc.bg);
    br.update(dc.br);
    //  by.update(dc.by); //Not using

    wad.update(50);

    stop.update(!is_start);

    digitalWrite(zabList[0],zab[0]);
    digitalWrite(zabList[1],zab[1]);
    digitalWrite(zabList[2],zab[2]);
    wad.update(50);
}
