#include "CButton.h"

CButton::CButton(int p) : Button(p)
{
}

bool CButton::wasReleased()
{
    bool ret = Button::wasReleased();
    if (ret && inLongPress)
    {
        inLongPress = false;
        return false;
    }
    return ret;
}

bool CButton::wasLongPressed()
{
    if (!inLongPress)
    {
        bool ret = Button::pressedFor(LONG_PRESS);
        inLongPress = ret;
        return ret;
    }

    return false;
}
