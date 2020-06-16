#pragma once
#include "BaseMode.h"
#include <Adafruit_BMP280.h>

class TempMode : public BaseMode
{
private:
    Adafruit_BMP280 bmp; // TODO change this to static when the other sensor arrives.

public:
    using BaseMode::BaseMode;
    int pollButtons();
    void display();
    void begin();
};
