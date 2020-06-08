#include "TimeMode.h"

RTCWrapper TimeMode::m_rtc;

int TimeMode::pollButtons()
{
    readButtons();

    if (m_setMode != 0)
    {
        // if (buttons[0].pressedFor(1000))
        // {
        //     if (checkDisplayTimer())
        //     {
        //         m_setMode == 1 ? decHour() : decMin();
        //     }
        //     resetDisplayTimer(true);
        // }
        // if (buttons[1].pressedFor(1000))
        // {
        //     if (checkDisplayTimer())
        //     {
        //         m_setMode == 1 ? incHour() : incMin();
        //     }
        //     resetDisplayTimer(true);
        // }
        if (buttons[0].wasReleased())
        {
            m_setMode == 1 ? decHour() : decMin();
            displayTimer.reset(true);
        }
        if (buttons[1].wasReleased())
        {
            m_setMode == 1 ? incHour() : incMin();
            displayTimer.reset(true);
        }
        if (buttons[2].wasReleased())
        {
            m_setMode = m_setMode == 1 ? 2 : 0;
            displayTimer.reset();

            if (m_setMode == 0)
            {
                return 0;
            }
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
            displayTimer.reset();
        }

        int ret = iMode::pollButtons();

        if (ret != rets[0])
        {
            displayTimer.reset();
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
            hour = !displayTimer.check() ? hour : -1;
        }
        if (m_setMode == 2)
        {
            min = !displayTimer.check() ? min : -1;
        }
        if (!isAlarm())
        {
            a1 = false;
            a2 = false;
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
            if (displayTimer.check())
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