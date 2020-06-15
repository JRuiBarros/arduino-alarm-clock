#include "TimeMode.h"

RTC TimeMode::m_rtc;
Timer TimeMode::setTimer{150};

int TimeMode::pollButtons()
{
    readButtons();

    // Poll clear alarm button
    if (buttons[3].wasReleased())
    {
        m_rtc.clearAlarms();
    }

    if (m_setMode != 0)
    {
        if (buttons[0].pressedFor(LONG_PRESS))
        {
            if (setTimer.check())
            {
                m_setMode == 1 ? decHour() : decMin();
                setTimer.reset(true);
            }
            displayTimer.reset(true);
        }
        if (buttons[1].pressedFor(LONG_PRESS))
        {
            if (setTimer.check())
            {
                m_setMode == 1 ? incHour() : incMin();
                setTimer.reset(true);
            }
            displayTimer.reset(true);
        }
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