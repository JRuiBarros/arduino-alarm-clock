#include "CurrentTime.h"

//TODO This logic should be on the parent class using the template patttern
int CurrentTime::pollButtons()
{
    if (m_setMode != 0)
    {
        return TimeMode::setMode();
    }
    else
    {
        int ret = iMode::pollButtons();

        if (buttons[0].wasLongPressed())
        {
            m_rtc.toggleAlarm1();
            return 0;
        }

        if (buttons[1].wasLongPressed())
        {
            m_rtc.toggleAlarm2();
            return 0;
        }

        if (buttons[2].wasLongPressed())
        {
            m_setMode = 1;
            return 0;
        }

        return ret;
    }
}

void CurrentTime::display()
{
    // get time values
    int hour = m_rtc.getHour();
    int min = m_rtc.getMinute();
    m_display.displayTime(hour, min, m_rtc.isAlarm1(), m_rtc.isAlarm2());
}