#pragma once
#include "BaseMode.h"
#include <Adafruit_BMP280.h>

// Class representing the temperature display mode of the alarm clock.
class TempMode : public BaseMode
{
private:
    Adafruit_BMP280 bmp; // TODO change this to static when the other sensor arrives.

public:
    using BaseMode::BaseMode;
    int pollButtons();
    void display();

    // Starts up the temperature module.
    void begin();
};
