#include "./printElement.h"



    printElement::printElement(const String text,bool center1,bool center2){
        int x = text.indexOf(this->brakeChar);
        if(x!=-1)
        {
            this->line1 = text.substring(0,x);
            this->line2 = text.substring(x+1,text.length());
        }else
        {
            this->line1 = text;
            this->line2 = "";
        }
        this->isCenter1 = center1;
        this->isCenter2 = center2;
    }
    printElement::printElement(const String text,bool center1){
        int x = text.indexOf(this->brakeChar);
        if(x!=-1)
        {
            this->line1 = text.substring(0,x);
            this->line2 = text.substring(x+1,text.length());
        }else
        {
            this->line1 = text;
            this->line2 = "";
        }
        this->isCenter1 = center1;
        this->isCenter2 = center1;
    }
    printElement::printElement(const String text){
        int x = text.indexOf(this->brakeChar);
        if(x!=-1)
        {
            this->line1 = text.substring(0,x);
            this->line2 = text.substring(x+1,text.length());
        }else
        {
            this->line1 = text;
            this->line2 = "";
        }
        this->isCenter1 = true;
        this->isCenter2 = true;
    }
    printElement::~printElement(){

    }
    void printElement::print(LiquidCrystal_PCF8574 * root,pwm * wd){
        int a1 = 0,a2 = 0;
        // root->clear();
        wd->update(50);
        if(this->isCenter1)
        {
        a1=(20-this->line1.length())/2;
        }
        wd->update(50);
        if(this->isCenter2)
        {
        a2=(20-this->line2.length())/2;
        }
        wd->update(50);
        root->setCursor(a1,1);
        wd->update(50);
        root->print(this->line1);
        wd->update(50);
        root->setCursor(a2,2);
        wd->update(50);
        root->print(this->line2);
        wd->update(50);
    }