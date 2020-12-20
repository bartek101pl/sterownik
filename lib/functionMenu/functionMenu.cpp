#include "./functionMenu.h"

functionMenu::functionMenu(String lable,uint8_t * data,String units,int min,int max)
{
    this->lable = lable;
    this->max = max;
    this->min = min;
    this->data = data;
    this->unit = units;
}

functionMenu::~functionMenu()
{
}
void functionMenu::moreEvent(){
    if(this->old == -1)
    {
        this->old = *this->data;
    }
        if(*this->data<this->max)
    {
        *this->data+=this->counter;
        
    }
}
void functionMenu::lessEvent(){
     if(this->old == -1)
    {
        this->old = *this->data;
    }
    if(*this->data>this->min)
    {
        *this->data-=this->counter;
        
    }
}
void functionMenu::backEvent(){
    if(this->old!=-1)
        *this->data = this->old;
    
    this->old = -1;
    this->isActive =false;
}
void functionMenu::nextEvent(){
    this->old = -1;
    this->isActive =false;
}
void functionMenu::print(driver::lcdController * lcd){
    
    lcd->setContent(new printElement{this->lable+"&"+(String(*this->data)+" "+this->unit),false,true});
}
void functionMenu::setStatus(bool x){
    this->currentID = 0;
    this->isActive = x;
}