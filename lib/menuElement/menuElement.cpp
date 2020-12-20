#include "./menuElement.h"

void menuElement::nextEvent(){
    
}
void menuElement::backEvent(){

}
void menuElement::lessEvent(){

}
void menuElement::moreEvent(){

}
String menuElement::getLable(){
    return this->lable;
}

bool menuElement::getStatus(){
    return this->isActive;
}
void menuElement::print(driver::lcdController * lcd){
    
}
void menuElement::setStatus(bool x){
    this->currentID = 0;
    this->isActive = x;
}