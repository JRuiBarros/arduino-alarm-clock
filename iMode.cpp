#include "iMode.h"

unsigned long iMode::previousMillis{0};
boolean iMode::isDisplaying{false};

CButton b1(2);
CButton b2(3);
CButton b3(4);
CButton iMode::buttons[] = {b1, b2, b3};
DisplayWrapper iMode::m_display;

iMode::iMode(int p_rets[]) : rets{p_rets}
{
}

void iMode::readButtons()
{
    buttons[0].read();
    buttons[1].read();
    buttons[2].read();
}

int iMode::pollButtons()
{
    int ret = rets[0];

    if (buttons[0].wasReleased())
    {
        ret = rets[1];
    }
    if (buttons[1].wasReleased())
    {
        ret = rets[2];
    }
    if (buttons[2].wasReleased())
    {
        ret = rets[3];
    }
    return ret;
}

void iMode::begin()
{
    buttons[0].begin();
    buttons[1].begin();
    buttons[2].begin();
    m_display.begin();
}

boolean iMode::checkTimerToDisplay()
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval)
    {
        // save the last time you blinked the LED
        previousMillis = currentMillis;
        isDisplaying = !isDisplaying;
    }
    return isDisplaying;
}

void iMode::resetTimer()
{
    previousMillis = 0;
    isDisplaying = false;
}