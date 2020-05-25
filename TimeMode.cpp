#include "TimeMode.h"

int TimeMode::pollButtons()
{
    readButtons();

    if (m_setMode != 0)
    {
        if (buttons[0].wasReleased())
        {
            m_setMode == 1 ? decHour() : decMin();
            resetTimer();
        }
        if (buttons[1].wasReleased())
        {
            m_setMode == 1 ? incHour() : incMin();
            resetTimer();
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
        if (hook())
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
        }

        int ret = iMode::pollButtons();

        if (ret != rets[0])
        {
            resetTimer();
        }

        return ret;
    }
}

boolean TimeMode::checkTimer()
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval)
    {
        // save the last time you blinked the LED
        previousMillis = currentMillis;
        isBlink = !isBlink;
    }
    return isBlink;
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
            hour = !checkTimer() ? hour : -1;
        }
        if (m_setMode == 2)
        {
            min = !checkTimer() ? min : -1;
        }
        m_display.displayTime(hour, min, a1, a2);
    }
    else
    {
        if (hook())
        {
            m_display.displayTime(hour, min, a1, a2);
        }
        else
        {
            if (!checkTimer())
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