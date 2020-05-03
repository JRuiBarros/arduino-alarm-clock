#include "iMode.h"

iMode::iMode(int p_rets[]) : rets{p_rets}
{
}

int iMode::pollButtons()
{
    buttons[0].read();
    buttons[1].read();
    buttons[2].read();

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

void iMode::beginButtons()
{
    buttons[0].begin();
    buttons[1].begin();
    buttons[2].begin();
}