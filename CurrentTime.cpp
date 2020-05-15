#include "CurrentTime.h"

void CurrentTime::display()
{
    // get time values
    int hour = m_rtc.getHour();
    int min = m_rtc.getMinute();
    m_display.displayTime(hour, min, m_rtc.isAlarm1(), m_rtc.isAlarm2());
}