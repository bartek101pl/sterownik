#include "./analogMenu.h"

analogMenu::analogMenu(String lable,driver::axisData * data)
{
    elements[0]= new axisMenu{"Analog&do przodu",&data->x1};
    elements[1] = new axisMenu{"Analog&do tylu",&data->x2};
    elements[2] = new axisMenu{"Analog&w prawo",&data->y1};
    elements[3] = new axisMenu{"Analog&w lewo",&data->y2};
    elements[4] = new axisMenu{"obrot&w prawo",&data->z1};
    elements[5] = new axisMenu{"obrot&w lewo",&data->z2};
    this->lable = lable;
    this->max = (sizeof(this->elements)/sizeof(*this->elements))-1;
}

analogMenu::~analogMenu()
{

}

void analogMenu::moreEvent() {
    if(!this->isSelect)
    {
    this->currentID++;
    this->currentID = (this->currentID>this->max)?0:this->currentID;
    }else
    {
        this->elements[this->currentID]->moreEvent();
    }
}
void analogMenu::lessEvent(){
    if(!this->isSelect)
    {
    this->currentID--;
    this->currentID = (this->currentID<0)?this->max:this->currentID;
    }else
    {
        this->elements[this->currentID]->lessEvent();
    }
}
void analogMenu::nextEvent(){
    if(!this->isSelect)
    {
        this->isSelect = true;
        this->elements[this->currentID]->setStatus(true);
    }else
    {
        this->elements[this->currentID]->nextEvent();
         this->isSelect = this->elements[this->currentID]->getStatus();
    }
}
void analogMenu::backEvent(){
    if(!this->isSelect){
        this->isActive = false;
    }else
    {
        this->elements[this->currentID]->backEvent();
        this->isSelect = this->elements[this->currentID]->getStatus();
    }
}
void analogMenu::print(driver::lcdController * lcd){
    if(!this->isSelect)
    lcd->setContent(new printElement{this->elements[this->currentID]->getLable()});
    else
        this->elements[this->currentID]->print(lcd);
}
