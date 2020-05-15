#include "TimeMode.h"

int TimeMode::pollButtons()
{
    readButtons();

    if (m_setMode != 0)
    {
        if (buttons[0].wasReleased())
        {
            Serial.println("SETU MODE 111111111111");
            m_setMode == 1 ? decHour() : decMin();
        }
        if (buttons[1].wasReleased())
        {
            Serial.println("SETU MODE 222222222222");
            m_setMode == 1 ? incHour() : incMin();
        }
        if (buttons[2].wasReleased())
        {
            Serial.println("SETU MODE 333333333333");
            m_setMode = m_setMode == 1 ? 2 : 0;
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
            isBlink = true;
            previousMillis = 0;
        }

        return ret;
    }
}

void TimeMode::displayAlarm(int hour, int min, bool a1, bool a2)
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval)
    {
        // save the last time you blinked the LED
        previousMillis = currentMillis;

        if (isBlink)
        {
            m_display.displayTime(hour, min, a1, a2);
            isBlink = false;
        }
        else
        {
            m_display.displayBlank();
            isBlink = true;
        }
    }
}