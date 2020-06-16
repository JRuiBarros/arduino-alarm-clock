#pragma once
#include "TimeMode.h"

// Class representing the Alarm1 display mode.
class Alarm1 : public TimeMode
{
public:
    using TimeMode::TimeMode;

private:
    void decHour() { m_rtc.processA1Hour(false); }
    void decMin() { m_rtc.processA1Minute(false); }
    void incHour() { m_rtc.processA1Hour(true); }
    void incMin() { m_rtc.processA1Minute(true); }
    void longPress1() {}
    void longPress2() {}
    int getHour() { m_rtc.getA1Hour(); }
    int getMin() { m_rtc.getA1Minute(); }
    bool getA1() { return true; }
    bool getA2() { return false; }
};