#pragma once
#include "BaseMode.h"

// Class representing the temperature display mode of the alarm clock.
class TempMode : public BaseMode
{
public:
    using BaseMode::BaseMode;
    void display() {m_display.displayTemperature(bme.readTemperature());}
};
