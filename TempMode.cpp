#include "TempMode.h"

int TempMode::pollButtons()
{
    readButtons();
    BaseMode::pollButtons();
}

void TempMode::display()
{
    m_display.displayTemperature(bme.readTemperature());
}