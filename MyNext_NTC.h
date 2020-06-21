#ifndef MyNext_NTC_H
#define MyNext_NTC_H
#include <stdint.h>//comment it for usage in Arduino boards
//#include "Arduino.h"//for Arduino boards uncomment this line | comment or change it for other test cases

using namespace std;

class NTC
{
    public:
        NTC(uint8_t Analog_pin, uint16_t SR, uint16_t TR, uint8_t sn=5 );
        ~NTC();

        //methods
        void init();
        float average();
        float read();

    protected:

    private:
        //attributes
        float RT=25; //room temperature in which thermistor nominal resistance is measured.
        uint8_t pin,_sn;
        uint16_t _SR,_TR;
		uint16_t BetaCoef = 4000; // Beta coefficient of the thermistor (usually 3000-4000)
};

#endif // NTC_H
