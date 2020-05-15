#pragma once
#include "iMode.h"
#include <Adafruit_BMP280.h>

class TempMode: public iMode
{
    private:
        Adafruit_BMP280 bmp;
    public:
        using iMode::iMode;
        // TempMode(int p_ret[]);
        virtual int pollButtons();
        virtual void display();
        void begin();
};
