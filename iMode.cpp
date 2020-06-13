#include "iMode.h"

CButton b1(2);
CButton b2(3);
CButton b3(4);
CButton b4(5);
CButton iMode::buttons[] = {b1, b2, b3, b4};
DisplayWrapper iMode::m_display;
Timer iMode::displayTimer{500};

iMode::iMode(int p_rets[]) : rets{p_rets}
{
}

void iMode::readButtons()
{
    buttons[0].read();
    buttons[1].read();
    buttons[2].read();
    buttons[3].read();
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
    buttons[3].begin();
    m_display.begin(DISPLAY_ADDRESS);
}