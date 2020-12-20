#include "./menuController.h"

using namespace driver;

menuController::menuController(lcdController * lcd, dataController * data){
    this->data = &data->settings;
    this->_dataController = data;
    elements[0] = (new analogMenu{"Analog Prawy",&this->data->a1});
    elements[1] = (new analogMenu{"Analog Lewy",&this->data->a2});
    elements[2] = (new analogMenu{"Analog Srodkowy",&this->data->a3});

    this->lcd = lcd;
    this->max = (sizeof(this->elements)/sizeof(*this->elements))-1;
}
    
menuController::~menuController()
{
    delete this->lcd;
}
void menuController::next(){
if(!isSelect){
    if(this->lcd->getBackLightStatus()){
    this->elements[this->curretID]->setStatus(true);
    this->isSelect = true;
    }else
    {
        this->lcd->setBackLight(true);
    }
}else
{
    this->elements[this->curretID]->nextEvent();
}
this->refer();
}
void menuController::back(){
if(!isSelect){

        this->_dataController->save();
        
    
}else
{
    this->elements[this->curretID]->backEvent();
    this->isSelect = this->elements[this->curretID]->getStatus();
}
this->refer();
}
void menuController::less(){
    if(!isSelect){
        this->curretID--;
        this->curretID = (this->curretID<0)?this->max:this->curretID;
    }else
    {
        this->elements[this->curretID]->lessEvent();
    }
    this->refer();
}
void menuController::more(){
    if(!isSelect){
        this->curretID++;
        this->curretID = (this->curretID>this->max)?0:this->curretID;
    }else
    {
        this->elements[this->curretID]->moreEvent();
    }
    
    this->refer();
}
void menuController::refer(){
    if(!isSelect)
        this->lcd->setContent(new printElement(this->elements[this->curretID]->getLable()));
    else
        this->elements[curretID]->print(this->lcd);
}

void menuController::connect(){
this->lcd->init();
this->refer();
}
void menuController::NRF_status(bool x){
this->lcd->NRF_Status(x);
digitalWrite(A0,x);
}
