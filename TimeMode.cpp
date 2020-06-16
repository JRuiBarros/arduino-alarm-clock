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

    // Logic during the setting of the time values.
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
                // After setting always returns the current time mode.
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

        int ret = BaseMode::pollButtons();

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

    // Logic during the setting mode to create the blinking effect.
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
        if (!isAlarm()) // Show no leds if current time is being set.
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
        else // Blink the screen is showing the alarm values.
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