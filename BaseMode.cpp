#include "BaseMode.h"

CButton b1(2);
CButton b2(3);
CButton b3(4);
CButton b4(5);
CButton BaseMode::buttons[] = {b1, b2, b3, b4};
Display BaseMode::m_display;
Timer BaseMode::displayTimer{500};

BaseMode::BaseMode(int p_rets[]) : rets{p_rets}
{
}

void BaseMode::readButtons()
{
    buttons[0].read();
    buttons[1].read();
    buttons[2].read();
    buttons[3].read();
}

int BaseMode::pollButtons()
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

void BaseMode::begin()
{
    buttons[0].begin();
    buttons[1].begin();
    buttons[2].begin();
    buttons[3].begin();
    m_display.begin(DISPLAY_ADDRESS);
}