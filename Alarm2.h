#pragma once
#include "TimeMode.h"

// Class representing the Alarm2 display mode.
class Alarm2 : public TimeMode
{
public:
    using TimeMode::TimeMode;

private:
    void decHour() { m_rtc.processA2Hour(false); }
    void decMin() { m_rtc.processA2Minute(false); }
    void incHour() { m_rtc.processA2Hour(true); }
    void incMin() { m_rtc.processA2Minute(true); }
    void longPress1() {}
    void longPress2() {}
    int getHour() { m_rtc.getA2Hour(); }
    int getMin() { m_rtc.getA2Minute(); }
    bool getA1() { return false; }
    bool getA2() { return true; }
};