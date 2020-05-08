#include "TimeMode.h"

int TimeMode::setMode()
{
    // Serial.println("SETU MODE!!!!!!!!!!!!");

    buttons[0].read();
    buttons[1].read();
    buttons[2].read();

    if (buttons[0].wasReleased())
    {
        Serial.println("SETU MODE 111111111111");
        m_setMode == 1 ? m_rtc.processHour(rets[0], false) : m_rtc.processMinute(rets[0], false);
    }
    if (buttons[1].wasReleased())
    {
        Serial.println("SETU MODE 222222222222");
        m_setMode == 1 ? m_rtc.processHour(rets[0], true) : m_rtc.processMinute(rets[0], true);
    }
    if (buttons[2].wasReleased())
    {
        Serial.println("SETU MODE 333333333333");
        m_setMode = m_setMode == 1 ? 2 : 0;
    }

    return rets[0];
}