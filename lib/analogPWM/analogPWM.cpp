#include "./analogPWM.h"

analogPWM::analogPWM(uint8_t pinCode,driver::function * data,bool * zab,bool * help)
{
    this->help = help;
    this->zab =zab;
    this->data = data;
    this->pinCode = pinCode;
    this->time = 0;
    this->oldTime= 0;

}

void analogPWM::init() {
    pinMode(this->pinCode,OUTPUT);
}

void analogPWM::update(float x , bool i){
    if(i){
        this->last = 0;
    }
    x =  (x>100) ? 100 : x;
    //  x = (x>10) ? x: 0;

    this->currentTime = micros() - this->oldTime;

    if(this->last == 0 && x == 0){
        digitalWrite(this->pinCode,LOW);


    }else{
        if(this->data->help == 1)
        {
            *this->help = (*this->help|| true);
        }

        *this->zab = (*this->zab || 1);
        if(this->currentTime>=this->time)
        {
            this->oldTime = micros();
            if(this->status)
            {
                this->basTime = 1000000/ this->data->hz;
                float h = (float)petB*(float)this->data->ramp/100.00f;
                h = (h==0)?0.01:h;
                if(this->data->ramp!=100){
                    if(abs(this->last-x)>h) {
                        if (this->last > x) {
                            x = this->last - h;
                        } else {
                            x = this->last + h;
                        }

                    }
                }
                float minTime = (float)this->basTime*(float)this->data->min/(float)100;
                float maxTime = ((float)this->basTime-minTime)*(float)this->data->max/(float)100;
                float Htime = minTime+(maxTime)*((float)x/(float)100);
                this->lowTime = (float)this->basTime-Htime;
                if(x!=0)
                    digitalWrite(this->pinCode,HIGH);
                else
                    digitalWrite(this->pinCode,LOW);
                this->status = false;
                this->time = Htime;
                this->last = x;
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


void analogPWM::update(float x , bool * hPinStatus){
    x =  (x>100) ? 100 : x;
    //  x = (x>10) ? x: 0;

    this->currentTime = micros() - this->oldTime;
    hPinStatus = (this->last!=0?hPinStatus:false);
    if(this->last == 0 && x == 0){
        digitalWrite(this->pinCode,LOW);


    }else{
        *this->zab = (*this->zab || 1);
        *hPinStatus = (*hPinStatus || true);

        if(this->data->help == 1)
        {
            *this->help = (*this->help|| true);
        }

        if(this->currentTime>=this->time)
        {
            this->oldTime = micros();
            if(this->status)
            {
                this->basTime = 1000000/ this->data->hz;
                float h = (float)petB*(float)this->data->ramp/100.00f;
                h = (h==0)?0.01:h;
                if(this->data->ramp!=100){
                    if(abs(this->last-x)>h) {
                        if (this->last > x) {
                            x = this->last - h;
                        } else {
                            x = this->last + h;
                        }

                    }
                }
                float minTime = (float)this->basTime*(float)this->data->min/(float)100;
                float maxTime = ((float)this->basTime-minTime)*(float)this->data->max/(float)100;
                float Htime = minTime+(maxTime)*((float)x/(float)100);
                this->lowTime = (float)this->basTime-Htime;
                if(x!=0)
                    digitalWrite(this->pinCode,HIGH);
                else
                    digitalWrite(this->pinCode,LOW);
                this->status = false;
                this->time = Htime;
                this->last = x;
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


bool analogPWM::getStatus(){
    return this->status;
}

analogPWM::~analogPWM()
{
    delete this->zab;
}