#include "TimeMode.h"

Timer TimeMode::setTimer{150};

int TimeMode::pollButtons()
{
    readButtons();

    // Logic during the setting of the time values.
    if (m_setMode != 0)
    {
        // First two blocks refer to long press setting, where you long press the button and the values
        // increment rapidly, a timer is used to control the speed of the increments.
        if (buttons[0].pressedFor(LONG_PRESS))
        {
            if (setTimer.check())
            {
                m_setMode == 1 ? decHour() : decMin();
                // We're passing a true parameter here so the next timer call will return false, otherwise time would increment as fast as possible. 
                setTimer.reset(true);
            }
            displayTimer.reset();
        }
        if (buttons[1].pressedFor(LONG_PRESS))
        {
            if (setTimer.check())
            {
                m_setMode == 1 ? incHour() : incMin();
                setTimer.reset(true);
            }
            displayTimer.reset();
        }
        // Regular button press settings
        if (buttons[0].wasReleased())
        {
            m_setMode == 1 ? decHour() : decMin();
            displayTimer.reset();
        }
        if (buttons[1].wasReleased())
        {
            m_setMode == 1 ? incHour() : incMin();
            displayTimer.reset();
        }
        // Change setting mode.
        if (buttons[2].wasReleased())
        {
            m_setMode = m_setMode == 1 ? 2 : 0;
            displayTimer.reset(true); // We want the blinking effect to start immediately so we pass a "true" as a parameter.

            if (m_setMode == 0)
            {
                // After setting time values always return the current time mode.
                return 0;
            }
        }

        // Returs current state
        return rets[0];
    }
    else
    {
        // Only check for long presses during the current time display mode.
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
        // Start up setting the time if button 2 is long pressed.
        if (buttons[2].wasLongPressed())
        {
            m_setMode = 1;
            displayTimer.reset(true); // We want the blinking effect to start immediately so we pass a "true" as a parameter.
        }

        // Superclass button polling function, always needed.
        int ret = BaseMode::pollButtons();

        // If changing alarm display mode then reset the display timer, so the blinking restarts properly.
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
            hour = displayTimer.check() ? hour : -1;
        }
        if (m_setMode == 2)
        {
            min = displayTimer.check() ? min : -1;
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