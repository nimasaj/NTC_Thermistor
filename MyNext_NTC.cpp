#include <bits/stdc++.h>//comment it for usage in Arduino boards
#include <stdint.h>//comment it for usage in Arduino boards
#include "MyNext_NTC.h"

using namespace std;


NTC::NTC(uint8_t Analog_pin, uint16_t SR, uint16_t TR, uint8_t sn )
{
    pin=Analog_pin;
    _SR=SR;
    _TR=TR;
    _sn=sn;
}

NTC::~NTC()
{
    //dtor
}


void NTC::init()
{
    //MCU config
    //pinMode(pin, INPUT); //for Arduino boards, uncomment this line | comment or change it for other test cases
}

float NTC::average()
{
    float ave=0;
    for (uint8_t i=0; i<_sn; i++)
    {
        //ave+=analogRead(pin);//for Arduino boards uncomment this line | comment or change it for other test cases
        //delay(20);//for Arduino boards uncomment this line | comment or change it for other test cases
        ave+=529.5;//test case - cooment this line
        if(i==(_sn-1))
        {
            ave/=_sn;
            return ave;
        }
    }
    return 0;
}


float NTC::read() //Steinhart-hart equation
{
    float ave=average();

    float Res=1023/ave -1;
    Res= _SR/Res;
    float val= Res/_TR, a;
    val = log(val);
    val /= BetaCoef;
    val += 1 / (RT + 273.15);
    val = 1 / val;
    val -= 273.15;

    return val;
}