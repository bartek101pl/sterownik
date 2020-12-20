#include "./lcdController.h"
using namespace driver;

lcdController::lcdController(/* args */)
= default;

lcdController::~lcdController()
= default;

void lcdController::init(){
    this->lcd.begin(20,4);
    lcd.clear();
    lcd.setBacklight(this->backLight);
}
void lcdController::setContent(printElement * content){
    
    delete this->content;
    this->content = content;
    
    // if(this->backLight)
    this->lcd.clear();

    

    this->lcd.setCursor(0,0);

    wd->update(50);

    if(!_NRF_Status)
        this->lcd.print("Status: Rozlaczono");
    else
        this->lcd.print("Status: Polaczono");
    wd->update(50);
    
    this->content->print(&this->lcd, wd);
    wd->update(50);

}
void lcdController::setBackLight(bool x){
//Not using
}
bool lcdController::getBackLightStatus(){
    return this->backLight;
}
void lcdController::NRF_Status(bool x){
    if(x!=this->_NRF_Status){
    this->_NRF_Status = x;
    this->lcd.clear();
    this->lcd.setCursor(0,0);
    if(!_NRF_Status)
    this->lcd.print("Status: Rozlaczono");
    else
    this->lcd.print("Status: Polaczono");
        this->content->print(&this->lcd , wd);
    }
}

void lcdController::setWD(pwm * wd){
    this->wd = wd;
}