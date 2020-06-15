#pragma once
#include "iMode.h"
#include <Adafruit_BMP280.h>

class TempMode : public iMode
{
private:
    Adafruit_BMP280 bmp;

public:
    using iMode::iMode;
    int pollButtons();
    void display();
    void begin();
};
