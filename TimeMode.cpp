#include "TimeMode.h"

RTCWrapper TimeMode::m_rtc;

int TimeMode::pollButtons()
{
    readButtons();

    if (m_setMode != 0)
    {
        if (buttons[0].wasReleased())
        {
            m_setMode == 1 ? decHour() : decMin();
            resetTimer(true);
        }
        if (buttons[1].wasReleased())
        {
            m_setMode == 1 ? incHour() : incMin();
            resetTimer(true);
        }
        if (buttons[2].wasReleased())
        {
            m_setMode = m_setMode == 1 ? 2 : 0;
            resetTimer();
        }

        // Returs current state
        return rets[0];
    }
    else
    {
        if (!isAlarm())
        {
            if (buttons[0].wasLongPressed())
            {
                longPress1();
            }

            if (buttons[1].wasLongPressed())
            {
                longPress2();
            }
        }
        if (buttons[2].wasLongPressed())
        {
            m_setMode = 1;
            resetTimer();
        }

        int ret = iMode::pollButtons();

        if (ret != rets[0])
        {
            resetTimer();
        }

        return ret;
    }
}

void TimeMode::display()
{
    int hour = getHour();
    int min = getMin();
    bool a1 = getA1();
    bool a2 = getA2();

    if (m_setMode != 0)
    {
        if (m_setMode == 1)
        {
            hour = !checkTimerToDisplay() ? hour : -1;
        }
        if (m_setMode == 2)
        {
            min = !checkTimerToDisplay() ? min : -1;
        }
        m_display.displayTime(hour, min, a1, a2);
    }
    else
    {
        if (!isAlarm())
        {
            m_display.displayTime(hour, min, a1, a2);
        }
        else
        {
            if (checkTimerToDisplay())
            {
                m_display.displayTime(hour, min, a1, a2);
            }
            else
            {
                m_display.displayBlank();
            }
        }
    }
}