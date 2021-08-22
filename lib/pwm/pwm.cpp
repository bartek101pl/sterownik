#include "./pwm.h"
pwm::pwm(uint8_t pinCode,int Hz)
{
    this->basTime = 1000000/ Hz;
    this->pinCode = pinCode;
    this->time = 0;
    this->oldTime= 0;

}

void pwm::init() {
    pinMode(this->pinCode,OUTPUT);
}

void pwm::update(float x){
    x =  (x>100) ? 100 : x;
    this->currentTime = micros() - this->oldTime;

    if( x == 0){
        digitalWrite(this->pinCode,LOW);


    }else{

        if(this->currentTime>=this->time)
        {
            this->oldTime = micros();
            if(this->status)
            {
                this->time = this->basTime * x /100;
                this->lowTime = this->basTime - this->time;
                digitalWrite(this->pinCode,HIGH);
                this->status = false;
            }
            else
            {
                digitalWrite(this->pinCode,LOW);
                this->status = true;
                this->time = (this->lowTime);
            }

        }

    }


}


bool pwm::getStatus(){
    return this->status;
}

pwm::~pwm()
{

}