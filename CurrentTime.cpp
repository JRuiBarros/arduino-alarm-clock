#include "CurrentTime.h"

int CurrentTime::pollButtons()
{
    iMode::pollButtons();

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

    if (buttons[0].wasReleased())
    {
        return 1;
    }

    if (buttons[1].wasReleased())
    {
        return 2;
    }

    return 0;
}

void CurrentTime::display()
{
    // get time values
    int hour = m_rtc.getHour();
    int min = m_rtc.getMinute();
    m_display.displayTime(hour, min, m_rtc.isAlarm1(), m_rtc.isAlarm2());
}