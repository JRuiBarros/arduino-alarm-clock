#pragma once
#include "BaseMode.h"

// Class representing the humidity display mode of the alarm clock.
class HumiMode : public BaseMode
{
public:
    using BaseMode::BaseMode;
    void display() { m_display.displayHumidity(bme.readHumidity()); }
};
