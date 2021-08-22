#include "./axisMenu.h"

axisMenu::axisMenu(String lable, driver::function * data)
{
    this->data = data;
    this->lable = lable;
    this->elements[0] = new functionMenu{"Prog min",&this->data->min,"%",0,100};
    this->elements[1] = new functionMenu{"Prog max",&this->data->max,"%",0,100};
    this->elements[2] = new functionMenu{"Rampa",&this->data->ramp,"",10,100};
    this->elements[3] = new functionMenu{"Czestotliwosc",&this->data->hz,"Hz",25,50};
    this->elements[4] = new functionMenu{"Dodatkowa Cewka",&this->data->help,"0-NIE/1-TAK",0,1};
    this->max = (sizeof(this->elements)/sizeof(*this->elements))-1;
}

axisMenu::~axisMenu()
{
}

void axisMenu::moreEvent(){
    if(!this->isSelect)
    {
    this->currentID++;
    this->currentID = (this->currentID>this->max)?0:this->currentID;
    }else{
        this->elements[this->currentID]->moreEvent();
    }
}
void axisMenu::lessEvent(){
    if(!this->isSelect)
    {
        this->currentID--;
        this->currentID = (this->currentID<0)?this->max:this->currentID;
    }else{

        this->elements[this->currentID]->lessEvent();
    }
}
void axisMenu::backEvent(){
    if(!this->isSelect)
    {
        this->isActive = false;
    }else
    {
        this->elements[currentID]->backEvent();
        this->isSelect = this->elements[this->currentID]->getStatus();
    }
}
void axisMenu::nextEvent(){
    if(!isSelect)
    {
        isSelect = true;
    }else{
        this->elements[this->currentID]->nextEvent();
        this->isSelect = this->elements[this->currentID]->getStatus();
    }
}
void axisMenu::print(driver::lcdController * lcd){
    if(!this->isSelect){
        lcd->setContent(new printElement{this->elements[this->currentID]->getLable()});
    }else
    {
        Serial.println("h");
        elements[currentID]->print(lcd);
    }
}