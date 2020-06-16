#pragma once
#include "TimeMode.h"

// Class representing the current time display mode (shows current time).
class CurrentTime : public TimeMode
{
public:
    using TimeMode::TimeMode;

private:
    bool isAlarm() { return false; }

    void decHour() { m_rtc.processHour(false); }
    void decMin() { m_rtc.processMinute(false); }
    void incHour() { m_rtc.processHour(true); }
    void incMin() { m_rtc.processMinute(true); }
    void longPress1() { m_rtc.toggleAlarm1(); }
    void longPress2() { m_rtc.toggleAlarm2(); }
    int getHour() { return m_rtc.getHour(); }
    int getMin() { return m_rtc.getMinute(); }
    bool getA1() { return m_rtc.isAlarm1(); }
    bool getA2() { return m_rtc.isAlarm2(); }
};